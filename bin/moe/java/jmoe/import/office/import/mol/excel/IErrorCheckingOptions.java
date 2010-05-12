package mol.excel  ;

import com4j.*;

@IID("{0002445B-0001-0000-C000-000000000046}")
public interface IErrorCheckingOptions extends Com4jObject {
    @VTID(7)
    mol.excel._Application application();

    @VTID(8)
    mol.excel.XlCreator creator();

    @VTID(9)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

    @VTID(10)
    boolean backgroundChecking();

    @VTID(11)
    void backgroundChecking(
        boolean rhs);

    @VTID(12)
    mol.excel.XlColorIndex indicatorColorIndex();

    @VTID(13)
    void indicatorColorIndex(
        mol.excel.XlColorIndex rhs);

    @VTID(14)
    boolean evaluateToError();

    @VTID(15)
    void evaluateToError(
        boolean rhs);

    @VTID(16)
    boolean textDate();

    @VTID(17)
    void textDate(
        boolean rhs);

    @VTID(18)
    boolean numberAsText();

    @VTID(19)
    void numberAsText(
        boolean rhs);

    @VTID(20)
    boolean inconsistentFormula();

    @VTID(21)
    void inconsistentFormula(
        boolean rhs);

    @VTID(22)
    boolean omittedCells();

    @VTID(23)
    void omittedCells(
        boolean rhs);

    @VTID(24)
    boolean unlockedFormulaCells();

    @VTID(25)
    void unlockedFormulaCells(
        boolean rhs);

    @VTID(26)
    boolean emptyCellReferences();

    @VTID(27)
    void emptyCellReferences(
        boolean rhs);

    @VTID(28)
    boolean listDataValidation();

    @VTID(29)
    void listDataValidation(
        boolean rhs);

    @VTID(30)
    boolean inconsistentTableFormula();

    @VTID(31)
    void inconsistentTableFormula(
        boolean rhs);

}
