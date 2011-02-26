
package org.oha7.mol.io;

import org.oha7.dispdriver.annotations.ProgId;
import org.oha7.dispdriver.annotations.Dispid;
import org.oha7.dispdriver.interfaces.IUnknown;


@ProgId("IO.file")
public interface IFile extends IUnknown {

    @Dispid(1)
	String getFilename();

    @Dispid(2)
	int getEoL();

    @Dispid(3)
	int getEncoding();

    @Dispid(4)
	boolean getUseBOM();

    @Dispid(5)
	boolean getEoF();

    @Dispid(6)
	int getSize();

    @Dispid(2)
	void setEoL(int t);

    @Dispid(3)
	void setEncoding(int cp);

    @Dispid(4)
	void setUseBOM(boolean vb);

    @Dispid(7)
    boolean Open( String file);

    @Dispid(8)
    boolean OpenReadOnly( String file);

    @Dispid(9)
    boolean OpenAppend( String file);

    @Dispid(10)
    void Close( );

    @Dispid(11)
    String Read( int cnt);

    @Dispid(12)
    String ReadText( );

    @Dispid(13)
    void Seek( int pos);

    @Dispid(14)
    int Write( String file, int len);

    @Dispid(15)
    int WriteText( String txt);

    @Dispid(16)
    boolean Create( String txt);


}
