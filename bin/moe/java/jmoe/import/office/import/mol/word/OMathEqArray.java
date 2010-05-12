package mol.word  ;

import com4j.*;

@IID("{1F998A61-71C6-44C2-A0F2-1D66169B47CB}")
public interface OMathEqArray extends Com4jObject {
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
    boolean maxDist();

    @VTID(12)
    void maxDist(
        boolean prop);

    @VTID(13)
    boolean objDist();

    @VTID(14)
    void objDist(
        boolean prop);

    @VTID(15)
    mol.word.WdOMathVertAlignType align();

    @VTID(16)
    void align(
        mol.word.WdOMathVertAlignType prop);

    @VTID(17)
    mol.word.WdOMathSpacingRule rowSpacingRule();

    @VTID(18)
    void rowSpacingRule(
        mol.word.WdOMathSpacingRule prop);

    @VTID(19)
    int rowSpacing();

    @VTID(20)
    void rowSpacing(
        int prop);

}
