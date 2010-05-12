package mol.wsh  ;

import com4j.*;

/**
 * Generic Collection Object
 */
@IID("{F935DC27-1CF0-11D0-ADB9-00C04FD58A0B}")
public interface IWshCollection extends Com4jObject,Iterable<Com4jObject> {
    @VTID(7)
    @DefaultMethod
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object item(
        java.lang.Object index);

    @VTID(8)
    int count();

    @VTID(9)
    int length();

    @VTID(10)
    java.util.Iterator<Com4jObject> iterator();

}
