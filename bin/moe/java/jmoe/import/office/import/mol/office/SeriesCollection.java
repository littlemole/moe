package mol.office  ;

import com4j.*;

@IID("{000C170A-0000-0000-C000-000000000046}")
public interface SeriesCollection extends Com4jObject,Iterable<Com4jObject> {
    @VTID(7)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

    @VTID(8)
    mol.office.IMsoSeries add(
        @MarshalAs(NativeType.VARIANT) java.lang.Object source,
        mol.office.XlRowCol rowcol,
        @MarshalAs(NativeType.VARIANT) java.lang.Object seriesLabels,
        @MarshalAs(NativeType.VARIANT) java.lang.Object categoryLabels,
        @MarshalAs(NativeType.VARIANT) java.lang.Object replace);

    @VTID(9)
    int count();

    @VTID(10)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object extend(
        @MarshalAs(NativeType.VARIANT) java.lang.Object source,
        @MarshalAs(NativeType.VARIANT) java.lang.Object rowcol,
        @MarshalAs(NativeType.VARIANT) java.lang.Object categoryLabels);

    @VTID(11)
    mol.office.IMsoSeries item(
        @MarshalAs(NativeType.VARIANT) java.lang.Object index);

    @VTID(12)
    java.util.Iterator<Com4jObject> iterator();

    @VTID(13)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object paste(
        mol.office.XlRowCol rowcol,
        @MarshalAs(NativeType.VARIANT) java.lang.Object seriesLabels,
        @MarshalAs(NativeType.VARIANT) java.lang.Object categoryLabels,
        @MarshalAs(NativeType.VARIANT) java.lang.Object replace,
        @MarshalAs(NativeType.VARIANT) java.lang.Object newSeries);

    @VTID(14)
    mol.office.IMsoSeries newSeries();

}
