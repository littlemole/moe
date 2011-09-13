package org.oha7.dispdriver.swing;

import java.lang.reflect.InvocationTargetException;
import java.lang.reflect.Method;

import javax.swing.SwingUtilities;

import org.oha7.dispdriver.impl.ComProxy;
import org.oha7.dispdriver.impl.DispDriver;
import org.oha7.dispdriver.impl.RawComPtr;
import org.oha7.dispdriver.interfaces.IDispatch;

public class Util {
	
	public static void dispose( Object o ) throws SecurityException, NoSuchMethodException, IllegalArgumentException, IllegalAccessException, InvocationTargetException {
		
		Class<?> clazz = o.getClass();
		Method m = clazz.getMethod( "dispose" );
		
		if ( m != null ) {
			SwingUtilities.invokeLater(new Invocation(m,o));
		}
	}
	
	

	public static void invoke( Object o, String methodName ) throws SecurityException, NoSuchMethodException, IllegalArgumentException, IllegalAccessException, InvocationTargetException {
		
		Class<?> clazz = null;
		
		if ( o instanceof Class<?> ) {
			clazz = (Class<?>)o;
		} else {		
			clazz = o.getClass();
		}
	
		Class<?>[] argTypes = new Class<?>[0];		
		Object[] args = new Object[0];
				
		Method m = DispDriver.getMethod(clazz, methodName, args, argTypes);
		if ( m != null ) {
			SwingUtilities.invokeLater(new Invocation(m,o,args));
		}
	}	
	
	private static Object getArg(Class<?> clazz, Object arg) {
		
		if ( arg instanceof RawComPtr ) {
			RawComPtr ptr = (RawComPtr)arg;
			return ComProxy.newInstance( ptr.value(), clazz);
		}	
		return arg;
	}
	
	public static void invoke( Object o, String methodName, Object arg ) throws SecurityException, NoSuchMethodException, IllegalArgumentException, IllegalAccessException, InvocationTargetException {
		
		Class<?> clazz = null;
				
		if ( o instanceof Class<?> ) {
			clazz = (Class<?>)o;
		} else {		
			clazz = o.getClass();
		}
		
		o = getArg(clazz,o);		
	
		Class<?>[] argTypes = new Class<?>[1];
		argTypes[0] = arg.getClass();
		
		Object[] args = new Object[1];
		args[0] = getArg(argTypes[0],arg);
				
		Method m = DispDriver.getMethod(clazz, methodName, args, argTypes);
		if ( m != null ) {
			SwingUtilities.invokeLater(new Invocation(m,o,args));
		}
	}	
	
	public static void invoke( Object o, String methodName, Object arg1, Object arg2 ) throws SecurityException, NoSuchMethodException, IllegalArgumentException, IllegalAccessException, InvocationTargetException {
		
		Class<?> clazz = null;
		
		if ( o instanceof Class<?> ) {
			clazz = (Class<?>)o;
		} else {		
			clazz = o.getClass();
		}
	
		Class<?>[] argTypes = new Class<?>[2];
		argTypes[0] = arg1.getClass();
		argTypes[1] = arg2.getClass();
		
		Object[] args = new Object[2];
		args[0] = getArg(argTypes[0],arg1);
		args[1] = getArg(argTypes[1],arg2);
				
		Method m = DispDriver.getMethod(clazz, methodName, args, argTypes);
		if ( m != null ) {
			SwingUtilities.invokeLater(new Invocation(m,o,args));
		}
	}	
	
	
	public static void invoke( Object o, String methodName, Object arg1, Object arg2, Object arg3 ) throws SecurityException, NoSuchMethodException, IllegalArgumentException, IllegalAccessException, InvocationTargetException {
		
		Class<?> clazz = null;
		
		if ( o instanceof Class<?> ) {
			clazz = (Class<?>)o;
		} else {		
			clazz = o.getClass();
		}
	
		Class<?>[] argTypes = new Class<?>[3];
		argTypes[0] = arg1.getClass();
		argTypes[1] = arg2.getClass();
		argTypes[2] = arg3.getClass();
		
		Object[] args = new Object[3];
		args[0] = getArg(argTypes[0],arg1);
		args[1] = getArg(argTypes[1],arg2);
		args[2] = getArg(argTypes[2],arg3);
				
		Method m = DispDriver.getMethod(clazz, methodName, args, argTypes);
		if ( m != null ) {
			SwingUtilities.invokeLater(new Invocation(m,o,args));
		}
	}	
	
	public static void exit(int i) {
		
		Method m = null;
		try {
			m = java.lang.System.class.getMethod("exit", int.class);
		} catch (SecurityException e) {
			e.printStackTrace();
			return;
		} catch (NoSuchMethodException e) {
			e.printStackTrace();
			return;
		}
		if ( m == null ) {
			return;
		}
		
		Object[] args = new Object[1];
		args[0] = i;
		SwingUtilities.invokeLater(new Invocation(m,null,args));		
	}
	
	public static Object Component(Object comp,String name) {
				
		ComponentLookup cl = new ComponentLookup(comp, name);
		try {
			SwingUtilities.invokeAndWait(cl);
			return cl.unwrap();
		} catch (InterruptedException e) {
			e.printStackTrace();
		} catch (InvocationTargetException e) {
			e.printStackTrace();
		}
		
		return null;
	}
	
	public static void run(final IDispatch disp) {
	
		Runnable doRun = new Runnable() {
			
			@Override
			public void run() {
				disp.invoke();
			}
		};
		
		try {
			SwingUtilities.invokeAndWait(doRun);
		} catch (InterruptedException e) {
			e.printStackTrace();
		} catch (InvocationTargetException e) {
			e.printStackTrace();
		}
	}	
	
	
}
