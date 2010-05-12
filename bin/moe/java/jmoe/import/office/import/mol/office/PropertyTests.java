package mol.office  ;

import com4j.*;

@IID("{000C0334-0000-0000-C000-000000000046}")
public interface PropertyTests extends mol.office._IMsoDispObj,Iterable<Com4jObject> {
    @VTID(9)
    @DefaultMethod
    mol.office.PropertyTest item(
        int index,
        int lcid);

    @VTID(10)
    int count();

    @VTID(11)
    void add(
        java.lang.String name,
        mol.office.MsoCondition condition,
        @MarshalAs(NativeType.VARIANT) java.lang.Object value,
        @MarshalAs(NativeType.VARIANT) java.lang.Object secondValue,
        mol.office.MsoConnector connector);

    @VTID(12)
    void remove(
        int index);

    @VTID(13)
    java.util.Iterator<Com4jObject> iterator();

}
