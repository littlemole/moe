package mol.word  ;

import com4j.*;

@IID("{98DFBD12-96CB-4F07-90EA-749FF1D6B89D}")
public interface OMathScrSub extends Com4jObject {
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
    mol.word.OMath sub();

}
