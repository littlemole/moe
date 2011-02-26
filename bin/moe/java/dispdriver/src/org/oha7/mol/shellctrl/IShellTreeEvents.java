
package org.oha7.mol.shellctrl;

import org.oha7.dispdriver.annotations.Dispid;
import org.oha7.dispdriver.interfaces.IUnknown;


public interface IShellTreeEvents extends IUnknown {

    @Dispid(1)
    void OnTreeSelection( String fname);

    @Dispid(2)
    void OnTreeDblClick( String fname);

    @Dispid(3)
    void OnTreeOpen( String fname);

    @Dispid(4)
    void OnContextMenu( String fname);


}
