package mol.io  ;

import com4j.*;

/**
 * IPath - interface to Path Information functions
 */
@IID("{FFEB4898-0ECC-465A-851E-F5F7BB4136A8}")
public interface IPath extends Com4jObject {
    /**
     * returns file Extension
     */
    @VTID(7)
    java.lang.String extension(
        java.lang.String f);

    /**
     * returns Filename w/o path
     */
    @VTID(8)
    java.lang.String filename(
        java.lang.String f);

    /**
     * returns Path w/o filename
     */
    @VTID(9)
    java.lang.String path(
        java.lang.String f);

    /**
     * strips Root directory
     */
    @VTID(10)
    java.lang.String stripRoot(
        java.lang.String f);

    /**
     * returns Root directory
     */
    @VTID(11)
    java.lang.String root(
        java.lang.String f);

    /**
     * Adds BackSlash, if not yet present
     */
    @VTID(12)
    java.lang.String addBackSlash(
        java.lang.String f);

    /**
     * Removes BackSlash, if any
     */
    @VTID(13)
    java.lang.String removeBackSlash(
        java.lang.String f);

    /**
     * Adds an Extension
     */
    @VTID(14)
    java.lang.String addExtension(
        java.lang.String f,
        java.lang.String e);

    /**
     * returns true if p1 is a subpath of p2 
     */
    @VTID(15)
    boolean isSubPath(
        java.lang.String p1,
        java.lang.String p2);

    /**
     * returns true if given path exists
     */
    @VTID(16)
    boolean exists(
        java.lang.String f);

    /**
     * return true if given path is a directory
     */
    @VTID(17)
    boolean isDir(
        java.lang.String f);

    /**
     * returns true if given path is a root directory
     */
    @VTID(18)
    boolean isRoot(
        java.lang.String f);

    /**
     * returns true if given path is a UNC path
     */
    @VTID(19)
    boolean isUNC(
        java.lang.String f);

    /**
     * returns true if given path is a mapped Net Drive
     */
    @VTID(20)
    boolean isNetDrive(
        java.lang.String f);

    /**
     * returns Parent Directory of a directory path, otherwise behaves like pathname
     */
    @VTID(21)
    java.lang.String parentDir(
        java.lang.String f);

    /**
     * Open a Directory path for enumeration
     */
    @VTID(22)
    mol.io.IDir openDir(
        java.lang.String f);

    /**
     * Open path as File, returning file object
     */
    @VTID(23)
    mol.io.IFile openFile(
        java.lang.String f);

    /**
     * Choose Directory - displays DirectoryBrowser to choose a Directory, returns path
     */
    @VTID(24)
    java.lang.String chooseDir();

    /**
     * Choose File to open - displays Filebrowser to open a file, returns path to file
     */
    @VTID(25)
    java.lang.String fileOpenDlg();

    /**
     * Choose File to save - displays the FileSave dialog, returns filename
     */
    @VTID(26)
    java.lang.String fileSaveDlg();

}
