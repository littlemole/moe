package mol.excel  ;

import com4j.*;

public enum XlSortMethodOld implements ComEnum {
    xlCodePage(2),
    xlSyllabary(1),
    ;

    private final int value;
    XlSortMethodOld(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
