package mol.excel  ;

import com4j.*;

@IID("{00020400-0000-0000-C000-000000000046}")
public interface PivotTable extends Com4jObject {
    @DISPID(148)
    @PropGet
    mol.excel._Application application();

    @DISPID(149)
    @PropGet
    mol.excel.XlCreator creator();

    @DISPID(150)
    @PropGet
    com4j.Com4jObject parent();

    @DISPID(708)
    java.lang.Object addFields(
        java.lang.Object rowFields,
        java.lang.Object columnFields,
        java.lang.Object pageFields,
        java.lang.Object addToTable);

    @DISPID(713)
    @PropGet
    com4j.Com4jObject columnFields(
        java.lang.Object index);

    @DISPID(694)
    @PropGet
    boolean columnGrand();

    @DISPID(694)
    @PropPut
    void columnGrand(
        boolean rhs);

    @DISPID(702)
    @PropGet
    mol.excel.Range columnRange();

    @DISPID(706)
    java.lang.Object showPages(
        java.lang.Object pageField);

    @DISPID(705)
    @PropGet
    mol.excel.Range dataBodyRange();

    @DISPID(715)
    @PropGet
    com4j.Com4jObject dataFields(
        java.lang.Object index);

    @DISPID(704)
    @PropGet
    mol.excel.Range dataLabelRange();

    @DISPID(0)
    @PropGet
    @DefaultMethod
    java.lang.String _Default();

    @DISPID(0)
    @PropPut
    @DefaultMethod
    void _Default(
        java.lang.String rhs);

    @DISPID(695)
    @PropGet
    boolean hasAutoFormat();

    @DISPID(695)
    @PropPut
    void hasAutoFormat(
        boolean rhs);

    @DISPID(711)
    @PropGet
    com4j.Com4jObject hiddenFields(
        java.lang.Object index);

    @DISPID(698)
    @PropGet
    java.lang.String innerDetail();

    @DISPID(698)
    @PropPut
    void innerDetail(
        java.lang.String rhs);

    @DISPID(110)
    @PropGet
    java.lang.String name();

    @DISPID(110)
    @PropPut
    void name(
        java.lang.String rhs);

    @DISPID(714)
    @PropGet
    com4j.Com4jObject pageFields(
        java.lang.Object index);

    @DISPID(703)
    @PropGet
    mol.excel.Range pageRange();

    @DISPID(1482)
    @PropGet
    mol.excel.Range pageRangeCells();

    @DISPID(718)
    com4j.Com4jObject pivotFields(
        java.lang.Object index);

    @DISPID(696)
    @PropGet
    java.util.Date refreshDate();

    @DISPID(697)
    @PropGet
    java.lang.String refreshName();

    @DISPID(717)
    boolean refreshTable();

    @DISPID(712)
    @PropGet
    com4j.Com4jObject rowFields(
        java.lang.Object index);

    @DISPID(693)
    @PropGet
    boolean rowGrand();

    @DISPID(693)
    @PropPut
    void rowGrand(
        boolean rhs);

    @DISPID(701)
    @PropGet
    mol.excel.Range rowRange();

    @DISPID(692)
    @PropGet
    boolean saveData();

    @DISPID(692)
    @PropPut
    void saveData(
        boolean rhs);

    @DISPID(686)
    @PropGet
    java.lang.Object sourceData();

    @DISPID(686)
    @PropPut
    void sourceData(
        java.lang.Object rhs);

    @DISPID(699)
    @PropGet
    mol.excel.Range tableRange1();

    @DISPID(700)
    @PropGet
    mol.excel.Range tableRange2();

    @DISPID(6)
    @PropGet
    java.lang.String value();

    @DISPID(6)
    @PropPut
    void value(
        java.lang.String rhs);

    @DISPID(710)
    @PropGet
    com4j.Com4jObject visibleFields(
        java.lang.Object index);

    @DISPID(1483)
    @PropGet
    int cacheIndex();

    @DISPID(1483)
    @PropPut
    void cacheIndex(
        int rhs);

    @DISPID(1484)
    mol.excel.CalculatedFields calculatedFields();

    @DISPID(1485)
    @PropGet
    boolean displayErrorString();

    @DISPID(1485)
    @PropPut
    void displayErrorString(
        boolean rhs);

    @DISPID(1486)
    @PropGet
    boolean displayNullString();

    @DISPID(1486)
    @PropPut
    void displayNullString(
        boolean rhs);

    @DISPID(1487)
    @PropGet
    boolean enableDrilldown();

    @DISPID(1487)
    @PropPut
    void enableDrilldown(
        boolean rhs);

    @DISPID(1488)
    @PropGet
    boolean enableFieldDialog();

    @DISPID(1488)
    @PropPut
    void enableFieldDialog(
        boolean rhs);

    @DISPID(1489)
    @PropGet
    boolean enableWizard();

    @DISPID(1489)
    @PropPut
    void enableWizard(
        boolean rhs);

    @DISPID(1490)
    @PropGet
    java.lang.String errorString();

    @DISPID(1490)
    @PropPut
    void errorString(
        java.lang.String rhs);

    @DISPID(1491)
    double getData(
        java.lang.String name);

    @DISPID(1492)
    void listFormulas();

    @DISPID(1493)
    @PropGet
    boolean manualUpdate();

    @DISPID(1493)
    @PropPut
    void manualUpdate(
        boolean rhs);

    @DISPID(1494)
    @PropGet
    boolean mergeLabels();

    @DISPID(1494)
    @PropPut
    void mergeLabels(
        boolean rhs);

    @DISPID(1495)
    @PropGet
    java.lang.String nullString();

    @DISPID(1495)
    @PropPut
    void nullString(
        java.lang.String rhs);

    @DISPID(1496)
    mol.excel.PivotCache pivotCache();

    @DISPID(1497)
    @PropGet
    mol.excel.PivotFormulas pivotFormulas();

    @DISPID(684)
    void pivotTableWizard(
        java.lang.Object sourceType,
        java.lang.Object sourceData,
        java.lang.Object tableDestination,
        java.lang.Object tableName,
        java.lang.Object rowGrand,
        java.lang.Object columnGrand,
        java.lang.Object saveData,
        java.lang.Object hasAutoFormat,
        java.lang.Object autoPage,
        java.lang.Object reserved,
        java.lang.Object backgroundQuery,
        java.lang.Object optimizeCache,
        java.lang.Object pageFieldOrder,
        java.lang.Object pageFieldWrapCount,
        java.lang.Object readData,
        java.lang.Object connection);

    @DISPID(1498)
    @PropGet
    boolean subtotalHiddenPageItems();

    @DISPID(1498)
    @PropPut
    void subtotalHiddenPageItems(
        boolean rhs);

    @DISPID(1429)
    @PropGet
    int pageFieldOrder();

    @DISPID(1429)
    @PropPut
    void pageFieldOrder(
        int rhs);

    @DISPID(1499)
    @PropGet
    java.lang.String pageFieldStyle();

    @DISPID(1499)
    @PropPut
    void pageFieldStyle(
        java.lang.String rhs);

    @DISPID(1430)
    @PropGet
    int pageFieldWrapCount();

    @DISPID(1430)
    @PropPut
    void pageFieldWrapCount(
        int rhs);

    @DISPID(1500)
    @PropGet
    boolean preserveFormatting();

    @DISPID(1500)
    @PropPut
    void preserveFormatting(
        boolean rhs);

    @DISPID(2087)
    void _PivotSelect(
        java.lang.String name,
        mol.excel.XlPTSelectionMode mode);

    @DISPID(1502)
    @PropGet
    java.lang.String pivotSelection();

    @DISPID(1502)
    @PropPut
    void pivotSelection(
        java.lang.String rhs);

    @DISPID(1503)
    @PropGet
    mol.excel.XlPTSelectionMode selectionMode();

    @DISPID(1503)
    @PropPut
    void selectionMode(
        mol.excel.XlPTSelectionMode rhs);

    @DISPID(1504)
    @PropGet
    java.lang.String tableStyle();

    @DISPID(1504)
    @PropPut
    void tableStyle(
        java.lang.String rhs);

    @DISPID(1505)
    @PropGet
    java.lang.String tag();

    @DISPID(1505)
    @PropPut
    void tag(
        java.lang.String rhs);

    @DISPID(680)
    void update();

    @DISPID(1506)
    @PropGet
    java.lang.String vacatedStyle();

    @DISPID(1506)
    @PropPut
    void vacatedStyle(
        java.lang.String rhs);

    @DISPID(116)
    void format(
        mol.excel.XlPivotFormatType format);

    @DISPID(1838)
    @PropGet
    boolean printTitles();

    @DISPID(1838)
    @PropPut
    void printTitles(
        boolean rhs);

    @DISPID(1839)
    @PropGet
    mol.excel.CubeFields cubeFields();

    @DISPID(1840)
    @PropGet
    java.lang.String grandTotalName();

    @DISPID(1840)
    @PropPut
    void grandTotalName(
        java.lang.String rhs);

    @DISPID(1841)
    @PropGet
    boolean smallGrid();

    @DISPID(1841)
    @PropPut
    void smallGrid(
        boolean rhs);

    @DISPID(1842)
    @PropGet
    boolean repeatItemsOnEachPrintedPage();

    @DISPID(1842)
    @PropPut
    void repeatItemsOnEachPrintedPage(
        boolean rhs);

    @DISPID(1843)
    @PropGet
    boolean totalsAnnotation();

    @DISPID(1843)
    @PropPut
    void totalsAnnotation(
        boolean rhs);

    @DISPID(1501)
    void pivotSelect(
        java.lang.String name,
        mol.excel.XlPTSelectionMode mode,
        java.lang.Object useStandardName);

    @DISPID(2089)
    @PropGet
    java.lang.String pivotSelectionStandard();

    @DISPID(2089)
    @PropPut
    void pivotSelectionStandard(
        java.lang.String rhs);

    @DISPID(2090)
    mol.excel.Range getPivotData(
        java.lang.Object dataField,
        java.lang.Object field1,
        java.lang.Object item1,
        java.lang.Object field2,
        java.lang.Object item2,
        java.lang.Object field3,
        java.lang.Object item3,
        java.lang.Object field4,
        java.lang.Object item4,
        java.lang.Object field5,
        java.lang.Object item5,
        java.lang.Object field6,
        java.lang.Object item6,
        java.lang.Object field7,
        java.lang.Object item7,
        java.lang.Object field8,
        java.lang.Object item8,
        java.lang.Object field9,
        java.lang.Object item9,
        java.lang.Object field10,
        java.lang.Object item10,
        java.lang.Object field11,
        java.lang.Object item11,
        java.lang.Object field12,
        java.lang.Object item12,
        java.lang.Object field13,
        java.lang.Object item13,
        java.lang.Object field14,
        java.lang.Object item14);

    @DISPID(2120)
    @PropGet
    mol.excel.PivotField dataPivotField();

    @DISPID(2121)
    @PropGet
    boolean enableDataValueEditing();

    @DISPID(2121)
    @PropPut
    void enableDataValueEditing(
        boolean rhs);

    @DISPID(2122)
    mol.excel.PivotField addDataField(
        com4j.Com4jObject field,
        java.lang.Object caption,
        java.lang.Object function);

    @DISPID(2123)
    @PropGet
    java.lang.String mdx();

    @DISPID(2124)
    @PropGet
    boolean viewCalculatedMembers();

    @DISPID(2124)
    @PropPut
    void viewCalculatedMembers(
        boolean rhs);

    @DISPID(2125)
    @PropGet
    mol.excel.CalculatedMembers calculatedMembers();

    @DISPID(2126)
    @PropGet
    boolean displayImmediateItems();

    @DISPID(2126)
    @PropPut
    void displayImmediateItems(
        boolean rhs);

    @DISPID(2127)
    java.lang.Object dummy15(
        java.lang.Object arg1,
        java.lang.Object arg2,
        java.lang.Object arg3,
        java.lang.Object arg4,
        java.lang.Object arg5,
        java.lang.Object arg6,
        java.lang.Object arg7,
        java.lang.Object arg8,
        java.lang.Object arg9,
        java.lang.Object arg10,
        java.lang.Object arg11,
        java.lang.Object arg12,
        java.lang.Object arg13,
        java.lang.Object arg14,
        java.lang.Object arg15,
        java.lang.Object arg16,
        java.lang.Object arg17,
        java.lang.Object arg18,
        java.lang.Object arg19,
        java.lang.Object arg20,
        java.lang.Object arg21,
        java.lang.Object arg22,
        java.lang.Object arg23,
        java.lang.Object arg24,
        java.lang.Object arg25,
        java.lang.Object arg26,
        java.lang.Object arg27,
        java.lang.Object arg28,
        java.lang.Object arg29,
        java.lang.Object arg30);

    @DISPID(2128)
    @PropGet
    boolean enableFieldList();

    @DISPID(2128)
    @PropPut
    void enableFieldList(
        boolean rhs);

    @DISPID(2129)
    @PropGet
    boolean visualTotals();

    @DISPID(2129)
    @PropPut
    void visualTotals(
        boolean rhs);

    @DISPID(2130)
    @PropGet
    boolean showPageMultipleItemLabel();

    @DISPID(2130)
    @PropPut
    void showPageMultipleItemLabel(
        boolean rhs);

    @DISPID(392)
    @PropGet
    mol.excel.XlPivotTableVersionList version();

    @DISPID(2131)
    java.lang.String createCubeFile(
        java.lang.String file,
        java.lang.Object measures,
        java.lang.Object levels,
        java.lang.Object members,
        java.lang.Object properties);

    @DISPID(2136)
    @PropGet
    boolean displayEmptyRow();

    @DISPID(2136)
    @PropPut
    void displayEmptyRow(
        boolean rhs);

    @DISPID(2137)
    @PropGet
    boolean displayEmptyColumn();

    @DISPID(2137)
    @PropPut
    void displayEmptyColumn(
        boolean rhs);

    @DISPID(2138)
    @PropGet
    boolean showCellBackgroundFromOLAP();

    @DISPID(2138)
    @PropPut
    void showCellBackgroundFromOLAP(
        boolean rhs);

    @DISPID(2546)
    @PropGet
    mol.excel.PivotAxis pivotColumnAxis();

    @DISPID(2547)
    @PropGet
    mol.excel.PivotAxis pivotRowAxis();

    @DISPID(2548)
    @PropGet
    boolean showDrillIndicators();

    @DISPID(2548)
    @PropPut
    void showDrillIndicators(
        boolean rhs);

    @DISPID(2549)
    @PropGet
    boolean printDrillIndicators();

    @DISPID(2549)
    @PropPut
    void printDrillIndicators(
        boolean rhs);

    @DISPID(2550)
    @PropGet
    boolean displayMemberPropertyTooltips();

    @DISPID(2550)
    @PropPut
    void displayMemberPropertyTooltips(
        boolean rhs);

    @DISPID(2551)
    @PropGet
    boolean displayContextTooltips();

    @DISPID(2551)
    @PropPut
    void displayContextTooltips(
        boolean rhs);

    @DISPID(2552)
    void clearTable();

    @DISPID(2553)
    @PropGet
    int compactRowIndent();

    @DISPID(2553)
    @PropPut
    void compactRowIndent(
        int rhs);

    @DISPID(2554)
    @PropGet
    mol.excel.XlLayoutRowType layoutRowDefault();

    @DISPID(2554)
    @PropPut
    void layoutRowDefault(
        mol.excel.XlLayoutRowType rhs);

    @DISPID(2555)
    @PropGet
    boolean displayFieldCaptions();

    @DISPID(2555)
    @PropPut
    void displayFieldCaptions(
        boolean rhs);

    @DISPID(2556)
    void rowAxisLayout(
        mol.excel.XlLayoutRowType rowLayout);

    @DISPID(2558)
    void subtotalLocation(
        mol.excel.XlSubtototalLocationType location);

    @DISPID(2559)
    @PropGet
    mol.excel.PivotFilters activeFilters();

    @DISPID(2560)
    @PropGet
    boolean inGridDropZones();

    @DISPID(2560)
    @PropPut
    void inGridDropZones(
        boolean rhs);

    @DISPID(2561)
    void clearAllFilters();

    @DISPID(2562)
    @PropGet
    java.lang.Object tableStyle2();

    @DISPID(2562)
    @PropPut
    void tableStyle2(
        java.lang.Object rhs);

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

    @DISPID(2566)
    @PropGet
    boolean showTableStyleRowHeaders();

    @DISPID(2566)
    @PropPut
    void showTableStyleRowHeaders(
        boolean rhs);

    @DISPID(2567)
    @PropGet
    boolean showTableStyleColumnHeaders();

    @DISPID(2567)
    @PropPut
    void showTableStyleColumnHeaders(
        boolean rhs);

    @DISPID(2568)
    void convertToFormulas(
        boolean convertFilters);

    @DISPID(2570)
    @PropGet
    boolean allowMultipleFilters();

    @DISPID(2570)
    @PropPut
    void allowMultipleFilters(
        boolean rhs);

    @DISPID(2571)
    @PropGet
    java.lang.String compactLayoutRowHeader();

    @DISPID(2571)
    @PropPut
    void compactLayoutRowHeader(
        java.lang.String rhs);

    @DISPID(2572)
    @PropGet
    java.lang.String compactLayoutColumnHeader();

    @DISPID(2572)
    @PropPut
    void compactLayoutColumnHeader(
        java.lang.String rhs);

    @DISPID(2573)
    @PropGet
    boolean fieldListSortAscending();

    @DISPID(2573)
    @PropPut
    void fieldListSortAscending(
        boolean rhs);

    @DISPID(2574)
    @PropGet
    boolean sortUsingCustomLists();

    @DISPID(2574)
    @PropPut
    void sortUsingCustomLists(
        boolean rhs);

    @DISPID(2575)
    void changeConnection(
        mol.excel.WorkbookConnection conn);

    @DISPID(2577)
    void changePivotCache(
        java.lang.Object pivotCache);

    @DISPID(1397)
    @PropGet
    java.lang.String location();

    @DISPID(1397)
    @PropPut
    void location(
        java.lang.String rhs);

}
