package mol.office  ;

import com4j.*;

@IID("{000C1722-0000-0000-C000-000000000046}")
public interface Trendlines extends Com4jObject,Iterable<Com4jObject> {
    @VTID(7)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

    @VTID(8)
    mol.office.IMsoTrendline add(
        mol.office.XlTrendlineType type,
        @MarshalAs(NativeType.VARIANT) java.lang.Object order,
        @MarshalAs(NativeType.VARIANT) java.lang.Object period,
        @MarshalAs(NativeType.VARIANT) java.lang.Object forward,
        @MarshalAs(NativeType.VARIANT) java.lang.Object backward,
        @MarshalAs(NativeType.VARIANT) java.lang.Object intercept,
        @MarshalAs(NativeType.VARIANT) java.lang.Object displayEquation,
        @MarshalAs(NativeType.VARIANT) java.lang.Object displayRSquared,
        @MarshalAs(NativeType.VARIANT) java.lang.Object name);

    @VTID(9)
    int count();

    @VTID(10)
    mol.office.IMsoTrendline item(
        @MarshalAs(NativeType.VARIANT) java.lang.Object index);

    @VTID(11)
    java.util.Iterator<Com4jObject> iterator();

}
