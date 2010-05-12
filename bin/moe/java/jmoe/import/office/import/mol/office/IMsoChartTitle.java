package mol.office  ;

import com4j.*;

@IID("{000C170F-0000-0000-C000-000000000046}")
public interface IMsoChartTitle extends Com4jObject {
    @VTID(7)
    void caption(
        java.lang.String pbstr);

    @VTID(8)
    java.lang.String caption();

    @VTID(9)
    mol.office.IMsoCharacters characters(
        @MarshalAs(NativeType.VARIANT) java.lang.Object start,
        @MarshalAs(NativeType.VARIANT) java.lang.Object length);

    @VTID(10)
    mol.office.ChartFont font();

    @VTID(11)
    void horizontalAlignment(
        @MarshalAs(NativeType.VARIANT) java.lang.Object val);

    @VTID(12)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object horizontalAlignment();

    @VTID(13)
    double left();

    @VTID(14)
    void left(
        double pval);

    @VTID(15)
    void orientation(
        @MarshalAs(NativeType.VARIANT) java.lang.Object val);

    @VTID(16)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object orientation();

    @VTID(17)
    boolean shadow();

    @VTID(18)
    void shadow(
        boolean pval);

    @VTID(19)
    void text(
        java.lang.String pbstr);

    @VTID(20)
    java.lang.String text();

    @VTID(21)
    double top();

    @VTID(22)
    void top(
        double pval);

    @VTID(23)
    void verticalAlignment(
        @MarshalAs(NativeType.VARIANT) java.lang.Object val);

    @VTID(24)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object verticalAlignment();

    @VTID(25)
    int readingOrder();

    @VTID(26)
    void readingOrder(
        int pval);

    @VTID(27)
    void autoScaleFont(
        @MarshalAs(NativeType.VARIANT) java.lang.Object val);

    @VTID(28)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object autoScaleFont();

    @VTID(29)
    mol.office.IMsoInterior interior();

    @VTID(30)
    mol.office.ChartFillFormat fill();

    @VTID(31)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object delete();

    @VTID(32)
    mol.office.IMsoBorder border();

    @VTID(33)
    java.lang.String name();

    @VTID(34)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

    @VTID(35)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object select();

    @VTID(36)
    boolean includeInLayout();

    @VTID(37)
    void includeInLayout(
        boolean rhs);

    @VTID(38)
    mol.office.XlChartElementPosition position();

    @VTID(39)
    void position(
        mol.office.XlChartElementPosition pval);

    @VTID(40)
    mol.office.IMsoChartFormat format();

    @VTID(41)
    double height();

}
