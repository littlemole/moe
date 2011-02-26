
package org.oha7.mol.shellfolder;

import org.oha7.dispdriver.annotations.Dispid;
import org.oha7.dispdriver.interfaces.IUnknown;


public interface IShellPaneEvents extends IUnknown {

    @Dispid(1)
    void OnListSelection( String fname);

    @Dispid(2)
    void OnListDblClick( String fname);

    @Dispid(3)
    void OnListOpen( String fname);

    @Dispid(4)
    void OnDirChanged( String dir);


}
