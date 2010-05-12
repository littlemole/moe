package mol.word  ;

import com4j.*;

@IID("{842C37FE-C76F-4B2B-9B60-C408CB5E838E}")
public interface OMathBox extends Com4jObject {
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
    boolean opEmu();

    @VTID(12)
    void opEmu(
        boolean prop);

    @VTID(13)
    boolean noBreak();

    @VTID(14)
    void noBreak(
        boolean prop);

    @VTID(15)
    boolean diff();

    @VTID(16)
    void diff(
        boolean prop);

}
