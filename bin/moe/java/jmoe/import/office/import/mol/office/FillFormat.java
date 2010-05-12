package mol.office  ;

import com4j.*;

@IID("{000C0314-0000-0000-C000-000000000046}")
public interface FillFormat extends mol.office._IMsoDispObj {
    @VTID(9)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

    @VTID(10)
    void background();

    @VTID(11)
    void oneColorGradient(
        mol.office.MsoGradientStyle style,
        int variant,
        float degree);

    @VTID(12)
    void patterned(
        mol.office.MsoPatternType pattern);

    @VTID(13)
    void presetGradient(
        mol.office.MsoGradientStyle style,
        int variant,
        mol.office.MsoPresetGradientType presetGradientType);

    @VTID(14)
    void presetTextured(
        mol.office.MsoPresetTexture presetTexture);

    @VTID(15)
    void solid();

    @VTID(16)
    void twoColorGradient(
        mol.office.MsoGradientStyle style,
        int variant);

    @VTID(17)
    void userPicture(
        java.lang.String pictureFile);

    @VTID(18)
    void userTextured(
        java.lang.String textureFile);

    @VTID(19)
    mol.office.ColorFormat backColor();

    @VTID(20)
    void backColor(
        mol.office.ColorFormat backColor);

    @VTID(21)
    mol.office.ColorFormat foreColor();

    @VTID(22)
    void foreColor(
        mol.office.ColorFormat foreColor);

    @VTID(23)
    mol.office.MsoGradientColorType gradientColorType();

    @VTID(24)
    float gradientDegree();

    @VTID(25)
    mol.office.MsoGradientStyle gradientStyle();

    @VTID(26)
    int gradientVariant();

    @VTID(27)
    mol.office.MsoPatternType pattern();

    @VTID(28)
    mol.office.MsoPresetGradientType presetGradientType();

    @VTID(29)
    mol.office.MsoPresetTexture presetTexture();

    @VTID(30)
    java.lang.String textureName();

    @VTID(31)
    mol.office.MsoTextureType textureType();

    @VTID(32)
    float transparency();

    @VTID(33)
    void transparency(
        float transparency);

    @VTID(34)
    mol.office.MsoFillType type();

    @VTID(35)
    mol.office.MsoTriState visible();

    @VTID(36)
    void visible(
        mol.office.MsoTriState visible);

    @VTID(37)
    mol.office.GradientStops gradientStops();

    @VTID(37)
    @ReturnValue(defaultPropertyThrough={mol.office.GradientStops.class})
    mol.office.GradientStop gradientStops(
        int index);

    @VTID(38)
    float textureOffsetX();

    @VTID(39)
    void textureOffsetX(
        float textureOffsetX);

    @VTID(40)
    float textureOffsetY();

    @VTID(41)
    void textureOffsetY(
        float textureOffsetY);

    @VTID(42)
    mol.office.MsoTextureAlignment textureAlignment();

    @VTID(43)
    void textureAlignment(
        mol.office.MsoTextureAlignment textureAlignment);

    @VTID(44)
    float textureHorizontalScale();

    @VTID(45)
    void textureHorizontalScale(
        float horizontalScale);

    @VTID(46)
    float textureVerticalScale();

    @VTID(47)
    void textureVerticalScale(
        float verticalScale);

    @VTID(48)
    mol.office.MsoTriState textureTile();

    @VTID(49)
    void textureTile(
        mol.office.MsoTriState textureTile);

    @VTID(50)
    mol.office.MsoTriState rotateWithObject();

    @VTID(51)
    void rotateWithObject(
        mol.office.MsoTriState rotateWithObject);

}
