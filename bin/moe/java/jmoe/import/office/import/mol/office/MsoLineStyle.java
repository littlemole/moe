package mol.office  ;

import com4j.*;

public enum MsoLineStyle implements ComEnum {
    msoLineStyleMixed(-2),
    msoLineSingle(1),
    msoLineThinThin(2),
    msoLineThinThick(3),
    msoLineThickThin(4),
    msoLineThickBetweenThin(5),
    ;

    private final int value;
    MsoLineStyle(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
