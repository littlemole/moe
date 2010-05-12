package mol.excel  ;

import com4j.*;

public enum XlCVError implements ComEnum {
    xlErrDiv0(2007),
    xlErrNA(2042),
    xlErrName(2029),
    xlErrNull(2000),
    xlErrNum(2036),
    xlErrRef(2023),
    xlErrValue(2015),
    ;

    private final int value;
    XlCVError(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
