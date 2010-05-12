package mol.excel  ;

import com4j.*;

public enum XlWindowState implements ComEnum {
    xlMaximized(-4137),
    xlMinimized(-4140),
    xlNormal(-4143),
    ;

    private final int value;
    XlWindowState(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
