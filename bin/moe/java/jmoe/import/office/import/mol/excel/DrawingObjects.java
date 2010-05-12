package mol.excel  ;

import com4j.*;

@IID("{00020400-0000-0000-C000-000000000046}")
public interface DrawingObjects extends Com4jObject,Iterable<Com4jObject> {
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

    @DISPID(846)
    @PropGet
    java.lang.Object accelerator();

    @DISPID(846)
    @PropPut
    void accelerator(
        java.lang.Object rhs);

    @DISPID(65564)
    void _Dummy28();

    @DISPID(1063)
    @PropGet
    boolean addIndent();

    @DISPID(1063)
    @PropPut
    void addIndent(
        boolean rhs);

    @DISPID(851)
    java.lang.Object addItem(
        java.lang.Object text,
        java.lang.Object index);

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

    @DISPID(858)
    @PropGet
    boolean cancelButton();

    @DISPID(858)
    @PropPut
    void cancelButton(
        boolean rhs);

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

    @DISPID(0)
    @PropGet
    @DefaultMethod
    int _Default();

    @DISPID(0)
    @PropPut
    @DefaultMethod
    void _Default(
        int rhs);

    @DISPID(857)
    @PropGet
    boolean defaultButton();

    @DISPID(857)
    @PropPut
    void defaultButton(
        boolean rhs);

    @DISPID(859)
    @PropGet
    boolean dismissButton();

    @DISPID(859)
    @PropPut
    void dismissButton(
        boolean rhs);

    @DISPID(1122)
    @PropGet
    boolean display3DShading();

    @DISPID(1122)
    @PropPut
    void display3DShading(
        boolean rhs);

    @DISPID(922)
    @PropGet
    boolean displayVerticalScrollBar();

    @DISPID(922)
    @PropPut
    void displayVerticalScrollBar(
        boolean rhs);

    @DISPID(848)
    @PropGet
    int dropDownLines();

    @DISPID(848)
    @PropPut
    void dropDownLines(
        int rhs);

    @DISPID(146)
    @PropGet
    mol.excel.Font font();

    @DISPID(65583)
    void _Dummy47();

    @DISPID(860)
    @PropGet
    boolean helpButton();

    @DISPID(860)
    @PropPut
    void helpButton(
        boolean rhs);

    @DISPID(136)
    @PropGet
    java.lang.Object horizontalAlignment();

    @DISPID(136)
    @PropPut
    void horizontalAlignment(
        java.lang.Object rhs);

    @DISPID(854)
    @PropGet
    int inputType();

    @DISPID(854)
    @PropPut
    void inputType(
        int rhs);

    @DISPID(129)
    @PropGet
    mol.excel.Interior interior();

    @DISPID(845)
    @PropGet
    int largeChange();

    @DISPID(845)
    @PropPut
    void largeChange(
        int rhs);

    @DISPID(1058)
    @PropGet
    java.lang.String linkedCell();

    @DISPID(1058)
    @PropPut
    void linkedCell(
        java.lang.String rhs);

    @DISPID(65590)
    void _Dummy54();

    @DISPID(861)
    java.lang.Object list(
        java.lang.Object index);

    @DISPID(65592)
    void _Dummy56();

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

    @DISPID(616)
    @PropGet
    boolean lockedText();

    @DISPID(616)
    @PropPut
    void lockedText(
        boolean rhs);

    @DISPID(842)
    @PropGet
    int max();

    @DISPID(842)
    @PropPut
    void max(
        int rhs);

    @DISPID(843)
    @PropGet
    int min();

    @DISPID(843)
    @PropPut
    void min(
        int rhs);

    @DISPID(855)
    @PropGet
    boolean multiLine();

    @DISPID(855)
    @PropPut
    void multiLine(
        boolean rhs);

    @DISPID(32)
    @PropGet
    boolean multiSelect();

    @DISPID(32)
    @PropPut
    void multiSelect(
        boolean rhs);

    @DISPID(134)
    @PropGet
    java.lang.Object orientation();

    @DISPID(134)
    @PropPut
    void orientation(
        java.lang.Object rhs);

    @DISPID(1121)
    @PropGet
    java.lang.Object phoneticAccelerator();

    @DISPID(1121)
    @PropPut
    void phoneticAccelerator(
        java.lang.Object rhs);

    @DISPID(853)
    java.lang.Object removeAllItems();

    @DISPID(852)
    java.lang.Object removeItem(
        int index,
        java.lang.Object count);

    @DISPID(604)
    java.lang.Object reshape(
        int vertex,
        java.lang.Object insert,
        java.lang.Object left,
        java.lang.Object top);

    @DISPID(619)
    @PropGet
    boolean roundedCorners();

    @DISPID(619)
    @PropPut
    void roundedCorners(
        boolean rhs);

    @DISPID(1123)
    java.lang.Object selected(
        java.lang.Object index);

    @DISPID(103)
    @PropGet
    boolean shadow();

    @DISPID(103)
    @PropPut
    void shadow(
        boolean rhs);

    @DISPID(844)
    @PropGet
    int smallChange();

    @DISPID(844)
    @PropPut
    void smallChange(
        int rhs);

    @DISPID(138)
    @PropGet
    java.lang.String text();

    @DISPID(138)
    @PropPut
    void text(
        java.lang.String rhs);

    @DISPID(244)
    com4j.Com4jObject ungroup();

    @DISPID(6)
    @PropGet
    int value();

    @DISPID(6)
    @PropPut
    void value(
        int rhs);

    @DISPID(137)
    @PropGet
    java.lang.Object verticalAlignment();

    @DISPID(137)
    @PropPut
    void verticalAlignment(
        java.lang.Object rhs);

    @DISPID(621)
    java.lang.Object vertices(
        java.lang.Object index1,
        java.lang.Object index2);

    @DISPID(975)
    @PropGet
    int readingOrder();

    @DISPID(975)
    @PropPut
    void readingOrder(
        int rhs);

    @DISPID(118)
    @PropGet
    int count();

    @DISPID(170)
    com4j.Com4jObject item(
        java.lang.Object index);

    @DISPID(46)
    mol.excel.GroupObject group();

    @DISPID(856)
    java.lang.Object linkCombo(
        java.lang.Object link);

    @DISPID(-4)
    java.util.Iterator<Com4jObject> iterator();

}
