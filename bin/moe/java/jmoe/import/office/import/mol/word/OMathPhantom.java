package mol.word  ;

import com4j.*;

@IID("{DB77D541-85C3-42E8-8649-AFBD7CF87866}")
public interface OMathPhantom extends Com4jObject {
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
    boolean show();

    @VTID(12)
    void show(
        boolean prop);

    @VTID(13)
    boolean zeroWid();

    @VTID(14)
    void zeroWid(
        boolean prop);

    @VTID(15)
    boolean zeroAsc();

    @VTID(16)
    void zeroAsc(
        boolean prop);

    @VTID(17)
    boolean zeroDesc();

    @VTID(18)
    void zeroDesc(
        boolean prop);

    @VTID(19)
    boolean transp();

    @VTID(20)
    void transp(
        boolean prop);

    @VTID(21)
    boolean smash();

    @VTID(22)
    void smash(
        boolean prop);

}
