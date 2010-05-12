package mol.wsh  ;

import com4j.*;

@IID("{C7C3F5A0-88A3-11D0-ABCB-00A0C90FFFC0}")
public interface IDrive extends Com4jObject {
    @VTID(7)
    @DefaultMethod
    java.lang.String path();

    @VTID(8)
    java.lang.String driveLetter();

    @VTID(9)
    java.lang.String shareName();

    @VTID(10)
    mol.wsh.DriveTypeConst driveType();

    @VTID(11)
    mol.wsh.IFolder rootFolder();

    @VTID(12)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object availableSpace();

    @VTID(13)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object freeSpace();

    @VTID(14)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object totalSize();

    @VTID(15)
    java.lang.String volumeName();

    @VTID(16)
    void volumeName(
        java.lang.String pbstrName);

    @VTID(17)
    java.lang.String fileSystem();

    @VTID(18)
    int serialNumber();

    @VTID(19)
    boolean isReady();

}
