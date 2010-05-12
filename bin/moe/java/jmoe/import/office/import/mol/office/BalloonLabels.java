package mol.office  ;

import com4j.*;

@IID("{000C032E-0000-0000-C000-000000000046}")
public interface BalloonLabels extends mol.office._IMsoDispObj,Iterable<Com4jObject> {
    @VTID(9)
    java.lang.String name();

    @VTID(10)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

    @VTID(11)
    @DefaultMethod
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject item(
        int index);

    @VTID(12)
    int count();

    @VTID(13)
    void count(
        int pcwz);

    @VTID(14)
    java.util.Iterator<Com4jObject> iterator();

}
