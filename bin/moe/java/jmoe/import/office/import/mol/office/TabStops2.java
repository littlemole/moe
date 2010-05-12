package mol.office  ;

import com4j.*;

@IID("{000C03BA-0000-0000-C000-000000000046}")
public interface TabStops2 extends mol.office._IMsoDispObj,Iterable<Com4jObject> {
    @VTID(9)
    @DefaultMethod
    mol.office.TabStop2 item(
        @MarshalAs(NativeType.VARIANT) java.lang.Object index);

    @VTID(10)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

    @VTID(11)
    mol.office.TabStop2 add(
        mol.office.MsoTabStopType type,
        float position);

    @VTID(12)
    int count();

    @VTID(13)
    float defaultSpacing();

    @VTID(14)
    void defaultSpacing(
        float spacing);

    @VTID(15)
    java.util.Iterator<Com4jObject> iterator();

}
