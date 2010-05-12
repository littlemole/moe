package mol.word  ;

import com4j.*;

@IID("{F08B45F1-8F23-4156-9D63-1820C0ED229A}")
public interface OMathBar extends Com4jObject {
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
    boolean barTop();

    @VTID(12)
    void barTop(
        boolean prop);

}
