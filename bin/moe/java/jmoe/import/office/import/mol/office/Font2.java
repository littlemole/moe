package mol.office  ;

import com4j.*;

@IID("{000C039A-0000-0000-C000-000000000046}")
public interface Font2 extends mol.office._IMsoDispObj {
    @VTID(9)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

    @VTID(10)
    mol.office.MsoTriState bold();

    @VTID(11)
    void bold(
        mol.office.MsoTriState bold);

    @VTID(12)
    mol.office.MsoTriState italic();

    @VTID(13)
    void italic(
        mol.office.MsoTriState italic);

    @VTID(14)
    mol.office.MsoTextStrike strike();

    @VTID(15)
    void strike(
        mol.office.MsoTextStrike strike);

    @VTID(16)
    mol.office.MsoTextCaps caps();

    @VTID(17)
    void caps(
        mol.office.MsoTextCaps caps);

    @VTID(18)
    mol.office.MsoTriState autorotateNumbers();

    @VTID(19)
    void autorotateNumbers(
        mol.office.MsoTriState rotateNumbers);

    @VTID(20)
    float baselineOffset();

    @VTID(21)
    void baselineOffset(
        float offset);

    @VTID(22)
    float kerning();

    @VTID(23)
    void kerning(
        float kerningSize);

    @VTID(24)
    float size();

    @VTID(25)
    void size(
        float size);

    @VTID(26)
    float spacing();

    @VTID(27)
    void spacing(
        float spacing);

    @VTID(28)
    mol.office.MsoTextUnderlineType underlineStyle();

    @VTID(29)
    void underlineStyle(
        mol.office.MsoTextUnderlineType style);

    @VTID(30)
    mol.office.MsoTriState allcaps();

    @VTID(31)
    void allcaps(
        mol.office.MsoTriState allcaps);

    @VTID(32)
    mol.office.MsoTriState doubleStrikeThrough();

    @VTID(33)
    void doubleStrikeThrough(
        mol.office.MsoTriState doubleStrikeThrough);

    @VTID(34)
    mol.office.MsoTriState equalize();

    @VTID(35)
    void equalize(
        mol.office.MsoTriState equalize);

    @VTID(36)
    mol.office.FillFormat fill();

    @VTID(37)
    mol.office.GlowFormat glow();

    @VTID(38)
    mol.office.ReflectionFormat reflection();

    @VTID(39)
    mol.office.LineFormat line();

    @VTID(40)
    mol.office.ShadowFormat shadow();

    @VTID(41)
    mol.office.ColorFormat highlight();

    @VTID(42)
    mol.office.ColorFormat underlineColor();

    @VTID(43)
    mol.office.MsoTriState smallcaps();

    @VTID(44)
    void smallcaps(
        mol.office.MsoTriState smallcaps);

    @VTID(45)
    mol.office.MsoSoftEdgeType softEdgeFormat();

    @VTID(46)
    void softEdgeFormat(
        mol.office.MsoSoftEdgeType softEdgeFormat);

    @VTID(47)
    mol.office.MsoTriState strikeThrough();

    @VTID(48)
    void strikeThrough(
        mol.office.MsoTriState strikeThrough);

    @VTID(49)
    mol.office.MsoTriState subscript();

    @VTID(50)
    void subscript(
        mol.office.MsoTriState subscript);

    @VTID(51)
    mol.office.MsoTriState superscript();

    @VTID(52)
    void superscript(
        mol.office.MsoTriState superscript);

    @VTID(53)
    mol.office.MsoPresetTextEffect wordArtformat();

    @VTID(54)
    void wordArtformat(
        mol.office.MsoPresetTextEffect wordArtformat);

    @VTID(55)
    mol.office.MsoTriState embeddable();

    @VTID(56)
    mol.office.MsoTriState embedded();

    @VTID(57)
    java.lang.String name();

    @VTID(58)
    void name(
        java.lang.String name);

    @VTID(59)
    java.lang.String nameAscii();

    @VTID(60)
    void nameAscii(
        java.lang.String nameAscii);

    @VTID(61)
    java.lang.String nameComplexScript();

    @VTID(62)
    void nameComplexScript(
        java.lang.String nameComplexScript);

    @VTID(63)
    java.lang.String nameFarEast();

    @VTID(64)
    void nameFarEast(
        java.lang.String nameFarEast);

    @VTID(65)
    java.lang.String nameOther();

    @VTID(66)
    void nameOther(
        java.lang.String nameOther);

}
