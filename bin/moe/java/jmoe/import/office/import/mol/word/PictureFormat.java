package mol.word  ;

import com4j.*;

@IID("{000209CB-0000-0000-C000-000000000046}")
public interface PictureFormat extends Com4jObject {
    @VTID(7)
    mol.word._Application application();

    @VTID(8)
    int creator();

    @VTID(9)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

    @VTID(10)
    float brightness();

    @VTID(11)
    void brightness(
        float prop);

    @VTID(12)
    mol.office.MsoPictureColorType colorType();

    @VTID(13)
    void colorType(
        mol.office.MsoPictureColorType prop);

    @VTID(14)
    float contrast();

    @VTID(15)
    void contrast(
        float prop);

    @VTID(16)
    float cropBottom();

    @VTID(17)
    void cropBottom(
        float prop);

    @VTID(18)
    float cropLeft();

    @VTID(19)
    void cropLeft(
        float prop);

    @VTID(20)
    float cropRight();

    @VTID(21)
    void cropRight(
        float prop);

    @VTID(22)
    float cropTop();

    @VTID(23)
    void cropTop(
        float prop);

    @VTID(24)
    int transparencyColor();

    @VTID(25)
    void transparencyColor(
        int prop);

    @VTID(26)
    mol.office.MsoTriState transparentBackground();

    @VTID(27)
    void transparentBackground(
        mol.office.MsoTriState prop);

    @VTID(28)
    void incrementBrightness(
        float increment);

    @VTID(29)
    void incrementContrast(
        float increment);

}
