package mol.word  ;

import com4j.*;

@IID("{67A7EEC5-285D-4024-B071-BD6B33B88547}")
public interface OMathRad extends Com4jObject {
    @VTID(7)
    mol.word._Application application();

    @VTID(8)
    int creator();

    @VTID(9)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

    @VTID(10)
    mol.word.OMath deg();

    @VTID(11)
    mol.word.OMath e();

    @VTID(12)
    boolean hideDeg();

    @VTID(13)
    void hideDeg(
        boolean prop);

}
