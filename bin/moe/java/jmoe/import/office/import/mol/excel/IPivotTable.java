package mol.excel  ;

import com4j.*;

@IID("{00020872-0001-0000-C000-000000000046}")
public interface IPivotTable extends Com4jObject {
    @VTID(7)
    mol.excel._Application application();

    @VTID(8)
    mol.excel.XlCreator creator();

    @VTID(9)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

    @VTID(10)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object addFields(
        @MarshalAs(NativeType.VARIANT) java.lang.Object rowFields,
        @MarshalAs(NativeType.VARIANT) java.lang.Object columnFields,
        @MarshalAs(NativeType.VARIANT) java.lang.Object pageFields,
        @MarshalAs(NativeType.VARIANT) java.lang.Object addToTable);

    @VTID(11)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject columnFields(
        @MarshalAs(NativeType.VARIANT) java.lang.Object index);

    @VTID(12)
    boolean columnGrand();

    @VTID(13)
    void columnGrand(
        boolean rhs);

    @VTID(14)
    mol.excel.Range columnRange();

    @VTID(15)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object showPages(
        @MarshalAs(NativeType.VARIANT) java.lang.Object pageField);

    @VTID(16)
    mol.excel.Range dataBodyRange();

    @VTID(17)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject dataFields(
        @MarshalAs(NativeType.VARIANT) java.lang.Object index);

    @VTID(18)
    mol.excel.Range dataLabelRange();

    @VTID(19)
    @DefaultMethod
    java.lang.String _Default();

    @VTID(20)
    @DefaultMethod
    void _Default(
        java.lang.String rhs);

    @VTID(21)
    boolean hasAutoFormat();

    @VTID(22)
    void hasAutoFormat(
        boolean rhs);

    @VTID(23)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject hiddenFields(
        @MarshalAs(NativeType.VARIANT) java.lang.Object index);

    @VTID(24)
    java.lang.String innerDetail();

    @VTID(25)
    void innerDetail(
        java.lang.String rhs);

    @VTID(26)
    java.lang.String name();

    @VTID(27)
    void name(
        java.lang.String rhs);

    @VTID(28)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject pageFields(
        @MarshalAs(NativeType.VARIANT) java.lang.Object index);

    @VTID(29)
    mol.excel.Range pageRange();

    @VTID(30)
    mol.excel.Range pageRangeCells();

    @VTID(31)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject pivotFields(
        @MarshalAs(NativeType.VARIANT) java.lang.Object index);

    @VTID(32)
    java.util.Date refreshDate();

    @VTID(33)
    java.lang.String refreshName();

    @VTID(34)
    boolean refreshTable();

    @VTID(35)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject rowFields(
        @MarshalAs(NativeType.VARIANT) java.lang.Object index);

    @VTID(36)
    boolean rowGrand();

    @VTID(37)
    void rowGrand(
        boolean rhs);

    @VTID(38)
    mol.excel.Range rowRange();

    @VTID(39)
    boolean saveData();

    @VTID(40)
    void saveData(
        boolean rhs);

    @VTID(41)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object sourceData();

    @VTID(42)
    void sourceData(
        @MarshalAs(NativeType.VARIANT) java.lang.Object rhs);

    @VTID(43)
    mol.excel.Range tableRange1();

    @VTID(44)
    mol.excel.Range tableRange2();

    @VTID(45)
    java.lang.String value();

    @VTID(46)
    void value(
        java.lang.String rhs);

    @VTID(47)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject visibleFields(
        @MarshalAs(NativeType.VARIANT) java.lang.Object index);

    @VTID(48)
    int cacheIndex();

    @VTID(49)
    void cacheIndex(
        int rhs);

    @VTID(50)
    mol.excel.CalculatedFields calculatedFields();

    @VTID(51)
    boolean displayErrorString();

    @VTID(52)
    void displayErrorString(
        boolean rhs);

    @VTID(53)
    boolean displayNullString();

    @VTID(54)
    void displayNullString(
        boolean rhs);

    @VTID(55)
    boolean enableDrilldown();

    @VTID(56)
    void enableDrilldown(
        boolean rhs);

    @VTID(57)
    boolean enableFieldDialog();

    @VTID(58)
    void enableFieldDialog(
        boolean rhs);

    @VTID(59)
    boolean enableWizard();

    @VTID(60)
    void enableWizard(
        boolean rhs);

    @VTID(61)
    java.lang.String errorString();

    @VTID(62)
    void errorString(
        java.lang.String rhs);

    @VTID(63)
    double getData(
        java.lang.String name);

    @VTID(64)
    void listFormulas();

    @VTID(65)
    boolean manualUpdate();

    @VTID(66)
    void manualUpdate(
        boolean rhs);

    @VTID(67)
    boolean mergeLabels();

    @VTID(68)
    void mergeLabels(
        boolean rhs);

    @VTID(69)
    java.lang.String nullString();

    @VTID(70)
    void nullString(
        java.lang.String rhs);

    @VTID(71)
    mol.excel.PivotCache pivotCache();

    @VTID(72)
    mol.excel.PivotFormulas pivotFormulas();

    @VTID(73)
    void pivotTableWizard(
        @MarshalAs(NativeType.VARIANT) java.lang.Object sourceType,
        @MarshalAs(NativeType.VARIANT) java.lang.Object sourceData,
        @MarshalAs(NativeType.VARIANT) java.lang.Object tableDestination,
        @MarshalAs(NativeType.VARIANT) java.lang.Object tableName,
        @MarshalAs(NativeType.VARIANT) java.lang.Object rowGrand,
        @MarshalAs(NativeType.VARIANT) java.lang.Object columnGrand,
        @MarshalAs(NativeType.VARIANT) java.lang.Object saveData,
        @MarshalAs(NativeType.VARIANT) java.lang.Object hasAutoFormat,
        @MarshalAs(NativeType.VARIANT) java.lang.Object autoPage,
        @MarshalAs(NativeType.VARIANT) java.lang.Object reserved,
        @MarshalAs(NativeType.VARIANT) java.lang.Object backgroundQuery,
        @MarshalAs(NativeType.VARIANT) java.lang.Object optimizeCache,
        @MarshalAs(NativeType.VARIANT) java.lang.Object pageFieldOrder,
        @MarshalAs(NativeType.VARIANT) java.lang.Object pageFieldWrapCount,
        @MarshalAs(NativeType.VARIANT) java.lang.Object readData,
        @MarshalAs(NativeType.VARIANT) java.lang.Object connection);

    @VTID(74)
    boolean subtotalHiddenPageItems();

    @VTID(75)
    void subtotalHiddenPageItems(
        boolean rhs);

    @VTID(76)
    int pageFieldOrder();

    @VTID(77)
    void pageFieldOrder(
        int rhs);

    @VTID(78)
    java.lang.String pageFieldStyle();

    @VTID(79)
    void pageFieldStyle(
        java.lang.String rhs);

    @VTID(80)
    int pageFieldWrapCount();

    @VTID(81)
    void pageFieldWrapCount(
        int rhs);

    @VTID(82)
    boolean preserveFormatting();

    @VTID(83)
    void preserveFormatting(
        boolean rhs);

    @VTID(84)
    void _PivotSelect(
        java.lang.String name,
        mol.excel.XlPTSelectionMode mode);

    @VTID(85)
    java.lang.String pivotSelection();

    @VTID(86)
    void pivotSelection(
        java.lang.String rhs);

    @VTID(87)
    mol.excel.XlPTSelectionMode selectionMode();

    @VTID(88)
    void selectionMode(
        mol.excel.XlPTSelectionMode rhs);

    @VTID(89)
    java.lang.String tableStyle();

    @VTID(90)
    void tableStyle(
        java.lang.String rhs);

    @VTID(91)
    java.lang.String tag();

    @VTID(92)
    void tag(
        java.lang.String rhs);

    @VTID(93)
    void update();

    @VTID(94)
    java.lang.String vacatedStyle();

    @VTID(95)
    void vacatedStyle(
        java.lang.String rhs);

    @VTID(96)
    void format(
        mol.excel.XlPivotFormatType format);

    @VTID(97)
    boolean printTitles();

    @VTID(98)
    void printTitles(
        boolean rhs);

    @VTID(99)
    mol.excel.CubeFields cubeFields();

    @VTID(99)
    @ReturnValue(defaultPropertyThrough={mol.excel.CubeFields.class})
    mol.excel.CubeField cubeFields(
        @MarshalAs(NativeType.VARIANT) java.lang.Object index);

    @VTID(100)
    java.lang.String grandTotalName();

    @VTID(101)
    void grandTotalName(
        java.lang.String rhs);

    @VTID(102)
    boolean smallGrid();

    @VTID(103)
    void smallGrid(
        boolean rhs);

    @VTID(104)
    boolean repeatItemsOnEachPrintedPage();

    @VTID(105)
    void repeatItemsOnEachPrintedPage(
        boolean rhs);

    @VTID(106)
    boolean totalsAnnotation();

    @VTID(107)
    void totalsAnnotation(
        boolean rhs);

    @VTID(108)
    void pivotSelect(
        java.lang.String name,
        mol.excel.XlPTSelectionMode mode,
        @MarshalAs(NativeType.VARIANT) java.lang.Object useStandardName);

    @VTID(109)
    java.lang.String pivotSelectionStandard();

    @VTID(110)
    void pivotSelectionStandard(
        java.lang.String rhs);

    @VTID(111)
    mol.excel.Range getPivotData(
        @MarshalAs(NativeType.VARIANT) java.lang.Object dataField,
        @MarshalAs(NativeType.VARIANT) java.lang.Object field1,
        @MarshalAs(NativeType.VARIANT) java.lang.Object item1,
        @MarshalAs(NativeType.VARIANT) java.lang.Object field2,
        @MarshalAs(NativeType.VARIANT) java.lang.Object item2,
        @MarshalAs(NativeType.VARIANT) java.lang.Object field3,
        @MarshalAs(NativeType.VARIANT) java.lang.Object item3,
        @MarshalAs(NativeType.VARIANT) java.lang.Object field4,
        @MarshalAs(NativeType.VARIANT) java.lang.Object item4,
        @MarshalAs(NativeType.VARIANT) java.lang.Object field5,
        @MarshalAs(NativeType.VARIANT) java.lang.Object item5,
        @MarshalAs(NativeType.VARIANT) java.lang.Object field6,
        @MarshalAs(NativeType.VARIANT) java.lang.Object item6,
        @MarshalAs(NativeType.VARIANT) java.lang.Object field7,
        @MarshalAs(NativeType.VARIANT) java.lang.Object item7,
        @MarshalAs(NativeType.VARIANT) java.lang.Object field8,
        @MarshalAs(NativeType.VARIANT) java.lang.Object item8,
        @MarshalAs(NativeType.VARIANT) java.lang.Object field9,
        @MarshalAs(NativeType.VARIANT) java.lang.Object item9,
        @MarshalAs(NativeType.VARIANT) java.lang.Object field10,
        @MarshalAs(NativeType.VARIANT) java.lang.Object item10,
        @MarshalAs(NativeType.VARIANT) java.lang.Object field11,
        @MarshalAs(NativeType.VARIANT) java.lang.Object item11,
        @MarshalAs(NativeType.VARIANT) java.lang.Object field12,
        @MarshalAs(NativeType.VARIANT) java.lang.Object item12,
        @MarshalAs(NativeType.VARIANT) java.lang.Object field13,
        @MarshalAs(NativeType.VARIANT) java.lang.Object item13,
        @MarshalAs(NativeType.VARIANT) java.lang.Object field14,
        @MarshalAs(NativeType.VARIANT) java.lang.Object item14);

    @VTID(112)
    mol.excel.PivotField dataPivotField();

    @VTID(113)
    boolean enableDataValueEditing();

    @VTID(114)
    void enableDataValueEditing(
        boolean rhs);

    @VTID(115)
    mol.excel.PivotField addDataField(
        @MarshalAs(NativeType.Dispatch) com4j.Com4jObject field,
        @MarshalAs(NativeType.VARIANT) java.lang.Object caption,
        @MarshalAs(NativeType.VARIANT) java.lang.Object function);

    @VTID(116)
    java.lang.String mdx();

    @VTID(117)
    boolean viewCalculatedMembers();

    @VTID(118)
    void viewCalculatedMembers(
        boolean rhs);

    @VTID(119)
    mol.excel.CalculatedMembers calculatedMembers();

    @VTID(120)
    boolean displayImmediateItems();

    @VTID(121)
    void displayImmediateItems(
        boolean rhs);

    @VTID(122)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object dummy15(
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg1,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg2,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg3,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg4,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg5,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg6,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg7,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg8,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg9,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg10,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg11,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg12,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg13,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg14,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg15,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg16,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg17,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg18,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg19,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg20,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg21,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg22,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg23,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg24,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg25,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg26,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg27,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg28,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg29,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg30);

    @VTID(123)
    boolean enableFieldList();

    @VTID(124)
    void enableFieldList(
        boolean rhs);

    @VTID(125)
    boolean visualTotals();

    @VTID(126)
    void visualTotals(
        boolean rhs);

    @VTID(127)
    boolean showPageMultipleItemLabel();

    @VTID(128)
    void showPageMultipleItemLabel(
        boolean rhs);

    @VTID(129)
    mol.excel.XlPivotTableVersionList version();

    @VTID(130)
    java.lang.String createCubeFile(
        java.lang.String file,
        @MarshalAs(NativeType.VARIANT) java.lang.Object measures,
        @MarshalAs(NativeType.VARIANT) java.lang.Object levels,
        @MarshalAs(NativeType.VARIANT) java.lang.Object members,
        @MarshalAs(NativeType.VARIANT) java.lang.Object properties);

    @VTID(131)
    boolean displayEmptyRow();

    @VTID(132)
    void displayEmptyRow(
        boolean rhs);

    @VTID(133)
    boolean displayEmptyColumn();

    @VTID(134)
    void displayEmptyColumn(
        boolean rhs);

    @VTID(135)
    boolean showCellBackgroundFromOLAP();

    @VTID(136)
    void showCellBackgroundFromOLAP(
        boolean rhs);

    @VTID(137)
    mol.excel.PivotAxis pivotColumnAxis();

    @VTID(138)
    mol.excel.PivotAxis pivotRowAxis();

    @VTID(139)
    boolean showDrillIndicators();

    @VTID(140)
    void showDrillIndicators(
        boolean rhs);

    @VTID(141)
    boolean printDrillIndicators();

    @VTID(142)
    void printDrillIndicators(
        boolean rhs);

    @VTID(143)
    boolean displayMemberPropertyTooltips();

    @VTID(144)
    void displayMemberPropertyTooltips(
        boolean rhs);

    @VTID(145)
    boolean displayContextTooltips();

    @VTID(146)
    void displayContextTooltips(
        boolean rhs);

    @VTID(147)
    void clearTable();

    @VTID(148)
    int compactRowIndent();

    @VTID(149)
    void compactRowIndent(
        int rhs);

    @VTID(150)
    mol.excel.XlLayoutRowType layoutRowDefault();

    @VTID(151)
    void layoutRowDefault(
        mol.excel.XlLayoutRowType rhs);

    @VTID(152)
    boolean displayFieldCaptions();

    @VTID(153)
    void displayFieldCaptions(
        boolean rhs);

    @VTID(154)
    void rowAxisLayout(
        mol.excel.XlLayoutRowType rowLayout);

    @VTID(155)
    void subtotalLocation(
        mol.excel.XlSubtototalLocationType location);

    @VTID(156)
    mol.excel.PivotFilters activeFilters();

    @VTID(157)
    boolean inGridDropZones();

    @VTID(158)
    void inGridDropZones(
        boolean rhs);

    @VTID(159)
    void clearAllFilters();

    @VTID(160)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object tableStyle2();

    @VTID(161)
    void tableStyle2(
        @MarshalAs(NativeType.VARIANT) java.lang.Object rhs);

    @VTID(162)
    boolean showTableStyleLastColumn();

    @VTID(163)
    void showTableStyleLastColumn(
        boolean rhs);

    @VTID(164)
    boolean showTableStyleRowStripes();

    @VTID(165)
    void showTableStyleRowStripes(
        boolean rhs);

    @VTID(166)
    boolean showTableStyleColumnStripes();

    @VTID(167)
    void showTableStyleColumnStripes(
        boolean rhs);

    @VTID(168)
    boolean showTableStyleRowHeaders();

    @VTID(169)
    void showTableStyleRowHeaders(
        boolean rhs);

    @VTID(170)
    boolean showTableStyleColumnHeaders();

    @VTID(171)
    void showTableStyleColumnHeaders(
        boolean rhs);

    @VTID(172)
    void convertToFormulas(
        boolean convertFilters);

    @VTID(173)
    boolean allowMultipleFilters();

    @VTID(174)
    void allowMultipleFilters(
        boolean rhs);

    @VTID(175)
    java.lang.String compactLayoutRowHeader();

    @VTID(176)
    void compactLayoutRowHeader(
        java.lang.String rhs);

    @VTID(177)
    java.lang.String compactLayoutColumnHeader();

    @VTID(178)
    void compactLayoutColumnHeader(
        java.lang.String rhs);

    @VTID(179)
    boolean fieldListSortAscending();

    @VTID(180)
    void fieldListSortAscending(
        boolean rhs);

    @VTID(181)
    boolean sortUsingCustomLists();

    @VTID(182)
    void sortUsingCustomLists(
        boolean rhs);

    @VTID(183)
    void changeConnection(
        mol.excel.WorkbookConnection conn);

    @VTID(184)
    void changePivotCache(
        @MarshalAs(NativeType.VARIANT) java.lang.Object pivotCache);

    @VTID(185)
    java.lang.String location();

    @VTID(186)
    void location(
        java.lang.String rhs);

}
