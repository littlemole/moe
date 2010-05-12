package mol.word  ;

import com4j.*;

@IID("{00020977-0000-0000-C000-000000000046}")
public interface TableOfAuthoritiesCategory extends Com4jObject {
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
    @DefaultMethod
    void name(
        java.lang.String prop);

    @VTID(12)
    int index();

}
