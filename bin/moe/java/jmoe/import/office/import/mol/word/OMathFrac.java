package mol.word  ;

import com4j.*;

@IID("{50209974-BA32-4A03-8FA6-BAC56CC056FD}")
public interface OMathFrac extends Com4jObject {
    @VTID(7)
    mol.word._Application application();

    @VTID(8)
    int creator();

    @VTID(9)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

    @VTID(10)
    mol.word.OMath num();

    @VTID(11)
    mol.word.OMath den();

    @VTID(12)
    mol.word.WdOMathFracType type();

    @VTID(13)
    void type(
        mol.word.WdOMathFracType prop);

}
