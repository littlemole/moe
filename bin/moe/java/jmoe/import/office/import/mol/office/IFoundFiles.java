package mol.office  ;

import com4j.*;

@IID("{000C0338-0000-0000-C000-000000000046}")
public interface IFoundFiles extends Com4jObject,Iterable<Com4jObject> {
    @VTID(7)
    @DefaultMethod
    java.lang.String item(
        int index);

    @VTID(8)
    int count();

    @VTID(9)
    java.util.Iterator<Com4jObject> iterator();

}
