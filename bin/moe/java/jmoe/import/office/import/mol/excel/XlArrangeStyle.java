package mol.excel  ;

import com4j.*;

public enum XlArrangeStyle implements ComEnum {
    xlArrangeStyleCascade(7),
    xlArrangeStyleHorizontal(-4128),
    xlArrangeStyleTiled(1),
    xlArrangeStyleVertical(-4166),
    ;

    private final int value;
    XlArrangeStyle(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
