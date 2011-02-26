
package org.oha7.mol.io;

import org.oha7.dispdriver.annotations.ProgId;
import org.oha7.dispdriver.annotations.Dispid;
import org.oha7.dispdriver.interfaces.IUnknown;

import org.oha7.mol.io.IDir;
import org.oha7.mol.io.IFile;

@ProgId("IO.Path")
public interface IPath extends IUnknown {

    @Dispid(1)
    String Extension( String f);

    @Dispid(2)
    String Filename( String f);

    @Dispid(3)
    String Path( String f);

    @Dispid(4)
    String StripRoot( String f);

    @Dispid(5)
    String Root( String f);

    @Dispid(6)
    String AddBackSlash( String f);

    @Dispid(7)
    String RemoveBackSlash( String f);

    @Dispid(8)
    String AddExtension( String f, String e);

    @Dispid(9)
    boolean IsSubPath( String p1, String p2);

    @Dispid(10)
    boolean Exists( String f);

    @Dispid(11)
    boolean IsDir( String f);

    @Dispid(12)
    boolean IsRoot( String f);

    @Dispid(13)
    boolean IsUNC( String f);

    @Dispid(14)
    boolean IsNetDrive( String f);

    @Dispid(15)
    String ParentDir( String f);

    @Dispid(16)
    IDir OpenDir( String f);

    @Dispid(17)
    IFile OpenFile( String f);

    @Dispid(18)
    String ChooseDir( );

    @Dispid(19)
    String FileOpenDlg( );

    @Dispid(20)
    String FileSaveDlg( );


}
