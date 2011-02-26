
package org.oha7.mol.moe;

import org.oha7.dispdriver.annotations.Dispid;
import org.oha7.dispdriver.interfaces.IUnknown;

import org.oha7.dispdriver.interfaces.IDispatch;

public interface IMoeView extends IUnknown {

    @Dispid(1)
	int getTop();

    @Dispid(2)
	int getLeft();

    @Dispid(3)
	int getHeight();

    @Dispid(4)
	int getWidth();

    @Dispid(12)
	boolean getShowTreeView();

    @Dispid(13)
	IDispatch getTreeView();

    @Dispid(14)
	boolean getFullScreen();

    @Dispid(1)
	void setTop(int t);

    @Dispid(2)
	void setLeft(int l);

    @Dispid(3)
	void setHeight(int h);

    @Dispid(4)
	void setWidth(int w);

    @Dispid(12)
	void setShowTreeView(boolean vb);

    @Dispid(14)
	void setFullScreen(boolean vb);

    @Dispid(5)
    void Show( );

    @Dispid(6)
    void Hide( );

    @Dispid(7)
    void Minimize( );

    @Dispid(8)
    void Maximize( );

    @Dispid(9)
    void Restore( );

    @Dispid(10)
    void Tile( );

    @Dispid(11)
    void Cascade( );


}
