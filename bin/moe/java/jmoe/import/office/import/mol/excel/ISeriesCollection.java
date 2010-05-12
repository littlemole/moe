package mol.excel  ;

import com4j.*;

@IID("{0002086C-0001-0000-C000-000000000046}")
public interface ISeriesCollection extends Com4jObject,Iterable<Com4jObject> {
    @VTID(7)
    mol.excel._Application application();

    @VTID(8)
    mol.excel.XlCreator creator();

    @VTID(9)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

    @VTID(10)
    mol.excel.Series add(
        @MarshalAs(NativeType.VARIANT) java.lang.Object source,
        mol.excel.XlRowCol rowcol,
        @MarshalAs(NativeType.VARIANT) java.lang.Object seriesLabels,
        @MarshalAs(NativeType.VARIANT) java.lang.Object categoryLabels,
        @MarshalAs(NativeType.VARIANT) java.lang.Object replace);

    @VTID(11)
    int count();

    @VTID(12)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object extend(
        @MarshalAs(NativeType.VARIANT) java.lang.Object source,
        @MarshalAs(NativeType.VARIANT) java.lang.Object rowcol,
        @MarshalAs(NativeType.VARIANT) java.lang.Object categoryLabels);

    @VTID(13)
    mol.excel.Series item(
        @MarshalAs(NativeType.VARIANT) java.lang.Object index);

    @VTID(14)
    java.util.Iterator<Com4jObject> iterator();

    @VTID(15)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object paste(
        mol.excel.XlRowCol rowcol,
        @MarshalAs(NativeType.VARIANT) java.lang.Object seriesLabels,
        @MarshalAs(NativeType.VARIANT) java.lang.Object categoryLabels,
        @MarshalAs(NativeType.VARIANT) java.lang.Object replace,
        @MarshalAs(NativeType.VARIANT) java.lang.Object newSeries);

    @VTID(16)
    mol.excel.Series newSeries();

    @VTID(17)
    @DefaultMethod
    mol.excel.Series _Default(
        @MarshalAs(NativeType.VARIANT) java.lang.Object index);

}
