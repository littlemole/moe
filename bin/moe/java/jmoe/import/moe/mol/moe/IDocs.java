package mol.moe  ;

import com4j.*;

/**
 * IDocs Xmoe Interface - MDI Child Document Collection
 */
@IID("{609BCD33-CDEC-416D-9BBD-F551D452614D}")
public interface IDocs extends Com4jObject,Iterable<Com4jObject> {
    /**
     * New Enum - enable iteration from script
     */
    @VTID(7)
    java.util.Iterator<Com4jObject> iterator();

    /**
     * Item - retrieve child document by numeric or string (full document path) index
     */
    @VTID(8)
    @DefaultMethod
    mol.moe.IDoc item(
        @MarshalAs(NativeType.VARIANT) java.lang.Object i);

    /**
     * Count number of child documents
     */
    @VTID(9)
    int count();

}
