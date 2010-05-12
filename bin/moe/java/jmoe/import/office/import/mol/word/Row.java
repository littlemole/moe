package mol.word  ;

import com4j.*;

@IID("{00020950-0000-0000-C000-000000000046}")
public interface Row extends Com4jObject {
    @VTID(7)
    @DefaultMethod
    mol.word.Range range();

    @VTID(8)
    mol.word._Application application();

    @VTID(9)
    int creator();

    @VTID(10)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

    @VTID(11)
    int allowBreakAcrossPages();

    @VTID(12)
    void allowBreakAcrossPages(
        int prop);

    @VTID(13)
    mol.word.WdRowAlignment alignment();

    @VTID(14)
    void alignment(
        mol.word.WdRowAlignment prop);

    @VTID(15)
    int headingFormat();

    @VTID(16)
    void headingFormat(
        int prop);

    @VTID(17)
    float spaceBetweenColumns();

    @VTID(18)
    void spaceBetweenColumns(
        float prop);

    @VTID(19)
    float height();

    @VTID(20)
    void height(
        float prop);

    @VTID(21)
    mol.word.WdRowHeightRule heightRule();

    @VTID(22)
    void heightRule(
        mol.word.WdRowHeightRule prop);

    @VTID(23)
    float leftIndent();

    @VTID(24)
    void leftIndent(
        float prop);

    @VTID(25)
    boolean isLast();

    @VTID(26)
    boolean isFirst();

    @VTID(27)
    int index();

    @VTID(28)
    mol.word.Cells cells();

    @VTID(28)
    @ReturnValue(defaultPropertyThrough={mol.word.Cells.class})
    mol.word.Cell cells(
        int index);

    @VTID(29)
    mol.word.Borders borders();

    @VTID(29)
    @ReturnValue(defaultPropertyThrough={mol.word.Borders.class})
    mol.word.Border borders(
        mol.word.WdBorderType index);

    @VTID(30)
    void borders(
        mol.word.Borders prop);

    @VTID(31)
    mol.word.Shading shading();

    @VTID(32)
    mol.word.Row next();

    @VTID(33)
    mol.word.Row previous();

    @VTID(34)
    void select();

    @VTID(35)
    void delete();

    @VTID(36)
    void setLeftIndent(
        float leftIndent,
        mol.word.WdRulerStyle rulerStyle);

    @VTID(37)
    void setHeight(
        float rowHeight,
        mol.word.WdRowHeightRule heightRule);

    @VTID(38)
    mol.word.Range convertToTextOld(
        java.lang.Object separator);

    @VTID(39)
    mol.word.Range convertToText(
        java.lang.Object separator,
        java.lang.Object nestedTables);

    @VTID(40)
    int nestingLevel();

    @VTID(41)
    java.lang.String id();

    @VTID(42)
    void id(
        java.lang.String prop);

}
