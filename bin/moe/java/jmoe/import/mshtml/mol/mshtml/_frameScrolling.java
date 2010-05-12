package mol.mshtml  ;

import com4j.*;

public enum _frameScrolling implements ComEnum {
    frameScrollingyes(1),
    frameScrollingno(2),
    frameScrollingauto(4),
    frameScrolling_Max(2147483647),
    ;

    private final int value;
    _frameScrolling(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
