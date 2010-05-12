package mol.word  ;

import com4j.*;

@IID("{C94688A6-A2A7-4133-A26D-726CD569D5F3}")
public interface OMathDelim extends Com4jObject {
    @VTID(7)
    mol.word._Application application();

    @VTID(8)
    int creator();

    @VTID(9)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

    @VTID(10)
    mol.word.OMathArgs e();

    @VTID(10)
    @ReturnValue(defaultPropertyThrough={mol.word.OMathArgs.class})
    mol.word.OMath e(
        int index);

    @VTID(11)
    short begChar();

    @VTID(12)
    void begChar(
        short prop);

    @VTID(13)
    short sepChar();

    @VTID(14)
    void sepChar(
        short prop);

    @VTID(15)
    short endChar();

    @VTID(16)
    void endChar(
        short prop);

    @VTID(17)
    boolean grow();

    @VTID(18)
    void grow(
        boolean prop);

    @VTID(19)
    mol.word.WdOMathShapeType shape();

    @VTID(20)
    void shape(
        mol.word.WdOMathShapeType prop);

    @VTID(21)
    boolean noLeftChar();

    @VTID(22)
    void noLeftChar(
        boolean prop);

    @VTID(23)
    boolean noRightChar();

    @VTID(24)
    void noRightChar(
        boolean prop);

}
