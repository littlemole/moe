package org.oha7.dispdriver.swing;

import java.awt.Component;


public class ComponentLookup implements Runnable {

	private Object comp = null;
	private String name = null;
	private Object result = null;
	
	public ComponentLookup(Object c, String n ) {
	  this.comp = c;
	  this.name = n;
	}
		
	public Object unwrap() {
		return result;
	}
	
	@Override
	public void run() {

		result = lookup(comp,name);
	}
	
	private Component lookup( Object o, String name ) {
		
		if ( (o instanceof java.awt.Container) == false ) {
			return null;
		}
		
		java.awt.Container container = (java.awt.Container)o;
		Component[] components = container.getComponents();
		for ( int i = 0; i < components.length; i++) {
			if ( components[i].getName() != null && components[i].getName().equals(name)) {
				return components[i];
			}
			Component c = lookup(components[i],name);
			if ( c != null ) {
				return c;
			}
		}
		return null;
	}
}
