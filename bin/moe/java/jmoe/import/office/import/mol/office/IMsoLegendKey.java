package mol.office  ;

import com4j.*;

@IID("{000C171E-0000-0000-C000-000000000046}")
public interface IMsoLegendKey extends Com4jObject {
    @VTID(7)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

    @VTID(8)
    mol.office.IMsoBorder border();

    @VTID(9)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object clearFormats();

    @VTID(10)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object delete();

    @VTID(11)
    mol.office.IMsoInterior interior();

    @VTID(12)
    mol.office.ChartFillFormat fill();

    @VTID(13)
    boolean invertIfNegative();

    @VTID(14)
    void invertIfNegative(
        boolean rhs);

    @VTID(15)
    int markerBackgroundColor();

    @VTID(16)
    void markerBackgroundColor(
        int rhs);

    @VTID(17)
    mol.office.XlColorIndex markerBackgroundColorIndex();

    @VTID(18)
    void markerBackgroundColorIndex(
        mol.office.XlColorIndex rhs);

    @VTID(19)
    int markerForegroundColor();

    @VTID(20)
    void markerForegroundColor(
        int rhs);

    @VTID(21)
    mol.office.XlColorIndex markerForegroundColorIndex();

    @VTID(22)
    void markerForegroundColorIndex(
        mol.office.XlColorIndex rhs);

    @VTID(23)
    int markerSize();

    @VTID(24)
    void markerSize(
        int rhs);

    @VTID(25)
    mol.office.XlMarkerStyle markerStyle();

    @VTID(26)
    void markerStyle(
        mol.office.XlMarkerStyle rhs);

    @VTID(27)
    int pictureType();

    @VTID(28)
    void pictureType(
        int rhs);

    @VTID(29)
    double pictureUnit();

    @VTID(30)
    void pictureUnit(
        double rhs);

    @VTID(31)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object select();

    @VTID(32)
    boolean smooth();

    @VTID(33)
    void smooth(
        boolean rhs);

    @VTID(34)
    double left();

    @VTID(35)
    double top();

    @VTID(36)
    double width();

    @VTID(37)
    double height();

    @VTID(38)
    boolean shadow();

    @VTID(39)
    void shadow(
        boolean rhs);

    @VTID(40)
    mol.office.IMsoChartFormat format();

}
