package mol.excel  ;

import com4j.*;

@IID("{000208BC-0001-0000-C000-000000000046}")
public interface ILegendKey extends Com4jObject {
    @VTID(7)
    mol.excel._Application application();

    @VTID(8)
    mol.excel.XlCreator creator();

    @VTID(9)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

    @VTID(10)
    mol.excel.Border border();

    @VTID(11)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object clearFormats();

    @VTID(12)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object delete();

    @VTID(13)
    mol.excel.Interior interior();

    @VTID(14)
    mol.excel.ChartFillFormat fill();

    @VTID(15)
    boolean invertIfNegative();

    @VTID(16)
    void invertIfNegative(
        boolean rhs);

    @VTID(17)
    int markerBackgroundColor();

    @VTID(18)
    void markerBackgroundColor(
        int rhs);

    @VTID(19)
    mol.excel.XlColorIndex markerBackgroundColorIndex();

    @VTID(20)
    void markerBackgroundColorIndex(
        mol.excel.XlColorIndex rhs);

    @VTID(21)
    int markerForegroundColor();

    @VTID(22)
    void markerForegroundColor(
        int rhs);

    @VTID(23)
    mol.excel.XlColorIndex markerForegroundColorIndex();

    @VTID(24)
    void markerForegroundColorIndex(
        mol.excel.XlColorIndex rhs);

    @VTID(25)
    int markerSize();

    @VTID(26)
    void markerSize(
        int rhs);

    @VTID(27)
    mol.excel.XlMarkerStyle markerStyle();

    @VTID(28)
    void markerStyle(
        mol.excel.XlMarkerStyle rhs);

    @VTID(29)
    int pictureType();

    @VTID(30)
    void pictureType(
        int rhs);

    @VTID(31)
    int pictureUnit();

    @VTID(32)
    void pictureUnit(
        int rhs);

    @VTID(33)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object select();

    @VTID(34)
    boolean smooth();

    @VTID(35)
    void smooth(
        boolean rhs);

    @VTID(36)
    double left();

    @VTID(37)
    double top();

    @VTID(38)
    double width();

    @VTID(39)
    double height();

    @VTID(40)
    boolean shadow();

    @VTID(41)
    void shadow(
        boolean rhs);

    @VTID(42)
    double pictureUnit2();

    @VTID(43)
    void pictureUnit2(
        double rhs);

    @VTID(44)
    mol.excel.ChartFormat format();

}
