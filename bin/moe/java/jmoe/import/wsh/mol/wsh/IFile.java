package mol.wsh  ;

import com4j.*;

@IID("{C7C3F5A4-88A3-11D0-ABCB-00A0C90FFFC0}")
public interface IFile extends Com4jObject {
    @VTID(7)
    @DefaultMethod
    java.lang.String path();

    @VTID(8)
    java.lang.String name();

    @VTID(9)
    void name(
        java.lang.String pbstrName);

    @VTID(10)
    java.lang.String shortPath();

    @VTID(11)
    java.lang.String shortName();

    @VTID(12)
    mol.wsh.IDrive drive();

    @VTID(13)
    mol.wsh.IFolder parentFolder();

    @VTID(14)
    mol.wsh.FileAttribute attributes();

    @VTID(15)
    void attributes(
        mol.wsh.FileAttribute pfa);

    @VTID(16)
    java.util.Date dateCreated();

    @VTID(17)
    java.util.Date dateLastModified();

    @VTID(18)
    java.util.Date dateLastAccessed();

    @VTID(19)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object size();

    @VTID(20)
    java.lang.String type();

    @VTID(21)
    void delete(
        boolean force);

    @VTID(22)
    void copy(
        java.lang.String destination,
        boolean overWriteFiles);

    @VTID(23)
    void move(
        java.lang.String destination);

    @VTID(24)
    mol.wsh.ITextStream openAsTextStream(
        mol.wsh.IOMode ioMode,
        mol.wsh.Tristate format);

}
