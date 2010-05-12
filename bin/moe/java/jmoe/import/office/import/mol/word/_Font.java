package mol.word  ;

import com4j.*;

@IID("{00020952-0000-0000-C000-000000000046}")
public interface _Font extends Com4jObject {
    @VTID(7)
    mol.word._Application application();

    @VTID(8)
    int creator();

    @VTID(9)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

    @VTID(10)
    mol.word._Font duplicate();

    @VTID(11)
    int bold();

    @VTID(12)
    void bold(
        int prop);

    @VTID(13)
    int italic();

    @VTID(14)
    void italic(
        int prop);

    @VTID(15)
    int hidden();

    @VTID(16)
    void hidden(
        int prop);

    @VTID(17)
    int smallCaps();

    @VTID(18)
    void smallCaps(
        int prop);

    @VTID(19)
    int allCaps();

    @VTID(20)
    void allCaps(
        int prop);

    @VTID(21)
    int strikeThrough();

    @VTID(22)
    void strikeThrough(
        int prop);

    @VTID(23)
    int doubleStrikeThrough();

    @VTID(24)
    void doubleStrikeThrough(
        int prop);

    @VTID(25)
    mol.word.WdColorIndex colorIndex();

    @VTID(26)
    void colorIndex(
        mol.word.WdColorIndex prop);

    @VTID(27)
    int subscript();

    @VTID(28)
    void subscript(
        int prop);

    @VTID(29)
    int superscript();

    @VTID(30)
    void superscript(
        int prop);

    @VTID(31)
    mol.word.WdUnderline underline();

    @VTID(32)
    void underline(
        mol.word.WdUnderline prop);

    @VTID(33)
    float size();

    @VTID(34)
    void size(
        float prop);

    @VTID(35)
    java.lang.String name();

    @VTID(36)
    void name(
        java.lang.String prop);

    @VTID(37)
    int position();

    @VTID(38)
    void position(
        int prop);

    @VTID(39)
    float spacing();

    @VTID(40)
    void spacing(
        float prop);

    @VTID(41)
    int scaling();

    @VTID(42)
    void scaling(
        int prop);

    @VTID(43)
    int shadow();

    @VTID(44)
    void shadow(
        int prop);

    @VTID(45)
    int outline();

    @VTID(46)
    void outline(
        int prop);

    @VTID(47)
    int emboss();

    @VTID(48)
    void emboss(
        int prop);

    @VTID(49)
    float kerning();

    @VTID(50)
    void kerning(
        float prop);

    @VTID(51)
    int engrave();

    @VTID(52)
    void engrave(
        int prop);

    @VTID(53)
    mol.word.WdAnimation animation();

    @VTID(54)
    void animation(
        mol.word.WdAnimation prop);

    @VTID(55)
    mol.word.Borders borders();

    @VTID(55)
    @ReturnValue(defaultPropertyThrough={mol.word.Borders.class})
    mol.word.Border borders(
        mol.word.WdBorderType index);

    @VTID(56)
    void borders(
        mol.word.Borders prop);

    @VTID(57)
    mol.word.Shading shading();

    @VTID(58)
    mol.word.WdEmphasisMark emphasisMark();

    @VTID(59)
    void emphasisMark(
        mol.word.WdEmphasisMark prop);

    @VTID(60)
    boolean disableCharacterSpaceGrid();

    @VTID(61)
    void disableCharacterSpaceGrid(
        boolean prop);

    @VTID(62)
    java.lang.String nameFarEast();

    @VTID(63)
    void nameFarEast(
        java.lang.String prop);

    @VTID(64)
    java.lang.String nameAscii();

    @VTID(65)
    void nameAscii(
        java.lang.String prop);

    @VTID(66)
    java.lang.String nameOther();

    @VTID(67)
    void nameOther(
        java.lang.String prop);

    @VTID(68)
    void grow();

    @VTID(69)
    void shrink();

    @VTID(70)
    void reset();

    @VTID(71)
    void setAsTemplateDefault();

    @VTID(72)
    mol.word.WdColor color();

    @VTID(73)
    void color(
        mol.word.WdColor prop);

    @VTID(74)
    int boldBi();

    @VTID(75)
    void boldBi(
        int prop);

    @VTID(76)
    int italicBi();

    @VTID(77)
    void italicBi(
        int prop);

    @VTID(78)
    float sizeBi();

    @VTID(79)
    void sizeBi(
        float prop);

    @VTID(80)
    java.lang.String nameBi();

    @VTID(81)
    void nameBi(
        java.lang.String prop);

    @VTID(82)
    mol.word.WdColorIndex colorIndexBi();

    @VTID(83)
    void colorIndexBi(
        mol.word.WdColorIndex prop);

    @VTID(84)
    mol.word.WdColor diacriticColor();

    @VTID(85)
    void diacriticColor(
        mol.word.WdColor prop);

    @VTID(86)
    mol.word.WdColor underlineColor();

    @VTID(87)
    void underlineColor(
        mol.word.WdColor prop);

}
