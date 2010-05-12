package mol.word  ;

import com4j.*;

@IID("{00020951-0000-0000-C000-000000000046}")
public interface Table extends Com4jObject {
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
    mol.word.Columns columns();

    @VTID(11)
    @ReturnValue(defaultPropertyThrough={mol.word.Columns.class})
    mol.word.Column columns(
        int index);

    @VTID(12)
    mol.word.Rows rows();

    @VTID(12)
    @ReturnValue(defaultPropertyThrough={mol.word.Rows.class})
    mol.word.Row rows(
        int index);

    @VTID(13)
    mol.word.Borders borders();

    @VTID(13)
    @ReturnValue(defaultPropertyThrough={mol.word.Borders.class})
    mol.word.Border borders(
        mol.word.WdBorderType index);

    @VTID(14)
    void borders(
        mol.word.Borders prop);

    @VTID(15)
    mol.word.Shading shading();

    @VTID(16)
    boolean uniform();

    @VTID(17)
    int autoFormatType();

    @VTID(18)
    void select();

    @VTID(19)
    void delete();

    @VTID(20)
    void sortOld(
        java.lang.Object excludeHeader,
        java.lang.Object fieldNumber,
        java.lang.Object sortFieldType,
        java.lang.Object sortOrder,
        java.lang.Object fieldNumber2,
        java.lang.Object sortFieldType2,
        java.lang.Object sortOrder2,
        java.lang.Object fieldNumber3,
        java.lang.Object sortFieldType3,
        java.lang.Object sortOrder3,
        java.lang.Object caseSensitive,
        java.lang.Object languageID);

    @VTID(21)
    void sortAscending();

    @VTID(22)
    void sortDescending();

    @VTID(23)
    void autoFormat(
        java.lang.Object format,
        java.lang.Object applyBorders,
        java.lang.Object applyShading,
        java.lang.Object applyFont,
        java.lang.Object applyColor,
        java.lang.Object applyHeadingRows,
        java.lang.Object applyLastRow,
        java.lang.Object applyFirstColumn,
        java.lang.Object applyLastColumn,
        java.lang.Object autoFit);

    @VTID(24)
    void updateAutoFormat();

    @VTID(25)
    mol.word.Range convertToTextOld(
        java.lang.Object separator);

    @VTID(26)
    mol.word.Cell cell(
        int row,
        int column);

    @VTID(27)
    mol.word.Table split(
        java.lang.Object beforeRow);

    @VTID(28)
    mol.word.Range convertToText(
        java.lang.Object separator,
        java.lang.Object nestedTables);

    @VTID(29)
    void autoFitBehavior(
        mol.word.WdAutoFitBehavior behavior);

    @VTID(30)
    void sort(
        java.lang.Object excludeHeader,
        java.lang.Object fieldNumber,
        java.lang.Object sortFieldType,
        java.lang.Object sortOrder,
        java.lang.Object fieldNumber2,
        java.lang.Object sortFieldType2,
        java.lang.Object sortOrder2,
        java.lang.Object fieldNumber3,
        java.lang.Object sortFieldType3,
        java.lang.Object sortOrder3,
        java.lang.Object caseSensitive,
        java.lang.Object bidiSort,
        java.lang.Object ignoreThe,
        java.lang.Object ignoreKashida,
        java.lang.Object ignoreDiacritics,
        java.lang.Object ignoreHe,
        java.lang.Object languageID);

    @VTID(31)
    mol.word.Tables tables();

    @VTID(31)
    @ReturnValue(defaultPropertyThrough={mol.word.Tables.class})
    mol.word.Table tables(
        int index);

    @VTID(32)
    int nestingLevel();

    @VTID(33)
    boolean allowPageBreaks();

    @VTID(34)
    void allowPageBreaks(
        boolean prop);

    @VTID(35)
    boolean allowAutoFit();

    @VTID(36)
    void allowAutoFit(
        boolean prop);

    @VTID(37)
    float preferredWidth();

    @VTID(38)
    void preferredWidth(
        float prop);

    @VTID(39)
    mol.word.WdPreferredWidthType preferredWidthType();

    @VTID(40)
    void preferredWidthType(
        mol.word.WdPreferredWidthType prop);

    @VTID(41)
    float topPadding();

    @VTID(42)
    void topPadding(
        float prop);

    @VTID(43)
    float bottomPadding();

    @VTID(44)
    void bottomPadding(
        float prop);

    @VTID(45)
    float leftPadding();

    @VTID(46)
    void leftPadding(
        float prop);

    @VTID(47)
    float rightPadding();

    @VTID(48)
    void rightPadding(
        float prop);

    @VTID(49)
    float spacing();

    @VTID(50)
    void spacing(
        float prop);

    @VTID(51)
    mol.word.WdTableDirection tableDirection();

    @VTID(52)
    void tableDirection(
        mol.word.WdTableDirection prop);

    @VTID(53)
    java.lang.String id();

    @VTID(54)
    void id(
        java.lang.String prop);

    @VTID(55)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object style();

    @VTID(56)
    void style(
        java.lang.Object prop);

    @VTID(57)
    boolean applyStyleHeadingRows();

    @VTID(58)
    void applyStyleHeadingRows(
        boolean prop);

    @VTID(59)
    boolean applyStyleLastRow();

    @VTID(60)
    void applyStyleLastRow(
        boolean prop);

    @VTID(61)
    boolean applyStyleFirstColumn();

    @VTID(62)
    void applyStyleFirstColumn(
        boolean prop);

    @VTID(63)
    boolean applyStyleLastColumn();

    @VTID(64)
    void applyStyleLastColumn(
        boolean prop);

    @VTID(65)
    boolean applyStyleRowBands();

    @VTID(66)
    void applyStyleRowBands(
        boolean prop);

    @VTID(67)
    boolean applyStyleColumnBands();

    @VTID(68)
    void applyStyleColumnBands(
        boolean prop);

    @VTID(69)
    void applyStyleDirectFormatting(
        java.lang.String styleName);

}
