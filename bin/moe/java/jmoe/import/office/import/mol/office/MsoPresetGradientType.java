package mol.office  ;

import com4j.*;

public enum MsoPresetGradientType implements ComEnum {
    msoPresetGradientMixed(-2),
    msoGradientEarlySunset(1),
    msoGradientLateSunset(2),
    msoGradientNightfall(3),
    msoGradientDaybreak(4),
    msoGradientHorizon(5),
    msoGradientDesert(6),
    msoGradientOcean(7),
    msoGradientCalmWater(8),
    msoGradientFire(9),
    msoGradientFog(10),
    msoGradientMoss(11),
    msoGradientPeacock(12),
    msoGradientWheat(13),
    msoGradientParchment(14),
    msoGradientMahogany(15),
    msoGradientRainbow(16),
    msoGradientRainbowII(17),
    msoGradientGold(18),
    msoGradientGoldII(19),
    msoGradientBrass(20),
    msoGradientChrome(21),
    msoGradientChromeII(22),
    msoGradientSilver(23),
    msoGradientSapphire(24),
    ;

    private final int value;
    MsoPresetGradientType(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
