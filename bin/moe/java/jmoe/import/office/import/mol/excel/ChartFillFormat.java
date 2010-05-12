package mol.excel  ;

import com4j.*;
import mol.office.*;
import mol.vba.*;

@IID("{00020400-0000-0000-C000-000000000046}")
public interface ChartFillFormat extends Com4jObject {
    @DISPID(148)
    @PropGet
    mol.excel._Application application();

    @DISPID(149)
    @PropGet
    mol.excel.XlCreator creator();

    @DISPID(150)
    @PropGet
    com4j.Com4jObject parent();

    @DISPID(1621)
    void oneColorGradient(
        mol.office.MsoGradientStyle style,
        int variant,
        float degree);

    @DISPID(1624)
    void twoColorGradient(
        mol.office.MsoGradientStyle style,
        int variant);

    @DISPID(1625)
    void presetTextured(
        mol.office.MsoPresetTexture presetTexture);

    @DISPID(1627)
    void solid();

    @DISPID(1628)
    void patterned(
        mol.office.MsoPatternType pattern);

    @DISPID(1629)
    void userPicture(
        java.lang.Object pictureFile,
        java.lang.Object pictureFormat,
        java.lang.Object pictureStackUnit,
        java.lang.Object picturePlacement);

    @DISPID(1634)
    void userTextured(
        java.lang.String textureFile);

    @DISPID(1636)
    void presetGradient(
        mol.office.MsoGradientStyle style,
        int variant,
        mol.office.MsoPresetGradientType presetGradientType);

    @DISPID(1638)
    @PropGet
    mol.excel.ChartColorFormat backColor();

    @DISPID(1639)
    @PropGet
    mol.excel.ChartColorFormat foreColor();

    @DISPID(1640)
    @PropGet
    mol.office.MsoGradientColorType gradientColorType();

    @DISPID(1641)
    @PropGet
    float gradientDegree();

    @DISPID(1642)
    @PropGet
    mol.office.MsoGradientStyle gradientStyle();

    @DISPID(1643)
    @PropGet
    int gradientVariant();

    @DISPID(95)
    @PropGet
    mol.office.MsoPatternType pattern();

    @DISPID(1637)
    @PropGet
    mol.office.MsoPresetGradientType presetGradientType();

    @DISPID(1626)
    @PropGet
    mol.office.MsoPresetTexture presetTexture();

    @DISPID(1644)
    @PropGet
    java.lang.String textureName();

    @DISPID(1645)
    @PropGet
    mol.office.MsoTextureType textureType();

    @DISPID(108)
    @PropGet
    mol.office.MsoFillType type();

    @DISPID(558)
    @PropGet
    mol.office.MsoTriState visible();

    @DISPID(558)
    @PropPut
    void visible(
        mol.office.MsoTriState rhs);

}
