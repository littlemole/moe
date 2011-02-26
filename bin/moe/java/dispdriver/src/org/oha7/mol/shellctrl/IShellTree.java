
package org.oha7.mol.shellctrl;

import org.oha7.dispdriver.annotations.ProgId;
import org.oha7.dispdriver.annotations.Dispid;
import org.oha7.dispdriver.interfaces.IUnknown;


@ProgId("ShellCtrls.ShellTree")
public interface IShellTree extends IUnknown {

    @Dispid(1)
	boolean getDisplayFiles();

    @Dispid(2)
	String getSelection();

    @Dispid(3)
	boolean getHasFocus();

    @Dispid(15)
	boolean getUseContext();

    @Dispid(1)
	void setDisplayFiles(boolean vb);

    @Dispid(2)
	void setSelection(String fname);

    @Dispid(15)
	void setUseContext(boolean vb);

    @Dispid(4)
    void Update( );

    @Dispid(5)
    void Cut( );

    @Dispid(6)
    void Copy( );

    @Dispid(7)
    void Paste( );

    @Dispid(8)
    void Rename( );

    @Dispid(9)
    void Delete( );

    @Dispid(10)
    void Properties( );

    @Dispid(11)
    void Execute( );

    @Dispid(12)
    void AddFolder( String dname);

    @Dispid(13)
    void RemoveFolder( String dname);

    @Dispid(14)
    void CreateDir( );


}
