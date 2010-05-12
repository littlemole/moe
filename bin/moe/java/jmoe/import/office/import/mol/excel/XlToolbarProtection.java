package mol.excel  ;

import com4j.*;

public enum XlToolbarProtection implements ComEnum {
    xlNoButtonChanges(1),
    xlNoChanges(4),
    xlNoDockingChanges(3),
    xlToolbarProtectionNone(-4143),
    xlNoShapeChanges(2),
    ;

    private final int value;
    XlToolbarProtection(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
