
package org.oha7.mol.shellctrl;

import org.oha7.dispdriver.annotations.ProgId;
import org.oha7.dispdriver.annotations.Dispid;
import org.oha7.dispdriver.interfaces.IUnknown;


@ProgId("ShellCtrls.HexCtrl")
public interface IHexCtrl extends IUnknown {

    @Dispid(1)
	boolean getReadOnly();

    @Dispid(2)
	int getDisplayColumns();

    @Dispid(3)
	String getFilename();

    @Dispid(4)
	boolean getHasFocus();

    @Dispid(5)
	boolean getShowToolbar();

    @Dispid(6)
	int getScrollPos();

    @Dispid(7)
	int getScrollMax();

    @Dispid(8)
	int getOffset();

    @Dispid(9)
	int getFileSize();

    @Dispid(10)
	int getSearchPos();

    @Dispid(1)
	void setReadOnly(boolean vb);

    @Dispid(2)
	void setDisplayColumns(int cols);

    @Dispid(3)
	void setFilename(String fname);

    @Dispid(5)
	void setShowToolbar(boolean vb);

    @Dispid(6)
	void setScrollPos(int pos);

    @Dispid(8)
	void setOffset(int off);

    @Dispid(10)
	void setSearchPos(int pos);

    @Dispid(11)
    boolean Open( String file);

    @Dispid(12)
    boolean OpenReadOnly( String file);

    @Dispid(13)
    void SetOffsetDWORD( int Offset, String val);

    @Dispid(14)
    void SetOffsetByte( int Offset, String val);

    @Dispid(15)
    void SetOffsetChar( int Offset, int val);

    @Dispid(16)
    void Search( String what, int flags);

    @Dispid(17)
    String Value( int off);


}
