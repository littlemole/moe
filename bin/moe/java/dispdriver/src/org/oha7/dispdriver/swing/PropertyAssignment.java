package org.oha7.dispdriver.swing;

import java.lang.reflect.Field;

public class PropertyAssignment implements Runnable {

	private Field field = null;
	private Object obj = null;
	private Object value = null;
	
	public PropertyAssignment(Field f, Object o, Object v) {
	  this.field = f;
	  this.obj = o;
	  this.value = v;
	}
			
	@Override
	public void run() {
		try {
			field.set(obj,value);
		} catch (IllegalArgumentException e) {
			e.printStackTrace();
		} catch (IllegalAccessException e) {
			e.printStackTrace();
		} 
	}

}
