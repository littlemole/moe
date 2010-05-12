package mol.wsh  ;

import com4j.*;

public enum Tristate implements ComEnum {
    TristateTrue(-1),
    TristateFalse(0),
    TristateUseDefault(-2),
    TristateMixed(-2),
    ;

    private final int value;
    Tristate(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
