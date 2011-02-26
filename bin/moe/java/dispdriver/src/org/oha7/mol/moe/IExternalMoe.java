
package org.oha7.mol.moe;

import org.oha7.dispdriver.annotations.Dispid;
import org.oha7.dispdriver.interfaces.IUnknown;

import org.oha7.mol.moe.IMoe;
import org.oha7.mol.moe.IMoeHtmlFrame;

public interface IExternalMoe extends IUnknown {

    @Dispid(0)
	IMoe getMoe();

    @Dispid(1)
	IMoeHtmlFrame getFrame();

    @Dispid(2)
    void Close( );


}
