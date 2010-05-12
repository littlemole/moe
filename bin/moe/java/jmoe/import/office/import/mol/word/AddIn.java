package mol.word  ;

import com4j.*;

@IID("{0002097E-0000-0000-C000-000000000046}")
public interface AddIn extends Com4jObject {
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
    java.lang.String path();

    @VTID(13)
    boolean installed();

    @VTID(14)
    void installed(
        boolean prop);

    @VTID(15)
    boolean compiled();

    @VTID(16)
    boolean autoload();

    @VTID(17)
    void delete();

}
