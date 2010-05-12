package mol.office  ;

import com4j.*;

@IID("{000C0331-0000-0000-C000-000000000046}")
public interface FoundFiles extends mol.office._IMsoDispObj,Iterable<Com4jObject> {
    @VTID(9)
    @DefaultMethod
    java.lang.String item(
        int index,
        int lcid);

    @VTID(10)
    int count();

    @VTID(11)
    java.util.Iterator<Com4jObject> iterator();

}
