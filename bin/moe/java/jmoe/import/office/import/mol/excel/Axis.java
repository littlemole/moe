package mol.excel  ;

import com4j.*;

@IID("{00020400-0000-0000-C000-000000000046}")
public interface Axis extends Com4jObject {
    @DISPID(148)
    @PropGet
    mol.excel._Application application();

    @DISPID(149)
    @PropGet
    mol.excel.XlCreator creator();

    @DISPID(150)
    @PropGet
    com4j.Com4jObject parent();

    @DISPID(45)
    @PropGet
    boolean axisBetweenCategories();

    @DISPID(45)
    @PropPut
    void axisBetweenCategories(
        boolean rhs);

    @DISPID(47)
    @PropGet
    mol.excel.XlAxisGroup axisGroup();

    @DISPID(82)
    @PropGet
    mol.excel.AxisTitle axisTitle();

    @DISPID(128)
    @PropGet
    mol.excel.Border border();

    @DISPID(156)
    @PropGet
    java.lang.Object categoryNames();

    @DISPID(156)
    @PropPut
    void categoryNames(
        java.lang.Object rhs);

    @DISPID(42)
    @PropGet
    mol.excel.XlAxisCrosses crosses();

    @DISPID(42)
    @PropPut
    void crosses(
        mol.excel.XlAxisCrosses rhs);

    @DISPID(43)
    @PropGet
    double crossesAt();

    @DISPID(43)
    @PropPut
    void crossesAt(
        double rhs);

    @DISPID(117)
    java.lang.Object delete();

    @DISPID(24)
    @PropGet
    boolean hasMajorGridlines();

    @DISPID(24)
    @PropPut
    void hasMajorGridlines(
        boolean rhs);

    @DISPID(25)
    @PropGet
    boolean hasMinorGridlines();

    @DISPID(25)
    @PropPut
    void hasMinorGridlines(
        boolean rhs);

    @DISPID(54)
    @PropGet
    boolean hasTitle();

    @DISPID(54)
    @PropPut
    void hasTitle(
        boolean rhs);

    @DISPID(89)
    @PropGet
    mol.excel.Gridlines majorGridlines();

    @DISPID(26)
    @PropGet
    mol.excel.XlTickMark majorTickMark();

    @DISPID(26)
    @PropPut
    void majorTickMark(
        mol.excel.XlTickMark rhs);

    @DISPID(37)
    @PropGet
    double majorUnit();

    @DISPID(37)
    @PropPut
    void majorUnit(
        double rhs);

    @DISPID(38)
    @PropGet
    boolean majorUnitIsAuto();

    @DISPID(38)
    @PropPut
    void majorUnitIsAuto(
        boolean rhs);

    @DISPID(35)
    @PropGet
    double maximumScale();

    @DISPID(35)
    @PropPut
    void maximumScale(
        double rhs);

    @DISPID(36)
    @PropGet
    boolean maximumScaleIsAuto();

    @DISPID(36)
    @PropPut
    void maximumScaleIsAuto(
        boolean rhs);

    @DISPID(33)
    @PropGet
    double minimumScale();

    @DISPID(33)
    @PropPut
    void minimumScale(
        double rhs);

    @DISPID(34)
    @PropGet
    boolean minimumScaleIsAuto();

    @DISPID(34)
    @PropPut
    void minimumScaleIsAuto(
        boolean rhs);

    @DISPID(90)
    @PropGet
    mol.excel.Gridlines minorGridlines();

    @DISPID(27)
    @PropGet
    mol.excel.XlTickMark minorTickMark();

    @DISPID(27)
    @PropPut
    void minorTickMark(
        mol.excel.XlTickMark rhs);

    @DISPID(39)
    @PropGet
    double minorUnit();

    @DISPID(39)
    @PropPut
    void minorUnit(
        double rhs);

    @DISPID(40)
    @PropGet
    boolean minorUnitIsAuto();

    @DISPID(40)
    @PropPut
    void minorUnitIsAuto(
        boolean rhs);

    @DISPID(44)
    @PropGet
    boolean reversePlotOrder();

    @DISPID(44)
    @PropPut
    void reversePlotOrder(
        boolean rhs);

    @DISPID(41)
    @PropGet
    mol.excel.XlScaleType scaleType();

    @DISPID(41)
    @PropPut
    void scaleType(
        mol.excel.XlScaleType rhs);

    @DISPID(235)
    java.lang.Object select();

    @DISPID(28)
    @PropGet
    mol.excel.XlTickLabelPosition tickLabelPosition();

    @DISPID(28)
    @PropPut
    void tickLabelPosition(
        mol.excel.XlTickLabelPosition rhs);

    @DISPID(91)
    @PropGet
    mol.excel.TickLabels tickLabels();

    @DISPID(29)
    @PropGet
    int tickLabelSpacing();

    @DISPID(29)
    @PropPut
    void tickLabelSpacing(
        int rhs);

    @DISPID(31)
    @PropGet
    int tickMarkSpacing();

    @DISPID(31)
    @PropPut
    void tickMarkSpacing(
        int rhs);

    @DISPID(108)
    @PropGet
    mol.excel.XlAxisType type();

    @DISPID(108)
    @PropPut
    void type(
        mol.excel.XlAxisType rhs);

    @DISPID(1647)
    @PropGet
    mol.excel.XlTimeUnit baseUnit();

    @DISPID(1647)
    @PropPut
    void baseUnit(
        mol.excel.XlTimeUnit rhs);

    @DISPID(1648)
    @PropGet
    boolean baseUnitIsAuto();

    @DISPID(1648)
    @PropPut
    void baseUnitIsAuto(
        boolean rhs);

    @DISPID(1649)
    @PropGet
    mol.excel.XlTimeUnit majorUnitScale();

    @DISPID(1649)
    @PropPut
    void majorUnitScale(
        mol.excel.XlTimeUnit rhs);

    @DISPID(1650)
    @PropGet
    mol.excel.XlTimeUnit minorUnitScale();

    @DISPID(1650)
    @PropPut
    void minorUnitScale(
        mol.excel.XlTimeUnit rhs);

    @DISPID(1651)
    @PropGet
    mol.excel.XlCategoryType categoryType();

    @DISPID(1651)
    @PropPut
    void categoryType(
        mol.excel.XlCategoryType rhs);

    @DISPID(127)
    @PropGet
    double left();

    @DISPID(126)
    @PropGet
    double top();

    @DISPID(122)
    @PropGet
    double width();

    @DISPID(123)
    @PropGet
    double height();

    @DISPID(1886)
    @PropGet
    mol.excel.XlDisplayUnit displayUnit();

    @DISPID(1886)
    @PropPut
    void displayUnit(
        mol.excel.XlDisplayUnit rhs);

    @DISPID(1887)
    @PropGet
    double displayUnitCustom();

    @DISPID(1887)
    @PropPut
    void displayUnitCustom(
        double rhs);

    @DISPID(1888)
    @PropGet
    boolean hasDisplayUnitLabel();

    @DISPID(1888)
    @PropPut
    void hasDisplayUnitLabel(
        boolean rhs);

    @DISPID(1889)
    @PropGet
    mol.excel.DisplayUnitLabel displayUnitLabel();

    @DISPID(2646)
    @PropGet
    double logBase();

    @DISPID(2646)
    @PropPut
    void logBase(
        double rhs);

    @DISPID(2647)
    @PropGet
    boolean tickLabelSpacingIsAuto();

    @DISPID(2647)
    @PropPut
    void tickLabelSpacingIsAuto(
        boolean rhs);

    @DISPID(116)
    @PropGet
    mol.excel.ChartFormat format();

}
