package org.oha7.dispdriver.impl;

import java.lang.reflect.Array;
import java.lang.reflect.Method;

import org.oha7.dispdriver.annotations.Dispid;
import org.oha7.dispdriver.interfaces.IUnknown;
import org.oha7.dispdriver.interfaces.RawPtr;

/**
 * runtime proxy wrapped around naked native IUnknown pointers
 * the interfaces claimed to implemented are actually forwarded down the COM layer
 * @author mike
 *
 */
public class ComProxy implements java.lang.reflect.InvocationHandler {

	/**
	 * raw c++ IUnknown pointer
	 */
    private long ptr;

    /**
     * generate a new instance of a ComProxy for the native c++ IUnknown ptr passed as Long
     * with the interface as indicated
     * @param <T> - IUnknown derived java interface
     * @param ptr - naked c++ pointer to IUnknown
     * @param clazz - class object of interface
     * @return
     */
    public static <T> T newInstance(long ptr, Class<T> clazz) {
    	
    	Class<?>[] iClazzes = { clazz, RawPtr.class };
    	
    	@SuppressWarnings("unchecked")
		T t =  (T) java.lang.reflect.Proxy.newProxyInstance(
					//clazz.getClassLoader(),
					RawPtr.class.getClassLoader(),
    				iClazzes,
    				new ComProxy(ptr));
    	return t;
    }
    
    /**
     * generate a new instance of a ComProxy by calling CoCreate for the Progid given
     * 
     * @param <T>
     * @param progId
     * @param clazz
     * @return
     */
    public static <T> T newInstance(String progId, Class<T> clazz) {
    	
		long ptr = Native.CreateObject(progId);
		return ComProxy.newInstance(ptr, clazz);
    }
    
    /**
     * get a ComProxy for a ComObject registered as ActiveObject in ROT
     * @param <T>
     * @param progId
     * @param clazz
     * @return
     */
    public static <T> T runningInstance(String progId, Class<T> clazz) {
    	
		long ptr = Native.GetObject(progId);
		return ComProxy.newInstance(ptr, clazz);
    }    

    /**
     * prive ctor - stores the naked c++ IUnknown ptr
     * @param obj
     */
    private ComProxy(Long obj) {
    	
    	if ( obj == 0) {
    		throw new IllegalArgumentException("null COM ptr");
    	}
    	
    	this.ptr = obj;
    }

    /**
     * invocation handler - redirect the call to the COM layer
     */
    public Object invoke(Object proxy, Method m, Object[] args)	throws Throwable
    {
        Object result;
    
    	String methodName = m.getName();
    	
    	// intercept calls to Addref/Release as we can serve them right now
    	if ( methodName.equals("AddRef")) {
    		Native.Addref(ptr);
    		return null;
    	}        	
    	if ( methodName.equals("Release")) {
    		Native.Release(ptr);
    		ptr = 0;
    		return null;
    	}
    	
    	// intercept calls to value and return a RawComPtr
    	if ( m.getDeclaringClass() == RawPtr.class ) 
    	if ( methodName.equals("value")) {
    		return new RawComPtr(ptr);
    	}        	
    	
    	// intercept calls to QueryInterface and return a casted RawComPtr    	
    	if ( methodName.equals("QueryInterface")) {
    		
    		Class<?> clazz = (Class<?>) args[0];
    		Native.Addref(this.ptr);
    		return ComProxy.newInstance(this.ptr, clazz);
    	}
    	
		// walk arguments and replace Interfaces with raw ptrs
    	args = walkArguments(args);
    	       	        	
    	// get flags
    	int flags = determineFlags(methodName);        	
    	
    	// get dispid
    	int dispid = 0;
    	Dispid dispidAnnotation = m.getAnnotation(Dispid.class);
    	if ( dispidAnnotation != null ) {
    		dispid = dispidAnnotation.value();
    	} else {
    		if ( proxy instanceof IUnknown ) {
    			throw new NoSuchMethodException(methodName);
    		}
    	}
    	       	
    	// do the native invocation
    	result = Native.Invoke(ptr,dispid,m.getParameterTypes(),args, flags);	    	
    	
    	// handle results of IDispatch type
    	if ( result instanceof RawComPtr) {
    		
    		Class<?> clazz = m.getReturnType();
    		return ComProxy.newInstance( ((RawComPtr) result).value(), clazz);
    	}
        	
        return result;
    }

    /**
     * get propPut/propGet flags for method
     * @param methodName
     * @return - flag
     */
	private int determineFlags(String methodName) {
		
		int flags = Native.DISPATCH_METHOD;
		if ( methodName.startsWith("set")) {
			flags = Native.DISPATCH_PROPERTYPUT;
			methodName = methodName.substring(3);
		}
		if ( methodName.startsWith("get")) {
			flags = Native.DISPATCH_PROPERTYGET;
			methodName = methodName.substring(3);
		}
		return flags;
	}

	/**
	 * walk arguments and replace Interfaces with raw ptrs
	 * @param args
	 * @return
	 */
	private Object[] walkArguments(Object[] args) {
		
		if ( args != null )
		for ( int i = 0; i < args.length; i++ ) {
					
			// convert primitive Arrays to corresponding Wrapper Array
			Object obj = args[i];
			if ( obj.getClass().isArray() ) {
				
				for ( int j = 0; j < Array.getLength(obj); j++) {
					Object o = Array.get(obj, j);
					args[i] = replaceInterfaceWithRawPointer(o, i);
				}
			}
			else {
				args[i] = replaceInterfaceWithRawPointer(obj, i);
			}
		}
		return args;
	}

	/**
	 * replace Interfaces with raw ptrs
	 * @param obj
	 * @param i
	 * @return 
	 */
	private Object replaceInterfaceWithRawPointer(Object obj, int i) {
		
		if ( obj instanceof IUnknown ) {
			
			RawPtr raw = (RawPtr)obj;				
			RawComPtr rawPtr = raw.value();
			obj = rawPtr;
		}
		return obj;
	}
        
}
