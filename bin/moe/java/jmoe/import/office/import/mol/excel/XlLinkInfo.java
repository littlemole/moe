package mol.excel  ;

import com4j.*;

public enum XlLinkInfo implements ComEnum {
    xlEditionDate(2),
    xlUpdateState(1),
    xlLinkInfoStatus(3),
    ;

    private final int value;
    XlLinkInfo(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
