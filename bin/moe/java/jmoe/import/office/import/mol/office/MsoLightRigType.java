package mol.office  ;

import com4j.*;

public enum MsoLightRigType implements ComEnum {
    msoLightRigMixed(-2),
    msoLightRigLegacyFlat1(1),
    msoLightRigLegacyFlat2(2),
    msoLightRigLegacyFlat3(3),
    msoLightRigLegacyFlat4(4),
    msoLightRigLegacyNormal1(5),
    msoLightRigLegacyNormal2(6),
    msoLightRigLegacyNormal3(7),
    msoLightRigLegacyNormal4(8),
    msoLightRigLegacyHarsh1(9),
    msoLightRigLegacyHarsh2(10),
    msoLightRigLegacyHarsh3(11),
    msoLightRigLegacyHarsh4(12),
    msoLightRigThreePoint(13),
    msoLightRigBalanced(14),
    msoLightRigSoft(15),
    msoLightRigHarsh(16),
    msoLightRigFlood(17),
    msoLightRigContrasting(18),
    msoLightRigMorning(19),
    msoLightRigSunrise(20),
    msoLightRigSunset(21),
    msoLightRigChilly(22),
    msoLightRigFreezing(23),
    msoLightRigFlat(24),
    msoLightRigTwoPoint(25),
    msoLightRigGlow(26),
    msoLightRigBrightRoom(27),
    ;

    private final int value;
    MsoLightRigType(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
