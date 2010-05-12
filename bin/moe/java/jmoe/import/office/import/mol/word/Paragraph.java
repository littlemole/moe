package mol.word  ;

import com4j.*;

@IID("{00020957-0000-0000-C000-000000000046}")
public interface Paragraph extends Com4jObject {
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
    mol.word._ParagraphFormat format();

    @VTID(12)
    void format(
        mol.word._ParagraphFormat prop);

    @VTID(13)
    mol.word.TabStops tabStops();

    @VTID(13)
    @ReturnValue(defaultPropertyThrough={mol.word.TabStops.class})
    mol.word.TabStop tabStops(
        java.lang.Object index);

    @VTID(14)
    void tabStops(
        mol.word.TabStops prop);

    @VTID(15)
    mol.word.Borders borders();

    @VTID(15)
    @ReturnValue(defaultPropertyThrough={mol.word.Borders.class})
    mol.word.Border borders(
        mol.word.WdBorderType index);

    @VTID(16)
    void borders(
        mol.word.Borders prop);

    @VTID(17)
    mol.word.DropCap dropCap();

    @VTID(18)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object style();

    @VTID(19)
    void style(
        java.lang.Object prop);

    @VTID(20)
    mol.word.WdParagraphAlignment alignment();

    @VTID(21)
    void alignment(
        mol.word.WdParagraphAlignment prop);

    @VTID(22)
    int keepTogether();

    @VTID(23)
    void keepTogether(
        int prop);

    @VTID(24)
    int keepWithNext();

    @VTID(25)
    void keepWithNext(
        int prop);

    @VTID(26)
    int pageBreakBefore();

    @VTID(27)
    void pageBreakBefore(
        int prop);

    @VTID(28)
    int noLineNumber();

    @VTID(29)
    void noLineNumber(
        int prop);

    @VTID(30)
    float rightIndent();

    @VTID(31)
    void rightIndent(
        float prop);

    @VTID(32)
    float leftIndent();

    @VTID(33)
    void leftIndent(
        float prop);

    @VTID(34)
    float firstLineIndent();

    @VTID(35)
    void firstLineIndent(
        float prop);

    @VTID(36)
    float lineSpacing();

    @VTID(37)
    void lineSpacing(
        float prop);

    @VTID(38)
    mol.word.WdLineSpacing lineSpacingRule();

    @VTID(39)
    void lineSpacingRule(
        mol.word.WdLineSpacing prop);

    @VTID(40)
    float spaceBefore();

    @VTID(41)
    void spaceBefore(
        float prop);

    @VTID(42)
    float spaceAfter();

    @VTID(43)
    void spaceAfter(
        float prop);

    @VTID(44)
    int hyphenation();

    @VTID(45)
    void hyphenation(
        int prop);

    @VTID(46)
    int widowControl();

    @VTID(47)
    void widowControl(
        int prop);

    @VTID(48)
    mol.word.Shading shading();

    @VTID(49)
    int farEastLineBreakControl();

    @VTID(50)
    void farEastLineBreakControl(
        int prop);

    @VTID(51)
    int wordWrap();

    @VTID(52)
    void wordWrap(
        int prop);

    @VTID(53)
    int hangingPunctuation();

    @VTID(54)
    void hangingPunctuation(
        int prop);

    @VTID(55)
    int halfWidthPunctuationOnTopOfLine();

    @VTID(56)
    void halfWidthPunctuationOnTopOfLine(
        int prop);

    @VTID(57)
    int addSpaceBetweenFarEastAndAlpha();

    @VTID(58)
    void addSpaceBetweenFarEastAndAlpha(
        int prop);

    @VTID(59)
    int addSpaceBetweenFarEastAndDigit();

    @VTID(60)
    void addSpaceBetweenFarEastAndDigit(
        int prop);

    @VTID(61)
    mol.word.WdBaselineAlignment baseLineAlignment();

    @VTID(62)
    void baseLineAlignment(
        mol.word.WdBaselineAlignment prop);

    @VTID(63)
    int autoAdjustRightIndent();

    @VTID(64)
    void autoAdjustRightIndent(
        int prop);

    @VTID(65)
    int disableLineHeightGrid();

    @VTID(66)
    void disableLineHeightGrid(
        int prop);

    @VTID(67)
    mol.word.WdOutlineLevel outlineLevel();

    @VTID(68)
    void outlineLevel(
        mol.word.WdOutlineLevel prop);

    @VTID(69)
    void closeUp();

    @VTID(70)
    void openUp();

    @VTID(71)
    void openOrCloseUp();

    @VTID(72)
    void tabHangingIndent(
        short count);

    @VTID(73)
    void tabIndent(
        short count);

    @VTID(74)
    void reset();

    @VTID(75)
    void space1();

    @VTID(76)
    void space15();

    @VTID(77)
    void space2();

    @VTID(78)
    void indentCharWidth(
        short count);

    @VTID(79)
    void indentFirstLineCharWidth(
        short count);

    @VTID(80)
    mol.word.Paragraph next(
        java.lang.Object count);

    @VTID(81)
    mol.word.Paragraph previous(
        java.lang.Object count);

    @VTID(82)
    void outlinePromote();

    @VTID(83)
    void outlineDemote();

    @VTID(84)
    void outlineDemoteToBody();

    @VTID(85)
    void indent();

    @VTID(86)
    void outdent();

    @VTID(87)
    float characterUnitRightIndent();

    @VTID(88)
    void characterUnitRightIndent(
        float prop);

    @VTID(89)
    float characterUnitLeftIndent();

    @VTID(90)
    void characterUnitLeftIndent(
        float prop);

    @VTID(91)
    float characterUnitFirstLineIndent();

    @VTID(92)
    void characterUnitFirstLineIndent(
        float prop);

    @VTID(93)
    float lineUnitBefore();

    @VTID(94)
    void lineUnitBefore(
        float prop);

    @VTID(95)
    float lineUnitAfter();

    @VTID(96)
    void lineUnitAfter(
        float prop);

    @VTID(97)
    mol.word.WdReadingOrder readingOrder();

    @VTID(98)
    void readingOrder(
        mol.word.WdReadingOrder prop);

    @VTID(99)
    java.lang.String id();

    @VTID(100)
    void id(
        java.lang.String prop);

    @VTID(101)
    int spaceBeforeAuto();

    @VTID(102)
    void spaceBeforeAuto(
        int prop);

    @VTID(103)
    int spaceAfterAuto();

    @VTID(104)
    void spaceAfterAuto(
        int prop);

    @VTID(105)
    boolean isStyleSeparator();

    @VTID(106)
    void selectNumber();

    @VTID(107)
    void listAdvanceTo(
        short level1,
        short level2,
        short level3,
        short level4,
        short level5,
        short level6,
        short level7,
        short level8,
        short level9);

    @VTID(108)
    void resetAdvanceTo();

    @VTID(109)
    void separateList();

    @VTID(110)
    void joinList();

    @VTID(111)
    int mirrorIndents();

    @VTID(112)
    void mirrorIndents(
        int prop);

    @VTID(113)
    mol.word.WdTextboxTightWrap textboxTightWrap();

    @VTID(114)
    void textboxTightWrap(
        mol.word.WdTextboxTightWrap prop);

    @VTID(115)
    short listNumberOriginal(
        short level);

}
