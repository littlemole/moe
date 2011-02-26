
package org.oha7.mol.scintillax;

import org.oha7.dispdriver.annotations.Dispid;
import org.oha7.dispdriver.interfaces.IUnknown;


public interface IScintillAxPosition extends IUnknown {

    @Dispid(0)
	int getCaret();

    @Dispid(1)
	int getSearchPos();

    @Dispid(2)
	int getAnchor();

    @Dispid(0)
	void setCaret(int p);

    @Dispid(1)
	void setSearchPos(int p);

    @Dispid(2)
	void setAnchor(int p);

    @Dispid(3)
    String CharAt( int p);

    @Dispid(4)
    void Scroll( int cCols, int cLines);

    @Dispid(5)
    void ScrollIntoView( );


}
