package mol.office  ;

import com4j.*;

@IID("{000C1713-0000-0000-C000-000000000046}")
public interface IMsoAxis extends Com4jObject {
    @VTID(7)
    boolean axisBetweenCategories();

    @VTID(8)
    void axisBetweenCategories(
        boolean pval);

    @VTID(9)
    mol.office.XlAxisGroup axisGroup();

    @VTID(10)
    mol.office.IMsoAxisTitle axisTitle();

    @VTID(11)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object categoryNames();

    @VTID(12)
    void categoryNames(
        @MarshalAs(NativeType.VARIANT) java.lang.Object pval);

    @VTID(13)
    mol.office.XlAxisCrosses crosses();

    @VTID(14)
    void crosses(
        mol.office.XlAxisCrosses pval);

    @VTID(15)
    double crossesAt();

    @VTID(16)
    void crossesAt(
        double pval);

    @VTID(17)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object delete();

    @VTID(18)
    boolean hasMajorGridlines();

    @VTID(19)
    void hasMajorGridlines(
        boolean pval);

    @VTID(20)
    boolean hasMinorGridlines();

    @VTID(21)
    void hasMinorGridlines(
        boolean pval);

    @VTID(22)
    boolean hasTitle();

    @VTID(23)
    void hasTitle(
        boolean pval);

    @VTID(24)
    mol.office.GridLines majorGridlines();

    @VTID(25)
    mol.office.XlTickMark majorTickMark();

    @VTID(26)
    void majorTickMark(
        mol.office.XlTickMark pval);

    @VTID(27)
    double majorUnit();

    @VTID(28)
    void majorUnit(
        double pval);

    @VTID(29)
    double logBase();

    @VTID(30)
    void logBase(
        double pval);

    @VTID(31)
    boolean tickLabelSpacingIsAuto();

    @VTID(32)
    void tickLabelSpacingIsAuto(
        boolean pval);

    @VTID(33)
    boolean majorUnitIsAuto();

    @VTID(34)
    void majorUnitIsAuto(
        boolean pval);

    @VTID(35)
    double maximumScale();

    @VTID(36)
    void maximumScale(
        double pval);

    @VTID(37)
    boolean maximumScaleIsAuto();

    @VTID(38)
    void maximumScaleIsAuto(
        boolean pval);

    @VTID(39)
    double minimumScale();

    @VTID(40)
    void minimumScale(
        double pval);

    @VTID(41)
    boolean minimumScaleIsAuto();

    @VTID(42)
    void minimumScaleIsAuto(
        boolean pval);

    @VTID(43)
    mol.office.GridLines minorGridlines();

    @VTID(44)
    mol.office.XlTickMark minorTickMark();

    @VTID(45)
    void minorTickMark(
        mol.office.XlTickMark pval);

    @VTID(46)
    double minorUnit();

    @VTID(47)
    void minorUnit(
        double pval);

    @VTID(48)
    boolean minorUnitIsAuto();

    @VTID(49)
    void minorUnitIsAuto(
        boolean pval);

    @VTID(50)
    boolean reversePlotOrder();

    @VTID(51)
    void reversePlotOrder(
        boolean pval);

    @VTID(52)
    mol.office.XlScaleType scaleType();

    @VTID(53)
    void scaleType(
        mol.office.XlScaleType pval);

    @VTID(54)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object select();

    @VTID(55)
    mol.office.XlTickLabelPosition tickLabelPosition();

    @VTID(56)
    void tickLabelPosition(
        mol.office.XlTickLabelPosition pval);

    @VTID(57)
    mol.office.IMsoTickLabels tickLabels();

    @VTID(58)
    int tickLabelSpacing();

    @VTID(59)
    void tickLabelSpacing(
        int pval);

    @VTID(60)
    int tickMarkSpacing();

    @VTID(61)
    void tickMarkSpacing(
        int pval);

    @VTID(62)
    mol.office.XlAxisType type();

    @VTID(63)
    void type(
        mol.office.XlAxisType pval);

    @VTID(64)
    mol.office.XlTimeUnit baseUnit();

    @VTID(65)
    void baseUnit(
        mol.office.XlTimeUnit pval);

    @VTID(66)
    boolean baseUnitIsAuto();

    @VTID(67)
    void baseUnitIsAuto(
        boolean pval);

    @VTID(68)
    mol.office.XlTimeUnit majorUnitScale();

    @VTID(69)
    void majorUnitScale(
        mol.office.XlTimeUnit pval);

    @VTID(70)
    mol.office.XlTimeUnit minorUnitScale();

    @VTID(71)
    void minorUnitScale(
        mol.office.XlTimeUnit pval);

    @VTID(72)
    mol.office.XlCategoryType categoryType();

    @VTID(73)
    void categoryType(
        mol.office.XlCategoryType pval);

    @VTID(74)
    double left();

    @VTID(75)
    double top();

    @VTID(76)
    double width();

    @VTID(77)
    double height();

    @VTID(78)
    mol.office.XlDisplayUnit displayUnit();

    @VTID(79)
    void displayUnit(
        mol.office.XlDisplayUnit pval);

    @VTID(80)
    double displayUnitCustom();

    @VTID(81)
    void displayUnitCustom(
        double pval);

    @VTID(82)
    boolean hasDisplayUnitLabel();

    @VTID(83)
    void hasDisplayUnitLabel(
        boolean pval);

    @VTID(84)
    mol.office.IMsoDisplayUnitLabel displayUnitLabel();

    @VTID(85)
    mol.office.IMsoBorder border();

    @VTID(86)
    java.lang.String name();

    @VTID(87)
    mol.office.IMsoChartFormat format();

}
