package org.oha7.dispdriver.interfaces;

import org.oha7.dispdriver.annotations.Dispid;

public interface IDispatch extends IUnknown {
	
	@Dispid(0)
	<T> void invoke( T ... args);
	
}
