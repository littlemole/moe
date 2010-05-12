package mol.word  ;

import com4j.*;

@IID("{000209CC-0000-0000-C000-000000000046}")
public interface ShadowFormat extends Com4jObject {
    @VTID(7)
    mol.word._Application application();

    @VTID(8)
    int creator();

    @VTID(9)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

    @VTID(10)
    mol.word.ColorFormat foreColor();

    @VTID(11)
    mol.office.MsoTriState obscured();

    @VTID(12)
    void obscured(
        mol.office.MsoTriState prop);

    @VTID(13)
    float offsetX();

    @VTID(14)
    void offsetX(
        float prop);

    @VTID(15)
    float offsetY();

    @VTID(16)
    void offsetY(
        float prop);

    @VTID(17)
    float transparency();

    @VTID(18)
    void transparency(
        float prop);

    @VTID(19)
    mol.office.MsoShadowType type();

    @VTID(20)
    void type(
        mol.office.MsoShadowType prop);

    @VTID(21)
    mol.office.MsoTriState visible();

    @VTID(22)
    void visible(
        mol.office.MsoTriState prop);

    @VTID(23)
    void incrementOffsetX(
        float increment);

    @VTID(24)
    void incrementOffsetY(
        float increment);

    @VTID(25)
    mol.office.MsoShadowStyle style();

    @VTID(26)
    void style(
        mol.office.MsoShadowStyle prop);

    @VTID(27)
    float blur();

    @VTID(28)
    void blur(
        float prop);

    @VTID(29)
    float size();

    @VTID(30)
    void size(
        float prop);

    @VTID(31)
    mol.office.MsoTriState rotateWithShape();

    @VTID(32)
    void rotateWithShape(
        mol.office.MsoTriState prop);

}
