package mol.excel  ;

import com4j.*;

public enum XlParameterDataType implements ComEnum {
    xlParamTypeUnknown(0),
    xlParamTypeChar(1),
    xlParamTypeNumeric(2),
    xlParamTypeDecimal(3),
    xlParamTypeInteger(4),
    xlParamTypeSmallInt(5),
    xlParamTypeFloat(6),
    xlParamTypeReal(7),
    xlParamTypeDouble(8),
    xlParamTypeVarChar(12),
    xlParamTypeDate(9),
    xlParamTypeTime(10),
    xlParamTypeTimestamp(11),
    xlParamTypeLongVarChar(-1),
    xlParamTypeBinary(-2),
    xlParamTypeVarBinary(-3),
    xlParamTypeLongVarBinary(-4),
    xlParamTypeBigInt(-5),
    xlParamTypeTinyInt(-6),
    xlParamTypeBit(-7),
    xlParamTypeWChar(-8),
    ;

    private final int value;
    XlParameterDataType(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
