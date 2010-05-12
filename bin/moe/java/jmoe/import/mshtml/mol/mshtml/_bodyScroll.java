package mol.mshtml  ;

import com4j.*;

public enum _bodyScroll implements ComEnum {
    bodyScrollyes(1),
    bodyScrollno(2),
    bodyScrollauto(4),
    bodyScrolldefault(3),
    bodyScroll_Max(2147483647),
    ;

    private final int value;
    _bodyScroll(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
