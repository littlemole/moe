package mol.word  ;

import com4j.*;

@IID("{0002098B-0000-0000-C000-000000000046}")
public interface HeadingStyle extends Com4jObject {
    @VTID(7)
    mol.word._Application application();

    @VTID(8)
    int creator();

    @VTID(9)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

    @VTID(10)
    @DefaultMethod
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object style();

    @VTID(11)
    @DefaultMethod
    void style(
        java.lang.Object prop);

    @VTID(12)
    short level();

    @VTID(13)
    void level(
        short prop);

    @VTID(14)
    void delete();

}
