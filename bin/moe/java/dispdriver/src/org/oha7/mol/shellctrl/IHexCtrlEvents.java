
package org.oha7.mol.shellctrl;

import org.oha7.dispdriver.annotations.Dispid;
import org.oha7.dispdriver.interfaces.IUnknown;


public interface IHexCtrlEvents extends IUnknown {

    @Dispid(1)
    void OnNewFile( String fname, boolean vbReadOnly);

    @Dispid(2)
    void OnNewOffset( String address, String Value);

    @Dispid(3)
    void OnNewValue( String address, String Value);


}
