package mol.word  ;

import com4j.*;

@IID("{F258DE05-C41B-4C33-A778-F0D3F98CEEB3}")
public interface OMathAcc extends Com4jObject {
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
    short _char();

    @VTID(12)
    void _char(
        short prop);

}
