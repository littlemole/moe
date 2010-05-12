package mol.excel  ;

import com4j.*;

public enum XlLink implements ComEnum {
    xlExcelLinks(1),
    xlOLELinks(2),
    xlPublishers(5),
    xlSubscribers(6),
    ;

    private final int value;
    XlLink(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
