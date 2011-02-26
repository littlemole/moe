
package org.oha7.mol.scintillax;

import org.oha7.dispdriver.annotations.Dispid;
import org.oha7.dispdriver.interfaces.IUnknown;


public interface IScintillAxMarkers extends IUnknown {

    @Dispid(1)
	boolean getUseMarkers();

    @Dispid(1)
	void setUseMarkers(boolean vbMarkers);

    @Dispid(2)
    void ToggleMarker( int line);

    @Dispid(3)
    void SetMarker( int line);

    @Dispid(4)
    void Remove( int line);

    @Dispid(5)
    void RemoveAll( );

    @Dispid(6)
    void HasMarker( int line);

    @Dispid(7)
    void GetMarkers( Object[] markers);


}
