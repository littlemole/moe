package mol.office  ;

import com4j.*;

public enum MsoPresetThreeDFormat implements ComEnum {
    msoPresetThreeDFormatMixed(-2),
    msoThreeD1(1),
    msoThreeD2(2),
    msoThreeD3(3),
    msoThreeD4(4),
    msoThreeD5(5),
    msoThreeD6(6),
    msoThreeD7(7),
    msoThreeD8(8),
    msoThreeD9(9),
    msoThreeD10(10),
    msoThreeD11(11),
    msoThreeD12(12),
    msoThreeD13(13),
    msoThreeD14(14),
    msoThreeD15(15),
    msoThreeD16(16),
    msoThreeD17(17),
    msoThreeD18(18),
    msoThreeD19(19),
    msoThreeD20(20),
    ;

    private final int value;
    MsoPresetThreeDFormat(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
