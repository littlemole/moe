package mol.word  ;

import com4j.*;

@IID("{000209B4-0000-0000-C000-000000000046}")
public interface Version extends Com4jObject {
    @VTID(7)
    mol.word._Application application();

    @VTID(8)
    int creator();

    @VTID(9)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

    @VTID(10)
    java.lang.String savedBy();

    @VTID(11)
    java.lang.String comment();

    @VTID(12)
    java.util.Date date();

    @VTID(13)
    int index();

    @VTID(14)
    void openOld();

    @VTID(15)
    void delete();

    @VTID(16)
    mol.word._Document open();

}
