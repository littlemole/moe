package mol.word  ;

import com4j.*;

@IID("{000209CA-0000-0000-C000-000000000046}")
public interface LineFormat extends Com4jObject {
    @VTID(7)
    mol.word._Application application();

    @VTID(8)
    int creator();

    @VTID(9)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

    @VTID(10)
    mol.word.ColorFormat backColor();

    @VTID(11)
    mol.office.MsoArrowheadLength beginArrowheadLength();

    @VTID(12)
    void beginArrowheadLength(
        mol.office.MsoArrowheadLength prop);

    @VTID(13)
    mol.office.MsoArrowheadStyle beginArrowheadStyle();

    @VTID(14)
    void beginArrowheadStyle(
        mol.office.MsoArrowheadStyle prop);

    @VTID(15)
    mol.office.MsoArrowheadWidth beginArrowheadWidth();

    @VTID(16)
    void beginArrowheadWidth(
        mol.office.MsoArrowheadWidth prop);

    @VTID(17)
    mol.office.MsoLineDashStyle dashStyle();

    @VTID(18)
    void dashStyle(
        mol.office.MsoLineDashStyle prop);

    @VTID(19)
    mol.office.MsoArrowheadLength endArrowheadLength();

    @VTID(20)
    void endArrowheadLength(
        mol.office.MsoArrowheadLength prop);

    @VTID(21)
    mol.office.MsoArrowheadStyle endArrowheadStyle();

    @VTID(22)
    void endArrowheadStyle(
        mol.office.MsoArrowheadStyle prop);

    @VTID(23)
    mol.office.MsoArrowheadWidth endArrowheadWidth();

    @VTID(24)
    void endArrowheadWidth(
        mol.office.MsoArrowheadWidth prop);

    @VTID(25)
    mol.word.ColorFormat foreColor();

    @VTID(26)
    mol.office.MsoPatternType pattern();

    @VTID(27)
    void pattern(
        mol.office.MsoPatternType prop);

    @VTID(28)
    mol.office.MsoLineStyle style();

    @VTID(29)
    void style(
        mol.office.MsoLineStyle prop);

    @VTID(30)
    float transparency();

    @VTID(31)
    void transparency(
        float prop);

    @VTID(32)
    mol.office.MsoTriState visible();

    @VTID(33)
    void visible(
        mol.office.MsoTriState prop);

    @VTID(34)
    float weight();

    @VTID(35)
    void weight(
        float prop);

    @VTID(36)
    mol.office.MsoTriState insetPen();

    @VTID(37)
    void insetPen(
        mol.office.MsoTriState prop);

}
