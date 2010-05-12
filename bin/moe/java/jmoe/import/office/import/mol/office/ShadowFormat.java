package mol.office  ;

import com4j.*;

@IID("{000C031B-0000-0000-C000-000000000046}")
public interface ShadowFormat extends mol.office._IMsoDispObj {
    @VTID(9)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

    @VTID(10)
    void incrementOffsetX(
        float increment);

    @VTID(11)
    void incrementOffsetY(
        float increment);

    @VTID(12)
    mol.office.ColorFormat foreColor();

    @VTID(13)
    void foreColor(
        mol.office.ColorFormat foreColor);

    @VTID(14)
    mol.office.MsoTriState obscured();

    @VTID(15)
    void obscured(
        mol.office.MsoTriState obscured);

    @VTID(16)
    float offsetX();

    @VTID(17)
    void offsetX(
        float offsetX);

    @VTID(18)
    float offsetY();

    @VTID(19)
    void offsetY(
        float offsetY);

    @VTID(20)
    float transparency();

    @VTID(21)
    void transparency(
        float transparency);

    @VTID(22)
    mol.office.MsoShadowType type();

    @VTID(23)
    void type(
        mol.office.MsoShadowType type);

    @VTID(24)
    mol.office.MsoTriState visible();

    @VTID(25)
    void visible(
        mol.office.MsoTriState visible);

    @VTID(26)
    mol.office.MsoShadowStyle style();

    @VTID(27)
    void style(
        mol.office.MsoShadowStyle shadowStyle);

    @VTID(28)
    float blur();

    @VTID(29)
    void blur(
        float blur);

    @VTID(30)
    float size();

    @VTID(31)
    void size(
        float size);

    @VTID(32)
    mol.office.MsoTriState rotateWithShape();

    @VTID(33)
    void rotateWithShape(
        mol.office.MsoTriState rotateWithShape);

}
