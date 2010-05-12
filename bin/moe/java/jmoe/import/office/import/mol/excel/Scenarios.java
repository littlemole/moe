package mol.excel  ;

import com4j.*;

@IID("{00020400-0000-0000-C000-000000000046}")
public interface Scenarios extends Com4jObject,Iterable<Com4jObject> {
    @DISPID(148)
    @PropGet
    mol.excel._Application application();

    @DISPID(149)
    @PropGet
    mol.excel.XlCreator creator();

    @DISPID(150)
    @PropGet
    com4j.Com4jObject parent();

    @DISPID(181)
    mol.excel.Scenario add(
        java.lang.String name,
        java.lang.Object changingCells,
        java.lang.Object values,
        java.lang.Object comment,
        java.lang.Object locked,
        java.lang.Object hidden);

    @DISPID(118)
    @PropGet
    int count();

    @DISPID(913)
    java.lang.Object createSummary(
        mol.excel.XlSummaryReportType reportType,
        java.lang.Object resultCells);

    @DISPID(170)
    mol.excel.Scenario item(
        java.lang.Object index);

    @DISPID(564)
    java.lang.Object merge(
        java.lang.Object source);

    @DISPID(-4)
    java.util.Iterator<Com4jObject> iterator();

}
