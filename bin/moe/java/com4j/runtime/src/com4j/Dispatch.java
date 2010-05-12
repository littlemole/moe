package com4j;

import java.io.StringWriter;
import java.io.PrintWriter;
import java.util.Map;
import java.util.HashMap;
import java.util.WeakHashMap;
import java.util.Collections;
import java.util.logging.Logger;
import java.util.logging.Level;
import java.lang.reflect.Method;
import java.lang.reflect.InvocationTargetException;


public final class Dispatch<T extends Object> implements com4j.IDispatch {

    int nativeProxy;
    
	private final T javaObject;
    private final ComThread thread;
    private final EventInterfaceDescriptor<T> descriptor;
    
    /**
     * Creates a new dispatch proxy that implements IDispatch
     * and delivers events to {@code javaObject}.
     */
    public Dispatch( Class<T> clazz, T javaObject) {
    	
        this.descriptor = getDescriptor( clazz );
        this.javaObject = javaObject;
        
        assert ComThread.isComThread();
        thread = ComThread.get();        
        
    }
    
    /**
     * Return native IDispatch pointer, does not do AddRef
     */
    
    public int getPtr() {
    	return nativeProxy;
    }    

    /**
     * Return IDispatch pointer as (AddRef'd) Variant
     */
    
    public com4j.Variant variant() {

    	return new Task<com4j.Variant>() {
            public com4j.Variant call() {
            	Native.addRef(nativeProxy);
            	com4j.Variant v = new com4j.Variant();
            	v.set( nativeProxy );
            	v.setType(com4j.Variant.Type.VT_DISPATCH);
            	return v;
            }
        }.execute(thread);       
    }   
    
    /**
     * Return IDispatch wrapper to java class as (AddRef'd) com4j.Com4jObject
     */
    
    public com4j.Com4jObject wrapper() {
    	
        return new Task<com4j.Com4jObject>() {
            public com4j.Com4jObject call() {
            	Native.addRef(nativeProxy);
            	return Wrapper.create(nativeProxy);
            }
        }.execute(thread);       
    }    

    /**
     * Return DISPIDs for this {@code javaObject}.
     */
    
    int[] getDISPIDs(String[] names) {
        int[] r = new int[names.length];
        for( int i=0; i<names.length; i++ ) {
            r[i] = descriptor.getDISPID(names[i]);
        }
        return r;
    }

    /**
     * IDispatch invoke handler (java side)
     */
    
    Object invoke(int dispId, int flag, Variant[] args) throws Throwable {
        EventMethod m = descriptor.get(dispId);
        if(m==null)
            throw new ComException("Undefined DISPID="+dispId,DISP_E_MEMBERNOTFOUND);
        if ( javaObject == null )
        	throw new ComException("No Java handler for DISPID="+dispId,DISP_E_MEMBERNOTFOUND);
                
        
        return m.invoke(javaObject,flag,args);
    }
    
    //////////////////////////////////////////////////////////
    // implementation - see EventProxy ! TODO: duplicate code
    //////////////////////////////////////////////////////////

    /**
     * Descriptor cache.
     */
    private static final Map<Class,EventInterfaceDescriptor> descriptors =
        Collections.synchronizedMap(new WeakHashMap<Class,EventInterfaceDescriptor>());

    /**
     * Gets the descriptor for the given type.
     */
    private static <T> EventInterfaceDescriptor<T> getDescriptor(Class<T> t) {
        EventInterfaceDescriptor<T> r = descriptors.get(t);
        if(r==null) {
            r = new EventInterfaceDescriptor<T>(t);
            descriptors.put(t,r);
        }
        return r;
    }

    /**
     * Describes the event interface.
     */
    private static class EventInterfaceDescriptor<T> {
        private final Class<T> eventInterface;

        /**
         * Methods by their names.
         */
        private final Map<String,EventMethod> methodsByName = new HashMap<String,EventMethod>();

        private final Map<Integer,EventMethod> methodsByID = new HashMap<Integer, EventMethod>();

        EventInterfaceDescriptor(Class<T> eventInterface) {
            this.eventInterface = eventInterface;

            for (Method m : eventInterface.getDeclaredMethods()) {
            	
            	try {
            		DISPID a = DispatchComMethod.getDISPID(m);
                	if ( a == null )
                		continue;            		
            	}
            	catch ( Throwable t) {
            		continue;
            	}
            	
                EventMethod em = new EventMethod(m);
                methodsByName.put(m.getName(),em);
                methodsByID.put(em.dispid,em);
            }
        }

        public int getDISPID(String name) {
            EventMethod r = methodsByName.get(name);
            if(r==null)
                return DISP_E_UNKNOWNNAME;
            else
                return r.dispid;
        }

        public EventMethod get(int id) {
            return methodsByID.get(id);
        }
    }

    private static class EventMethod {
        private final int dispid;
        private final Method method;
        private final Class[] params;

        public EventMethod(Method m) {
        	DISPID a = DispatchComMethod.getDISPID(m);
            if(a==null)
                throw new IllegalAnnotationException(m+" needs to have @DISPID");
            dispid = a.value();
            method = m;
            params = m.getParameterTypes();
        }

        /**
         * Invokes a method.
         */
        public Object invoke(Object o, int flag, Variant[] args) throws Throwable {
            try {
                if(args.length!=params.length)
                    throw new ComException("Argument length mismatch. Expected "+params.length+" but found "+args.length,DISP_E_BADPARAMCOUNT);

                Object[] oargs = new Object[args.length];
                for( int i=0; i<args.length; i++ )
                    oargs[i] = args[i].convertTo(params[i]);
                return method.invoke(o,oargs);
            } catch (InvocationTargetException e) {
                logger.log(Level.WARNING, method+" on "+o+" reported an exception",e.getTargetException());
                throw e.getTargetException();
            } catch (RuntimeException e) {
                logger.log(Level.WARNING, "Unable to invoke "+method+" on "+o,e);
                throw e;
            }
        }
    }
    
    private static final int DISP_E_UNKNOWNNAME = 0x80020006;
    private static final int DISP_E_MEMBERNOTFOUND = 0x80020003;
    private static final int DISP_E_BADPARAMCOUNT = 0x8002000E;    

    //
    // Used by the native code to assist exception handling
    //
     
     static String getErrorSource(Throwable t) {
         return t.toString();
     }

     static String getErrorDetail(Throwable t) {
         StringWriter sw = new StringWriter();
         t.printStackTrace(new PrintWriter(sw));
         return sw.toString();
     }
    
    private static final Logger logger = Logger.getLogger(EventProxy.class.getName());

    static {
        boolean com4jDebug = false;
        try {
            com4jDebug = System.getProperty("com4j.debug")!=null;
        } catch (Throwable e) {
            ;
        }

        if(!com4jDebug)
            logger.setLevel(Level.OFF);
    }
}
