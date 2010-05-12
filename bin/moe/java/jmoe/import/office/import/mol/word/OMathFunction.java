package mol.word  ;

import com4j.*;

@IID("{F1F37152-1DB1-4901-AD9A-C740F99464B4}")
public interface OMathFunction extends Com4jObject {
    @VTID(7)
    @DefaultMethod
    mol.word.WdOMathFunctionType type();

    @VTID(8)
    mol.word._Application application();

    @VTID(9)
    int creator();

    @VTID(10)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

    @VTID(11)
    mol.word.Range range();

    @VTID(12)
    mol.word.OMathArgs args();

    @VTID(12)
    @ReturnValue(defaultPropertyThrough={mol.word.OMathArgs.class})
    mol.word.OMath args(
        int index);

    @VTID(13)
    mol.word.OMathAcc acc();

    @VTID(14)
    mol.word.OMathBar bar();

    @VTID(15)
    mol.word.OMathBox box();

    @VTID(16)
    mol.word.OMathBorderBox borderBox();

    @VTID(17)
    mol.word.OMathDelim delim();

    @VTID(18)
    mol.word.OMathEqArray eqArray();

    @VTID(19)
    mol.word.OMathFrac frac();

    @VTID(20)
    mol.word.OMathFunc func();

    @VTID(21)
    mol.word.OMathGroupChar groupChar();

    @VTID(22)
    mol.word.OMathLimLow limLow();

    @VTID(23)
    mol.word.OMathLimUpp limUpp();

    @VTID(24)
    mol.word.OMathMat mat();

    @VTID(25)
    mol.word.OMathNary nary();

    @VTID(26)
    mol.word.OMathPhantom phantom();

    @VTID(27)
    mol.word.OMathScrPre scrPre();

    @VTID(28)
    mol.word.OMathRad rad();

    @VTID(29)
    mol.word.OMathScrSub scrSub();

    @VTID(30)
    mol.word.OMathScrSubSup scrSubSup();

    @VTID(31)
    mol.word.OMathScrSup scrSup();

    @VTID(32)
    mol.word.OMath oMath();

    @VTID(33)
    mol.word.OMathFunction remove();

}
