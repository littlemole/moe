package mol.wsh  ;

import com4j.*;

@IID("{0AB5A3D0-E5B6-11D0-ABF5-00A0C90FFFC0}")
public interface IFileSystem extends Com4jObject {
    @VTID(7)
    mol.wsh.IDriveCollection drives();

    @VTID(7)
    @ReturnValue(defaultPropertyThrough={mol.wsh.IDriveCollection.class})
    mol.wsh.IDrive drives(
        @MarshalAs(NativeType.VARIANT) java.lang.Object key);

    @VTID(8)
    java.lang.String buildPath(
        java.lang.String path,
        java.lang.String name);

    @VTID(9)
    java.lang.String getDriveName(
        java.lang.String path);

    @VTID(10)
    java.lang.String getParentFolderName(
        java.lang.String path);

    @VTID(11)
    java.lang.String getFileName(
        java.lang.String path);

    @VTID(12)
    java.lang.String getBaseName(
        java.lang.String path);

    @VTID(13)
    java.lang.String getExtensionName(
        java.lang.String path);

    @VTID(14)
    java.lang.String getAbsolutePathName(
        java.lang.String path);

    @VTID(15)
    java.lang.String getTempName();

    @VTID(16)
    boolean driveExists(
        java.lang.String driveSpec);

    @VTID(17)
    boolean fileExists(
        java.lang.String fileSpec);

    @VTID(18)
    boolean folderExists(
        java.lang.String folderSpec);

    @VTID(19)
    mol.wsh.IDrive getDrive(
        java.lang.String driveSpec);

    @VTID(20)
    mol.wsh.IFile getFile(
        java.lang.String filePath);

    @VTID(21)
    mol.wsh.IFolder getFolder(
        java.lang.String folderPath);

    @VTID(22)
    mol.wsh.IFolder getSpecialFolder(
        mol.wsh.SpecialFolderConst specialFolder);

    @VTID(23)
    void deleteFile(
        java.lang.String fileSpec,
        boolean force);

    @VTID(24)
    void deleteFolder(
        java.lang.String folderSpec,
        boolean force);

    @VTID(25)
    void moveFile(
        java.lang.String source,
        java.lang.String destination);

    @VTID(26)
    void moveFolder(
        java.lang.String source,
        java.lang.String destination);

    @VTID(27)
    void copyFile(
        java.lang.String source,
        java.lang.String destination,
        boolean overWriteFiles);

    @VTID(28)
    void copyFolder(
        java.lang.String source,
        java.lang.String destination,
        boolean overWriteFiles);

    @VTID(29)
    mol.wsh.IFolder createFolder(
        java.lang.String path);

    @VTID(30)
    mol.wsh.ITextStream createTextFile(
        java.lang.String fileName,
        boolean overwrite,
        boolean unicode);

    @VTID(31)
    mol.wsh.ITextStream openTextFile(
        java.lang.String fileName,
        mol.wsh.IOMode ioMode,
        boolean create,
        mol.wsh.Tristate format);

}
