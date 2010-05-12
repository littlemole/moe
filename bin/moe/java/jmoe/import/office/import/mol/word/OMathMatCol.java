package mol.word  ;

import com4j.*;

@IID("{CAE36175-3818-4C60-BCBF-0645D51EB33B}")
public interface OMathMatCol extends Com4jObject {
    @VTID(7)
    mol.word._Application application();

    @VTID(8)
    int creator();

    @VTID(9)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

    @VTID(10)
    mol.word.OMathArgs args();

    @VTID(10)
    @ReturnValue(defaultPropertyThrough={mol.word.OMathArgs.class})
    mol.word.OMath args(
        int index);

    @VTID(11)
    int colIndex();

    @VTID(12)
    mol.word.WdOMathHorizAlignType align();

    @VTID(13)
    void align(
        mol.word.WdOMathHorizAlignType prop);

    @VTID(14)
    void delete();

}
