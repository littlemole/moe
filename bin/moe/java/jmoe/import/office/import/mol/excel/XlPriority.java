package mol.excel  ;

import com4j.*;

public enum XlPriority implements ComEnum {
    xlPriorityHigh(-4127),
    xlPriorityLow(-4134),
    xlPriorityNormal(-4143),
    ;

    private final int value;
    XlPriority(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
