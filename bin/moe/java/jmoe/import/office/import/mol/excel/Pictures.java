package mol.excel  ;

import com4j.*;

@IID("{00020400-0000-0000-C000-000000000046}")
public interface Pictures extends Com4jObject,Iterable<Com4jObject> {
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

    @DISPID(128)
    @PropGet
    mol.excel.Border border();

    @DISPID(129)
    @PropGet
    mol.excel.Interior interior();

    @DISPID(103)
    @PropGet
    boolean shadow();

    @DISPID(103)
    @PropPut
    void shadow(
        boolean rhs);

    @DISPID(261)
    @PropGet
    java.lang.String formula();

    @DISPID(261)
    @PropPut
    void formula(
        java.lang.String rhs);

    @DISPID(181)
    mol.excel.Picture add(
        double left,
        double top,
        double width,
        double height);

    @DISPID(118)
    @PropGet
    int count();

    @DISPID(46)
    mol.excel.GroupObject group();

    @DISPID(252)
    mol.excel.Picture insert(
        java.lang.String filename,
        java.lang.Object converter);

    @DISPID(170)
    com4j.Com4jObject item(
        java.lang.Object index);

    @DISPID(-4)
    java.util.Iterator<Com4jObject> iterator();

    @DISPID(211)
    mol.excel.Picture paste(
        java.lang.Object link);

}
