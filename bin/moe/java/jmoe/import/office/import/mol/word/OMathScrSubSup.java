package mol.word  ;

import com4j.*;

@IID("{DC489AD4-23C4-4F4B-990F-45A51C7C0C4F}")
public interface OMathScrSubSup extends Com4jObject {
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

    @VTID(12)
    mol.word.OMath sup();

    @VTID(13)
    boolean alignScripts();

    @VTID(14)
    void alignScripts(
        boolean prop);

    @VTID(15)
    mol.word.OMathFunction removeSub();

    @VTID(16)
    mol.word.OMathFunction removeSup();

    @VTID(17)
    mol.word.OMathFunction toScrPre();

}
