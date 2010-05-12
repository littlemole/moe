package mol.excel  ;

import com4j.*;

@IID("{00020400-0000-0000-C000-000000000046}")
public interface TickLabels extends Com4jObject {
    @DISPID(148)
    @PropGet
    mol.excel._Application application();

    @DISPID(149)
    @PropGet
    mol.excel.XlCreator creator();

    @DISPID(150)
    @PropGet
    com4j.Com4jObject parent();

    @DISPID(117)
    java.lang.Object delete();

    @DISPID(146)
    @PropGet
    mol.excel.Font font();

    @DISPID(110)
    @PropGet
    java.lang.String name();

    @DISPID(193)
    @PropGet
    java.lang.String numberFormat();

    @DISPID(193)
    @PropPut
    void numberFormat(
        java.lang.String rhs);

    @DISPID(194)
    @PropGet
    boolean numberFormatLinked();

    @DISPID(194)
    @PropPut
    void numberFormatLinked(
        boolean rhs);

    @DISPID(1097)
    @PropGet
    java.lang.Object numberFormatLocal();

    @DISPID(1097)
    @PropPut
    void numberFormatLocal(
        java.lang.Object rhs);

    @DISPID(134)
    @PropGet
    mol.excel.XlTickLabelOrientation orientation();

    @DISPID(134)
    @PropPut
    void orientation(
        mol.excel.XlTickLabelOrientation rhs);

    @DISPID(235)
    java.lang.Object select();

    @DISPID(975)
    @PropGet
    int readingOrder();

    @DISPID(975)
    @PropPut
    void readingOrder(
        int rhs);

    @DISPID(1525)
    @PropGet
    java.lang.Object autoScaleFont();

    @DISPID(1525)
    @PropPut
    void autoScaleFont(
        java.lang.Object rhs);

    @DISPID(1890)
    @PropGet
    int depth();

    @DISPID(254)
    @PropGet
    int offset();

    @DISPID(254)
    @PropPut
    void offset(
        int rhs);

    @DISPID(453)
    @PropGet
    int alignment();

    @DISPID(453)
    @PropPut
    void alignment(
        int rhs);

    @DISPID(2653)
    @PropGet
    boolean multiLevel();

    @DISPID(2653)
    @PropPut
    void multiLevel(
        boolean rhs);

    @DISPID(116)
    @PropGet
    mol.excel.ChartFormat format();

}
