package mol.word  ;

import com4j.*;

@IID("{00020953-0000-0000-C000-000000000046}")
public interface _ParagraphFormat extends Com4jObject {
    @VTID(7)
    mol.word._Application application();

    @VTID(8)
    int creator();

    @VTID(9)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

    @VTID(10)
    mol.word._ParagraphFormat duplicate();

    @VTID(11)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object style();

    @VTID(12)
    void style(
        java.lang.Object prop);

    @VTID(13)
    mol.word.WdParagraphAlignment alignment();

    @VTID(14)
    void alignment(
        mol.word.WdParagraphAlignment prop);

    @VTID(15)
    int keepTogether();

    @VTID(16)
    void keepTogether(
        int prop);

    @VTID(17)
    int keepWithNext();

    @VTID(18)
    void keepWithNext(
        int prop);

    @VTID(19)
    int pageBreakBefore();

    @VTID(20)
    void pageBreakBefore(
        int prop);

    @VTID(21)
    int noLineNumber();

    @VTID(22)
    void noLineNumber(
        int prop);

    @VTID(23)
    float rightIndent();

    @VTID(24)
    void rightIndent(
        float prop);

    @VTID(25)
    float leftIndent();

    @VTID(26)
    void leftIndent(
        float prop);

    @VTID(27)
    float firstLineIndent();

    @VTID(28)
    void firstLineIndent(
        float prop);

    @VTID(29)
    float lineSpacing();

    @VTID(30)
    void lineSpacing(
        float prop);

    @VTID(31)
    mol.word.WdLineSpacing lineSpacingRule();

    @VTID(32)
    void lineSpacingRule(
        mol.word.WdLineSpacing prop);

    @VTID(33)
    float spaceBefore();

    @VTID(34)
    void spaceBefore(
        float prop);

    @VTID(35)
    float spaceAfter();

    @VTID(36)
    void spaceAfter(
        float prop);

    @VTID(37)
    int hyphenation();

    @VTID(38)
    void hyphenation(
        int prop);

    @VTID(39)
    int widowControl();

    @VTID(40)
    void widowControl(
        int prop);

    @VTID(41)
    int farEastLineBreakControl();

    @VTID(42)
    void farEastLineBreakControl(
        int prop);

    @VTID(43)
    int wordWrap();

    @VTID(44)
    void wordWrap(
        int prop);

    @VTID(45)
    int hangingPunctuation();

    @VTID(46)
    void hangingPunctuation(
        int prop);

    @VTID(47)
    int halfWidthPunctuationOnTopOfLine();

    @VTID(48)
    void halfWidthPunctuationOnTopOfLine(
        int prop);

    @VTID(49)
    int addSpaceBetweenFarEastAndAlpha();

    @VTID(50)
    void addSpaceBetweenFarEastAndAlpha(
        int prop);

    @VTID(51)
    int addSpaceBetweenFarEastAndDigit();

    @VTID(52)
    void addSpaceBetweenFarEastAndDigit(
        int prop);

    @VTID(53)
    mol.word.WdBaselineAlignment baseLineAlignment();

    @VTID(54)
    void baseLineAlignment(
        mol.word.WdBaselineAlignment prop);

    @VTID(55)
    int autoAdjustRightIndent();

    @VTID(56)
    void autoAdjustRightIndent(
        int prop);

    @VTID(57)
    int disableLineHeightGrid();

    @VTID(58)
    void disableLineHeightGrid(
        int prop);

    @VTID(59)
    mol.word.TabStops tabStops();

    @VTID(59)
    @ReturnValue(defaultPropertyThrough={mol.word.TabStops.class})
    mol.word.TabStop tabStops(
        java.lang.Object index);

    @VTID(60)
    void tabStops(
        mol.word.TabStops prop);

    @VTID(61)
    mol.word.Borders borders();

    @VTID(61)
    @ReturnValue(defaultPropertyThrough={mol.word.Borders.class})
    mol.word.Border borders(
        mol.word.WdBorderType index);

    @VTID(62)
    void borders(
        mol.word.Borders prop);

    @VTID(63)
    mol.word.Shading shading();

    @VTID(64)
    mol.word.WdOutlineLevel outlineLevel();

    @VTID(65)
    void outlineLevel(
        mol.word.WdOutlineLevel prop);

    @VTID(66)
    void closeUp();

    @VTID(67)
    void openUp();

    @VTID(68)
    void openOrCloseUp();

    @VTID(69)
    void tabHangingIndent(
        short count);

    @VTID(70)
    void tabIndent(
        short count);

    @VTID(71)
    void reset();

    @VTID(72)
    void space1();

    @VTID(73)
    void space15();

    @VTID(74)
    void space2();

    @VTID(75)
    void indentCharWidth(
        short count);

    @VTID(76)
    void indentFirstLineCharWidth(
        short count);

    @VTID(77)
    float characterUnitRightIndent();

    @VTID(78)
    void characterUnitRightIndent(
        float prop);

    @VTID(79)
    float characterUnitLeftIndent();

    @VTID(80)
    void characterUnitLeftIndent(
        float prop);

    @VTID(81)
    float characterUnitFirstLineIndent();

    @VTID(82)
    void characterUnitFirstLineIndent(
        float prop);

    @VTID(83)
    float lineUnitBefore();

    @VTID(84)
    void lineUnitBefore(
        float prop);

    @VTID(85)
    float lineUnitAfter();

    @VTID(86)
    void lineUnitAfter(
        float prop);

    @VTID(87)
    mol.word.WdReadingOrder readingOrder();

    @VTID(88)
    void readingOrder(
        mol.word.WdReadingOrder prop);

    @VTID(89)
    int spaceBeforeAuto();

    @VTID(90)
    void spaceBeforeAuto(
        int prop);

    @VTID(91)
    int spaceAfterAuto();

    @VTID(92)
    void spaceAfterAuto(
        int prop);

    @VTID(93)
    int mirrorIndents();

    @VTID(94)
    void mirrorIndents(
        int prop);

    @VTID(95)
    mol.word.WdTextboxTightWrap textboxTightWrap();

    @VTID(96)
    void textboxTightWrap(
        mol.word.WdTextboxTightWrap prop);

}
