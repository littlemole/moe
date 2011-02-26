
package org.oha7.mol.scintillax;

import org.oha7.dispdriver.annotations.Dispid;
import org.oha7.dispdriver.interfaces.IUnknown;

import org.oha7.dispdriver.interfaces.IFontDisp;

public interface IScintillAxProperties extends IUnknown {

    @Dispid(-512)
	IFontDisp getFont();

    @Dispid(1)
	String getFilename();

    @Dispid(2)
	boolean getReadOnly();

    @Dispid(3)
	int getSyntax();

    @Dispid(4)
	int getSysType();

    @Dispid(5)
	int getEncoding();

    @Dispid(6)
	boolean getTabUsage();

    @Dispid(7)
	boolean getTabIndents();

    @Dispid(8)
	boolean getBackSpaceUnindents();

    @Dispid(9)
	int getTabWidth();

    @Dispid(10)
	boolean getOvertype();

    @Dispid(11)
	boolean getUseContext();

    @Dispid(12)
	boolean getWriteBOM();

    @Dispid(13)
	boolean getShowLineNumbers();

    @Dispid(-512)
	void setFont(IFontDisp fnt);

    @Dispid(1)
	void setFilename(String fname);

    @Dispid(2)
	void setReadOnly(boolean vbReadOnly);

    @Dispid(3)
	void setSyntax(int typ);

    @Dispid(4)
	void setSysType(int typ);

    @Dispid(5)
	void setEncoding(int typ);

    @Dispid(6)
	void setTabUsage(boolean vbTabUsage);

    @Dispid(7)
	void setTabIndents(boolean vbTabIndents);

    @Dispid(8)
	void setBackSpaceUnindents(boolean vbBackSpaceIndents);

    @Dispid(9)
	void setTabWidth(int w);

    @Dispid(10)
	void setOvertype(boolean over_type);

    @Dispid(11)
	void setUseContext(boolean useMenu);

    @Dispid(12)
	void setWriteBOM(boolean vb);

    @Dispid(13)
	void setShowLineNumbers(boolean useLineNums);

    @Dispid(14)
    String SyntaxDisplayName( );

    @Dispid(15)
    String GetSyntaxDisplayName( int type);

    @Dispid(16)
    void SetIndent( int i);

    @Dispid(17)
    void ConvertTabs( );


}
