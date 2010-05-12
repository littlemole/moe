package mol.excel  ;

import com4j.*;

@IID("{00020400-0000-0000-C000-000000000046}")
public interface ListBox extends Com4jObject {
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

    @DISPID(851)
    java.lang.Object addItem(
        java.lang.Object text,
        java.lang.Object index);

    @DISPID(1122)
    @PropGet
    boolean display3DShading();

    @DISPID(1122)
    @PropPut
    void display3DShading(
        boolean rhs);

    @DISPID(0)
    @PropGet
    @DefaultMethod
    int _Default();

    @DISPID(0)
    @PropPut
    @DefaultMethod
    void _Default(
        int rhs);

    @DISPID(1058)
    @PropGet
    java.lang.String linkedCell();

    @DISPID(1058)
    @PropPut
    void linkedCell(
        java.lang.String rhs);

    @DISPID(862)
    @PropGet
    java.lang.Object linkedObject();

    @DISPID(861)
    @PropGet
    java.lang.Object list(
        java.lang.Object index);

    @DISPID(861)
    @PropPut
    void list(
        java.lang.Object index,
        java.lang.Object rhs);

    @DISPID(849)
    @PropGet
    int listCount();

    @DISPID(847)
    @PropGet
    java.lang.String listFillRange();

    @DISPID(847)
    @PropPut
    void listFillRange(
        java.lang.String rhs);

    @DISPID(850)
    @PropGet
    int listIndex();

    @DISPID(850)
    @PropPut
    void listIndex(
        int rhs);

    @DISPID(32)
    @PropGet
    int multiSelect();

    @DISPID(32)
    @PropPut
    void multiSelect(
        int rhs);

    @DISPID(853)
    java.lang.Object removeAllItems();

    @DISPID(852)
    java.lang.Object removeItem(
        int index,
        java.lang.Object count);

    @DISPID(1123)
    @PropGet
    java.lang.Object selected(
        java.lang.Object index);

    @DISPID(1123)
    @PropPut
    void selected(
        java.lang.Object index,
        java.lang.Object rhs);

    @DISPID(6)
    @PropGet
    int value();

    @DISPID(6)
    @PropPut
    void value(
        int rhs);

}
