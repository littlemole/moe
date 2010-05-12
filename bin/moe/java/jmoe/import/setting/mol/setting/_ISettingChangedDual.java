package mol.setting  ;

import com4j.*;

/**
 * _ISettingChangedDual - setting changed, dual version
 */
@IID("{0DB8CB91-F13F-4374-BDD8-FDEEED4210F6}")
public interface _ISettingChangedDual extends Com4jObject {
    /**
     * setting changed
     */
    @VTID(7)
    void onChange(
        java.lang.String fullkey,
        java.lang.String key,
        java.lang.String val);

}
