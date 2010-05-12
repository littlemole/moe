package mol.wsh  ;

import com4j.*;

/**
 * Shell Object Interface
 */
@IID("{F935DC21-1CF0-11D0-ADB9-00C04FD58A0B}")
public interface IWshShell extends Com4jObject {
    @VTID(7)
    mol.wsh.IWshCollection specialFolders();

    @VTID(7)
    @ReturnValue(type=NativeType.VARIANT,defaultPropertyThrough={mol.wsh.IWshCollection.class})
    java.lang.Object specialFolders(
        java.lang.Object index);

    @VTID(8)
    mol.wsh.IWshEnvironment environment(
        java.lang.Object type);

    @VTID(9)
    int run(
        java.lang.String command,
        java.lang.Object windowStyle,
        java.lang.Object waitOnReturn);

    @VTID(10)
    int popup(
        java.lang.String text,
        java.lang.Object secondsToWait,
        java.lang.Object title,
        java.lang.Object type);

    @VTID(11)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject createShortcut(
        java.lang.String pathLink);

    @VTID(12)
    java.lang.String expandEnvironmentStrings(
        java.lang.String src);

    @VTID(13)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object regRead(
        java.lang.String name);

    @VTID(14)
    void regWrite(
        java.lang.String name,
        java.lang.Object value,
        java.lang.Object type);

    @VTID(15)
    void regDelete(
        java.lang.String name);

}
