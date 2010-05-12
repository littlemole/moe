package mol.word  ;

import com4j.*;

@IID("{0002094E-0000-0000-C000-000000000046}")
public interface Cell extends Com4jObject {
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
    int rowIndex();

    @VTID(12)
    int columnIndex();

    @VTID(13)
    float width();

    @VTID(14)
    void width(
        float prop);

    @VTID(15)
    float height();

    @VTID(16)
    void height(
        float prop);

    @VTID(17)
    mol.word.WdRowHeightRule heightRule();

    @VTID(18)
    void heightRule(
        mol.word.WdRowHeightRule prop);

    @VTID(19)
    mol.word.WdCellVerticalAlignment verticalAlignment();

    @VTID(20)
    void verticalAlignment(
        mol.word.WdCellVerticalAlignment prop);

    @VTID(21)
    mol.word.Column column();

    @VTID(22)
    mol.word.Row row();

    @VTID(23)
    mol.word.Cell next();

    @VTID(24)
    mol.word.Cell previous();

    @VTID(25)
    mol.word.Shading shading();

    @VTID(26)
    mol.word.Borders borders();

    @VTID(26)
    @ReturnValue(defaultPropertyThrough={mol.word.Borders.class})
    mol.word.Border borders(
        mol.word.WdBorderType index);

    @VTID(27)
    void borders(
        mol.word.Borders prop);

    @VTID(28)
    void select();

    @VTID(29)
    void delete(
        java.lang.Object shiftCells);

    @VTID(30)
    void formula(
        java.lang.Object formula,
        java.lang.Object numFormat);

    @VTID(31)
    void setWidth(
        float columnWidth,
        mol.word.WdRulerStyle rulerStyle);

    @VTID(32)
    void setHeight(
        java.lang.Object rowHeight,
        mol.word.WdRowHeightRule heightRule);

    @VTID(33)
    void merge(
        mol.word.Cell mergeTo);

    @VTID(34)
    void split(
        java.lang.Object numRows,
        java.lang.Object numColumns);

    @VTID(35)
    void autoSum();

    @VTID(36)
    mol.word.Tables tables();

    @VTID(36)
    @ReturnValue(defaultPropertyThrough={mol.word.Tables.class})
    mol.word.Table tables(
        int index);

    @VTID(37)
    int nestingLevel();

    @VTID(38)
    boolean wordWrap();

    @VTID(39)
    void wordWrap(
        boolean prop);

    @VTID(40)
    float preferredWidth();

    @VTID(41)
    void preferredWidth(
        float prop);

    @VTID(42)
    boolean fitText();

    @VTID(43)
    void fitText(
        boolean prop);

    @VTID(44)
    float topPadding();

    @VTID(45)
    void topPadding(
        float prop);

    @VTID(46)
    float bottomPadding();

    @VTID(47)
    void bottomPadding(
        float prop);

    @VTID(48)
    float leftPadding();

    @VTID(49)
    void leftPadding(
        float prop);

    @VTID(50)
    float rightPadding();

    @VTID(51)
    void rightPadding(
        float prop);

    @VTID(52)
    java.lang.String id();

    @VTID(53)
    void id(
        java.lang.String prop);

    @VTID(54)
    mol.word.WdPreferredWidthType preferredWidthType();

    @VTID(55)
    void preferredWidthType(
        mol.word.WdPreferredWidthType prop);

}
