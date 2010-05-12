package mol.excel  ;

import com4j.*;

@IID("{00020400-0000-0000-C000-000000000046}")
public interface ErrorCheckingOptions extends Com4jObject {
    @DISPID(148)
    @PropGet
    mol.excel._Application application();

    @DISPID(149)
    @PropGet
    mol.excel.XlCreator creator();

    @DISPID(150)
    @PropGet
    com4j.Com4jObject parent();

    @DISPID(2201)
    @PropGet
    boolean backgroundChecking();

    @DISPID(2201)
    @PropPut
    void backgroundChecking(
        boolean rhs);

    @DISPID(2202)
    @PropGet
    mol.excel.XlColorIndex indicatorColorIndex();

    @DISPID(2202)
    @PropPut
    void indicatorColorIndex(
        mol.excel.XlColorIndex rhs);

    @DISPID(2203)
    @PropGet
    boolean evaluateToError();

    @DISPID(2203)
    @PropPut
    void evaluateToError(
        boolean rhs);

    @DISPID(2204)
    @PropGet
    boolean textDate();

    @DISPID(2204)
    @PropPut
    void textDate(
        boolean rhs);

    @DISPID(2205)
    @PropGet
    boolean numberAsText();

    @DISPID(2205)
    @PropPut
    void numberAsText(
        boolean rhs);

    @DISPID(2206)
    @PropGet
    boolean inconsistentFormula();

    @DISPID(2206)
    @PropPut
    void inconsistentFormula(
        boolean rhs);

    @DISPID(2207)
    @PropGet
    boolean omittedCells();

    @DISPID(2207)
    @PropPut
    void omittedCells(
        boolean rhs);

    @DISPID(2208)
    @PropGet
    boolean unlockedFormulaCells();

    @DISPID(2208)
    @PropPut
    void unlockedFormulaCells(
        boolean rhs);

    @DISPID(2209)
    @PropGet
    boolean emptyCellReferences();

    @DISPID(2209)
    @PropPut
    void emptyCellReferences(
        boolean rhs);

    @DISPID(2296)
    @PropGet
    boolean listDataValidation();

    @DISPID(2296)
    @PropPut
    void listDataValidation(
        boolean rhs);

    @DISPID(2675)
    @PropGet
    boolean inconsistentTableFormula();

    @DISPID(2675)
    @PropPut
    void inconsistentTableFormula(
        boolean rhs);

}
