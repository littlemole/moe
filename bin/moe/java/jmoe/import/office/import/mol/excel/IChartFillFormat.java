package mol.excel  ;

import com4j.*;
import mol.office.*;
import mol.vba.*;

@IID("{00024435-0001-0000-C000-000000000046}")
public interface IChartFillFormat extends Com4jObject {
    @VTID(7)
    mol.excel._Application application();

    @VTID(8)
    mol.excel.XlCreator creator();

    @VTID(9)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

    @VTID(10)
    void oneColorGradient(
        mol.office.MsoGradientStyle style,
        int variant,
        float degree);

    @VTID(11)
    void twoColorGradient(
        mol.office.MsoGradientStyle style,
        int variant);

    @VTID(12)
    void presetTextured(
        mol.office.MsoPresetTexture presetTexture);

    @VTID(13)
    void solid();

    @VTID(14)
    void patterned(
        mol.office.MsoPatternType pattern);

    @VTID(15)
    void userPicture(
        @MarshalAs(NativeType.VARIANT) java.lang.Object pictureFile,
        @MarshalAs(NativeType.VARIANT) java.lang.Object pictureFormat,
        @MarshalAs(NativeType.VARIANT) java.lang.Object pictureStackUnit,
        @MarshalAs(NativeType.VARIANT) java.lang.Object picturePlacement);

    @VTID(16)
    void userTextured(
        java.lang.String textureFile);

    @VTID(17)
    void presetGradient(
        mol.office.MsoGradientStyle style,
        int variant,
        mol.office.MsoPresetGradientType presetGradientType);

    @VTID(18)
    mol.excel.ChartColorFormat backColor();

    @VTID(19)
    mol.excel.ChartColorFormat foreColor();

    @VTID(20)
    mol.office.MsoGradientColorType gradientColorType();

    @VTID(21)
    float gradientDegree();

    @VTID(22)
    mol.office.MsoGradientStyle gradientStyle();

    @VTID(23)
    int gradientVariant();

    @VTID(24)
    mol.office.MsoPatternType pattern();

    @VTID(25)
    mol.office.MsoPresetGradientType presetGradientType();

    @VTID(26)
    mol.office.MsoPresetTexture presetTexture();

    @VTID(27)
    java.lang.String textureName();

    @VTID(28)
    mol.office.MsoTextureType textureType();

    @VTID(29)
    mol.office.MsoFillType type();

    @VTID(30)
    mol.office.MsoTriState visible();

    @VTID(31)
    void visible(
        mol.office.MsoTriState rhs);

}
