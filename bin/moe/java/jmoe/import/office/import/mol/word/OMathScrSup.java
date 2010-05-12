package mol.word  ;

import com4j.*;

@IID("{D0A95726-678A-4B9D-8103-1E2B86735AE7}")
public interface OMathScrSup extends Com4jObject {
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
    mol.word.OMath sup();

}
