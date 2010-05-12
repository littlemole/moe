package mol.excel  ;

import com4j.*;

public enum XlOLEVerb implements ComEnum {
    xlVerbOpen(2),
    xlVerbPrimary(1),
    ;

    private final int value;
    XlOLEVerb(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
