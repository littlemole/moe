package mol.office  ;

import com4j.*;

public enum MsoScriptLocation implements ComEnum {
    msoScriptLocationInHead(1),
    msoScriptLocationInBody(2),
    ;

    private final int value;
    MsoScriptLocation(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
