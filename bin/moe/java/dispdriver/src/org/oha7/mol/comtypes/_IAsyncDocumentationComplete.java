
package org.oha7.mol.comtypes;

import org.oha7.dispdriver.annotations.Dispid;
import org.oha7.dispdriver.interfaces.IUnknown;


public interface _IAsyncDocumentationComplete extends IUnknown {

    @Dispid(1)
    void onComplete( );

    @Dispid(2)
    void onStatus( Object msg);


}
