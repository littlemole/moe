package mol.excel  ;

import com4j.*;

@IID("{00020400-0000-0000-C000-000000000046}")
public interface _OLEObject extends Com4jObject {
    @DISPID(-2147417964)
    @PropGet
    mol.excel._Application application();

    @DISPID(-2147417963)
    @PropGet
    mol.excel.XlCreator creator();

    @DISPID(-2147417962)
    @PropGet
    com4j.Com4jObject parent();

    @DISPID(-2147417497)
    @PropGet
    mol.excel.Range bottomRightCell();

    @DISPID(-2147417510)
    java.lang.Object bringToFront();

    @DISPID(-2147417561)
    java.lang.Object copy();

    @DISPID(-2147417899)
    java.lang.Object copyPicture(
        mol.excel.XlPictureAppearance appearance,
        mol.excel.XlCopyPictureFormat format);

    @DISPID(-2147417547)
    java.lang.Object cut();

    @DISPID(-2147417995)
    java.lang.Object delete();

    @DISPID(-2147417073)
    com4j.Com4jObject duplicate();

    @DISPID(-2147417512)
    @PropGet
    boolean enabled();

    @DISPID(-2147417512)
    @PropPut
    void enabled(
        boolean rhs);

    @DISPID(-2147417989)
    @PropGet
    double height();

    @DISPID(-2147417989)
    @PropPut
    void height(
        double rhs);

    @DISPID(-2147417626)
    @PropGet
    int index();

    @DISPID(-2147417985)
    @PropGet
    double left();

    @DISPID(-2147417985)
    @PropPut
    void left(
        double rhs);

    @DISPID(-2147417843)
    @PropGet
    boolean locked();

    @DISPID(-2147417843)
    @PropPut
    void locked(
        boolean rhs);

    @DISPID(-2147418002)
    @PropGet
    java.lang.String name();

    @DISPID(-2147418002)
    @PropPut
    void name(
        java.lang.String rhs);

    @DISPID(-2147417516)
    @PropGet
    java.lang.String onAction();

    @DISPID(-2147417516)
    @PropPut
    void onAction(
        java.lang.String rhs);

    @DISPID(-2147417495)
    @PropGet
    java.lang.Object placement();

    @DISPID(-2147417495)
    @PropPut
    void placement(
        java.lang.Object rhs);

    @DISPID(-2147417494)
    @PropGet
    boolean printObject();

    @DISPID(-2147417494)
    @PropPut
    void printObject(
        boolean rhs);

    @DISPID(-2147417877)
    java.lang.Object select(
        java.lang.Object replace);

    @DISPID(-2147417507)
    java.lang.Object sendToBack();

    @DISPID(-2147417986)
    @PropGet
    double top();

    @DISPID(-2147417986)
    @PropPut
    void top(
        double rhs);

    @DISPID(-2147417492)
    @PropGet
    mol.excel.Range topLeftCell();

    @DISPID(-2147417554)
    @PropGet
    boolean visible();

    @DISPID(-2147417554)
    @PropPut
    void visible(
        boolean rhs);

    @DISPID(-2147417990)
    @PropGet
    double width();

    @DISPID(-2147417990)
    @PropPut
    void width(
        double rhs);

    @DISPID(-2147417490)
    @PropGet
    int zOrder();

    @DISPID(-2147416584)
    @PropGet
    mol.excel.ShapeRange shapeRange();

    @DISPID(-2147417984)
    @PropGet
    mol.excel.Border border();

    @DISPID(-2147417983)
    @PropGet
    mol.excel.Interior interior();

    @DISPID(-2147418009)
    @PropGet
    boolean shadow();

    @DISPID(-2147418009)
    @PropPut
    void shadow(
        boolean rhs);

    @DISPID(-2147417808)
    java.lang.Object activate();

    @DISPID(-2147416926)
    @PropGet
    boolean autoLoad();

    @DISPID(-2147416926)
    @PropPut
    void autoLoad(
        boolean rhs);

    @DISPID(-2147417064)
    @PropGet
    boolean autoUpdate();

    @DISPID(-2147417064)
    @PropPut
    void autoUpdate(
        boolean rhs);

    @DISPID(-2147417063)
    @PropGet
    com4j.Com4jObject object();

    @DISPID(-2147417058)
    @PropGet
    java.lang.Object oleType();

    @DISPID(-2147417391)
    @PropGet
    java.lang.String sourceName();

    @DISPID(-2147417391)
    @PropPut
    void sourceName(
        java.lang.String rhs);

    @DISPID(-2147417432)
    java.lang.Object update();

    @DISPID(-2147417506)
    java.lang.Object verb(
        mol.excel.XlOLEVerb verb);

    @DISPID(-2147417054)
    @PropGet
    java.lang.String linkedCell();

    @DISPID(-2147417054)
    @PropPut
    void linkedCell(
        java.lang.String rhs);

    @DISPID(-2147417265)
    @PropGet
    java.lang.String listFillRange();

    @DISPID(-2147417265)
    @PropPut
    void listFillRange(
        java.lang.String rhs);

    @DISPID(-2147416589)
    @PropGet
    java.lang.String progID();

    @DISPID(-2147416259)
    @PropGet
    java.lang.String altHTML();

    @DISPID(-2147416259)
    @PropPut
    void altHTML(
        java.lang.String rhs);

}
