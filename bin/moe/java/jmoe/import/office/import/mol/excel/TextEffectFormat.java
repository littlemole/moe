package mol.excel  ;

import com4j.*;
import mol.office.*;
import mol.vba.*;

@IID("{000C031F-0000-0000-C000-000000000046}")
public interface TextEffectFormat extends mol.office._IMsoDispObj {
    @VTID(9)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

    @VTID(10)
    void toggleVerticalText();

    @VTID(11)
    mol.office.MsoTextEffectAlignment alignment();

    @VTID(12)
    void alignment(
        mol.office.MsoTextEffectAlignment alignment);

    @VTID(13)
    mol.office.MsoTriState fontBold();

    @VTID(14)
    void fontBold(
        mol.office.MsoTriState fontBold);

    @VTID(15)
    mol.office.MsoTriState fontItalic();

    @VTID(16)
    void fontItalic(
        mol.office.MsoTriState fontItalic);

    @VTID(17)
    java.lang.String fontName();

    @VTID(18)
    void fontName(
        java.lang.String fontName);

    @VTID(19)
    float fontSize();

    @VTID(20)
    void fontSize(
        float fontSize);

    @VTID(21)
    mol.office.MsoTriState kernedPairs();

    @VTID(22)
    void kernedPairs(
        mol.office.MsoTriState kernedPairs);

    @VTID(23)
    mol.office.MsoTriState normalizedHeight();

    @VTID(24)
    void normalizedHeight(
        mol.office.MsoTriState normalizedHeight);

    @VTID(25)
    mol.office.MsoPresetTextEffectShape presetShape();

    @VTID(26)
    void presetShape(
        mol.office.MsoPresetTextEffectShape presetShape);

    @VTID(27)
    mol.office.MsoPresetTextEffect presetTextEffect();

    @VTID(28)
    void presetTextEffect(
        mol.office.MsoPresetTextEffect preset);

    @VTID(29)
    mol.office.MsoTriState rotatedChars();

    @VTID(30)
    void rotatedChars(
        mol.office.MsoTriState rotatedChars);

    @VTID(31)
    java.lang.String text();

    @VTID(32)
    void text(
        java.lang.String text);

    @VTID(33)
    float tracking();

    @VTID(34)
    void tracking(
        float tracking);

}
