
package org.oha7.mol.moe;

import org.oha7.dispdriver.annotations.Dispid;
import org.oha7.dispdriver.interfaces.IUnknown;

import org.oha7.dispdriver.interfaces.IDispatch;
import org.oha7.mol.moe.IMoeDialogView;

public interface IMoeHtmlFrame extends IUnknown {

    @Dispid(0)
	IDispatch getObject();

    @Dispid(1)
	IMoeDialogView getView();

    @Dispid(2)
	IDispatch getScripts();

    @Dispid(5)
	String getFilePath();

    @Dispid(3)
    void Eval( String src, String scriptLanguage);

    @Dispid(4)
    void OleCmd( int cmd);


}
