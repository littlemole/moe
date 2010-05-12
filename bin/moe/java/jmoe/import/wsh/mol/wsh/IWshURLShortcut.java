package mol.wsh  ;

import com4j.*;

/**
 * URLShortcut Object
 */
@IID("{F935DC2B-1CF0-11D0-ADB9-00C04FD58A0B}")
public interface IWshURLShortcut extends Com4jObject {
    @VTID(7)
    @DefaultMethod
    java.lang.String fullName();

    @VTID(8)
    java.lang.String targetPath();

    @VTID(9)
    void targetPath(
        java.lang.String out_Path);

    @VTID(10)
    void load(
        java.lang.String pathLink);

    @VTID(11)
    void save();

}
