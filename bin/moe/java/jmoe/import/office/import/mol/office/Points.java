package mol.office  ;

import com4j.*;

@IID("{000C170D-0000-0000-C000-000000000046}")
public interface Points extends Com4jObject,Iterable<Com4jObject> {
    @VTID(7)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

    @VTID(8)
    int count();

    @VTID(9)
    mol.office.ChartPoint item(
        int index);

    @VTID(10)
    java.util.Iterator<Com4jObject> iterator();

}
