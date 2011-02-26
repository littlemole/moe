
package org.oha7.mol.comtypes;

import org.oha7.dispdriver.annotations.ProgId;
import org.oha7.dispdriver.annotations.Dispid;
import org.oha7.dispdriver.interfaces.IUnknown;

import org.oha7.dispdriver.interfaces.IDispatch;

@ProgId("TypeToXml.TypeLibToXml")
public interface ITypeLibToXml extends IUnknown {

    @Dispid(2)
	String getXML();

    @Dispid(5)
	IDispatch getonComplete();

    @Dispid(6)
	IDispatch getonStatus();

    @Dispid(7)
	boolean getError();

    @Dispid(8)
	String getResult();

    @Dispid(5)
	void setonComplete(IDispatch onCompleteHandler);

    @Dispid(6)
	void setonStatus(IDispatch onStatusHandler);

    @Dispid(1)
    boolean Load( String filename);

    @Dispid(3)
    String Transform( Object xsltDoc);

    @Dispid(4)
    void AsyncDocumentation( String filename, String filter, Object xsltDoc);


}
