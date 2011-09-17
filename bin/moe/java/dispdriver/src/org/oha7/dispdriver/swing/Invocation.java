package org.oha7.dispdriver.swing;

import java.lang.reflect.InvocationTargetException;
import java.lang.reflect.Method;

public class Invocation implements Runnable {

	private Method method = null;
	private Object obj = null;
	private Object[] args = null;
	private Object result = null;
	
	public Invocation(Method m, Object o, Object ... args ) {
	  this.method = m;
	  this.obj = o;
	  this.args = args;
	}
		
	public Object unwrap() {
		return result;
	}
	
	@Override
	public void run() {
		try {
			result = method.invoke(obj,args);
		} catch (IllegalArgumentException e) {
			e.printStackTrace();
		} catch (IllegalAccessException e) {
			e.printStackTrace();
		} catch (InvocationTargetException e) {
			e.printStackTrace();
		}
	}
	
}