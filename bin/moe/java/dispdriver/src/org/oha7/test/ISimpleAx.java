package org.oha7.test;

import org.oha7.dispdriver.annotations.Dispid;
import org.oha7.dispdriver.annotations.ProgId;
import org.oha7.dispdriver.interfaces.IUnknown;

@ProgId("SimpleAx.SimpleAx")
public interface ISimpleAx extends IUnknown {

	@Dispid(1)
	String getTitle();
	
	@Dispid(1)
	void setTitle(String s);
	
	@Dispid(2) 
	void Msg( String text);

	@Dispid(3) 
	void MsgInt( String text, int value );

	@Dispid(4)
	boolean Confirm( String text );
	
	@Dispid(5)
	ISimpleTuple getTuple();
	@Dispid(5)
	void setTuple(ISimpleTuple tuple);
	
}
