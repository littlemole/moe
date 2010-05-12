package mol.mshtml  ;

import com4j.*;

public enum _HTMLDlgBorder implements ComEnum {
    HTMLDlgBorderThin(0),
    HTMLDlgBorderThick(262144),
    HTMLDlgBorder_Max(2147483647),
    ;

    private final int value;
    _HTMLDlgBorder(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
