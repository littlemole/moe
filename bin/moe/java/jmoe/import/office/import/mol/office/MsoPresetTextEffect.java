package mol.office  ;

import com4j.*;

public enum MsoPresetTextEffect implements ComEnum {
    msoTextEffectMixed(-2),
    msoTextEffect1(0),
    msoTextEffect2(1),
    msoTextEffect3(2),
    msoTextEffect4(3),
    msoTextEffect5(4),
    msoTextEffect6(5),
    msoTextEffect7(6),
    msoTextEffect8(7),
    msoTextEffect9(8),
    msoTextEffect10(9),
    msoTextEffect11(10),
    msoTextEffect12(11),
    msoTextEffect13(12),
    msoTextEffect14(13),
    msoTextEffect15(14),
    msoTextEffect16(15),
    msoTextEffect17(16),
    msoTextEffect18(17),
    msoTextEffect19(18),
    msoTextEffect20(19),
    msoTextEffect21(20),
    msoTextEffect22(21),
    msoTextEffect23(22),
    msoTextEffect24(23),
    msoTextEffect25(24),
    msoTextEffect26(25),
    msoTextEffect27(26),
    msoTextEffect28(27),
    msoTextEffect29(28),
    msoTextEffect30(29),
    ;

    private final int value;
    MsoPresetTextEffect(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
