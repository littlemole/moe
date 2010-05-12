package mol.excel  ;

import com4j.*;

@IID("{000208BD-0001-0000-C000-000000000046}")
public interface ITrendlines extends Com4jObject,Iterable<Com4jObject> {
    @VTID(7)
    mol.excel._Application application();

    @VTID(8)
    mol.excel.XlCreator creator();

    @VTID(9)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

    @VTID(10)
    mol.excel.Trendline add(
        mol.excel.XlTrendlineType type,
        @MarshalAs(NativeType.VARIANT) java.lang.Object order,
        @MarshalAs(NativeType.VARIANT) java.lang.Object period,
        @MarshalAs(NativeType.VARIANT) java.lang.Object forward,
        @MarshalAs(NativeType.VARIANT) java.lang.Object backward,
        @MarshalAs(NativeType.VARIANT) java.lang.Object intercept,
        @MarshalAs(NativeType.VARIANT) java.lang.Object displayEquation,
        @MarshalAs(NativeType.VARIANT) java.lang.Object displayRSquared,
        @MarshalAs(NativeType.VARIANT) java.lang.Object name);

    @VTID(11)
    int count();

    @VTID(12)
    mol.excel.Trendline item(
        @MarshalAs(NativeType.VARIANT) java.lang.Object index);

    @VTID(13)
    java.util.Iterator<Com4jObject> iterator();

    @VTID(14)
    @DefaultMethod
    mol.excel.Trendline _Default(
        @MarshalAs(NativeType.VARIANT) java.lang.Object index);

}
