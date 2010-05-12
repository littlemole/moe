package mol.excel  ;

import com4j.*;

public enum XlPattern implements ComEnum {
    xlPatternAutomatic(-4105),
    xlPatternChecker(9),
    xlPatternCrissCross(16),
    xlPatternDown(-4121),
    xlPatternGray16(17),
    xlPatternGray25(-4124),
    xlPatternGray50(-4125),
    xlPatternGray75(-4126),
    xlPatternGray8(18),
    xlPatternGrid(15),
    xlPatternHorizontal(-4128),
    xlPatternLightDown(13),
    xlPatternLightHorizontal(11),
    xlPatternLightUp(14),
    xlPatternLightVertical(12),
    xlPatternNone(-4142),
    xlPatternSemiGray75(10),
    xlPatternSolid(1),
    xlPatternUp(-4162),
    xlPatternVertical(-4166),
    xlPatternLinearGradient(4000),
    xlPatternRectangularGradient(4001),
    ;

    private final int value;
    XlPattern(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
