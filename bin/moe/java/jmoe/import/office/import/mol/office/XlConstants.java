package mol.office  ;

import com4j.*;

public enum XlConstants implements ComEnum {
    xlAutomatic(-4105),
    xlCombination(-4111),
    xlCustom(-4114),
    xlBar(2),
    xlColumn(3),
    xl3DBar(-4099),
    xl3DSurface(-4103),
    xlDefaultAutoFormat(-1),
    xlNone(-4142),
    ;

    private final int value;
    XlConstants(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
