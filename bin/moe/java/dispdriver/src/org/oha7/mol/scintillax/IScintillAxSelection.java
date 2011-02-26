
package org.oha7.mol.scintillax;

import org.oha7.dispdriver.annotations.Dispid;
import org.oha7.dispdriver.interfaces.IUnknown;


public interface IScintillAxSelection extends IUnknown {

    @Dispid(1)
	int getStart();

    @Dispid(2)
	int getEnd();

    @Dispid(3)
	String getText();

    @Dispid(1)
	void setStart(int p);

    @Dispid(2)
	void setEnd(int p);

    @Dispid(3)
	void setText(String txt);

    @Dispid(4)
    void GetSelection( int pFirst, int pLast);

    @Dispid(5)
    void SetSelection( int pFirst, int pLast);

    @Dispid(6)
    void Cut( );

    @Dispid(7)
    void Copy( );

    @Dispid(8)
    void Paste( );


}
