
package org.oha7.mol.moe;

import org.oha7.dispdriver.annotations.Dispid;
import org.oha7.dispdriver.interfaces.IUnknown;

import org.oha7.dispdriver.interfaces.IDispatch;
import org.oha7.mol.moe.IMoeDocumentView;

public interface IMoeDocument extends IUnknown {

    @Dispid(0)
	IDispatch getObject();

    @Dispid(1)
	IMoeDocumentView getView();

    @Dispid(2)
	String getFilePath();

    @Dispid(3)
	int getType();

    @Dispid(4)
    void Save( );

    @Dispid(5)
    void SaveAs( String f);


}
