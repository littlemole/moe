
package org.oha7.mol.io;

import org.oha7.dispdriver.annotations.ProgId;
import org.oha7.dispdriver.annotations.Dispid;
import org.oha7.dispdriver.interfaces.IUnknown;

import org.oha7.dispdriver.interfaces.IEnumVARIANT;

@ProgId("IO.Dir")
public interface IDir extends IUnknown {

    @Dispid(-4)
    IEnumVARIANT _NewEnum( );

    @Dispid(0)
    String Item( int i);

    @Dispid(1)
    int Count( );


}
