package mol.wsh  ;

import com4j.*;

/**
 * Network Object
 */
@IID("{F935DC25-1CF0-11D0-ADB9-00C04FD58A0B}")
public interface IWshNetwork extends Com4jObject {
    @VTID(7)
    java.lang.String userDomain();

    @VTID(8)
    java.lang.String userName();

    @VTID(9)
    java.lang.String userProfile();

    @VTID(10)
    java.lang.String computerName();

    @VTID(11)
    java.lang.String organization();

    @VTID(12)
    java.lang.String site();

    @VTID(13)
    void mapNetworkDrive(
        java.lang.String localName,
        java.lang.String remoteName,
        java.lang.Object updateProfile,
        java.lang.Object userName,
        java.lang.Object password);

    @VTID(14)
    void removeNetworkDrive(
        java.lang.String name,
        java.lang.Object force,
        java.lang.Object updateProfile);

    @VTID(15)
    mol.wsh.IWshCollection enumNetworkDrives();

    @VTID(15)
    @ReturnValue(type=NativeType.VARIANT,defaultPropertyThrough={mol.wsh.IWshCollection.class})
    java.lang.Object enumNetworkDrives(
        java.lang.Object index);

    @VTID(16)
    void addPrinterConnection(
        java.lang.String localName,
        java.lang.String remoteName,
        java.lang.Object updateProfile,
        java.lang.Object userName,
        java.lang.Object password);

    @VTID(17)
    void removePrinterConnection(
        java.lang.String name,
        java.lang.Object force,
        java.lang.Object updateProfile);

    @VTID(18)
    mol.wsh.IWshCollection enumPrinterConnections();

    @VTID(18)
    @ReturnValue(type=NativeType.VARIANT,defaultPropertyThrough={mol.wsh.IWshCollection.class})
    java.lang.Object enumPrinterConnections(
        java.lang.Object index);

    @VTID(19)
    void setDefaultPrinter(
        java.lang.String name);

}
