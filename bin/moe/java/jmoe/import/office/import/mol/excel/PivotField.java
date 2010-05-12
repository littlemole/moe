package mol.excel  ;

import com4j.*;

@IID("{00020400-0000-0000-C000-000000000046}")
public interface PivotField extends Com4jObject {
    @DISPID(148)
    @PropGet
    mol.excel._Application application();

    @DISPID(149)
    @PropGet
    mol.excel.XlCreator creator();

    @DISPID(150)
    @PropGet
    com4j.Com4jObject parent();

    @DISPID(316)
    @PropGet
    mol.excel.XlPivotFieldCalculation calculation();

    @DISPID(316)
    @PropPut
    void calculation(
        mol.excel.XlPivotFieldCalculation rhs);

    @DISPID(736)
    @PropGet
    mol.excel.PivotField childField();

    @DISPID(730)
    @PropGet
    java.lang.Object childItems(
        java.lang.Object index);

    @DISPID(738)
    @PropGet
    java.lang.Object currentPage();

    @DISPID(738)
    @PropPut
    void currentPage(
        java.lang.Object rhs);

    @DISPID(720)
    @PropGet
    mol.excel.Range dataRange();

    @DISPID(722)
    @PropGet
    mol.excel.XlPivotFieldDataType dataType();

    @DISPID(0)
    @PropGet
    @DefaultMethod
    java.lang.String _Default();

    @DISPID(0)
    @PropPut
    @DefaultMethod
    void _Default(
        java.lang.String rhs);

    @DISPID(899)
    @PropGet
    mol.excel.XlConsolidationFunction function();

    @DISPID(899)
    @PropPut
    void function(
        mol.excel.XlConsolidationFunction rhs);

    @DISPID(723)
    @PropGet
    java.lang.Object groupLevel();

    @DISPID(728)
    @PropGet
    java.lang.Object hiddenItems(
        java.lang.Object index);

    @DISPID(719)
    @PropGet
    mol.excel.Range labelRange();

    @DISPID(110)
    @PropGet
    java.lang.String name();

    @DISPID(110)
    @PropPut
    void name(
        java.lang.String rhs);

    @DISPID(193)
    @PropGet
    java.lang.String numberFormat();

    @DISPID(193)
    @PropPut
    void numberFormat(
        java.lang.String rhs);

    @DISPID(134)
    @PropGet
    mol.excel.XlPivotFieldOrientation orientation();

    @DISPID(134)
    @PropPut
    void orientation(
        mol.excel.XlPivotFieldOrientation rhs);

    @DISPID(452)
    @PropGet
    boolean showAllItems();

    @DISPID(452)
    @PropPut
    void showAllItems(
        boolean rhs);

    @DISPID(732)
    @PropGet
    mol.excel.PivotField parentField();

    @DISPID(729)
    @PropGet
    java.lang.Object parentItems(
        java.lang.Object index);

    @DISPID(737)
    java.lang.Object pivotItems(
        java.lang.Object index);

    @DISPID(133)
    @PropGet
    java.lang.Object position();

    @DISPID(133)
    @PropPut
    void position(
        java.lang.Object rhs);

    @DISPID(721)
    @PropGet
    java.lang.String sourceName();

    @DISPID(733)
    @PropGet
    java.lang.Object subtotals(
        java.lang.Object index);

    @DISPID(733)
    @PropPut
    void subtotals(
        java.lang.Object index,
        java.lang.Object rhs);

    @DISPID(734)
    @PropGet
    java.lang.Object baseField();

    @DISPID(734)
    @PropPut
    void baseField(
        java.lang.Object rhs);

    @DISPID(735)
    @PropGet
    java.lang.Object baseItem();

    @DISPID(735)
    @PropPut
    void baseItem(
        java.lang.Object rhs);

    @DISPID(724)
    @PropGet
    java.lang.Object totalLevels();

    @DISPID(6)
    @PropGet
    java.lang.String value();

    @DISPID(6)
    @PropPut
    void value(
        java.lang.String rhs);

    @DISPID(727)
    @PropGet
    java.lang.Object visibleItems(
        java.lang.Object index);

    @DISPID(1507)
    mol.excel.CalculatedItems calculatedItems();

    @DISPID(117)
    void delete();

    @DISPID(1508)
    @PropGet
    boolean dragToColumn();

    @DISPID(1508)
    @PropPut
    void dragToColumn(
        boolean rhs);

    @DISPID(1509)
    @PropGet
    boolean dragToHide();

    @DISPID(1509)
    @PropPut
    void dragToHide(
        boolean rhs);

    @DISPID(1510)
    @PropGet
    boolean dragToPage();

    @DISPID(1510)
    @PropPut
    void dragToPage(
        boolean rhs);

    @DISPID(1511)
    @PropGet
    boolean dragToRow();

    @DISPID(1511)
    @PropPut
    void dragToRow(
        boolean rhs);

    @DISPID(1844)
    @PropGet
    boolean dragToData();

    @DISPID(1844)
    @PropPut
    void dragToData(
        boolean rhs);

    @DISPID(261)
    @PropGet
    java.lang.String formula();

    @DISPID(261)
    @PropPut
    void formula(
        java.lang.String rhs);

    @DISPID(1512)
    @PropGet
    boolean isCalculated();

    @DISPID(372)
    @PropGet
    int memoryUsed();

    @DISPID(1513)
    @PropGet
    boolean serverBased();

    @DISPID(1513)
    @PropPut
    void serverBased(
        boolean rhs);

    @DISPID(2579)
    void _AutoSort(
        int order,
        java.lang.String field);

    @DISPID(1515)
    void autoShow(
        int type,
        int range,
        int count,
        java.lang.String field);

    @DISPID(1516)
    @PropGet
    int autoSortOrder();

    @DISPID(1517)
    @PropGet
    java.lang.String autoSortField();

    @DISPID(1518)
    @PropGet
    int autoShowType();

    @DISPID(1519)
    @PropGet
    int autoShowRange();

    @DISPID(1520)
    @PropGet
    int autoShowCount();

    @DISPID(1521)
    @PropGet
    java.lang.String autoShowField();

    @DISPID(1845)
    @PropGet
    boolean layoutBlankLine();

    @DISPID(1845)
    @PropPut
    void layoutBlankLine(
        boolean rhs);

    @DISPID(1846)
    @PropGet
    mol.excel.XlSubtototalLocationType layoutSubtotalLocation();

    @DISPID(1846)
    @PropPut
    void layoutSubtotalLocation(
        mol.excel.XlSubtototalLocationType rhs);

    @DISPID(1847)
    @PropGet
    boolean layoutPageBreak();

    @DISPID(1847)
    @PropPut
    void layoutPageBreak(
        boolean rhs);

    @DISPID(1848)
    @PropGet
    mol.excel.XlLayoutFormType layoutForm();

    @DISPID(1848)
    @PropPut
    void layoutForm(
        mol.excel.XlLayoutFormType rhs);

    @DISPID(1849)
    @PropGet
    java.lang.String subtotalName();

    @DISPID(1849)
    @PropPut
    void subtotalName(
        java.lang.String rhs);

    @DISPID(139)
    @PropGet
    java.lang.String caption();

    @DISPID(139)
    @PropPut
    void caption(
        java.lang.String rhs);

    @DISPID(1850)
    @PropGet
    boolean drilledDown();

    @DISPID(1850)
    @PropPut
    void drilledDown(
        boolean rhs);

    @DISPID(1851)
    @PropGet
    mol.excel.CubeField cubeField();

    @DISPID(1852)
    @PropGet
    java.lang.String currentPageName();

    @DISPID(1852)
    @PropPut
    void currentPageName(
        java.lang.String rhs);

    @DISPID(2084)
    @PropGet
    java.lang.String standardFormula();

    @DISPID(2084)
    @PropPut
    void standardFormula(
        java.lang.String rhs);

    @DISPID(2139)
    @PropGet
    java.lang.Object hiddenItemsList();

    @DISPID(2139)
    @PropPut
    void hiddenItemsList(
        java.lang.Object rhs);

    @DISPID(2140)
    @PropGet
    boolean databaseSort();

    @DISPID(2140)
    @PropPut
    void databaseSort(
        boolean rhs);

    @DISPID(2141)
    @PropGet
    boolean isMemberProperty();

    @DISPID(2142)
    @PropGet
    mol.excel.PivotField propertyParentField();

    @DISPID(2143)
    @PropGet
    int propertyOrder();

    @DISPID(2143)
    @PropPut
    void propertyOrder(
        int rhs);

    @DISPID(2144)
    @PropGet
    boolean enableItemSelection();

    @DISPID(2144)
    @PropPut
    void enableItemSelection(
        boolean rhs);

    @DISPID(2145)
    @PropGet
    java.lang.Object currentPageList();

    @DISPID(2145)
    @PropPut
    void currentPageList(
        java.lang.Object rhs);

    @DISPID(2146)
    void addPageItem(
        java.lang.String item,
        java.lang.Object clearList);

    @DISPID(268)
    @PropGet
    boolean hidden();

    @DISPID(268)
    @PropPut
    void hidden(
        boolean rhs);

    @DISPID(2580)
    void drillTo(
        java.lang.String field);

    @DISPID(2581)
    @PropGet
    boolean useMemberPropertyAsCaption();

    @DISPID(2581)
    @PropPut
    void useMemberPropertyAsCaption(
        boolean rhs);

    @DISPID(2582)
    @PropGet
    java.lang.String memberPropertyCaption();

    @DISPID(2582)
    @PropPut
    void memberPropertyCaption(
        java.lang.String rhs);

    @DISPID(2583)
    @PropGet
    boolean displayAsTooltip();

    @DISPID(2583)
    @PropPut
    void displayAsTooltip(
        boolean rhs);

    @DISPID(2584)
    @PropGet
    boolean displayInReport();

    @DISPID(2584)
    @PropPut
    void displayInReport(
        boolean rhs);

    @DISPID(2585)
    @PropGet
    boolean displayAsCaption();

    @DISPID(2586)
    @PropGet
    boolean layoutCompactRow();

    @DISPID(2586)
    @PropPut
    void layoutCompactRow(
        boolean rhs);

    @DISPID(2587)
    @PropGet
    boolean includeNewItemsInFilter();

    @DISPID(2587)
    @PropPut
    void includeNewItemsInFilter(
        boolean rhs);

    @DISPID(2588)
    @PropGet
    java.lang.Object visibleItemsList();

    @DISPID(2588)
    @PropPut
    void visibleItemsList(
        java.lang.Object rhs);

    @DISPID(2589)
    @PropGet
    mol.excel.PivotFilters pivotFilters();

    @DISPID(2590)
    @PropGet
    mol.excel.PivotLine autoSortPivotLine();

    @DISPID(2591)
    @PropGet
    int autoSortCustomSubtotal();

    @DISPID(2592)
    @PropGet
    boolean showingInAxis();

    @DISPID(2184)
    @PropGet
    boolean enableMultiplePageItems();

    @DISPID(2184)
    @PropPut
    void enableMultiplePageItems(
        boolean rhs);

    @DISPID(2593)
    @PropGet
    boolean allItemsVisible();

    @DISPID(2594)
    void clearManualFilter();

    @DISPID(2561)
    void clearAllFilters();

    @DISPID(2595)
    void clearValueFilters();

    @DISPID(2596)
    void clearLabelFilters();

    @DISPID(1514)
    void autoSort(
        int order,
        java.lang.String field,
        java.lang.Object pivotLine,
        java.lang.Object customSubtotal);

    @DISPID(2599)
    @PropGet
    java.lang.String sourceCaption();

    @DISPID(585)
    @PropGet
    boolean showDetail();

    @DISPID(585)
    @PropPut
    void showDetail(
        boolean rhs);

}
