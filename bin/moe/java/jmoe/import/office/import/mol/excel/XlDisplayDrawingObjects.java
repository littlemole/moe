package mol.excel  ;

import com4j.*;

public enum XlDisplayDrawingObjects implements ComEnum {
    xlDisplayShapes(-4104),
    xlHide(3),
    xlPlaceholders(2),
    ;

    private final int value;
    XlDisplayDrawingObjects(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
