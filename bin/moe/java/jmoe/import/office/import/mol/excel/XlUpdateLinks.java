package mol.excel  ;

import com4j.*;

public enum XlUpdateLinks implements ComEnum {
    xlUpdateLinksUserSetting(1),
    xlUpdateLinksNever(2),
    xlUpdateLinksAlways(3),
    ;

    private final int value;
    XlUpdateLinks(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
