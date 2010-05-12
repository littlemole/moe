package mol.excel  ;

import com4j.*;

public enum XlErrorChecks implements ComEnum {
    xlEvaluateToError(1),
    xlTextDate(2),
    xlNumberAsText(3),
    xlInconsistentFormula(4),
    xlOmittedCells(5),
    xlUnlockedFormulaCells(6),
    xlEmptyCellReferences(7),
    xlListDataValidation(8),
    xlInconsistentListFormula(9),
    ;

    private final int value;
    XlErrorChecks(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
