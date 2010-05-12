package mol.office  ;

import com4j.*;

@IID("{000C0333-0000-0000-C000-000000000046}")
public interface PropertyTest extends mol.office._IMsoDispObj {
    @VTID(9)
    @DefaultMethod
    java.lang.String name();

    @VTID(10)
    mol.office.MsoCondition condition();

    @VTID(11)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object value();

    @VTID(12)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object secondValue();

    @VTID(13)
    mol.office.MsoConnector connector();

}
