package mol.office  ;

import com4j.*;

@IID("{000C1712-0000-0000-C000-000000000046}")
public interface Axes extends Com4jObject,Iterable<Com4jObject> {
    @VTID(7)
    int count();

    @VTID(8)
    mol.office.IMsoAxis item(
        mol.office.XlAxisType type,
        mol.office.XlAxisGroup axisGroup);

    @VTID(9)
    java.util.Iterator<Com4jObject> iterator();

}
