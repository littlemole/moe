package mol.excel  ;

import com4j.*;

public enum XlMailSystem implements ComEnum {
    xlMAPI(1),
    xlNoMailSystem(0),
    xlPowerTalk(2),
    ;

    private final int value;
    XlMailSystem(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
