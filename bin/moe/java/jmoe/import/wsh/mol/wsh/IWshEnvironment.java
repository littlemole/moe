package mol.wsh  ;

import com4j.*;

/**
 * Environment Variables Collection Object
 */
@IID("{F935DC29-1CF0-11D0-ADB9-00C04FD58A0B}")
public interface IWshEnvironment extends Com4jObject,Iterable<Com4jObject> {
    @VTID(7)
    @DefaultMethod
    java.lang.String item(
        java.lang.String name);

    @VTID(8)
    @DefaultMethod
    void item(
        java.lang.String name,
        java.lang.String out_Value);

    @VTID(9)
    int count();

    @VTID(10)
    int length();

    @VTID(11)
    java.util.Iterator<Com4jObject> iterator();

    @VTID(12)
    void remove(
        java.lang.String name);

}
