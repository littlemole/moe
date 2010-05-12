package mol.word  ;

import com4j.*;

@IID("{AFAF0C0E-8603-40F6-8FD1-42726CAC21E3}")
public interface OMathScrPre extends Com4jObject {
    @VTID(7)
    mol.word._Application application();

    @VTID(8)
    int creator();

    @VTID(9)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

    @VTID(10)
    mol.word.OMath sub();

    @VTID(11)
    mol.word.OMath sup();

    @VTID(12)
    mol.word.OMath e();

    @VTID(13)
    mol.word.OMathFunction toScrSubSup();

}
