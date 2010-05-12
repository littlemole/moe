package mol.excel  ;

import com4j.*;

@IID("{00020400-0000-0000-C000-000000000046}")
public interface Style extends Com4jObject {
    @DISPID(148)
    @PropGet
    mol.excel._Application application();

    @DISPID(149)
    @PropGet
    mol.excel.XlCreator creator();

    @DISPID(150)
    @PropGet
    com4j.Com4jObject parent();

    @DISPID(1063)
    @PropGet
    boolean addIndent();

    @DISPID(1063)
    @PropPut
    void addIndent(
        boolean rhs);

    @DISPID(553)
    @PropGet
    boolean builtIn();

    @DISPID(435)
    @PropGet
    mol.excel.Borders borders();

    @DISPID(117)
    java.lang.Object delete();

    @DISPID(146)
    @PropGet
    mol.excel.Font font();

    @DISPID(262)
    @PropGet
    boolean formulaHidden();

    @DISPID(262)
    @PropPut
    void formulaHidden(
        boolean rhs);

    @DISPID(136)
    @PropGet
    mol.excel.XlHAlign horizontalAlignment();

    @DISPID(136)
    @PropPut
    void horizontalAlignment(
        mol.excel.XlHAlign rhs);

    @DISPID(413)
    @PropGet
    boolean includeAlignment();

    @DISPID(413)
    @PropPut
    void includeAlignment(
        boolean rhs);

    @DISPID(414)
    @PropGet
    boolean includeBorder();

    @DISPID(414)
    @PropPut
    void includeBorder(
        boolean rhs);

    @DISPID(415)
    @PropGet
    boolean includeFont();

    @DISPID(415)
    @PropPut
    void includeFont(
        boolean rhs);

    @DISPID(416)
    @PropGet
    boolean includeNumber();

    @DISPID(416)
    @PropPut
    void includeNumber(
        boolean rhs);

    @DISPID(417)
    @PropGet
    boolean includePatterns();

    @DISPID(417)
    @PropPut
    void includePatterns(
        boolean rhs);

    @DISPID(418)
    @PropGet
    boolean includeProtection();

    @DISPID(418)
    @PropPut
    void includeProtection(
        boolean rhs);

    @DISPID(201)
    @PropGet
    int indentLevel();

    @DISPID(201)
    @PropPut
    void indentLevel(
        int rhs);

    @DISPID(129)
    @PropGet
    mol.excel.Interior interior();

    @DISPID(269)
    @PropGet
    boolean locked();

    @DISPID(269)
    @PropPut
    void locked(
        boolean rhs);

    @DISPID(208)
    @PropGet
    java.lang.Object mergeCells();

    @DISPID(208)
    @PropPut
    void mergeCells(
        java.lang.Object rhs);

    @DISPID(110)
    @PropGet
    java.lang.String name();

    @DISPID(937)
    @PropGet
    java.lang.String nameLocal();

    @DISPID(193)
    @PropGet
    java.lang.String numberFormat();

    @DISPID(193)
    @PropPut
    void numberFormat(
        java.lang.String rhs);

    @DISPID(1097)
    @PropGet
    java.lang.String numberFormatLocal();

    @DISPID(1097)
    @PropPut
    void numberFormatLocal(
        java.lang.String rhs);

    @DISPID(134)
    @PropGet
    mol.excel.XlOrientation orientation();

    @DISPID(134)
    @PropPut
    void orientation(
        mol.excel.XlOrientation rhs);

    @DISPID(209)
    @PropGet
    boolean shrinkToFit();

    @DISPID(209)
    @PropPut
    void shrinkToFit(
        boolean rhs);

    @DISPID(6)
    @PropGet
    java.lang.String value();

    @DISPID(137)
    @PropGet
    mol.excel.XlVAlign verticalAlignment();

    @DISPID(137)
    @PropPut
    void verticalAlignment(
        mol.excel.XlVAlign rhs);

    @DISPID(276)
    @PropGet
    boolean wrapText();

    @DISPID(276)
    @PropPut
    void wrapText(
        boolean rhs);

    @DISPID(0)
    @PropGet
    @DefaultMethod
    java.lang.String _Default();

    @DISPID(975)
    @PropGet
    int readingOrder();

    @DISPID(975)
    @PropPut
    void readingOrder(
        int rhs);

}
