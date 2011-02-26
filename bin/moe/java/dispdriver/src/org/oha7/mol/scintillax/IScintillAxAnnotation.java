
package org.oha7.mol.scintillax;

import org.oha7.dispdriver.annotations.Dispid;
import org.oha7.dispdriver.interfaces.IUnknown;


public interface IScintillAxAnnotation extends IUnknown {

    @Dispid(1)
    void SetText( int line, String txt);

    @Dispid(2)
    void Clear( int line);

    @Dispid(3)
    void ClearAll( );

    @Dispid(4)
    void SetStyle( int line, int style);


}
