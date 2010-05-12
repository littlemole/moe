package mol.excel  ;

import com4j.*;

public enum XlPasteSpecialOperation implements ComEnum {
    xlPasteSpecialOperationAdd(2),
    xlPasteSpecialOperationDivide(5),
    xlPasteSpecialOperationMultiply(4),
    xlPasteSpecialOperationNone(-4142),
    xlPasteSpecialOperationSubtract(3),
    ;

    private final int value;
    XlPasteSpecialOperation(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
