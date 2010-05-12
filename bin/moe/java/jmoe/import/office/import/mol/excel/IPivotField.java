package mol.excel  ;

import com4j.*;

@IID("{00020874-0001-0000-C000-000000000046}")
public interface IPivotField extends Com4jObject {
    @VTID(7)
    mol.excel._Application application();

    @VTID(8)
    mol.excel.XlCreator creator();

    @VTID(9)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

    @VTID(10)
    mol.excel.XlPivotFieldCalculation calculation();

    @VTID(11)
    void calculation(
        mol.excel.XlPivotFieldCalculation rhs);

    @VTID(12)
    mol.excel.PivotField childField();

    @VTID(13)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object childItems(
        @MarshalAs(NativeType.VARIANT) java.lang.Object index);

    @VTID(14)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object currentPage();

    @VTID(15)
    void currentPage(
        @MarshalAs(NativeType.VARIANT) java.lang.Object rhs);

    @VTID(16)
    mol.excel.Range dataRange();

    @VTID(17)
    mol.excel.XlPivotFieldDataType dataType();

    @VTID(18)
    @DefaultMethod
    java.lang.String _Default();

    @VTID(19)
    @DefaultMethod
    void _Default(
        java.lang.String rhs);

    @VTID(20)
    mol.excel.XlConsolidationFunction function();

    @VTID(21)
    void function(
        mol.excel.XlConsolidationFunction rhs);

    @VTID(22)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object groupLevel();

    @VTID(23)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object hiddenItems(
        @MarshalAs(NativeType.VARIANT) java.lang.Object index);

    @VTID(24)
    mol.excel.Range labelRange();

    @VTID(25)
    java.lang.String name();

    @VTID(26)
    void name(
        java.lang.String rhs);

    @VTID(27)
    java.lang.String numberFormat();

    @VTID(28)
    void numberFormat(
        java.lang.String rhs);

    @VTID(29)
    mol.excel.XlPivotFieldOrientation orientation();

    @VTID(30)
    void orientation(
        mol.excel.XlPivotFieldOrientation rhs);

    @VTID(31)
    boolean showAllItems();

    @VTID(32)
    void showAllItems(
        boolean rhs);

    @VTID(33)
    mol.excel.PivotField parentField();

    @VTID(34)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object parentItems(
        @MarshalAs(NativeType.VARIANT) java.lang.Object index);

    @VTID(35)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object pivotItems(
        @MarshalAs(NativeType.VARIANT) java.lang.Object index);

    @VTID(36)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object position();

    @VTID(37)
    void position(
        @MarshalAs(NativeType.VARIANT) java.lang.Object rhs);

    @VTID(38)
    java.lang.String sourceName();

    @VTID(39)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object subtotals(
        @MarshalAs(NativeType.VARIANT) java.lang.Object index);

    @VTID(40)
    void subtotals(
        @MarshalAs(NativeType.VARIANT) java.lang.Object index,
        @MarshalAs(NativeType.VARIANT) java.lang.Object rhs);

    @VTID(41)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object baseField();

    @VTID(42)
    void baseField(
        @MarshalAs(NativeType.VARIANT) java.lang.Object rhs);

    @VTID(43)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object baseItem();

    @VTID(44)
    void baseItem(
        @MarshalAs(NativeType.VARIANT) java.lang.Object rhs);

    @VTID(45)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object totalLevels();

    @VTID(46)
    java.lang.String value();

    @VTID(47)
    void value(
        java.lang.String rhs);

    @VTID(48)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object visibleItems(
        @MarshalAs(NativeType.VARIANT) java.lang.Object index);

    @VTID(49)
    mol.excel.CalculatedItems calculatedItems();

    @VTID(50)
    void delete();

    @VTID(51)
    boolean dragToColumn();

    @VTID(52)
    void dragToColumn(
        boolean rhs);

    @VTID(53)
    boolean dragToHide();

    @VTID(54)
    void dragToHide(
        boolean rhs);

    @VTID(55)
    boolean dragToPage();

    @VTID(56)
    void dragToPage(
        boolean rhs);

    @VTID(57)
    boolean dragToRow();

    @VTID(58)
    void dragToRow(
        boolean rhs);

    @VTID(59)
    boolean dragToData();

    @VTID(60)
    void dragToData(
        boolean rhs);

    @VTID(61)
    java.lang.String formula();

    @VTID(62)
    void formula(
        java.lang.String rhs);

    @VTID(63)
    boolean isCalculated();

    @VTID(64)
    int memoryUsed();

    @VTID(65)
    boolean serverBased();

    @VTID(66)
    void serverBased(
        boolean rhs);

    @VTID(67)
    void _AutoSort(
        int order,
        java.lang.String field);

    @VTID(68)
    void autoShow(
        int type,
        int range,
        int count,
        java.lang.String field);

    @VTID(69)
    int autoSortOrder();

    @VTID(70)
    java.lang.String autoSortField();

    @VTID(71)
    int autoShowType();

    @VTID(72)
    int autoShowRange();

    @VTID(73)
    int autoShowCount();

    @VTID(74)
    java.lang.String autoShowField();

    @VTID(75)
    boolean layoutBlankLine();

    @VTID(76)
    void layoutBlankLine(
        boolean rhs);

    @VTID(77)
    mol.excel.XlSubtototalLocationType layoutSubtotalLocation();

    @VTID(78)
    void layoutSubtotalLocation(
        mol.excel.XlSubtototalLocationType rhs);

    @VTID(79)
    boolean layoutPageBreak();

    @VTID(80)
    void layoutPageBreak(
        boolean rhs);

    @VTID(81)
    mol.excel.XlLayoutFormType layoutForm();

    @VTID(82)
    void layoutForm(
        mol.excel.XlLayoutFormType rhs);

    @VTID(83)
    java.lang.String subtotalName();

    @VTID(84)
    void subtotalName(
        java.lang.String rhs);

    @VTID(85)
    java.lang.String caption();

    @VTID(86)
    void caption(
        java.lang.String rhs);

    @VTID(87)
    boolean drilledDown();

    @VTID(88)
    void drilledDown(
        boolean rhs);

    @VTID(89)
    mol.excel.CubeField cubeField();

    @VTID(90)
    java.lang.String currentPageName();

    @VTID(91)
    void currentPageName(
        java.lang.String rhs);

    @VTID(92)
    java.lang.String standardFormula();

    @VTID(93)
    void standardFormula(
        java.lang.String rhs);

    @VTID(94)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object hiddenItemsList();

    @VTID(95)
    void hiddenItemsList(
        @MarshalAs(NativeType.VARIANT) java.lang.Object rhs);

    @VTID(96)
    boolean databaseSort();

    @VTID(97)
    void databaseSort(
        boolean rhs);

    @VTID(98)
    boolean isMemberProperty();

    @VTID(99)
    mol.excel.PivotField propertyParentField();

    @VTID(100)
    int propertyOrder();

    @VTID(101)
    void propertyOrder(
        int rhs);

    @VTID(102)
    boolean enableItemSelection();

    @VTID(103)
    void enableItemSelection(
        boolean rhs);

    @VTID(104)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object currentPageList();

    @VTID(105)
    void currentPageList(
        @MarshalAs(NativeType.VARIANT) java.lang.Object rhs);

    @VTID(106)
    void addPageItem(
        java.lang.String item,
        @MarshalAs(NativeType.VARIANT) java.lang.Object clearList);

    @VTID(107)
    boolean hidden();

    @VTID(108)
    void hidden(
        boolean rhs);

    @VTID(109)
    void drillTo(
        java.lang.String field);

    @VTID(110)
    boolean useMemberPropertyAsCaption();

    @VTID(111)
    void useMemberPropertyAsCaption(
        boolean rhs);

    @VTID(112)
    java.lang.String memberPropertyCaption();

    @VTID(113)
    void memberPropertyCaption(
        java.lang.String rhs);

    @VTID(114)
    boolean displayAsTooltip();

    @VTID(115)
    void displayAsTooltip(
        boolean rhs);

    @VTID(116)
    boolean displayInReport();

    @VTID(117)
    void displayInReport(
        boolean rhs);

    @VTID(118)
    boolean displayAsCaption();

    @VTID(119)
    boolean layoutCompactRow();

    @VTID(120)
    void layoutCompactRow(
        boolean rhs);

    @VTID(121)
    boolean includeNewItemsInFilter();

    @VTID(122)
    void includeNewItemsInFilter(
        boolean rhs);

    @VTID(123)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object visibleItemsList();

    @VTID(124)
    void visibleItemsList(
        @MarshalAs(NativeType.VARIANT) java.lang.Object rhs);

    @VTID(125)
    mol.excel.PivotFilters pivotFilters();

    @VTID(126)
    mol.excel.PivotLine autoSortPivotLine();

    @VTID(127)
    int autoSortCustomSubtotal();

    @VTID(128)
    boolean showingInAxis();

    @VTID(129)
    boolean enableMultiplePageItems();

    @VTID(130)
    void enableMultiplePageItems(
        boolean rhs);

    @VTID(131)
    boolean allItemsVisible();

    @VTID(132)
    void clearManualFilter();

    @VTID(133)
    void clearAllFilters();

    @VTID(134)
    void clearValueFilters();

    @VTID(135)
    void clearLabelFilters();

    @VTID(136)
    void autoSort(
        int order,
        java.lang.String field,
        @MarshalAs(NativeType.VARIANT) java.lang.Object pivotLine,
        @MarshalAs(NativeType.VARIANT) java.lang.Object customSubtotal);

    @VTID(137)
    java.lang.String sourceCaption();

    @VTID(138)
    boolean showDetail();

    @VTID(139)
    void showDetail(
        boolean rhs);

}
