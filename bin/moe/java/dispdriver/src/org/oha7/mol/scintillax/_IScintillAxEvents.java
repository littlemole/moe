
package org.oha7.mol.scintillax;

import org.oha7.dispdriver.annotations.Dispid;
import org.oha7.dispdriver.interfaces.IUnknown;


public interface _IScintillAxEvents extends IUnknown {

    @Dispid(1)
    void OnFileNameChanged( String fname, String fPath);

    @Dispid(2)
    void OnShowMenu( boolean vbShowMenue);

    @Dispid(3)
    void OnPosChange( int iLine);

    @Dispid(4)
    void OnChar( String ch);

    @Dispid(5)
    void OnMarker( int iLine);

    @Dispid(6)
    void OnSyntax( int s);

    @Dispid(7)
    void OnSystem( int s);

    @Dispid(8)
    void OnEncoding( int e);


}
