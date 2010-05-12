package mol.mshtml  ;

import com4j.*;

public enum _HTMLBorder implements ComEnum {
    HTMLBorderNone(0),
    HTMLBorderThick(262144),
    HTMLBorderDialog(4194304),
    HTMLBorderThin(8388608),
    HTMLBorder_Max(2147483647),
    ;

    private final int value;
    _HTMLBorder(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
