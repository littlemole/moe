package mol.office  ;

import com4j.*;

public enum MsoAutoSize implements ComEnum {
    msoAutoSizeMixed(-2),
    msoAutoSizeNone(0),
    msoAutoSizeShapeToFitText(1),
    msoAutoSizeTextToFitShape(2),
    ;

    private final int value;
    MsoAutoSize(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
