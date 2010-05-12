package mol.office  ;

import com4j.*;

public enum MsoTextFontAlign implements ComEnum {
    msoFontAlignMixed(-2),
    msoFontAlignAuto(0),
    msoFontAlignTop(1),
    msoFontAlignCenter(2),
    msoFontAlignBaseline(3),
    msoFontAlignBottom(4),
    ;

    private final int value;
    MsoTextFontAlign(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
