package mol.office  ;

import com4j.*;

@IID("{000C031A-0000-0000-C000-000000000046}")
public interface PictureFormat extends mol.office._IMsoDispObj {
    @VTID(9)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

    @VTID(10)
    void incrementBrightness(
        float increment);

    @VTID(11)
    void incrementContrast(
        float increment);

    @VTID(12)
    float brightness();

    @VTID(13)
    void brightness(
        float brightness);

    @VTID(14)
    mol.office.MsoPictureColorType colorType();

    @VTID(15)
    void colorType(
        mol.office.MsoPictureColorType colorType);

    @VTID(16)
    float contrast();

    @VTID(17)
    void contrast(
        float contrast);

    @VTID(18)
    float cropBottom();

    @VTID(19)
    void cropBottom(
        float cropBottom);

    @VTID(20)
    float cropLeft();

    @VTID(21)
    void cropLeft(
        float cropLeft);

    @VTID(22)
    float cropRight();

    @VTID(23)
    void cropRight(
        float cropRight);

    @VTID(24)
    float cropTop();

    @VTID(25)
    void cropTop(
        float cropTop);

    @VTID(26)
    int transparencyColor();

    @VTID(27)
    void transparencyColor(
        int transparencyColor);

    @VTID(28)
    mol.office.MsoTriState transparentBackground();

    @VTID(29)
    void transparentBackground(
        mol.office.MsoTriState transparentBackground);

}
