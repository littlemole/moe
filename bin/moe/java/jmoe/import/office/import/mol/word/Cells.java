package mol.word  ;

import com4j.*;

@IID("{0002094A-0000-0000-C000-000000000046}")
public interface Cells extends Com4jObject,Iterable<Com4jObject> {
    @VTID(7)
    java.util.Iterator<Com4jObject> iterator();

    @VTID(8)
    int count();

    @VTID(9)
    mol.word._Application application();

    @VTID(10)
    int creator();

    @VTID(11)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

    @VTID(12)
    float width();

    @VTID(13)
    void width(
        float prop);

    @VTID(14)
    float height();

    @VTID(15)
    void height(
        float prop);

    @VTID(16)
    mol.word.WdRowHeightRule heightRule();

    @VTID(17)
    void heightRule(
        mol.word.WdRowHeightRule prop);

    @VTID(18)
    mol.word.WdCellVerticalAlignment verticalAlignment();

    @VTID(19)
    void verticalAlignment(
        mol.word.WdCellVerticalAlignment prop);

    @VTID(20)
    mol.word.Borders borders();

    @VTID(20)
    @ReturnValue(defaultPropertyThrough={mol.word.Borders.class})
    mol.word.Border borders(
        mol.word.WdBorderType index);

    @VTID(21)
    void borders(
        mol.word.Borders prop);

    @VTID(22)
    mol.word.Shading shading();

    @VTID(23)
    @DefaultMethod
    mol.word.Cell item(
        int index);

    @VTID(24)
    mol.word.Cell add(
        java.lang.Object beforeCell);

    @VTID(25)
    void delete(
        java.lang.Object shiftCells);

    @VTID(26)
    void setWidth(
        float columnWidth,
        mol.word.WdRulerStyle rulerStyle);

    @VTID(27)
    void setHeight(
        java.lang.Object rowHeight,
        mol.word.WdRowHeightRule heightRule);

    @VTID(28)
    void merge();

    @VTID(29)
    void split(
        java.lang.Object numRows,
        java.lang.Object numColumns,
        java.lang.Object mergeBeforeSplit);

    @VTID(30)
    void distributeHeight();

    @VTID(31)
    void distributeWidth();

    @VTID(32)
    void autoFit();

    @VTID(33)
    int nestingLevel();

    @VTID(34)
    float preferredWidth();

    @VTID(35)
    void preferredWidth(
        float prop);

    @VTID(36)
    mol.word.WdPreferredWidthType preferredWidthType();

    @VTID(37)
    void preferredWidthType(
        mol.word.WdPreferredWidthType prop);

}
