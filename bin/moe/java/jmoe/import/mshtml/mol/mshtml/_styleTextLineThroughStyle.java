package mol.mshtml  ;

import com4j.*;

public enum _styleTextLineThroughStyle implements ComEnum {
    styleTextLineThroughStyleUndefined(0),
    styleTextLineThroughStyleSingle(1),
    styleTextLineThroughStyleDouble(2),
    styleTextLineThroughStyle_Max(2147483647),
    ;

    private final int value;
    _styleTextLineThroughStyle(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
