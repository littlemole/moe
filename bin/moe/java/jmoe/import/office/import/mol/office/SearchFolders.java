package mol.office  ;

import com4j.*;

@IID("{000C036A-0000-0000-C000-000000000046}")
public interface SearchFolders extends mol.office._IMsoDispObj,Iterable<Com4jObject> {
    @VTID(9)
    @DefaultMethod
    mol.office.ScopeFolder item(
        int index);

    @VTID(10)
    int count();

    @VTID(11)
    void add(
        mol.office.ScopeFolder scopeFolder);

    @VTID(12)
    void remove(
        int index);

    @VTID(13)
    java.util.Iterator<Com4jObject> iterator();

}
