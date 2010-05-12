package mol.word  ;

import com4j.*;

@IID("{2503B6EE-0889-44DF-B920-6D6F9659DEA3}")
public interface OMathBorderBox extends Com4jObject {
    @VTID(7)
    mol.word._Application application();

    @VTID(8)
    int creator();

    @VTID(9)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

    @VTID(10)
    mol.word.OMath e();

    @VTID(11)
    boolean hideTop();

    @VTID(12)
    void hideTop(
        boolean prop);

    @VTID(13)
    boolean hideBot();

    @VTID(14)
    void hideBot(
        boolean prop);

    @VTID(15)
    boolean hideLeft();

    @VTID(16)
    void hideLeft(
        boolean prop);

    @VTID(17)
    boolean hideRight();

    @VTID(18)
    void hideRight(
        boolean prop);

    @VTID(19)
    boolean strikeH();

    @VTID(20)
    void strikeH(
        boolean prop);

    @VTID(21)
    boolean strikeV();

    @VTID(22)
    void strikeV(
        boolean prop);

    @VTID(23)
    boolean strikeBLTR();

    @VTID(24)
    void strikeBLTR(
        boolean prop);

    @VTID(25)
    boolean strikeTLBR();

    @VTID(26)
    void strikeTLBR(
        boolean prop);

}
