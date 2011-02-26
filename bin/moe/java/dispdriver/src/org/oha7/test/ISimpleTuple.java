package org.oha7.test;

import org.oha7.dispdriver.annotations.Dispid;
import org.oha7.dispdriver.annotations.ProgId;
import org.oha7.dispdriver.interfaces.IUnknown;

@ProgId("SimpleAx.SimpleTuple")
public interface ISimpleTuple extends IUnknown {

	@Dispid(1)
	void setKey( String value);
	@Dispid(1)
	String getKey();
	
	@Dispid(2)
	void setValue( String value);	
	@Dispid(2)
	String getValue();	
	
}