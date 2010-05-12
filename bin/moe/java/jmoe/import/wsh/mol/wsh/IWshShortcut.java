package mol.wsh  ;

import com4j.*;

/**
 * Shortcut Object
 */
@IID("{F935DC23-1CF0-11D0-ADB9-00C04FD58A0B}")
public interface IWshShortcut extends Com4jObject {
    @VTID(7)
    @DefaultMethod
    java.lang.String fullName();

    @VTID(8)
    java.lang.String arguments();

    @VTID(9)
    void arguments(
        java.lang.String out_Arguments);

    @VTID(10)
    java.lang.String description();

    @VTID(11)
    void description(
        java.lang.String out_Description);

    @VTID(12)
    java.lang.String hotkey();

    @VTID(13)
    void hotkey(
        java.lang.String out_HotKey);

    @VTID(14)
    java.lang.String iconLocation();

    @VTID(15)
    void iconLocation(
        java.lang.String out_IconPath);

    @VTID(16)
    void relativePath(
        java.lang.String rhs);

    @VTID(17)
    java.lang.String targetPath();

    @VTID(18)
    void targetPath(
        java.lang.String out_Path);

    @VTID(19)
    int windowStyle();

    @VTID(20)
    void windowStyle(
        int out_ShowCmd);

    @VTID(21)
    java.lang.String workingDirectory();

    @VTID(22)
    void workingDirectory(
        java.lang.String out_WorkingDirectory);

    @VTID(23)
    void load(
        java.lang.String pathLink);

    @VTID(24)
    void save();

}
