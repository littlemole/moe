
package org.oha7.mol.moe;

import org.oha7.dispdriver.annotations.Dispid;
import org.oha7.dispdriver.interfaces.IUnknown;


public interface IMoeDocumentView extends IUnknown {

    @Dispid(1)
	int getTop();

    @Dispid(2)
	int getLeft();

    @Dispid(3)
	int getHeight();

    @Dispid(4)
	int getWidth();

    @Dispid(1)
	void setTop(int t);

    @Dispid(2)
	void setLeft(int l);

    @Dispid(3)
	void setHeight(int h);

    @Dispid(4)
	void setWidth(int w);

    @Dispid(5)
    void Show( );

    @Dispid(6)
    void Hide( );

    @Dispid(7)
    void Close( );

    @Dispid(8)
    void Minimize( );

    @Dispid(9)
    void Maximize( );

    @Dispid(10)
    void Restore( );

    @Dispid(11)
    void Activate( );


}
