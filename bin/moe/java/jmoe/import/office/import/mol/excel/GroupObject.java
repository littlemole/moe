package mol.excel  ;

import com4j.*;

@IID("{00020400-0000-0000-C000-000000000046}")
public interface GroupObject extends Com4jObject {
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

    @DISPID(65563)
    void _Dummy27();

    @DISPID(65564)
    void _Dummy28();

    @DISPID(1063)
    @PropGet
    boolean addIndent();

    @DISPID(1063)
    @PropPut
    void addIndent(
        boolean rhs);

    @DISPID(65566)
    void _Dummy30();

    @DISPID(611)
    @PropGet
    java.lang.Object arrowHeadLength();

    @DISPID(611)
    @PropPut
    void arrowHeadLength(
        java.lang.Object rhs);

    @DISPID(612)
    @PropGet
    java.lang.Object arrowHeadStyle();

    @DISPID(612)
    @PropPut
    void arrowHeadStyle(
        java.lang.Object rhs);

    @DISPID(613)
    @PropGet
    java.lang.Object arrowHeadWidth();

    @DISPID(613)
    @PropPut
    void arrowHeadWidth(
        java.lang.Object rhs);

    @DISPID(614)
    @PropGet
    boolean autoSize();

    @DISPID(614)
    @PropPut
    void autoSize(
        boolean rhs);

    @DISPID(128)
    @PropGet
    mol.excel.Border border();

    @DISPID(65572)
    void _Dummy36();

    @DISPID(65573)
    void _Dummy37();

    @DISPID(65574)
    void _Dummy38();

    @DISPID(505)
    java.lang.Object checkSpelling(
        java.lang.Object customDictionary,
        java.lang.Object ignoreUppercase,
        java.lang.Object alwaysSuggest,
        java.lang.Object spellLang);

    @DISPID(0)
    @PropGet
    @DefaultMethod
    int _Default();

    @DISPID(0)
    @PropPut
    @DefaultMethod
    void _Default(
        int rhs);

    @DISPID(65577)
    void _Dummy41();

    @DISPID(65578)
    void _Dummy42();

    @DISPID(65579)
    void _Dummy43();

    @DISPID(65580)
    void _Dummy44();

    @DISPID(65581)
    void _Dummy45();

    @DISPID(146)
    @PropGet
    mol.excel.Font font();

    @DISPID(65583)
    void _Dummy47();

    @DISPID(65584)
    void _Dummy48();

    @DISPID(136)
    @PropGet
    java.lang.Object horizontalAlignment();

    @DISPID(136)
    @PropPut
    void horizontalAlignment(
        java.lang.Object rhs);

    @DISPID(65586)
    void _Dummy50();

    @DISPID(129)
    @PropGet
    mol.excel.Interior interior();

    @DISPID(65588)
    void _Dummy52();

    @DISPID(65589)
    void _Dummy53();

    @DISPID(65590)
    void _Dummy54();

    @DISPID(65591)
    void _Dummy55();

    @DISPID(65592)
    void _Dummy56();

    @DISPID(65593)
    void _Dummy57();

    @DISPID(65594)
    void _Dummy58();

    @DISPID(65595)
    void _Dummy59();

    @DISPID(65596)
    void _Dummy60();

    @DISPID(65597)
    void _Dummy61();

    @DISPID(65598)
    void _Dummy62();

    @DISPID(65599)
    void _Dummy63();

    @DISPID(134)
    @PropGet
    java.lang.Object orientation();

    @DISPID(134)
    @PropPut
    void orientation(
        java.lang.Object rhs);

    @DISPID(65601)
    void _Dummy65();

    @DISPID(65602)
    void _Dummy66();

    @DISPID(65603)
    void _Dummy67();

    @DISPID(65604)
    void _Dummy68();

    @DISPID(619)
    @PropGet
    boolean roundedCorners();

    @DISPID(619)
    @PropPut
    void roundedCorners(
        boolean rhs);

    @DISPID(65606)
    void _Dummy70();

    @DISPID(103)
    @PropGet
    boolean shadow();

    @DISPID(103)
    @PropPut
    void shadow(
        boolean rhs);

    @DISPID(65608)
    void _Dummy72();

    @DISPID(65609)
    void _Dummy73();

    @DISPID(244)
    com4j.Com4jObject ungroup();

    @DISPID(65611)
    void _Dummy75();

    @DISPID(137)
    @PropGet
    java.lang.Object verticalAlignment();

    @DISPID(137)
    @PropPut
    void verticalAlignment(
        java.lang.Object rhs);

    @DISPID(65613)
    void _Dummy77();

    @DISPID(975)
    @PropGet
    int readingOrder();

    @DISPID(975)
    @PropPut
    void readingOrder(
        int rhs);

}
