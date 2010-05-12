package mol.word  ;

import com4j.*;

@IID("{5DAA8BB6-054E-48F6-BEAC-EAAD02BE0CC7}")
public interface OMathMatRow extends Com4jObject {
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
    int rowIndex();

    @VTID(12)
    void delete();

}
