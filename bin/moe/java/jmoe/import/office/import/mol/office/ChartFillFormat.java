package mol.office  ;

import com4j.*;

@IID("{000C171C-0000-0000-C000-000000000046}")
public interface ChartFillFormat extends Com4jObject {
    @VTID(7)
    void oneColorGradient(
        int style,
        int variant,
        float degree);

    @VTID(8)
    void twoColorGradient(
        int style,
        int variant);

    @VTID(9)
    void presetTextured(
        int presetTexture);

    @VTID(10)
    void solid();

    @VTID(11)
    void patterned(
        int pattern);

    @VTID(12)
    void userPicture(
        @MarshalAs(NativeType.VARIANT) java.lang.Object pictureFile,
        @MarshalAs(NativeType.VARIANT) java.lang.Object pictureFormat,
        @MarshalAs(NativeType.VARIANT) java.lang.Object pictureStackUnit,
        @MarshalAs(NativeType.VARIANT) java.lang.Object picturePlacement);

    @VTID(13)
    void userTextured(
        java.lang.String textureFile);

    @VTID(14)
    void presetGradient(
        int style,
        int variant,
        int presetGradientType);

    @VTID(15)
    mol.office.ChartColorFormat backColor();

    @VTID(16)
    mol.office.ChartColorFormat foreColor();

    @VTID(17)
    int gradientColorType();

    @VTID(18)
    float gradientDegree();

    @VTID(19)
    int gradientStyle();

    @VTID(20)
    int gradientVariant();

    @VTID(21)
    int pattern();

    @VTID(22)
    int presetGradientType();

    @VTID(23)
    int presetTexture();

    @VTID(24)
    java.lang.String textureName();

    @VTID(25)
    int textureType();

    @VTID(26)
    int type();

    @VTID(27)
    void visible(
        int pval);

    @VTID(28)
    int visible();

}
