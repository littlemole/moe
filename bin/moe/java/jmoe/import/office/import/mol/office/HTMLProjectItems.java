package mol.office  ;

import com4j.*;

@IID("{000C0357-0000-0000-C000-000000000046}")
public interface HTMLProjectItems extends mol.office._IMsoDispObj,Iterable<Com4jObject> {
    @VTID(9)
    @DefaultMethod
    mol.office.HTMLProjectItem item(
        java.lang.Object index);

    @VTID(10)
    int count();

    @VTID(11)
    java.util.Iterator<Com4jObject> iterator();

    @VTID(12)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

}
