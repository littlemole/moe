package mol.word  ;

import com4j.*;

@IID("{3E061A7E-67AD-4EAA-BC1E-55057D5E596F}")
public interface OMathMat extends Com4jObject {
    @VTID(7)
    mol.word._Application application();

    @VTID(8)
    int creator();

    @VTID(9)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

    @VTID(10)
    mol.word.OMathMatRows rows();

    @VTID(10)
    @ReturnValue(defaultPropertyThrough={mol.word.OMathMatRows.class})
    mol.word.OMathMatRow rows(
        int index);

    @VTID(11)
    mol.word.OMathMatCols cols();

    @VTID(11)
    @ReturnValue(defaultPropertyThrough={mol.word.OMathMatCols.class})
    mol.word.OMathMatCol cols(
        int index);

    @VTID(12)
    mol.word.OMath cell(
        int row,
        int col);

    @VTID(13)
    mol.word.WdOMathVertAlignType align();

    @VTID(14)
    void align(
        mol.word.WdOMathVertAlignType prop);

    @VTID(15)
    boolean plcHoldHidden();

    @VTID(16)
    void plcHoldHidden(
        boolean prop);

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

    @VTID(21)
    int colSpacing();

    @VTID(22)
    void colSpacing(
        int prop);

    @VTID(23)
    mol.word.WdOMathSpacingRule colGapRule();

    @VTID(24)
    void colGapRule(
        mol.word.WdOMathSpacingRule prop);

    @VTID(25)
    int colGap();

    @VTID(26)
    void colGap(
        int prop);

}
