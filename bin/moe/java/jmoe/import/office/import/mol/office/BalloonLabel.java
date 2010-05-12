package mol.office  ;

import com4j.*;

@IID("{000C0330-0000-0000-C000-000000000046}")
public interface BalloonLabel extends mol.office._IMsoDispObj {
    @VTID(9)
    @DefaultMethod
    java.lang.String item();

    @VTID(10)
    java.lang.String name();

    @VTID(11)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

    @VTID(12)
    void text(
        java.lang.String pbstr);

    @VTID(13)
    java.lang.String text();

}
