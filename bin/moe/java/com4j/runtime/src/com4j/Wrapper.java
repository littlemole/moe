package com4j;

import java.lang.reflect.InvocationHandler;
import java.lang.reflect.InvocationTargetException;
import java.lang.reflect.Method;
import java.lang.reflect.Proxy;
import java.util.Collections;
import java.util.Map;
import java.util.WeakHashMap;

/**
 * {@link InvocationHandler} that backs up a COM object.
 *
 * @author Kohsuke Kawaguchi (kk@kohsuke.org)
 */
public final class Wrapper implements InvocationHandler, Com4jObject {

    /**
     * interface pointer.
     */
    private int ptr;

    /**
     * Cached hash code. The value of {@code IUnknown*}.
     */
    private int hashCode=0;

    /**
     * Used to form a linked list for {@link ComThread#freeList}.
     */
    Wrapper next;

    /**
     * All the invocation to the wrapper COM object must go through this thread.
     */
    private final ComThread thread;

    /**
     * Cached of {@link ComMethod} keyed by the method decl.
     *
     * TODO: revisit the cache design
     */
    private Map<Method,ComMethod> cache = Collections.synchronizedMap(
        new WeakHashMap<Method,ComMethod>());

    /**
     * Wraps a new COM object. The pointer needs to be addref-ed by the caller if needed.
     */
    private Wrapper(int ptr) {
        if(ptr==0)   throw new IllegalArgumentException();
        assert ComThread.isComThread();

        this.ptr = ptr;
        thread = ComThread.get();
    }

    /**
     * Creates a new proxy object to a given COM pointer.
     * <p>
     * Must be run from a {@link ComThread}. This method doesn't do AddRef.
     */
    public static <T extends Com4jObject>
    T create( Class<T> primaryInterface, int ptr ) {
        Wrapper w = new Wrapper(ptr);
        T r = primaryInterface.cast(Proxy.newProxyInstance(
            primaryInterface.getClassLoader(),
            new Class<?>[]{primaryInterface},
                w));
        w.thread.addLiveObject(r);
        return r;
    }

    /**
     * Creates a new proxy object to a given COM pointer.
     * <p>
     * Must be run from a {@link ComThread}.
     */
    public static Com4jObject create( int ptr ) {
        Wrapper w = new Wrapper(ptr);
        w.thread.addLiveObject(w);
        return w;
    }


    int getPtr() {
        return ptr;
    }

    protected void finalize() throws Throwable {
        super.finalize();
        if(ptr!=0)
            thread.addToFreeList(this);
    }

    private static final Object[] EMPTY_ARRAY = new Object[0];

    public Object invoke(Object proxy, Method method, Object[] args) throws Throwable {
        if(ptr==0)
            throw new IllegalStateException("COM object is already disposed");
        if(args==null)  // this makes the processing easier
            args = EMPTY_ARRAY;

        Class<?> declClazz = method.getDeclaringClass();

        if( declClazz==Com4jObject.class || declClazz==Object.class ) {
            // method declared on Com4jObject is not meant to be delegated.
            try {
                return method.invoke(this,args);
            } catch( IllegalAccessException e ) {
                throw new IllegalAccessError(e.getMessage());
            } catch( InvocationTargetException e ) {
                throw e.getTargetException();
            }
        }

        if(invCache==null)
            invCache = new InvocationThunk();
        return invCache.invoke(getMethod(method),args);
    }

    private ComMethod getMethod(Method method) {
        ComMethod r = cache.get(method);
        if(r!=null)     return r;

        r = createComMethod(method);
        cache.put(method,r);
        return r;
    }

    private ComMethod createComMethod(Method method) {
        ReturnValue rv = method.getAnnotation(ReturnValue.class);
        if(rv!=null && rv.defaultPropertyThrough().length>0)
            return new DefaultedComMethod(method,rv);

        DISPID id = method.getAnnotation(DISPID.class);
        if(id!=null)
            return new DispatchComMethod(method);
        
        return new StandardComMethod(method);
    }

    public void dispose() {
        if(ptr!=0) {
            new Task<Void>() {
                public Void call() {
                    dispose0();
                    return null;
                }
            }.execute();
        }
    }

    /**
     * Called from {@link ComThread} to actually call IUnknown::Release.
     */
    boolean dispose0() {
        boolean r = ptr!=0;
        Native.release(ptr);
        ptr=0;
        return r;
    }

    public <T extends Com4jObject> boolean is( Class<T> comInterface ) {
        try {
            GUID iid = COM4J.getIID(comInterface);
            return new QITestTask(iid).execute(thread)!=0;
        } catch( ComException e ) {
            return false;
        }
    }

    public <T extends Com4jObject> T queryInterface( final Class<T> comInterface ) {
        return new Task<T>() {
            public T call() {
                GUID iid = COM4J.getIID(comInterface);
                int nptr = Native.queryInterface(ptr,iid);
                if(nptr==0)
                    return null;    // failed to cast
                return create( comInterface, nptr );
            }
        }.execute(thread);
    }

    public <T> EventProxy<?> advise(final Class<T> eventInterface, final T object) {
        return new Task<EventProxy<?>>() {
            public EventProxy<?> call() {
                IConnectionPointContainer cpc = queryInterface(IConnectionPointContainer.class);
                if(cpc==null)
                    throw new ComException("This object doesn't have event source",-1);
                GUID iid = COM4J.getIID(eventInterface);
                Com4jObject cp = cpc.FindConnectionPoint(iid);
                EventProxy<T> proxy = new EventProxy<T>(eventInterface, object);
                proxy.nativeProxy = Native.advise(COM4J.getPtr(cp),proxy,iid.v[0],iid.v[1]);

                // clean up resources to be nice
                cpc.dispose();
                cp.dispose();

                return proxy;
            }
        }.execute();
    }

    public String toString() {
        return "ComObject:"+Integer.toHexString(ptr);
    }

    public final int hashCode() {
        if(hashCode==0) {
            if(ptr!=0) {
                hashCode = new QITestTask(COM4J.IID_IUnknown).execute(thread);
            } else {
                hashCode = 0;
            }
        }
        return hashCode;
    }

    public final boolean equals( Object rhs ) {
        if(!(rhs instanceof Com4jObject))   return false;
        return hashCode()==rhs.hashCode();
    }

    /**
     * Used to pass parameters/return values between the host thread
     * and the peer {@link ComThread}.
     */
    private class InvocationThunk extends Task<Object> {
        private ComMethod method;
        private Object[] args;

        /**
         * Invokes the method on the peer {@link ComThread} and returns
         * its return value.
         */
        public synchronized Object invoke( ComMethod method, Object[] args ) {
            invCache = null;
            this.method = method;
            this.args = args;

            try {
                return execute(thread);
            } finally {
                invCache = this;
            }
        }

        /**
         * Called from {@link ComThread} to actually carry out the execution.
         */
        public synchronized Object call() {
            Object r = method.invoke(ptr,args);
            // clear fields that are no longer necessary
            method = null;
            args = null;
            return r;
        }
    }

    /**
     * We cache up to one {@link InvocationThunk}.
     */
    InvocationThunk invCache;



    /**
     * Invokes QueryInterface but immediately releases that pointer.
     * Useful for checking if an object implements a particular interface.
     */
    private final class QITestTask extends Task<Integer> {
        private final GUID iid;

        public QITestTask(GUID iid) {
            this.iid = iid;
        }

        public Integer call() {
            int nptr = Native.queryInterface(ptr,iid);
            if(nptr!=0)
                Native.release(nptr);
            return nptr;
        }
    }
}
