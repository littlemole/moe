
package org.oha7.mol.shellctrl;

import org.oha7.dispdriver.annotations.ProgId;
import org.oha7.dispdriver.annotations.Dispid;
import org.oha7.dispdriver.interfaces.IUnknown;


@ProgId("ShellCtrls.ColorDialog")
public interface IColorPicker extends IUnknown {

    @Dispid(1)
	long getColor();

    @Dispid(2)
	String getHexColor();

    @Dispid(1)
	void setColor(long cl);

    @Dispid(2)
	void setHexColor(String cl);

    @Dispid(3)
    boolean Show( );


}
