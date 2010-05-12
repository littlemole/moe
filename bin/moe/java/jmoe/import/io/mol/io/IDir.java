package mol.io  ;

import com4j.*;

/**
 * IDir - interface representing a Directory collection
 */
@IID("{92AF3107-79EB-480F-A118-6A3FF41E5085}")
public interface IDir extends Com4jObject,Iterable<Com4jObject> {
    /**
     * New Enum - scripting language enumaration support
     */
    @VTID(7)
    java.util.Iterator<Com4jObject> iterator();

    /**
     * Item - returns directory entry for index
     */
    @VTID(8)
    @DefaultMethod
    java.lang.String item(
        int i);

    /**
     * Count - returns number of files in directory
     */
    @VTID(9)
    int count();

}
