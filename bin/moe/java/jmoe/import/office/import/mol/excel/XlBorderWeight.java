package mol.excel  ;

import com4j.*;

public enum XlBorderWeight implements ComEnum {
    xlHairline(1),
    xlMedium(-4138),
    xlThick(4),
    xlThin(2),
    ;

    private final int value;
    XlBorderWeight(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
