package mol.word  ;

import com4j.*;

@IID("{FC9086C6-0287-4997-B2E1-816C334A22F8}")
public interface OMathLimUpp extends Com4jObject {
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
    mol.word.OMath lim();

    @VTID(12)
    mol.word.OMathFunction toLimLow();

}
