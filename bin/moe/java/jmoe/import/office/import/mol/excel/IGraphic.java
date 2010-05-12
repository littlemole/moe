package mol.excel  ;

import com4j.*;

@IID("{00024459-0001-0000-C000-000000000046}")
public interface IGraphic extends Com4jObject {
    @VTID(7)
    mol.excel._Application application();

    @VTID(8)
    mol.excel.XlCreator creator();

    @VTID(9)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

    @VTID(10)
    float brightness();

    @VTID(11)
    void brightness(
        float rhs);

    @VTID(12)
    mol.office.MsoPictureColorType colorType();

    @VTID(13)
    void colorType(
        mol.office.MsoPictureColorType rhs);

    @VTID(14)
    float contrast();

    @VTID(15)
    void contrast(
        float rhs);

    @VTID(16)
    float cropBottom();

    @VTID(17)
    void cropBottom(
        float rhs);

    @VTID(18)
    float cropLeft();

    @VTID(19)
    void cropLeft(
        float rhs);

    @VTID(20)
    float cropRight();

    @VTID(21)
    void cropRight(
        float rhs);

    @VTID(22)
    float cropTop();

    @VTID(23)
    void cropTop(
        float rhs);

    @VTID(24)
    java.lang.String filename();

    @VTID(25)
    void filename(
        java.lang.String rhs);

    @VTID(26)
    float height();

    @VTID(27)
    void height(
        float rhs);

    @VTID(28)
    mol.office.MsoTriState lockAspectRatio();

    @VTID(29)
    void lockAspectRatio(
        mol.office.MsoTriState rhs);

    @VTID(30)
    float width();

    @VTID(31)
    void width(
        float rhs);

}
