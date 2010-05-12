package mol.excel  ;

import com4j.*;

@IID("{00020400-0000-0000-C000-000000000046}")
public interface CellFormat extends Com4jObject {
    @DISPID(148)
    @PropGet
    mol.excel._Application application();

    @DISPID(149)
    @PropGet
    mol.excel.XlCreator creator();

    @DISPID(150)
    @PropGet
    com4j.Com4jObject parent();

    @DISPID(435)
    @PropGet
    mol.excel.Borders borders();

    @DISPID(435)
    @PropPut
    void borders(
        mol.excel.Borders rhs);

    @DISPID(146)
    @PropGet
    mol.excel.Font font();

    @DISPID(146)
    @PropPut
    void font(
        mol.excel.Font rhs);

    @DISPID(129)
    @PropGet
    mol.excel.Interior interior();

    @DISPID(129)
    @PropPut
    void interior(
        mol.excel.Interior rhs);

    @DISPID(193)
    @PropGet
    java.lang.Object numberFormat();

    @DISPID(193)
    @PropPut
    void numberFormat(
        java.lang.Object rhs);

    @DISPID(1097)
    @PropGet
    java.lang.Object numberFormatLocal();

    @DISPID(1097)
    @PropPut
    void numberFormatLocal(
        java.lang.Object rhs);

    @DISPID(1063)
    @PropGet
    java.lang.Object addIndent();

    @DISPID(1063)
    @PropPut
    void addIndent(
        java.lang.Object rhs);

    @DISPID(201)
    @PropGet
    java.lang.Object indentLevel();

    @DISPID(201)
    @PropPut
    void indentLevel(
        java.lang.Object rhs);

    @DISPID(136)
    @PropGet
    java.lang.Object horizontalAlignment();

    @DISPID(136)
    @PropPut
    void horizontalAlignment(
        java.lang.Object rhs);

    @DISPID(137)
    @PropGet
    java.lang.Object verticalAlignment();

    @DISPID(137)
    @PropPut
    void verticalAlignment(
        java.lang.Object rhs);

    @DISPID(134)
    @PropGet
    java.lang.Object orientation();

    @DISPID(134)
    @PropPut
    void orientation(
        java.lang.Object rhs);

    @DISPID(209)
    @PropGet
    java.lang.Object shrinkToFit();

    @DISPID(209)
    @PropPut
    void shrinkToFit(
        java.lang.Object rhs);

    @DISPID(276)
    @PropGet
    java.lang.Object wrapText();

    @DISPID(276)
    @PropPut
    void wrapText(
        java.lang.Object rhs);

    @DISPID(269)
    @PropGet
    java.lang.Object locked();

    @DISPID(269)
    @PropPut
    void locked(
        java.lang.Object rhs);

    @DISPID(262)
    @PropGet
    java.lang.Object formulaHidden();

    @DISPID(262)
    @PropPut
    void formulaHidden(
        java.lang.Object rhs);

    @DISPID(208)
    @PropGet
    java.lang.Object mergeCells();

    @DISPID(208)
    @PropPut
    void mergeCells(
        java.lang.Object rhs);

    @DISPID(111)
    void clear();

}
