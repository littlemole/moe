package mol.word  ;

import com4j.*;

@IID("{00020958-0000-0000-C000-000000000046}")
public interface Paragraphs extends Com4jObject,Iterable<Com4jObject> {
    @VTID(7)
    java.util.Iterator<Com4jObject> iterator();

    @VTID(8)
    int count();

    @VTID(9)
    mol.word.Paragraph first();

    @VTID(10)
    mol.word.Paragraph last();

    @VTID(11)
    mol.word._Application application();

    @VTID(12)
    int creator();

    @VTID(13)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

    @VTID(14)
    mol.word._ParagraphFormat format();

    @VTID(15)
    void format(
        mol.word._ParagraphFormat prop);

    @VTID(16)
    mol.word.TabStops tabStops();

    @VTID(16)
    @ReturnValue(defaultPropertyThrough={mol.word.TabStops.class})
    mol.word.TabStop tabStops(
        java.lang.Object index);

    @VTID(17)
    void tabStops(
        mol.word.TabStops prop);

    @VTID(18)
    mol.word.Borders borders();

    @VTID(18)
    @ReturnValue(defaultPropertyThrough={mol.word.Borders.class})
    mol.word.Border borders(
        mol.word.WdBorderType index);

    @VTID(19)
    void borders(
        mol.word.Borders prop);

    @VTID(20)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object style();

    @VTID(21)
    void style(
        java.lang.Object prop);

    @VTID(22)
    mol.word.WdParagraphAlignment alignment();

    @VTID(23)
    void alignment(
        mol.word.WdParagraphAlignment prop);

    @VTID(24)
    int keepTogether();

    @VTID(25)
    void keepTogether(
        int prop);

    @VTID(26)
    int keepWithNext();

    @VTID(27)
    void keepWithNext(
        int prop);

    @VTID(28)
    int pageBreakBefore();

    @VTID(29)
    void pageBreakBefore(
        int prop);

    @VTID(30)
    int noLineNumber();

    @VTID(31)
    void noLineNumber(
        int prop);

    @VTID(32)
    float rightIndent();

    @VTID(33)
    void rightIndent(
        float prop);

    @VTID(34)
    float leftIndent();

    @VTID(35)
    void leftIndent(
        float prop);

    @VTID(36)
    float firstLineIndent();

    @VTID(37)
    void firstLineIndent(
        float prop);

    @VTID(38)
    float lineSpacing();

    @VTID(39)
    void lineSpacing(
        float prop);

    @VTID(40)
    mol.word.WdLineSpacing lineSpacingRule();

    @VTID(41)
    void lineSpacingRule(
        mol.word.WdLineSpacing prop);

    @VTID(42)
    float spaceBefore();

    @VTID(43)
    void spaceBefore(
        float prop);

    @VTID(44)
    float spaceAfter();

    @VTID(45)
    void spaceAfter(
        float prop);

    @VTID(46)
    int hyphenation();

    @VTID(47)
    void hyphenation(
        int prop);

    @VTID(48)
    int widowControl();

    @VTID(49)
    void widowControl(
        int prop);

    @VTID(50)
    mol.word.Shading shading();

    @VTID(51)
    int farEastLineBreakControl();

    @VTID(52)
    void farEastLineBreakControl(
        int prop);

    @VTID(53)
    int wordWrap();

    @VTID(54)
    void wordWrap(
        int prop);

    @VTID(55)
    int hangingPunctuation();

    @VTID(56)
    void hangingPunctuation(
        int prop);

    @VTID(57)
    int halfWidthPunctuationOnTopOfLine();

    @VTID(58)
    void halfWidthPunctuationOnTopOfLine(
        int prop);

    @VTID(59)
    int addSpaceBetweenFarEastAndAlpha();

    @VTID(60)
    void addSpaceBetweenFarEastAndAlpha(
        int prop);

    @VTID(61)
    int addSpaceBetweenFarEastAndDigit();

    @VTID(62)
    void addSpaceBetweenFarEastAndDigit(
        int prop);

    @VTID(63)
    mol.word.WdBaselineAlignment baseLineAlignment();

    @VTID(64)
    void baseLineAlignment(
        mol.word.WdBaselineAlignment prop);

    @VTID(65)
    int autoAdjustRightIndent();

    @VTID(66)
    void autoAdjustRightIndent(
        int prop);

    @VTID(67)
    int disableLineHeightGrid();

    @VTID(68)
    void disableLineHeightGrid(
        int prop);

    @VTID(69)
    mol.word.WdOutlineLevel outlineLevel();

    @VTID(70)
    void outlineLevel(
        mol.word.WdOutlineLevel prop);

    @VTID(71)
    @DefaultMethod
    mol.word.Paragraph item(
        int index);

    @VTID(72)
    mol.word.Paragraph add(
        java.lang.Object range);

    @VTID(73)
    void closeUp();

    @VTID(74)
    void openUp();

    @VTID(75)
    void openOrCloseUp();

    @VTID(76)
    void tabHangingIndent(
        short count);

    @VTID(77)
    void tabIndent(
        short count);

    @VTID(78)
    void reset();

    @VTID(79)
    void space1();

    @VTID(80)
    void space15();

    @VTID(81)
    void space2();

    @VTID(82)
    void indentCharWidth(
        short count);

    @VTID(83)
    void indentFirstLineCharWidth(
        short count);

    @VTID(84)
    void outlinePromote();

    @VTID(85)
    void outlineDemote();

    @VTID(86)
    void outlineDemoteToBody();

    @VTID(87)
    void indent();

    @VTID(88)
    void outdent();

    @VTID(89)
    float characterUnitRightIndent();

    @VTID(90)
    void characterUnitRightIndent(
        float prop);

    @VTID(91)
    float characterUnitLeftIndent();

    @VTID(92)
    void characterUnitLeftIndent(
        float prop);

    @VTID(93)
    float characterUnitFirstLineIndent();

    @VTID(94)
    void characterUnitFirstLineIndent(
        float prop);

    @VTID(95)
    float lineUnitBefore();

    @VTID(96)
    void lineUnitBefore(
        float prop);

    @VTID(97)
    float lineUnitAfter();

    @VTID(98)
    void lineUnitAfter(
        float prop);

    @VTID(99)
    mol.word.WdReadingOrder readingOrder();

    @VTID(100)
    void readingOrder(
        mol.word.WdReadingOrder prop);

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
    void increaseSpacing();

    @VTID(106)
    void decreaseSpacing();

}
