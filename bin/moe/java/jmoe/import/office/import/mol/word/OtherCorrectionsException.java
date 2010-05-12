package mol.word  ;

import com4j.*;

@IID("{000209E1-0000-0000-C000-000000000046}")
public interface OtherCorrectionsException extends Com4jObject {
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
    void delete();

}
