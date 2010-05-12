package mol.excel  ;

import com4j.*;

@IID("{00020400-0000-0000-C000-000000000046}")
public interface Label extends Com4jObject {
    @DISPID(148)
    @PropGet
    mol.excel._Application application();

    @DISPID(149)
    @PropGet
    mol.excel.XlCreator creator();

    @DISPID(150)
    @PropGet
    com4j.Com4jObject parent();

    @DISPID(615)
    @PropGet
    mol.excel.Range bottomRightCell();

    @DISPID(602)
    java.lang.Object bringToFront();

    @DISPID(551)
    java.lang.Object copy();

    @DISPID(213)
    java.lang.Object copyPicture(
        mol.excel.XlPictureAppearance appearance,
        mol.excel.XlCopyPictureFormat format);

    @DISPID(565)
    java.lang.Object cut();

    @DISPID(117)
    java.lang.Object delete();

    @DISPID(1039)
    com4j.Com4jObject duplicate();

    @DISPID(600)
    @PropGet
    boolean enabled();

    @DISPID(600)
    @PropPut
    void enabled(
        boolean rhs);

    @DISPID(123)
    @PropGet
    double height();

    @DISPID(123)
    @PropPut
    void height(
        double rhs);

    @DISPID(486)
    @PropGet
    int index();

    @DISPID(127)
    @PropGet
    double left();

    @DISPID(127)
    @PropPut
    void left(
        double rhs);

    @DISPID(269)
    @PropGet
    boolean locked();

    @DISPID(269)
    @PropPut
    void locked(
        boolean rhs);

    @DISPID(110)
    @PropGet
    java.lang.String name();

    @DISPID(110)
    @PropPut
    void name(
        java.lang.String rhs);

    @DISPID(596)
    @PropGet
    java.lang.String onAction();

    @DISPID(596)
    @PropPut
    void onAction(
        java.lang.String rhs);

    @DISPID(617)
    @PropGet
    java.lang.Object placement();

    @DISPID(617)
    @PropPut
    void placement(
        java.lang.Object rhs);

    @DISPID(618)
    @PropGet
    boolean printObject();

    @DISPID(618)
    @PropPut
    void printObject(
        boolean rhs);

    @DISPID(235)
    java.lang.Object select(
        java.lang.Object replace);

    @DISPID(605)
    java.lang.Object sendToBack();

    @DISPID(126)
    @PropGet
    double top();

    @DISPID(126)
    @PropPut
    void top(
        double rhs);

    @DISPID(620)
    @PropGet
    mol.excel.Range topLeftCell();

    @DISPID(558)
    @PropGet
    boolean visible();

    @DISPID(558)
    @PropPut
    void visible(
        boolean rhs);

    @DISPID(122)
    @PropGet
    double width();

    @DISPID(122)
    @PropPut
    void width(
        double rhs);

    @DISPID(622)
    @PropGet
    int zOrder();

    @DISPID(1528)
    @PropGet
    mol.excel.ShapeRange shapeRange();

    @DISPID(139)
    @PropGet
    java.lang.String caption();

    @DISPID(139)
    @PropPut
    void caption(
        java.lang.String rhs);

    @DISPID(603)
    @PropGet
    mol.excel.Characters characters(
        java.lang.Object start,
        java.lang.Object length);

    @DISPID(505)
    java.lang.Object checkSpelling(
        java.lang.Object customDictionary,
        java.lang.Object ignoreUppercase,
        java.lang.Object alwaysSuggest,
        java.lang.Object spellLang);

    @DISPID(616)
    @PropGet
    boolean lockedText();

    @DISPID(616)
    @PropPut
    void lockedText(
        boolean rhs);

    @DISPID(138)
    @PropGet
    java.lang.String text();

    @DISPID(138)
    @PropPut
    void text(
        java.lang.String rhs);

    @DISPID(846)
    @PropGet
    java.lang.Object accelerator();

    @DISPID(846)
    @PropPut
    void accelerator(
        java.lang.Object rhs);

    @DISPID(65569)
    void _Dummy33();

    @DISPID(1121)
    @PropGet
    java.lang.Object phoneticAccelerator();

    @DISPID(1121)
    @PropPut
    void phoneticAccelerator(
        java.lang.Object rhs);

}
