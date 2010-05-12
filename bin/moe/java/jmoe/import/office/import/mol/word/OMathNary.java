package mol.word  ;

import com4j.*;

@IID("{CEBD4184-4E6D-4FC6-A42D-2142B1B76AF5}")
public interface OMathNary extends Com4jObject {
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
    short _char();

    @VTID(14)
    void _char(
        short prop);

    @VTID(15)
    boolean grow();

    @VTID(16)
    void grow(
        boolean prop);

    @VTID(17)
    boolean subSupLim();

    @VTID(18)
    void subSupLim(
        boolean prop);

    @VTID(19)
    boolean hideSub();

    @VTID(20)
    void hideSub(
        boolean prop);

    @VTID(21)
    boolean hideSup();

    @VTID(22)
    void hideSup(
        boolean prop);

}
