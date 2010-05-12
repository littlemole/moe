package mol.office  ;

import com4j.*;

@IID("{000C03C0-0000-0000-C000-000000000046}")
public interface GradientStops extends mol.office._IMsoDispObj,Iterable<Com4jObject> {
    @VTID(9)
    @DefaultMethod
    mol.office.GradientStop item(
        int index);

    @VTID(10)
    int count();

    @VTID(11)
    java.util.Iterator<Com4jObject> iterator();

    @VTID(12)
    void delete(
        int index);

    @VTID(13)
    void insert(
        int rgb,
        float position,
        float transparency,
        int index);

}
