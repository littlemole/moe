package mol.office  ;

import com4j.*;

public enum MsoShadowType implements ComEnum {
    msoShadowMixed(-2),
    msoShadow1(1),
    msoShadow2(2),
    msoShadow3(3),
    msoShadow4(4),
    msoShadow5(5),
    msoShadow6(6),
    msoShadow7(7),
    msoShadow8(8),
    msoShadow9(9),
    msoShadow10(10),
    msoShadow11(11),
    msoShadow12(12),
    msoShadow13(13),
    msoShadow14(14),
    msoShadow15(15),
    msoShadow16(16),
    msoShadow17(17),
    msoShadow18(18),
    msoShadow19(19),
    msoShadow20(20),
    ;

    private final int value;
    MsoShadowType(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
