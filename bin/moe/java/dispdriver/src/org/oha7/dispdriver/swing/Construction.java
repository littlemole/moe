package org.oha7.dispdriver.swing;

import java.lang.reflect.Constructor;
import java.lang.reflect.InvocationTargetException;

public class Construction implements Runnable {

	@SuppressWarnings("rawtypes")
	private Constructor constructor = null;
	private Object obj = null;
	private Object[] args = null;
	
	
	@SuppressWarnings("rawtypes")
	public Construction(Constructor c, Object ... args ) {
	  this.constructor = c;
	  this.args = args;
	}
	
	public Object unwrap() {
		return obj;
	}
	
	@Override
	public void run() {
			try {
				this.obj = constructor.newInstance(args);
			} catch (IllegalArgumentException e) {
				e.printStackTrace();
			} catch (InstantiationException e) {
				e.printStackTrace();
			} catch (IllegalAccessException e) {
				e.printStackTrace();
			} catch (InvocationTargetException e) {
				e.printStackTrace();
			}
	}
}
