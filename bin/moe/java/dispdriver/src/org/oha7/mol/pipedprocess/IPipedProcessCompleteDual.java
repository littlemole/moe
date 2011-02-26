
package org.oha7.mol.pipedprocess;

import org.oha7.dispdriver.annotations.Dispid;
import org.oha7.dispdriver.interfaces.IUnknown;


public interface IPipedProcessCompleteDual extends IUnknown {

    @Dispid(1)
    void onComplete( );


}
