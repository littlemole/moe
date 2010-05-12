package mol.mshtml  ;

import com4j.*;

public enum _styleAccelerator implements ComEnum {
    styleAcceleratorFalse(0),
    styleAcceleratorTrue(1),
    styleAccelerator_Max(2147483647),
    ;

    private final int value;
    _styleAccelerator(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
