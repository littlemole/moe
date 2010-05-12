package mol.word  ;

import com4j.*;

public enum WdOMathFunctionType implements ComEnum {
    wdOMathFunctionAcc(1),
    wdOMathFunctionBar(2),
    wdOMathFunctionBox(3),
    wdOMathFunctionBorderBox(4),
    wdOMathFunctionDelim(5),
    wdOMathFunctionEqArray(6),
    wdOMathFunctionFrac(7),
    wdOMathFunctionFunc(8),
    wdOMathFunctionGroupChar(9),
    wdOMathFunctionLimLow(10),
    wdOMathFunctionLimUpp(11),
    wdOMathFunctionMat(12),
    wdOMathFunctionNary(13),
    wdOMathFunctionPhantom(14),
    wdOMathFunctionScrPre(15),
    wdOMathFunctionRad(16),
    wdOMathFunctionScrSub(17),
    wdOMathFunctionScrSubSup(18),
    wdOMathFunctionScrSup(19),
    wdOMathFunctionText(20),
    wdOMathFunctionNormalText(21),
    wdOMathFunctionLiteralText(22),
    ;

    private final int value;
    WdOMathFunctionType(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
