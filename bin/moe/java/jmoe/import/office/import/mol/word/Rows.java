package mol.word  ;

import com4j.*;

@IID("{0002094C-0000-0000-C000-000000000046}")
public interface Rows extends Com4jObject,Iterable<Com4jObject> {
    @VTID(7)
    java.util.Iterator<Com4jObject> iterator();

    @VTID(8)
    int count();

    @VTID(9)
    int allowBreakAcrossPages();

    @VTID(10)
    void allowBreakAcrossPages(
        int prop);

    @VTID(11)
    mol.word.WdRowAlignment alignment();

    @VTID(12)
    void alignment(
        mol.word.WdRowAlignment prop);

    @VTID(13)
    int headingFormat();

    @VTID(14)
    void headingFormat(
        int prop);

    @VTID(15)
    float spaceBetweenColumns();

    @VTID(16)
    void spaceBetweenColumns(
        float prop);

    @VTID(17)
    float height();

    @VTID(18)
    void height(
        float prop);

    @VTID(19)
    mol.word.WdRowHeightRule heightRule();

    @VTID(20)
    void heightRule(
        mol.word.WdRowHeightRule prop);

    @VTID(21)
    float leftIndent();

    @VTID(22)
    void leftIndent(
        float prop);

    @VTID(23)
    mol.word.Row first();

    @VTID(24)
    mol.word.Row last();

    @VTID(25)
    mol.word._Application application();

    @VTID(26)
    int creator();

    @VTID(27)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

    @VTID(28)
    mol.word.Borders borders();

    @VTID(28)
    @ReturnValue(defaultPropertyThrough={mol.word.Borders.class})
    mol.word.Border borders(
        mol.word.WdBorderType index);

    @VTID(29)
    void borders(
        mol.word.Borders prop);

    @VTID(30)
    mol.word.Shading shading();

    @VTID(31)
    @DefaultMethod
    mol.word.Row item(
        int index);

    @VTID(32)
    mol.word.Row add(
        java.lang.Object beforeRow);

    @VTID(33)
    void select();

    @VTID(34)
    void delete();

    @VTID(35)
    void setLeftIndent(
        float leftIndent,
        mol.word.WdRulerStyle rulerStyle);

    @VTID(36)
    void setHeight(
        float rowHeight,
        mol.word.WdRowHeightRule heightRule);

    @VTID(37)
    mol.word.Range convertToTextOld(
        java.lang.Object separator);

    @VTID(38)
    void distributeHeight();

    @VTID(39)
    mol.word.Range convertToText(
        java.lang.Object separator,
        java.lang.Object nestedTables);

    @VTID(40)
    int wrapAroundText();

    @VTID(41)
    void wrapAroundText(
        int prop);

    @VTID(42)
    float distanceTop();

    @VTID(43)
    void distanceTop(
        float prop);

    @VTID(44)
    float distanceBottom();

    @VTID(45)
    void distanceBottom(
        float prop);

    @VTID(46)
    float distanceLeft();

    @VTID(47)
    void distanceLeft(
        float prop);

    @VTID(48)
    float distanceRight();

    @VTID(49)
    void distanceRight(
        float prop);

    @VTID(50)
    float horizontalPosition();

    @VTID(51)
    void horizontalPosition(
        float prop);

    @VTID(52)
    float verticalPosition();

    @VTID(53)
    void verticalPosition(
        float prop);

    @VTID(54)
    mol.word.WdRelativeHorizontalPosition relativeHorizontalPosition();

    @VTID(55)
    void relativeHorizontalPosition(
        mol.word.WdRelativeHorizontalPosition prop);

    @VTID(56)
    mol.word.WdRelativeVerticalPosition relativeVerticalPosition();

    @VTID(57)
    void relativeVerticalPosition(
        mol.word.WdRelativeVerticalPosition prop);

    @VTID(58)
    int allowOverlap();

    @VTID(59)
    void allowOverlap(
        int prop);

    @VTID(60)
    int nestingLevel();

    @VTID(61)
    mol.word.WdTableDirection tableDirection();

    @VTID(62)
    void tableDirection(
        mol.word.WdTableDirection prop);

}
