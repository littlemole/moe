package mol.excel  ;

import com4j.*;

public enum XlCreator implements ComEnum {
    xlCreatorCode(1480803660),
    ;

    private final int value;
    XlCreator(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
