package mol.word  ;

import com4j.*;

@IID("{74DE9576-8E99-4E28-912B-CB30747C60CE}")
public interface OMathLimLow extends Com4jObject {
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
    mol.word.OMathFunction toLimUpp();

}
