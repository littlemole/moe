package mol.word  ;

import com4j.*;

@IID("{000209E6-0000-0000-C000-000000000046}")
public interface EmailSignatureEntry extends Com4jObject {
    @VTID(7)
    mol.word._Application application();

    @VTID(8)
    int creator();

    @VTID(9)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

    @VTID(10)
    int index();

    @VTID(11)
    java.lang.String name();

    @VTID(12)
    void name(
        java.lang.String prop);

    @VTID(13)
    void delete();

}