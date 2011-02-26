
package org.oha7.mol.setting;

import org.oha7.dispdriver.annotations.ProgId;
import org.oha7.dispdriver.annotations.Dispid;
import org.oha7.dispdriver.interfaces.IUnknown;

import org.oha7.mol.setting.ISetting;
import org.oha7.dispdriver.interfaces.IEnumVARIANT;
import org.oha7.mol.setting.ISetting;

@ProgId("Settings.Setting")
public interface ISetting extends IUnknown {

    @Dispid(1)
	String getKey();

    @Dispid(2)
	String getValue();

    @Dispid(3)
	ISetting getParent();

    @Dispid(4)
	boolean getChildrenAllowed();

    @Dispid(5)
	boolean getKeyReadOnly();

    @Dispid(6)
	boolean getValueReadOnly();

    @Dispid(7)
	boolean getIsDirty();

    @Dispid(1)
	void setKey(String k);

    @Dispid(2)
	void setValue(String v);

    @Dispid(3)
	void setParent(ISetting s);

    @Dispid(4)
	void setChildrenAllowed(boolean vb);

    @Dispid(5)
	void setKeyReadOnly(boolean vb);

    @Dispid(6)
	void setValueReadOnly(boolean vb);

    @Dispid(7)
	void setIsDirty(boolean vb);

    @Dispid(-4)
    IEnumVARIANT _NewEnum( );

    @Dispid(0)
    ISetting Item( Object index);

    @Dispid(8)
    int Count( );

    @Dispid(9)
    ISetting Root( );

    @Dispid(10)
    String KeyName( );

    @Dispid(11)
    void Add( ISetting s);

    @Dispid(12)
    ISetting New( String k, String v);

    @Dispid(13)
    void Remove( );

    @Dispid(14)
    void RemoveItem( Object i);

    @Dispid(15)
    void Clear( );

    @Dispid(16)
    void Load( String fname);

    @Dispid(17)
    void Save( String fname);

    @Dispid(18)
    ISetting Clone( );


}
