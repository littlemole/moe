package mol.excel  ;

import com4j.*;
import mol.office.*;
import mol.vba.*;

@IID("{00020400-0000-0000-C000-000000000046}")
public interface TextFrame extends Com4jObject {
    @DISPID(148)
    @PropGet
    mol.excel._Application application();

    @DISPID(149)
    @PropGet
    mol.excel.XlCreator creator();

    @DISPID(150)
    @PropGet
    com4j.Com4jObject parent();

    @DISPID(1745)
    @PropGet
    float marginBottom();

    @DISPID(1745)
    @PropPut
    void marginBottom(
        float rhs);

    @DISPID(1746)
    @PropGet
    float marginLeft();

    @DISPID(1746)
    @PropPut
    void marginLeft(
        float rhs);

    @DISPID(1747)
    @PropGet
    float marginRight();

    @DISPID(1747)
    @PropPut
    void marginRight(
        float rhs);

    @DISPID(1748)
    @PropGet
    float marginTop();

    @DISPID(1748)
    @PropPut
    void marginTop(
        float rhs);

    @DISPID(134)
    @PropGet
    mol.office.MsoTextOrientation orientation();

    @DISPID(134)
    @PropPut
    void orientation(
        mol.office.MsoTextOrientation rhs);

    @DISPID(603)
    mol.excel.Characters characters(
        java.lang.Object start,
        java.lang.Object length);

    @DISPID(136)
    @PropGet
    mol.excel.XlHAlign horizontalAlignment();

    @DISPID(136)
    @PropPut
    void horizontalAlignment(
        mol.excel.XlHAlign rhs);

    @DISPID(137)
    @PropGet
    mol.excel.XlVAlign verticalAlignment();

    @DISPID(137)
    @PropPut
    void verticalAlignment(
        mol.excel.XlVAlign rhs);

    @DISPID(614)
    @PropGet
    boolean autoSize();

    @DISPID(614)
    @PropPut
    void autoSize(
        boolean rhs);

    @DISPID(975)
    @PropGet
    int readingOrder();

    @DISPID(975)
    @PropPut
    void readingOrder(
        int rhs);

    @DISPID(1749)
    @PropGet
    boolean autoMargins();

    @DISPID(1749)
    @PropPut
    void autoMargins(
        boolean rhs);

}
