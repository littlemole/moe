package mol.office  ;

import com4j.*;

@IID("{000C0317-0000-0000-C000-000000000046}")
public interface LineFormat extends mol.office._IMsoDispObj {
    @VTID(9)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

    @VTID(10)
    mol.office.ColorFormat backColor();

    @VTID(11)
    void backColor(
        mol.office.ColorFormat backColor);

    @VTID(12)
    mol.office.MsoArrowheadLength beginArrowheadLength();

    @VTID(13)
    void beginArrowheadLength(
        mol.office.MsoArrowheadLength beginArrowheadLength);

    @VTID(14)
    mol.office.MsoArrowheadStyle beginArrowheadStyle();

    @VTID(15)
    void beginArrowheadStyle(
        mol.office.MsoArrowheadStyle beginArrowheadStyle);

    @VTID(16)
    mol.office.MsoArrowheadWidth beginArrowheadWidth();

    @VTID(17)
    void beginArrowheadWidth(
        mol.office.MsoArrowheadWidth beginArrowheadWidth);

    @VTID(18)
    mol.office.MsoLineDashStyle dashStyle();

    @VTID(19)
    void dashStyle(
        mol.office.MsoLineDashStyle dashStyle);

    @VTID(20)
    mol.office.MsoArrowheadLength endArrowheadLength();

    @VTID(21)
    void endArrowheadLength(
        mol.office.MsoArrowheadLength endArrowheadLength);

    @VTID(22)
    mol.office.MsoArrowheadStyle endArrowheadStyle();

    @VTID(23)
    void endArrowheadStyle(
        mol.office.MsoArrowheadStyle endArrowheadStyle);

    @VTID(24)
    mol.office.MsoArrowheadWidth endArrowheadWidth();

    @VTID(25)
    void endArrowheadWidth(
        mol.office.MsoArrowheadWidth endArrowheadWidth);

    @VTID(26)
    mol.office.ColorFormat foreColor();

    @VTID(27)
    void foreColor(
        mol.office.ColorFormat foreColor);

    @VTID(28)
    mol.office.MsoPatternType pattern();

    @VTID(29)
    void pattern(
        mol.office.MsoPatternType pattern);

    @VTID(30)
    mol.office.MsoLineStyle style();

    @VTID(31)
    void style(
        mol.office.MsoLineStyle style);

    @VTID(32)
    float transparency();

    @VTID(33)
    void transparency(
        float transparency);

    @VTID(34)
    mol.office.MsoTriState visible();

    @VTID(35)
    void visible(
        mol.office.MsoTriState visible);

    @VTID(36)
    float weight();

    @VTID(37)
    void weight(
        float weight);

    @VTID(38)
    mol.office.MsoTriState insetPen();

    @VTID(39)
    void insetPen(
        mol.office.MsoTriState insetPen);

}
