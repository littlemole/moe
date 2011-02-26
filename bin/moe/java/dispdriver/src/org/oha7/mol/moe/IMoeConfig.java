
package org.oha7.mol.moe;

import org.oha7.dispdriver.annotations.Dispid;
import org.oha7.dispdriver.interfaces.IUnknown;


public interface IMoeConfig extends IUnknown {

    @Dispid(1)
	String getConfigPath();

    @Dispid(2)
	String getModulePath();

    @Dispid(3)
	int getSysType();

    @Dispid(4)
	int getEncoding();

    @Dispid(5)
	boolean getTabUsage();

    @Dispid(6)
	boolean getTabIndents();

    @Dispid(7)
	boolean getBackSpaceUnindents();

    @Dispid(8)
	int getTabWidth();

    @Dispid(9)
	boolean getShowLineNumbers();

    @Dispid(3)
	void setSysType(int typ);

    @Dispid(4)
	void setEncoding(int typ);

    @Dispid(5)
	void setTabUsage(boolean vbTabUsage);

    @Dispid(6)
	void setTabIndents(boolean vbTabIndents);

    @Dispid(7)
	void setBackSpaceUnindents(boolean vbBackSpaceIndents);

    @Dispid(8)
	void setTabWidth(int w);

    @Dispid(9)
	void setShowLineNumbers(boolean vb);

    @Dispid(10)
    void EditPreferences( );

    @Dispid(11)
    void EditSettings( );

    @Dispid(12)
    void ExportSettings( String f);

    @Dispid(13)
    void ImportSettings( String f);

    @Dispid(14)
    void InitializeEditorFromPreferences( IMoeDocument d);


}
