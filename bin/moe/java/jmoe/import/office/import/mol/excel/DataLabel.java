package mol.excel  ;

import com4j.*;

@IID("{00020400-0000-0000-C000-000000000046}")
public interface DataLabel extends Com4jObject {
    @DISPID(148)
    @PropGet
    mol.excel._Application application();

    @DISPID(149)
    @PropGet
    mol.excel.XlCreator creator();

    @DISPID(150)
    @PropGet
    com4j.Com4jObject parent();

    @DISPID(110)
    @PropGet
    java.lang.String name();

    @DISPID(235)
    java.lang.Object select();

    @DISPID(128)
    @PropGet
    mol.excel.Border border();

    @DISPID(117)
    java.lang.Object delete();

    @DISPID(129)
    @PropGet
    mol.excel.Interior interior();

    @DISPID(1663)
    @PropGet
    mol.excel.ChartFillFormat fill();

    @DISPID(139)
    @PropGet
    java.lang.String caption();

    @DISPID(139)
    @PropPut
    void caption(
        java.lang.String rhs);

    @DISPID(603)
    @PropGet
    mol.excel.Characters characters(
        java.lang.Object start,
        java.lang.Object length);

    @DISPID(146)
    @PropGet
    mol.excel.Font font();

    @DISPID(136)
    @PropGet
    java.lang.Object horizontalAlignment();

    @DISPID(136)
    @PropPut
    void horizontalAlignment(
        java.lang.Object rhs);

    @DISPID(127)
    @PropGet
    double left();

    @DISPID(127)
    @PropPut
    void left(
        double rhs);

    @DISPID(134)
    @PropGet
    java.lang.Object orientation();

    @DISPID(134)
    @PropPut
    void orientation(
        java.lang.Object rhs);

    @DISPID(103)
    @PropGet
    boolean shadow();

    @DISPID(103)
    @PropPut
    void shadow(
        boolean rhs);

    @DISPID(138)
    @PropGet
    java.lang.String text();

    @DISPID(138)
    @PropPut
    void text(
        java.lang.String rhs);

    @DISPID(126)
    @PropGet
    double top();

    @DISPID(126)
    @PropPut
    void top(
        double rhs);

    @DISPID(137)
    @PropGet
    java.lang.Object verticalAlignment();

    @DISPID(137)
    @PropPut
    void verticalAlignment(
        java.lang.Object rhs);

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

    @DISPID(135)
    @PropGet
    boolean autoText();

    @DISPID(135)
    @PropPut
    void autoText(
        boolean rhs);

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

    @DISPID(171)
    @PropGet
    boolean showLegendKey();

    @DISPID(171)
    @PropPut
    void showLegendKey(
        boolean rhs);

    @DISPID(108)
    @PropGet
    java.lang.Object type();

    @DISPID(108)
    @PropPut
    void type(
        java.lang.Object rhs);

    @DISPID(133)
    @PropGet
    mol.excel.XlDataLabelPosition position();

    @DISPID(133)
    @PropPut
    void position(
        mol.excel.XlDataLabelPosition rhs);

    @DISPID(2022)
    @PropGet
    boolean showSeriesName();

    @DISPID(2022)
    @PropPut
    void showSeriesName(
        boolean rhs);

    @DISPID(2023)
    @PropGet
    boolean showCategoryName();

    @DISPID(2023)
    @PropPut
    void showCategoryName(
        boolean rhs);

    @DISPID(2024)
    @PropGet
    boolean showValue();

    @DISPID(2024)
    @PropPut
    void showValue(
        boolean rhs);

    @DISPID(2025)
    @PropGet
    boolean showPercentage();

    @DISPID(2025)
    @PropPut
    void showPercentage(
        boolean rhs);

    @DISPID(2026)
    @PropGet
    boolean showBubbleSize();

    @DISPID(2026)
    @PropPut
    void showBubbleSize(
        boolean rhs);

    @DISPID(2027)
    @PropGet
    java.lang.Object separator();

    @DISPID(2027)
    @PropPut
    void separator(
        java.lang.Object rhs);

    @DISPID(116)
    @PropGet
    mol.excel.ChartFormat format();

}
