package mol.office  ;

import com4j.*;

@IID("{000C0369-0000-0000-C000-000000000046}")
public interface ScopeFolders extends mol.office._IMsoDispObj,Iterable<Com4jObject> {
    @VTID(9)
    @DefaultMethod
    mol.office.ScopeFolder item(
        int index);

    @VTID(10)
    int count();

    @VTID(11)
    java.util.Iterator<Com4jObject> iterator();

}
