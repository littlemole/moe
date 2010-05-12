package mol.word  ;

import com4j.*;

@IID("{E4442A83-F623-459C-8E95-8BFB44DCF23A}")
public interface OMath extends Com4jObject {
    @VTID(7)
    mol.word._Application application();

    @VTID(8)
    int creator();

    @VTID(9)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

    @VTID(10)
    mol.word.Range range();

    @VTID(11)
    mol.word.OMathFunctions functions();

    @VTID(11)
    @ReturnValue(defaultPropertyThrough={mol.word.OMathFunctions.class})
    mol.word.OMathFunction functions(
        int index);

    @VTID(12)
    mol.word.WdOMathType type();

    @VTID(13)
    void type(
        mol.word.WdOMathType prop);

    @VTID(14)
    mol.word.OMath parentOMath();

    @VTID(15)
    mol.word.OMathFunction parentFunction();

    @VTID(16)
    mol.word.OMathMatRow parentRow();

    @VTID(17)
    mol.word.OMathMatCol parentCol();

    @VTID(18)
    mol.word.OMath parentArg();

    @VTID(19)
    int argIndex();

    @VTID(20)
    int nestingLevel();

    @VTID(21)
    int argSize();

    @VTID(22)
    void argSize(
        int prop);

    @VTID(23)
    mol.word.OMathBreaks breaks();

    @VTID(23)
    @ReturnValue(defaultPropertyThrough={mol.word.OMathBreaks.class})
    mol.word.OMathBreak breaks(
        int index);

    @VTID(24)
    mol.word.WdOMathJc justification();

    @VTID(25)
    void justification(
        mol.word.WdOMathJc prop);

    @VTID(26)
    int alignPoint();

    @VTID(27)
    void alignPoint(
        int prop);

    @VTID(28)
    void linearize();

    @VTID(29)
    void buildUp();

    @VTID(30)
    void remove();

    @VTID(31)
    void convertToMathText();

    @VTID(32)
    void convertToNormalText();

    @VTID(33)
    void convertToLiteralText();

}
