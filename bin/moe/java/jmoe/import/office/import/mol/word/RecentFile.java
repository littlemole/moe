package mol.word  ;

import com4j.*;

@IID("{00020964-0000-0000-C000-000000000046}")
public interface RecentFile extends Com4jObject {
    @VTID(7)
    mol.word._Application application();

    @VTID(8)
    int creator();

    @VTID(9)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

    @VTID(10)
    @DefaultMethod
    java.lang.String name();

    @VTID(11)
    int index();

    @VTID(12)
    boolean readOnly();

    @VTID(13)
    void readOnly(
        boolean prop);

    @VTID(14)
    java.lang.String path();

    @VTID(15)
    mol.word._Document open();

    @VTID(16)
    void delete();

}
