
package org.oha7.mol.scintillax;

import org.oha7.dispdriver.annotations.Dispid;
import org.oha7.dispdriver.interfaces.IUnknown;


public interface IScintillAxLine extends IUnknown {

    @Dispid(0)
	int getCurrent();

    @Dispid(1)
	int getCount();

    @Dispid(2)
    int LineFromPos( int p);

    @Dispid(3)
    int PosFromLine( int l);

    @Dispid(4)
    int LineEndPos( int l);

    @Dispid(5)
    int FirstVisibleLine( );

    @Dispid(6)
    int LinesOnScreen( );

    @Dispid(7)
    int LineLength( int l);

    @Dispid(8)
    String LineText( int l);

    @Dispid(9)
    void SetLineText( int l, String txt);

    @Dispid(10)
    void Goto( int l);

    @Dispid(11)
    void Highlite( int line);


}
