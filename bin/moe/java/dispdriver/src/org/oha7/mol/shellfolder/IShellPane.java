
package org.oha7.mol.shellfolder;

import org.oha7.dispdriver.annotations.ProgId;
import org.oha7.dispdriver.annotations.Dispid;
import org.oha7.dispdriver.interfaces.IUnknown;


@ProgId("ShellFolder.ShellPane")
public interface IShellPane extends IUnknown {

    @Dispid(1)
	boolean getDisplayFiles();

    @Dispid(2)
	Object getSelection();

    @Dispid(3)
	boolean getHasFocus();

    @Dispid(1)
	void setDisplayFiles(boolean vb);

    @Dispid(2)
	void setSelection(Object fname);

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
    void CreateDir( );

    @Dispid(13)
    void UpDir( );


}
