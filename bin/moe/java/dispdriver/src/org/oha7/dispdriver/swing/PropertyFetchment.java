package org.oha7.dispdriver.swing;

import java.lang.reflect.Field;

public class PropertyFetchment implements Runnable {

	private Field field = null;
	private Object obj = null;
	private Object result = null;
	
	public PropertyFetchment(Field f, Object o) {
	  this.field = f;
	  this.obj = o;
	}
		
	public Object unwrap() {
		return result;
	}	
	
	@Override
	public void run() {
		try {
			result = field.get(obj);
		} catch (IllegalArgumentException e) {
			e.printStackTrace();
		} catch (IllegalAccessException e) {
			e.printStackTrace();
		} 
	}

}
