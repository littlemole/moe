package mol.excel  ;

import com4j.*;
import mol.office.*;
import mol.vba.*;

@IID("{00020400-0000-0000-C000-000000000046}")
public interface Graphic extends Com4jObject {
    @DISPID(148)
    @PropGet
    mol.excel._Application application();

    @DISPID(149)
    @PropGet
    mol.excel.XlCreator creator();

    @DISPID(150)
    @PropGet
    com4j.Com4jObject parent();

    @DISPID(2194)
    @PropGet
    float brightness();

    @DISPID(2194)
    @PropPut
    void brightness(
        float rhs);

    @DISPID(2195)
    @PropGet
    mol.office.MsoPictureColorType colorType();

    @DISPID(2195)
    @PropPut
    void colorType(
        mol.office.MsoPictureColorType rhs);

    @DISPID(2196)
    @PropGet
    float contrast();

    @DISPID(2196)
    @PropPut
    void contrast(
        float rhs);

    @DISPID(2197)
    @PropGet
    float cropBottom();

    @DISPID(2197)
    @PropPut
    void cropBottom(
        float rhs);

    @DISPID(2198)
    @PropGet
    float cropLeft();

    @DISPID(2198)
    @PropPut
    void cropLeft(
        float rhs);

    @DISPID(2199)
    @PropGet
    float cropRight();

    @DISPID(2199)
    @PropPut
    void cropRight(
        float rhs);

    @DISPID(2200)
    @PropGet
    float cropTop();

    @DISPID(2200)
    @PropPut
    void cropTop(
        float rhs);

    @DISPID(1415)
    @PropGet
    java.lang.String filename();

    @DISPID(1415)
    @PropPut
    void filename(
        java.lang.String rhs);

    @DISPID(123)
    @PropGet
    float height();

    @DISPID(123)
    @PropPut
    void height(
        float rhs);

    @DISPID(1700)
    @PropGet
    mol.office.MsoTriState lockAspectRatio();

    @DISPID(1700)
    @PropPut
    void lockAspectRatio(
        mol.office.MsoTriState rhs);

    @DISPID(122)
    @PropGet
    float width();

    @DISPID(122)
    @PropPut
    void width(
        float rhs);

}
