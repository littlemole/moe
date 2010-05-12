package mol.office  ;

import com4j.*;

public enum MsoBulletType implements ComEnum {
    msoBulletMixed(-2),
    msoBulletNone(0),
    msoBulletUnnumbered(1),
    msoBulletNumbered(2),
    msoBulletPicture(3),
    ;

    private final int value;
    MsoBulletType(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
