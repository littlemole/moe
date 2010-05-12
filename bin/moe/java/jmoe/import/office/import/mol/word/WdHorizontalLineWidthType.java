package mol.word  ;

import com4j.*;

public enum WdHorizontalLineWidthType implements ComEnum {
    wdHorizontalLinePercentWidth(-1),
    wdHorizontalLineFixedWidth(-2),
    ;

    private final int value;
    WdHorizontalLineWidthType(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
