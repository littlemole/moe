package mol.excel  ;

import com4j.*;

public enum XlOLEType implements ComEnum {
    xlOLEControl(2),
    xlOLEEmbed(1),
    xlOLELink(0),
    ;

    private final int value;
    XlOLEType(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
