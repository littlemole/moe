package mol.office  ;

import com4j.*;

@IID("{000C0399-0000-0000-C000-000000000046}")
public interface ParagraphFormat2 extends mol.office._IMsoDispObj {
    @VTID(9)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

    @VTID(10)
    mol.office.MsoParagraphAlignment alignment();

    @VTID(11)
    void alignment(
        mol.office.MsoParagraphAlignment alignment);

    @VTID(12)
    mol.office.MsoBaselineAlignment baselineAlignment();

    @VTID(13)
    void baselineAlignment(
        mol.office.MsoBaselineAlignment baselineAlignment);

    @VTID(14)
    mol.office.BulletFormat2 bullet();

    @VTID(15)
    mol.office.MsoTriState farEastLineBreakLevel();

    @VTID(16)
    void farEastLineBreakLevel(
        mol.office.MsoTriState _break);

    @VTID(17)
    float firstLineIndent();

    @VTID(18)
    void firstLineIndent(
        float indent);

    @VTID(19)
    mol.office.MsoTriState hangingPunctuation();

    @VTID(20)
    void hangingPunctuation(
        mol.office.MsoTriState hanging);

    @VTID(21)
    int indentLevel();

    @VTID(22)
    void indentLevel(
        int level);

    @VTID(23)
    float leftIndent();

    @VTID(24)
    void leftIndent(
        float indent);

    @VTID(25)
    mol.office.MsoTriState lineRuleAfter();

    @VTID(26)
    void lineRuleAfter(
        mol.office.MsoTriState lineRule);

    @VTID(27)
    mol.office.MsoTriState lineRuleBefore();

    @VTID(28)
    void lineRuleBefore(
        mol.office.MsoTriState lineRule);

    @VTID(29)
    mol.office.MsoTriState lineRuleWithin();

    @VTID(30)
    void lineRuleWithin(
        mol.office.MsoTriState lineRule);

    @VTID(31)
    float rightIndent();

    @VTID(32)
    void rightIndent(
        float indent);

    @VTID(33)
    float spaceAfter();

    @VTID(34)
    void spaceAfter(
        float space);

    @VTID(35)
    float spaceBefore();

    @VTID(36)
    void spaceBefore(
        float space);

    @VTID(37)
    float spaceWithin();

    @VTID(38)
    void spaceWithin(
        float space);

    @VTID(39)
    mol.office.TabStops2 tabStops();

    @VTID(39)
    @ReturnValue(defaultPropertyThrough={mol.office.TabStops2.class})
    mol.office.TabStop2 tabStops(
        @MarshalAs(NativeType.VARIANT) java.lang.Object index);

    @VTID(40)
    mol.office.MsoTextDirection textDirection();

    @VTID(41)
    void textDirection(
        mol.office.MsoTextDirection direction);

    @VTID(42)
    mol.office.MsoTriState wordWrap();

    @VTID(43)
    void wordWrap(
        mol.office.MsoTriState wordWrap);

}
