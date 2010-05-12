package mol.excel  ;

import com4j.*;

@IID("{00020400-0000-0000-C000-000000000046}")
public interface ListObject extends Com4jObject {
    @DISPID(148)
    @PropGet
    mol.excel._Application application();

    @DISPID(149)
    @PropGet
    mol.excel.XlCreator creator();

    @DISPID(150)
    @PropGet
    com4j.Com4jObject parent();

    @DISPID(117)
    void delete();

    @DISPID(1895)
    java.lang.String publish(
        java.lang.Object target,
        boolean linkSource);

    @DISPID(1417)
    void refresh();

    @DISPID(2308)
    void unlink();

    @DISPID(2309)
    void unlist();

    @DISPID(2310)
    void updateChanges(
        mol.excel.XlListConflict iConflictType);

    @DISPID(256)
    void resize(
        mol.excel.Range range);

    @DISPID(0)
    @PropGet
    @DefaultMethod
    java.lang.String _Default();

    @DISPID(2312)
    @PropGet
    boolean active();

    @DISPID(705)
    @PropGet
    mol.excel.Range dataBodyRange();

    @DISPID(1774)
    @PropGet
    boolean displayRightToLeft();

    @DISPID(2313)
    @PropGet
    mol.excel.Range headerRowRange();

    @DISPID(2314)
    @PropGet
    mol.excel.Range insertRowRange();

    @DISPID(2315)
    @PropGet
    mol.excel.ListColumns listColumns();

    @DISPID(2316)
    @PropGet
    mol.excel.ListRows listRows();

    @DISPID(110)
    @PropGet
    java.lang.String name();

    @DISPID(110)
    @PropPut
    void name(
        java.lang.String rhs);

    @DISPID(1386)
    @PropGet
    com4j.Com4jObject queryTable();

    @DISPID(197)
    @PropGet
    mol.excel.Range range();

    @DISPID(2317)
    @PropGet
    boolean showAutoFilter();

    @DISPID(2317)
    @PropPut
    void showAutoFilter(
        boolean rhs);

    @DISPID(2318)
    @PropGet
    boolean showTotals();

    @DISPID(2318)
    @PropPut
    void showTotals(
        boolean rhs);

    @DISPID(685)
    @PropGet
    mol.excel.XlListObjectSourceType sourceType();

    @DISPID(2319)
    @PropGet
    mol.excel.Range totalsRowRange();

    @DISPID(2320)
    @PropGet
    java.lang.String sharePointURL();

    @DISPID(2253)
    @PropGet
    mol.excel.XmlMap xmlMap();

    @DISPID(2677)
    @PropGet
    java.lang.String displayName();

    @DISPID(2677)
    @PropPut
    void displayName(
        java.lang.String rhs);

    @DISPID(2678)
    @PropGet
    boolean showHeaders();

    @DISPID(2678)
    @PropPut
    void showHeaders(
        boolean rhs);

    @DISPID(793)
    @PropGet
    mol.excel.AutoFilter autoFilter();

    @DISPID(1504)
    @PropGet
    java.lang.Object tableStyle();

    @DISPID(1504)
    @PropPut
    void tableStyle(
        java.lang.Object rhs);

    @DISPID(2679)
    @PropGet
    boolean showTableStyleFirstColumn();

    @DISPID(2679)
    @PropPut
    void showTableStyleFirstColumn(
        boolean rhs);

    @DISPID(2563)
    @PropGet
    boolean showTableStyleLastColumn();

    @DISPID(2563)
    @PropPut
    void showTableStyleLastColumn(
        boolean rhs);

    @DISPID(2564)
    @PropGet
    boolean showTableStyleRowStripes();

    @DISPID(2564)
    @PropPut
    void showTableStyleRowStripes(
        boolean rhs);

    @DISPID(2565)
    @PropGet
    boolean showTableStyleColumnStripes();

    @DISPID(2565)
    @PropPut
    void showTableStyleColumnStripes(
        boolean rhs);

    @DISPID(880)
    @PropGet
    mol.excel.Sort sort();

    @DISPID(910)
    @PropGet
    java.lang.String comment();

    @DISPID(910)
    @PropPut
    void comment(
        java.lang.String rhs);

    @DISPID(2680)
    void exportToVisio();

}
