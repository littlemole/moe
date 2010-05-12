package mol.word  ;

import com4j.*;

@IID("{1498F56D-ED33-41F9-B37B-EF30E50B08AC}")
public interface ConditionalStyle extends Com4jObject {
    @VTID(7)
    mol.word._Application application();

    @VTID(8)
    int creator();

    @VTID(9)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

    @VTID(10)
    mol.word.Shading shading();

    @VTID(11)
    mol.word.Borders borders();

    @VTID(11)
    @ReturnValue(defaultPropertyThrough={mol.word.Borders.class})
    mol.word.Border borders(
        mol.word.WdBorderType index);

    @VTID(12)
    void borders(
        mol.word.Borders prop);

    @VTID(13)
    float bottomPadding();

    @VTID(14)
    void bottomPadding(
        float prop);

    @VTID(15)
    float topPadding();

    @VTID(16)
    void topPadding(
        float prop);

    @VTID(17)
    float leftPadding();

    @VTID(18)
    void leftPadding(
        float prop);

    @VTID(19)
    float rightPadding();

    @VTID(20)
    void rightPadding(
        float prop);

    @VTID(21)
    mol.word._ParagraphFormat paragraphFormat();

    @VTID(22)
    void paragraphFormat(
        mol.word._ParagraphFormat prop);

    @VTID(23)
    mol.word._Font font();

    @VTID(24)
    void font(
        mol.word._Font prop);

}
