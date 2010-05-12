package mol.word  ;

import com4j.*;

@IID("{0002094F-0000-0000-C000-000000000046}")
public interface Column extends Com4jObject {
    @VTID(7)
    mol.word._Application application();

    @VTID(8)
    int creator();

    @VTID(9)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

    @VTID(10)
    float width();

    @VTID(11)
    void width(
        float prop);

    @VTID(12)
    boolean isFirst();

    @VTID(13)
    boolean isLast();

    @VTID(14)
    int index();

    @VTID(15)
    mol.word.Cells cells();

    @VTID(15)
    @ReturnValue(defaultPropertyThrough={mol.word.Cells.class})
    mol.word.Cell cells(
        int index);

    @VTID(16)
    mol.word.Borders borders();

    @VTID(16)
    @ReturnValue(defaultPropertyThrough={mol.word.Borders.class})
    mol.word.Border borders(
        mol.word.WdBorderType index);

    @VTID(17)
    void borders(
        mol.word.Borders prop);

    @VTID(18)
    mol.word.Shading shading();

    @VTID(19)
    mol.word.Column next();

    @VTID(20)
    mol.word.Column previous();

    @VTID(21)
    void select();

    @VTID(22)
    void delete();

    @VTID(23)
    void setWidth(
        float columnWidth,
        mol.word.WdRulerStyle rulerStyle);

    @VTID(24)
    void autoFit();

    @VTID(25)
    void sortOld(
        java.lang.Object excludeHeader,
        java.lang.Object sortFieldType,
        java.lang.Object sortOrder,
        java.lang.Object caseSensitive,
        java.lang.Object languageID);

    @VTID(26)
    void sort(
        java.lang.Object excludeHeader,
        java.lang.Object sortFieldType,
        java.lang.Object sortOrder,
        java.lang.Object caseSensitive,
        java.lang.Object bidiSort,
        java.lang.Object ignoreThe,
        java.lang.Object ignoreKashida,
        java.lang.Object ignoreDiacritics,
        java.lang.Object ignoreHe,
        java.lang.Object languageID);

    @VTID(27)
    int nestingLevel();

    @VTID(28)
    float preferredWidth();

    @VTID(29)
    void preferredWidth(
        float prop);

    @VTID(30)
    mol.word.WdPreferredWidthType preferredWidthType();

    @VTID(31)
    void preferredWidthType(
        mol.word.WdPreferredWidthType prop);

}
