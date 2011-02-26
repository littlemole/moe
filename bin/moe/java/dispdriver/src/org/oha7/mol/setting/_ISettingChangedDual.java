
package org.oha7.mol.setting;

import org.oha7.dispdriver.annotations.Dispid;
import org.oha7.dispdriver.interfaces.IUnknown;


public interface _ISettingChangedDual extends IUnknown {

    @Dispid(1)
    void OnChange( String fullkey, String Key, String val);


}
