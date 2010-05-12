package mol.vba  ;

import com4j.*;

@IID("{0002E163-0000-0000-C000-000000000046}")
public interface _Component extends Com4jObject {
    @VTID(7)
    mol.vba.Application application();

    @VTID(8)
    mol.vba._Components parent();

    @VTID(9)
    boolean isDirty();

    @VTID(10)
    void isDirty(
        boolean lpfReturn);

    @VTID(11)
    java.lang.String name();

    @VTID(12)
    void name(
        java.lang.String pbstrReturn);

}
