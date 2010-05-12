package mol.setting.events;

import com4j.*;

/**
 * _ISettingChanged - setting changed
 */
@IID("{05CE8141-F38B-4C50-AC21-931F4D07A6A0}")
public abstract class _ISettingChanged {
    /**
     * setting changed
     */
    @DISPID(1)
    public void onChange(
        java.lang.String fullkey,
        java.lang.String key,
        java.lang.String val) {
            throw new UnsupportedOperationException();
    }

}
