package org.oha7.dispdriver.swing;

import java.awt.Component;
import java.lang.reflect.InvocationTargetException;
import java.lang.reflect.Method;

import javax.swing.SwingUtilities;

import org.oha7.dispdriver.impl.ComProxy;
import org.oha7.dispdriver.impl.DispDriver;
import org.oha7.dispdriver.impl.RawComPtr;

public class Util {
	
	private static class Invoker implements Runnable {

		private Method method = null;
		private Object obj = null;
		private Object[] args = null;
		
		public Invoker(Method m, Object o, Object ... args ) {
		  this.method = m;
		  this.obj = o;
		  this.args = args;
		}
		
		@Override
		public void run() {
			try {
				method.invoke(obj,args);
			} catch (IllegalArgumentException e) {
				e.printStackTrace();
			} catch (IllegalAccessException e) {
				e.printStackTrace();
			} catch (InvocationTargetException e) {
				e.printStackTrace();
			}
		}
		
	}

	public static void dispose( Object o ) throws SecurityException, NoSuchMethodException, IllegalArgumentException, IllegalAccessException, InvocationTargetException {
		
		Class<?> clazz = o.getClass();
		Method m = clazz.getMethod( "dispose" );
		
		if ( m != null ) {
			SwingUtilities.invokeLater(new Invoker(m,o));
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
			SwingUtilities.invokeLater(new Invoker(m,o,args));
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
			SwingUtilities.invokeLater(new Invoker(m,o,args));
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
			SwingUtilities.invokeLater(new Invoker(m,o,args));
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
			SwingUtilities.invokeLater(new Invoker(m,o,args));
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
		SwingUtilities.invokeLater(new Invoker(m,null,args));		
	}
	
	public static Component Component(Object comp,String name) {
		
		if ( comp instanceof java.awt.Container ) {
			java.awt.Container container = (java.awt.Container)comp;
			Component[] components = container.getComponents();
			for ( int i = 0; i < components.length; i++) {
				if ( components[i].getName() != null && components[i].getName().equals(name)) {
					return components[i];
				}
				Component c = Component(components[i],name);
				if ( c != null ) {
					return c;
				}
			}
		}
		return null;
	}
}
