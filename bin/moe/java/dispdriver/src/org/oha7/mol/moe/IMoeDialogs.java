
package org.oha7.mol.moe;

import org.oha7.dispdriver.annotations.Dispid;
import org.oha7.dispdriver.interfaces.IUnknown;

import org.oha7.mol.moe.IMoeDocument;

public interface IMoeDialogs extends IUnknown {

    @Dispid(1)
    int MsgBox( String Text, String Title, int Flags);

    @Dispid(2)
    IMoeDocument Open( );

    @Dispid(4)
    IMoeDocument OpenDir( );

    @Dispid(5)
    String ChooseFile( );

    @Dispid(6)
    String ChooseDir( );

    @Dispid(7)
    void Help( );

    @Dispid(8)
    void Print( );


}
