package mol.word  ;

import com4j.*;

@IID("{02B17CB4-7D55-4B34-B38B-10381433441F}")
public interface OMathGroupChar extends Com4jObject {
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
    short _char();

    @VTID(12)
    void _char(
        short prop);

    @VTID(13)
    boolean charTop();

    @VTID(14)
    void charTop(
        boolean prop);

    @VTID(15)
    boolean alignTop();

    @VTID(16)
    void alignTop(
        boolean prop);

}
