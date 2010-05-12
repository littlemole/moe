package mol.office  ;

import com4j.*;

@IID("{000C0392-0000-0000-C000-000000000046}")
public interface DocumentInspectors extends mol.office._IMsoDispObj,Iterable<Com4jObject> {
    @VTID(9)
    java.util.Iterator<Com4jObject> iterator();

    @VTID(10)
    @DefaultMethod
    mol.office.DocumentInspector item(
        int index);

    @VTID(11)
    int count();

    @VTID(12)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

}
