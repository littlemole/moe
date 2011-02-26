
package org.oha7.mol.moe;

import org.oha7.dispdriver.annotations.Dispid;
import org.oha7.dispdriver.interfaces.IUnknown;

import org.oha7.dispdriver.interfaces.IDispatch;
import org.oha7.mol.moe.IMoeDialogView;

public interface IMoeUserForm extends IUnknown {

    @Dispid(0)
	IDispatch getObject();

    @Dispid(1)
	IMoeDialogView getView();

    @Dispid(2)
	IDispatch getScript();

    @Dispid(6)
	String getFilePath();

    @Dispid(3)
    void Show( );

    @Dispid(4)
    void Close( );

    @Dispid(5)
    void Hide( );


}
