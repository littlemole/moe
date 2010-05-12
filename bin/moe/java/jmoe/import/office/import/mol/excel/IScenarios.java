package mol.excel  ;

import com4j.*;

@IID("{00020896-0001-0000-C000-000000000046}")
public interface IScenarios extends Com4jObject,Iterable<Com4jObject> {
    @VTID(7)
    mol.excel._Application application();

    @VTID(8)
    mol.excel.XlCreator creator();

    @VTID(9)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

    @VTID(10)
    mol.excel.Scenario add(
        java.lang.String name,
        @MarshalAs(NativeType.VARIANT) java.lang.Object changingCells,
        @MarshalAs(NativeType.VARIANT) java.lang.Object values,
        @MarshalAs(NativeType.VARIANT) java.lang.Object comment,
        @MarshalAs(NativeType.VARIANT) java.lang.Object locked,
        @MarshalAs(NativeType.VARIANT) java.lang.Object hidden);

    @VTID(11)
    int count();

    @VTID(12)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object createSummary(
        mol.excel.XlSummaryReportType reportType,
        @MarshalAs(NativeType.VARIANT) java.lang.Object resultCells);

    @VTID(13)
    mol.excel.Scenario item(
        @MarshalAs(NativeType.VARIANT) java.lang.Object index);

    @VTID(14)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object merge(
        @MarshalAs(NativeType.VARIANT) java.lang.Object source);

    @VTID(15)
    java.util.Iterator<Com4jObject> iterator();

}
