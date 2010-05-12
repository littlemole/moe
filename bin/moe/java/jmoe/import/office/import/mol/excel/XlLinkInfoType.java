package mol.excel  ;

import com4j.*;

public enum XlLinkInfoType implements ComEnum {
    xlLinkInfoOLELinks(2),
    xlLinkInfoPublishers(5),
    xlLinkInfoSubscribers(6),
    ;

    private final int value;
    XlLinkInfoType(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
