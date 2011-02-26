
package org.oha7.mol.scintillax;

import org.oha7.dispdriver.annotations.Dispid;
import org.oha7.dispdriver.interfaces.IUnknown;


public interface IScintillAxText extends IUnknown {

    @Dispid(0)
	String getValue();

    @Dispid(1)
	boolean getModified();

    @Dispid(2)
	int getLength();

    @Dispid(0)
	void setValue(String txt);

    @Dispid(3)
    void SetText( String txt);

    @Dispid(4)
    String GetText( );

    @Dispid(5)
    String GetTextRange( int pStart, int pEnd);

    @Dispid(6)
    void Append( String txt);

    @Dispid(7)
    void Insert( String txt, int p);

    @Dispid(8)
    boolean Search( String sWhat, int lFlags);

    @Dispid(9)
    boolean Replace( String sWhat, String w, int lFlags);


}
