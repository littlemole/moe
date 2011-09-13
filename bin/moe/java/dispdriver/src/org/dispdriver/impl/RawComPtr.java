package org.oha7.dispdriver.impl;

/**
 * Holder Class to wrap a raw c++ interface pointer
 * @author mike
 *
 */
public class RawComPtr {

	private final long ptr;
	
	public RawComPtr ( long p ) {
		this.ptr = p;		
	}
	
	public Long value() {
		return ptr;
	}
	
	public long longValue() {
		return ptr;
	}	
}
