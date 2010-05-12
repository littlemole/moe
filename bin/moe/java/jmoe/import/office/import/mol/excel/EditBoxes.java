package mol.excel  ;

import com4j.*;

@IID("{00020400-0000-0000-C000-000000000046}")
public interface EditBoxes extends Com4jObject,Iterable<Com4jObject> {
    @DISPID(148)
    @PropGet
    mol.excel._Application application();

    @DISPID(149)
    @PropGet
    mol.excel.XlCreator creator();

    @DISPID(150)
    @PropGet
    com4j.Com4jObject parent();

    @DISPID(65539)
    void _Dummy3();

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

    @DISPID(65548)
    void _Dummy12();

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

    @DISPID(65551)
    void _Dummy15();

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

    @DISPID(65558)
    void _Dummy22();

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

    @DISPID(922)
    @PropGet
    boolean displayVerticalScrollBar();

    @DISPID(922)
    @PropPut
    void displayVerticalScrollBar(
        boolean rhs);

    @DISPID(854)
    @PropGet
    int inputType();

    @DISPID(854)
    @PropPut
    void inputType(
        int rhs);

    @DISPID(65570)
    void _Dummy34();

    @DISPID(855)
    @PropGet
    boolean multiLine();

    @DISPID(855)
    @PropPut
    void multiLine(
        boolean rhs);

    @DISPID(1162)
    @PropGet
    boolean passwordEdit();

    @DISPID(1162)
    @PropPut
    void passwordEdit(
        boolean rhs);

    @DISPID(181)
    mol.excel.EditBox add(
        double left,
        double top,
        double width,
        double height);

    @DISPID(118)
    @PropGet
    int count();

    @DISPID(46)
    mol.excel.GroupObject group();

    @DISPID(170)
    java.lang.Object item(
        java.lang.Object index);

    @DISPID(-4)
    java.util.Iterator<Com4jObject> iterator();

}
