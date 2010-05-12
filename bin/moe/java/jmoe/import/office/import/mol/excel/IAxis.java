package mol.excel  ;

import com4j.*;

@IID("{00020848-0001-0000-C000-000000000046}")
public interface IAxis extends Com4jObject {
    @VTID(7)
    mol.excel._Application application();

    @VTID(8)
    mol.excel.XlCreator creator();

    @VTID(9)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

    @VTID(10)
    boolean axisBetweenCategories();

    @VTID(11)
    void axisBetweenCategories(
        boolean rhs);

    @VTID(12)
    mol.excel.XlAxisGroup axisGroup();

    @VTID(13)
    mol.excel.AxisTitle axisTitle();

    @VTID(14)
    mol.excel.Border border();

    @VTID(15)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object categoryNames();

    @VTID(16)
    void categoryNames(
        @MarshalAs(NativeType.VARIANT) java.lang.Object rhs);

    @VTID(17)
    mol.excel.XlAxisCrosses crosses();

    @VTID(18)
    void crosses(
        mol.excel.XlAxisCrosses rhs);

    @VTID(19)
    double crossesAt();

    @VTID(20)
    void crossesAt(
        double rhs);

    @VTID(21)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object delete();

    @VTID(22)
    boolean hasMajorGridlines();

    @VTID(23)
    void hasMajorGridlines(
        boolean rhs);

    @VTID(24)
    boolean hasMinorGridlines();

    @VTID(25)
    void hasMinorGridlines(
        boolean rhs);

    @VTID(26)
    boolean hasTitle();

    @VTID(27)
    void hasTitle(
        boolean rhs);

    @VTID(28)
    mol.excel.Gridlines majorGridlines();

    @VTID(29)
    mol.excel.XlTickMark majorTickMark();

    @VTID(30)
    void majorTickMark(
        mol.excel.XlTickMark rhs);

    @VTID(31)
    double majorUnit();

    @VTID(32)
    void majorUnit(
        double rhs);

    @VTID(33)
    boolean majorUnitIsAuto();

    @VTID(34)
    void majorUnitIsAuto(
        boolean rhs);

    @VTID(35)
    double maximumScale();

    @VTID(36)
    void maximumScale(
        double rhs);

    @VTID(37)
    boolean maximumScaleIsAuto();

    @VTID(38)
    void maximumScaleIsAuto(
        boolean rhs);

    @VTID(39)
    double minimumScale();

    @VTID(40)
    void minimumScale(
        double rhs);

    @VTID(41)
    boolean minimumScaleIsAuto();

    @VTID(42)
    void minimumScaleIsAuto(
        boolean rhs);

    @VTID(43)
    mol.excel.Gridlines minorGridlines();

    @VTID(44)
    mol.excel.XlTickMark minorTickMark();

    @VTID(45)
    void minorTickMark(
        mol.excel.XlTickMark rhs);

    @VTID(46)
    double minorUnit();

    @VTID(47)
    void minorUnit(
        double rhs);

    @VTID(48)
    boolean minorUnitIsAuto();

    @VTID(49)
    void minorUnitIsAuto(
        boolean rhs);

    @VTID(50)
    boolean reversePlotOrder();

    @VTID(51)
    void reversePlotOrder(
        boolean rhs);

    @VTID(52)
    mol.excel.XlScaleType scaleType();

    @VTID(53)
    void scaleType(
        mol.excel.XlScaleType rhs);

    @VTID(54)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object select();

    @VTID(55)
    mol.excel.XlTickLabelPosition tickLabelPosition();

    @VTID(56)
    void tickLabelPosition(
        mol.excel.XlTickLabelPosition rhs);

    @VTID(57)
    mol.excel.TickLabels tickLabels();

    @VTID(58)
    int tickLabelSpacing();

    @VTID(59)
    void tickLabelSpacing(
        int rhs);

    @VTID(60)
    int tickMarkSpacing();

    @VTID(61)
    void tickMarkSpacing(
        int rhs);

    @VTID(62)
    mol.excel.XlAxisType type();

    @VTID(63)
    void type(
        mol.excel.XlAxisType rhs);

    @VTID(64)
    mol.excel.XlTimeUnit baseUnit();

    @VTID(65)
    void baseUnit(
        mol.excel.XlTimeUnit rhs);

    @VTID(66)
    boolean baseUnitIsAuto();

    @VTID(67)
    void baseUnitIsAuto(
        boolean rhs);

    @VTID(68)
    mol.excel.XlTimeUnit majorUnitScale();

    @VTID(69)
    void majorUnitScale(
        mol.excel.XlTimeUnit rhs);

    @VTID(70)
    mol.excel.XlTimeUnit minorUnitScale();

    @VTID(71)
    void minorUnitScale(
        mol.excel.XlTimeUnit rhs);

    @VTID(72)
    mol.excel.XlCategoryType categoryType();

    @VTID(73)
    void categoryType(
        mol.excel.XlCategoryType rhs);

    @VTID(74)
    double left();

    @VTID(75)
    double top();

    @VTID(76)
    double width();

    @VTID(77)
    double height();

    @VTID(78)
    mol.excel.XlDisplayUnit displayUnit();

    @VTID(79)
    void displayUnit(
        mol.excel.XlDisplayUnit rhs);

    @VTID(80)
    double displayUnitCustom();

    @VTID(81)
    void displayUnitCustom(
        double rhs);

    @VTID(82)
    boolean hasDisplayUnitLabel();

    @VTID(83)
    void hasDisplayUnitLabel(
        boolean rhs);

    @VTID(84)
    mol.excel.DisplayUnitLabel displayUnitLabel();

    @VTID(85)
    double logBase();

    @VTID(86)
    void logBase(
        double rhs);

    @VTID(87)
    boolean tickLabelSpacingIsAuto();

    @VTID(88)
    void tickLabelSpacingIsAuto(
        boolean rhs);

    @VTID(89)
    mol.excel.ChartFormat format();

}
