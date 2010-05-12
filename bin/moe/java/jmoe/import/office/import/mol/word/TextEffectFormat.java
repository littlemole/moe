package mol.word  ;

import com4j.*;

@IID("{000209CF-0000-0000-C000-000000000046}")
public interface TextEffectFormat extends Com4jObject {
    @VTID(7)
    mol.word._Application application();

    @VTID(8)
    int creator();

    @VTID(9)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

    @VTID(10)
    mol.office.MsoTextEffectAlignment alignment();

    @VTID(11)
    void alignment(
        mol.office.MsoTextEffectAlignment prop);

    @VTID(12)
    mol.office.MsoTriState fontBold();

    @VTID(13)
    void fontBold(
        mol.office.MsoTriState prop);

    @VTID(14)
    mol.office.MsoTriState fontItalic();

    @VTID(15)
    void fontItalic(
        mol.office.MsoTriState prop);

    @VTID(16)
    java.lang.String fontName();

    @VTID(17)
    void fontName(
        java.lang.String prop);

    @VTID(18)
    float fontSize();

    @VTID(19)
    void fontSize(
        float prop);

    @VTID(20)
    mol.office.MsoTriState kernedPairs();

    @VTID(21)
    void kernedPairs(
        mol.office.MsoTriState prop);

    @VTID(22)
    mol.office.MsoTriState normalizedHeight();

    @VTID(23)
    void normalizedHeight(
        mol.office.MsoTriState prop);

    @VTID(24)
    mol.office.MsoPresetTextEffectShape presetShape();

    @VTID(25)
    void presetShape(
        mol.office.MsoPresetTextEffectShape prop);

    @VTID(26)
    mol.office.MsoPresetTextEffect presetTextEffect();

    @VTID(27)
    void presetTextEffect(
        mol.office.MsoPresetTextEffect prop);

    @VTID(28)
    mol.office.MsoTriState rotatedChars();

    @VTID(29)
    void rotatedChars(
        mol.office.MsoTriState prop);

    @VTID(30)
    java.lang.String text();

    @VTID(31)
    void text(
        java.lang.String prop);

    @VTID(32)
    float tracking();

    @VTID(33)
    void tracking(
        float prop);

    @VTID(34)
    void toggleVerticalText();

}
