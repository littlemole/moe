package mol.word  ;

import com4j.*;

@IID("{B7564E97-0519-4C68-B400-3803E7C63242}")
public interface TableStyle extends Com4jObject {
    @VTID(7)
    mol.word._Application application();

    @VTID(8)
    int creator();

    @VTID(9)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

    @VTID(10)
    boolean allowPageBreaks();

    @VTID(11)
    void allowPageBreaks(
        boolean prop);

    @VTID(12)
    mol.word.Borders borders();

    @VTID(12)
    @ReturnValue(defaultPropertyThrough={mol.word.Borders.class})
    mol.word.Border borders(
        mol.word.WdBorderType index);

    @VTID(13)
    void borders(
        mol.word.Borders prop);

    @VTID(14)
    float bottomPadding();

    @VTID(15)
    void bottomPadding(
        float prop);

    @VTID(16)
    float leftPadding();

    @VTID(17)
    void leftPadding(
        float prop);

    @VTID(18)
    float topPadding();

    @VTID(19)
    void topPadding(
        float prop);

    @VTID(20)
    float rightPadding();

    @VTID(21)
    void rightPadding(
        float prop);

    @VTID(22)
    mol.word.WdRowAlignment alignment();

    @VTID(23)
    void alignment(
        mol.word.WdRowAlignment prop);

    @VTID(24)
    float spacing();

    @VTID(25)
    void spacing(
        float prop);

    @VTID(26)
    mol.word.ConditionalStyle condition(
        mol.word.WdConditionCode conditionCode);

    @VTID(27)
    mol.word.WdTableDirection tableDirection();

    @VTID(28)
    void tableDirection(
        mol.word.WdTableDirection prop);

    @VTID(29)
    int allowBreakAcrossPage();

    @VTID(30)
    void allowBreakAcrossPage(
        int prop);

    @VTID(31)
    float leftIndent();

    @VTID(32)
    void leftIndent(
        float prop);

    @VTID(33)
    mol.word.Shading shading();

    @VTID(34)
    int rowStripe();

    @VTID(35)
    void rowStripe(
        int prop);

    @VTID(36)
    int columnStripe();

    @VTID(37)
    void columnStripe(
        int prop);

}
