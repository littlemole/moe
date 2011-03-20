package org.oha7.dispdriver.impl;

import java.lang.reflect.Array;
import java.lang.reflect.Constructor;
import java.lang.reflect.Field;
import java.lang.reflect.InvocationTargetException;
import java.lang.reflect.Method;
import java.lang.reflect.Modifier;
import java.util.ArrayList;
import java.util.List;

import javax.swing.SwingUtilities;

import org.oha7.dispdriver.interfaces.RawPtr;
import org.oha7.dispdriver.swing.Construction;
import org.oha7.dispdriver.swing.Invocation;
import org.oha7.dispdriver.swing.PropertyAssignment;
import org.oha7.dispdriver.swing.PropertyFetchment;

/**
 * call java objects via COM utilizing IDispatch
 * @author mike
 *
 * native code does not call into the JVM directly, but just calls
 * these static helpers which will act as trampoline and return
 * desired values to native code
 *
 */

public class DispDriver {

	/**
	 * Create a java object from native code
	 * 
	 * @param clazz - class object of class to create
	 * @param args - arguments to be passed to constructor
	 * @return the newed object or null
	 * @throws NoSuchMethodException 
	 * @throws SecurityException 
	 * @throws InvocationTargetException 
	 * @throws IllegalAccessException 
	 * @throws InstantiationException 
	 * @throws IllegalArgumentException 
	 */
	public static Object Create ( Class<?> clazz, Object[] args ) throws SecurityException, NoSuchMethodException, IllegalArgumentException, InstantiationException, IllegalAccessException, InvocationTargetException {
				
		Class<?>[] argTypes = new Class<?>[args.length];
		for ( int i = 0; i < args.length; i++) {
			argTypes[i] = args[i].getClass();
		}
		Constructor<?> constructor = clazz.getConstructor(argTypes);
		if ( constructor == null ) {
			return null;
		}
		Object o = constructor.newInstance(args);
		return o;
		
	}
	
	public static Object CreateSwing ( Class<?> clazz, Object[] args ) throws SecurityException, NoSuchMethodException, IllegalArgumentException, InstantiationException, IllegalAccessException, InvocationTargetException {
		
		Class<?>[] argTypes = new Class<?>[args.length];
		for ( int i = 0; i < args.length; i++) {
			argTypes[i] = args[i].getClass();
		}
		Constructor<?> constructor = clazz.getConstructor(argTypes);
		if ( constructor == null ) {
			return null;
		}
		
		Construction construction = new Construction(constructor, args);
		
		try {
			SwingUtilities.invokeAndWait(construction);
		} catch (InterruptedException e) {
			e.printStackTrace();
			return null;
		}				
		
		return construction.unwrap();
		
	}	

	
	/**
	 * invoke a method on a java object from native code
	 * @param obj - the java object
	 * @param methodName - name of the method to invoke
	 * @param args - parameters for the method call
	 * @return the invoked methods return value or null in case of error or void methods
	 * @throws InvocationTargetException 
	 * @throws IllegalAccessException 
	 * @throws IllegalArgumentException 
	 */
	public static Object invoke ( Object obj, String methodName, Object[] varArgs ) throws IllegalArgumentException, IllegalAccessException, InvocationTargetException {
		
		Class<?>[] argTypes = getArgTypes(varArgs);
		Object[] args = getArgs(varArgs);
		
		Class<?> clazz = obj.getClass();
		
		Method method = getMethod( clazz, methodName, args, argTypes );	

		Object o = obj;
		if ( (method.getModifiers() & Modifier.STATIC) == Modifier.STATIC) {
				
			o = null;				
		}

		return doInvoke( method, o, args );
	}
	
	public static Object invokeSwing ( Object obj, String methodName, Object[] varArgs ) throws IllegalArgumentException, IllegalAccessException, InvocationTargetException {
		
		Class<?>[] argTypes = getArgTypes(varArgs);
		Object[] args = getArgs(varArgs);
		
		Class<?> clazz = obj.getClass();
		
		Method method = getMethod( clazz, methodName, args, argTypes );	

		Object o = obj;
		if ( (method.getModifiers() & Modifier.STATIC) == Modifier.STATIC) {
				
			o = null;				
		}

		return doInvokeSwing( method, o, args );
	}	

	/**
	 * invoke static method of java class
	 * @param clazz
	 * @param methodName
	 * @param varArgs
	 * @return Object
	 * @throws InvocationTargetException 
	 * @throws IllegalAccessException 
	 * @throws IllegalArgumentException 
	 */
	public static Object invoke ( Class<?> clazz, String methodName, Object[] varArgs ) throws IllegalArgumentException, IllegalAccessException, InvocationTargetException {
				
		Class<?>[] argTypes = getArgTypes(varArgs);
		Object[] args = getArgs(varArgs);
				
		Method method = getMethod(clazz,methodName, args, argTypes);
				
		return doInvoke(method,null,args);
	}
	
	public static Object invokeSwing ( Class<?> clazz, String methodName, Object[] varArgs ) throws IllegalArgumentException, IllegalAccessException, InvocationTargetException {
		
		Class<?>[] argTypes = getArgTypes(varArgs);
		Object[] args = getArgs(varArgs);
				
		Method method = getMethod(clazz,methodName, args, argTypes);
				
		return doInvokeSwing(method,null,args);
	}	
	
	/**
	 * get a field value
	 * @param obj
	 * @param name
	 * @param varArgs
	 * @return the fields value
	 * @throws IllegalAccessException 
	 * @throws IllegalArgumentException 
	 * @throws NoSuchFieldException 
	 * @throws SecurityException 
	 * @throws InvocationTargetException 
	 */
	public static Object propertyGet( Object obj, String name, Object[] varArgs) throws IllegalArgumentException, IllegalAccessException, SecurityException, NoSuchFieldException, InvocationTargetException {

		Class<?> clazz = null;
		if ( obj instanceof Class<?> ) {
			clazz = (Class<?>)obj;
		}
		else {
			clazz = obj.getClass();
		}
		
		Field[] fields = clazz.getFields();
		for ( Field field : fields) {
			if ( field.getName().equals(name)) {
			
				Object o = obj;
				if ( (field.getModifiers()& Modifier.STATIC) == Modifier.STATIC ) {
					o = null;
				}
				
				Object retval = field.get(o);
				retval = javaType2ObjectForVariant(retval);
				return retval;						
			}
		}
		Field field = clazz.getField(name);
		if ( field != null ) {
			
			Object o = obj;
			if ( (field.getModifiers()& Modifier.STATIC) == Modifier.STATIC ) {
				o = null;
			}
			
			Object retval = field.get(o);
			retval = javaType2ObjectForVariant(retval);
			return retval;			
		}			

		Class<?>[] argTypes = getArgTypes(varArgs);
		Object[] args = getArgs(varArgs);		
		Method method = getMethod( clazz, "get" + name, args, argTypes );	

		Object o = obj;
		if ( (method.getModifiers() & Modifier.STATIC) == Modifier.STATIC) {
				
			o = null;				
		}		
		
		Object retval = doInvoke(method,o,args);
		return retval;
	}
	
	public static Object propertyGetSwing( Object obj, String name, Object[] varArgs) throws IllegalArgumentException, IllegalAccessException, SecurityException, NoSuchFieldException, InvocationTargetException {

		Class<?> clazz = null;
		if ( obj instanceof Class<?> ) {
			clazz = (Class<?>)obj;
		}
		else {
			clazz = obj.getClass();
		}
		
		Field[] fields = clazz.getFields();
		for ( Field field : fields) {
			if ( field.getName().equals(name)) {
			
				Object o = obj;
				if ( (field.getModifiers()& Modifier.STATIC) == Modifier.STATIC ) {
					o = null;
				}
				
				PropertyFetchment pf = new PropertyFetchment(field,o);
				try {
					SwingUtilities.invokeAndWait(pf);
				} catch (InterruptedException e) {
					e.printStackTrace();
					return null;
				}
				
				Object retval = javaType2ObjectForVariant(pf.unwrap());
				return retval;						
			}
		}
		Field field = clazz.getField(name);
		if ( field != null ) {
			
			Object o = obj;
			if ( (field.getModifiers()& Modifier.STATIC) == Modifier.STATIC ) {
				o = null;
			}
			
			PropertyFetchment pf = new PropertyFetchment(field,o);
			try {
				SwingUtilities.invokeAndWait(pf);
			} catch (InterruptedException e) {
				e.printStackTrace();
				return null;
			}
			
			Object retval = javaType2ObjectForVariant(pf.unwrap());
			return retval;			
		}			

		Class<?>[] argTypes = getArgTypes(varArgs);
		Object[] args = getArgs(varArgs);		
		Method method = getMethod( clazz, "get" + name, args, argTypes );	

		Object o = obj;
		if ( (method.getModifiers() & Modifier.STATIC) == Modifier.STATIC) {
				
			o = null;				
		}		
		
		Object retval = doInvokeSwing(method,o,args);
		return retval;
	}
	
	/**
	 * set a Field value
	 * @param obj
	 * @param name
	 * @param varArgs
	 * @throws NoSuchFieldException 
	 * @throws SecurityException 
	 * @throws IllegalAccessException 
	 * @throws IllegalArgumentException 
	 * @throws InvocationTargetException 
	 */
	public static void propertyPut( Object obj, String name, Object[] varArgs) throws SecurityException, NoSuchFieldException, IllegalArgumentException, IllegalAccessException, InvocationTargetException {
		
		Class<?> clazz = obj.getClass();
		
		if ( varArgs.length == 0 ) {
			return;
		}
		
		Object value = varArgs[0];
		
		Field field = clazz.getField(name);
		if ( field != null ) {
			
			Object o = obj;
			if ( (field.getModifiers()& Modifier.STATIC) == Modifier.STATIC ) {
				o = null;
			}
							
			field.set(o,value);
			return;			
		}			

		Class<?>[] argTypes = getArgTypes(varArgs);
		Object[] args = getArgs(varArgs);		
		Method method = getMethod( clazz, "set" + name, args, argTypes );	

		Object o = obj;
		if ( (method.getModifiers() & Modifier.STATIC) == Modifier.STATIC) {
				
			o = null;				
		}		
		
		doInvoke(method,o,args);
	}
	
	/**
	 * set a Field value
	 * @param obj
	 * @param name
	 * @param varArgs
	 * @throws NoSuchFieldException 
	 * @throws SecurityException 
	 * @throws IllegalAccessException 
	 * @throws IllegalArgumentException 
	 * @throws InvocationTargetException 
	 */
	public static void propertyPutSwing( Object obj, String name, Object[] varArgs) throws SecurityException, NoSuchFieldException, IllegalArgumentException, IllegalAccessException, InvocationTargetException {
		
		Class<?> clazz = obj.getClass();
		
		if ( varArgs.length == 0 ) {
			return;
		}
		
		Object value = varArgs[0];
		
		Field field = clazz.getField(name);
		if ( field != null ) {
			
			Object o = obj;
			if ( (field.getModifiers()& Modifier.STATIC) == Modifier.STATIC ) {
				o = null;
			}
							
			//field.set(o,value);
			PropertyAssignment ps = new PropertyAssignment(field, o, value);
			SwingUtilities.invokeLater(ps);
			return;			
		}			

		Class<?>[] argTypes = getArgTypes(varArgs);
		Object[] args = getArgs(varArgs);		
		Method method = getMethod( clazz, "set" + name, args, argTypes );	

		Object o = obj;
		if ( (method.getModifiers() & Modifier.STATIC) == Modifier.STATIC) {
				
			o = null;				
		}		
		
		doInvokeSwing(method,o,args);
	}
	
	/**
	 * invoke a reflected method
	 * @param method
	 * @param obj
	 * @param args
	 * @return null or retval
	 * @throws InvocationTargetException 
	 * @throws IllegalAccessException 
	 * @throws IllegalArgumentException 
	 */
	private static Object doInvoke( Method method, Object obj, Object[] args ) throws IllegalArgumentException, IllegalAccessException, InvocationTargetException {

		if ( method == null) {
			return null;
		}
		
		Class<?>[] methodArgTypes = method.getParameterTypes();		
		for ( int i = 0; i < args.length; i++) {
			
			Object arg = args[i];
			
			if ( arg instanceof RawComPtr ) {
				RawComPtr ptr = (RawComPtr)arg;
				Class<?> clazz = methodArgTypes[i];
				args[i] = ComProxy.newInstance( ptr.value(), clazz);
			}
		}
		Object retval = method.invoke(obj,args);
		retval = javaType2ObjectForVariant(retval);
		return retval;
	}
	
	private static Object doInvokeSwing( Method method, Object obj, Object[] args ) throws IllegalArgumentException, IllegalAccessException, InvocationTargetException {

		if ( method == null) {
			return null;
		}
		
		Class<?>[] methodArgTypes = method.getParameterTypes();		
		for ( int i = 0; i < args.length; i++) {
			
			Object arg = args[i];
			
			if ( arg instanceof RawComPtr ) {
				RawComPtr ptr = (RawComPtr)arg;
				Class<?> clazz = methodArgTypes[i];
				args[i] = ComProxy.newInstance( ptr.value(), clazz);
			}
		}
		//Object retval = method.invoke(obj,args);
		
		Invocation invocation = new Invocation(method,obj,args);
		try {
			SwingUtilities.invokeAndWait(invocation);
		} catch (InterruptedException e) {
			e.printStackTrace();
			return null;
		}
				
		Object retval = javaType2ObjectForVariant(invocation.unwrap());
		return retval;
	}	
	
	/**
	 * retrieve runtime types of passed arguments
	 * @param varArgs
	 * @return array of argument Class Objects
	 */
	private static Class<?>[] getArgTypes( Object[] varArgs) {
		
		Class<?>[] argTypes = new Class<?>[varArgs.length];
	
		if ( varArgs.length > 0 ) {
			for ( int i = 0; i < varArgs.length; i++) {
				
				Object o = varArgs[varArgs.length-1-i];
				argTypes[i] = o == null ? null : o.getClass();
			}		
		}
		return argTypes;
	}
	
	/**
	 * reverse arguments passed from native code
	 * @param varArgs
	 * @return array of Objects
	 */
	private static Object[] getArgs( Object[] varArgs) {
		
		Object[] args = new Object[varArgs.length];
		if ( varArgs.length > 0 ) {
			for ( int i = 0; i < varArgs.length; i++) {
				
				Object o = varArgs[varArgs.length-1-i];
				args[i] = o;
			}		
		}
		return args;
	}	
	
	/**
	 * augment primitive types to Object
	 * @param <T>
	 * @param t
	 * @return Object
	 */
	private static <T> Object javaType2ObjectForVariant( T t) {
		
		if ( t == null ) {
			return null;
		}
		
		Class<?> clazz = t.getClass();
		
		if ( t instanceof RawPtr ) {
			RawPtr ptr = (RawPtr)t;
			return ptr.value();
		}
			
		
		if ( clazz.isPrimitive() ) {
			return t;
		}
		if ( clazz.isArray() ) {

			int len = Array.getLength(t);
			Object[] varArray = new Object[len];
			for ( int i = 0 ; i < len; i++) {
				Object item = Array.get(t, i);
				varArray[i] = item;
			}
			return varArray;				
		}
		return t;
	}
	
	
	
    /**
     * resolve java Method for dispatch call
     * @param clazz
     * @param methodName
     * @param args
     * @param argTypes
     * @return Method found or null
     */
   public static Method getMethod( Class<?> clazz, String methodName, Object[] args, Class<?>[] argTypes) {
    	
		Method[] methods = clazz.getMethods();
		List<Method> candidates = new ArrayList<Method>();
		
		for ( Method method : methods ) {
			if ( method.getName().equals(methodName)) {
				candidates.add(method);
			}
		}
		
		if ( candidates.size() == 0 ) {
			return null;
		}

		Method method = null;
		if ( candidates.size() == 1 ) {
			method = candidates.get(0);
		}
		else {
			method = getOverloadedMethod(candidates, args, argTypes );
		}
		return method;
    }
    
    /**
    * try to resolve overloaded methods by type 
    * @param candidates
    * @param args
    * @param argTypes
    * @return Method found or null
    */
	private static Method getOverloadedMethod( List<Method> candidates, Object[] args, Class<?>[] argTypes) {
		
		for ( Method method : candidates ) {
			
			Class<?>[] paramClazzes = method.getParameterTypes();
			if ( paramClazzes.length != args.length ) {
				continue;
			}
			
			Class<?>[] paramTypes = new Class<?>[paramClazzes.length];
			for ( int i = 0; i < paramClazzes.length; i++ ) {
				Object o = WrapperTypes.wrapperType( paramClazzes[i] );
				paramTypes[i] = (Class<?>)o;
			}
						
			boolean match = true;
			for ( int i = 0; i < args.length; i++ ) {
				
				if ( args[i] != null ) {
					if ( !paramTypes[i].isAssignableFrom(argTypes[i]) ) {
						match = false;
						break;
					}
				}
			}
			if ( match ) {
				return method;
			}
			
		}
				
		for ( Method method : candidates ) {
			
			Class<?>[] paramClazzes = method.getParameterTypes();
			if ( paramClazzes.length != args.length ) {
				continue;
			}
			return method;
		}
		
		return null;

	}
}
