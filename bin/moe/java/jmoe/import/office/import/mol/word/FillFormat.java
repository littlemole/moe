package mol.word  ;

import com4j.*;

@IID("{000209C8-0000-0000-C000-000000000046}")
public interface FillFormat extends Com4jObject {
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
    mol.word.ColorFormat foreColor();

    @VTID(12)
    mol.office.MsoGradientColorType gradientColorType();

    @VTID(13)
    float gradientDegree();

    @VTID(14)
    mol.office.MsoGradientStyle gradientStyle();

    @VTID(15)
    int gradientVariant();

    @VTID(16)
    mol.office.MsoPatternType pattern();

    @VTID(17)
    mol.office.MsoPresetGradientType presetGradientType();

    @VTID(18)
    mol.office.MsoPresetTexture presetTexture();

    @VTID(19)
    java.lang.String textureName();

    @VTID(20)
    mol.office.MsoTextureType textureType();

    @VTID(21)
    float transparency();

    @VTID(22)
    void transparency(
        float prop);

    @VTID(23)
    mol.office.MsoFillType type();

    @VTID(24)
    mol.office.MsoTriState visible();

    @VTID(25)
    void visible(
        mol.office.MsoTriState prop);

    @VTID(26)
    void background();

    @VTID(27)
    void oneColorGradient(
        mol.office.MsoGradientStyle style,
        int variant,
        float degree);

    @VTID(28)
    void patterned(
        mol.office.MsoPatternType pattern);

    @VTID(29)
    void presetGradient(
        mol.office.MsoGradientStyle style,
        int variant,
        mol.office.MsoPresetGradientType presetGradientType);

    @VTID(30)
    void presetTextured(
        mol.office.MsoPresetTexture presetTexture);

    @VTID(31)
    void solid();

    @VTID(32)
    void twoColorGradient(
        mol.office.MsoGradientStyle style,
        int variant);

    @VTID(33)
    void userPicture(
        java.lang.String pictureFile);

    @VTID(34)
    void userTextured(
        java.lang.String textureFile);

}
