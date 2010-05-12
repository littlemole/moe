package mol.excel  ;

import com4j.*;
import mol.office.*;
import mol.vba.*;

@IID("{000208D8-0000-0000-C000-000000000046}")
public interface _Worksheet extends Com4jObject {
    @VTID(7)
    mol.excel._Application application();

    @VTID(8)
    mol.excel.XlCreator creator();

    @VTID(9)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

    @VTID(10)
    void activate(
        int lcid);

    @VTID(11)
    void copy(
        @MarshalAs(NativeType.VARIANT) java.lang.Object before,
        @MarshalAs(NativeType.VARIANT) java.lang.Object after,
        int lcid);

    @VTID(12)
    void delete(
        int lcid);

    @VTID(13)
    java.lang.String codeName();

    @VTID(14)
    java.lang.String _CodeName();

    @VTID(15)
    void _CodeName(
        java.lang.String rhs);

    @VTID(16)
    int index(
        int lcid);

    @VTID(17)
    void move(
        @MarshalAs(NativeType.VARIANT) java.lang.Object before,
        @MarshalAs(NativeType.VARIANT) java.lang.Object after,
        int lcid);

    @VTID(18)
    java.lang.String name();

    @VTID(19)
    void name(
        java.lang.String rhs);

    @VTID(20)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject next();

    @VTID(21)
    java.lang.String onDoubleClick(
        int lcid);

    @VTID(22)
    void onDoubleClick(
        int lcid,
        java.lang.String rhs);

    @VTID(23)
    java.lang.String onSheetActivate(
        int lcid);

    @VTID(24)
    void onSheetActivate(
        int lcid,
        java.lang.String rhs);

    @VTID(25)
    java.lang.String onSheetDeactivate(
        int lcid);

    @VTID(26)
    void onSheetDeactivate(
        int lcid,
        java.lang.String rhs);

    @VTID(27)
    mol.excel.PageSetup pageSetup();

    @VTID(28)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject previous();

    @VTID(29)
    void __PrintOut(
        @MarshalAs(NativeType.VARIANT) java.lang.Object from,
        @MarshalAs(NativeType.VARIANT) java.lang.Object to,
        @MarshalAs(NativeType.VARIANT) java.lang.Object copies,
        @MarshalAs(NativeType.VARIANT) java.lang.Object preview,
        @MarshalAs(NativeType.VARIANT) java.lang.Object activePrinter,
        @MarshalAs(NativeType.VARIANT) java.lang.Object printToFile,
        @MarshalAs(NativeType.VARIANT) java.lang.Object collate,
        int lcid);

    @VTID(30)
    void printPreview(
        @MarshalAs(NativeType.VARIANT) java.lang.Object enableChanges,
        int lcid);

    @VTID(31)
    void _Protect(
        @MarshalAs(NativeType.VARIANT) java.lang.Object password,
        @MarshalAs(NativeType.VARIANT) java.lang.Object drawingObjects,
        @MarshalAs(NativeType.VARIANT) java.lang.Object contents,
        @MarshalAs(NativeType.VARIANT) java.lang.Object scenarios,
        @MarshalAs(NativeType.VARIANT) java.lang.Object userInterfaceOnly,
        int lcid);

    @VTID(32)
    boolean protectContents(
        int lcid);

    @VTID(33)
    boolean protectDrawingObjects(
        int lcid);

    @VTID(34)
    boolean protectionMode(
        int lcid);

    @VTID(35)
    boolean protectScenarios(
        int lcid);

    @VTID(36)
    void _SaveAs(
        java.lang.String filename,
        @MarshalAs(NativeType.VARIANT) java.lang.Object fileFormat,
        @MarshalAs(NativeType.VARIANT) java.lang.Object password,
        @MarshalAs(NativeType.VARIANT) java.lang.Object writeResPassword,
        @MarshalAs(NativeType.VARIANT) java.lang.Object readOnlyRecommended,
        @MarshalAs(NativeType.VARIANT) java.lang.Object createBackup,
        @MarshalAs(NativeType.VARIANT) java.lang.Object addToMru,
        @MarshalAs(NativeType.VARIANT) java.lang.Object textCodepage,
        @MarshalAs(NativeType.VARIANT) java.lang.Object textVisualLayout,
        int lcid);

    @VTID(37)
    void select(
        @MarshalAs(NativeType.VARIANT) java.lang.Object replace,
        int lcid);

    @VTID(38)
    void unprotect(
        @MarshalAs(NativeType.VARIANT) java.lang.Object password,
        int lcid);

    @VTID(39)
    mol.excel.XlSheetVisibility visible(
        int lcid);

    @VTID(40)
    void visible(
        int lcid,
        mol.excel.XlSheetVisibility rhs);

    @VTID(41)
    mol.excel.Shapes shapes();

    @VTID(42)
    boolean transitionExpEval(
        int lcid);

    @VTID(43)
    void transitionExpEval(
        int lcid,
        boolean rhs);

    @VTID(44)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject arcs(
        @MarshalAs(NativeType.VARIANT) java.lang.Object index,
        int lcid);

    @VTID(45)
    boolean autoFilterMode(
        int lcid);

    @VTID(46)
    void autoFilterMode(
        int lcid,
        boolean rhs);

    @VTID(47)
    void setBackgroundPicture(
        java.lang.String filename);

    @VTID(48)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject buttons(
        @MarshalAs(NativeType.VARIANT) java.lang.Object index,
        int lcid);

    @VTID(49)
    void calculate(
        int lcid);

    @VTID(50)
    boolean enableCalculation();

    @VTID(51)
    void enableCalculation(
        boolean rhs);

    @VTID(52)
    mol.excel.Range cells();

    @VTID(53)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject chartObjects(
        @MarshalAs(NativeType.VARIANT) java.lang.Object index,
        int lcid);

    @VTID(54)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject checkBoxes(
        @MarshalAs(NativeType.VARIANT) java.lang.Object index,
        int lcid);

    @VTID(55)
    void checkSpelling(
        @MarshalAs(NativeType.VARIANT) java.lang.Object customDictionary,
        @MarshalAs(NativeType.VARIANT) java.lang.Object ignoreUppercase,
        @MarshalAs(NativeType.VARIANT) java.lang.Object alwaysSuggest,
        @MarshalAs(NativeType.VARIANT) java.lang.Object spellLang,
        int lcid);

    @VTID(56)
    mol.excel.Range circularReference(
        int lcid);

    @VTID(57)
    void clearArrows(
        int lcid);

    @VTID(58)
    mol.excel.Range columns();

    @VTID(59)
    mol.excel.XlConsolidationFunction consolidationFunction(
        int lcid);

    @VTID(60)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object consolidationOptions(
        int lcid);

    @VTID(61)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object consolidationSources(
        int lcid);

    @VTID(62)
    boolean displayAutomaticPageBreaks(
        int lcid);

    @VTID(63)
    void displayAutomaticPageBreaks(
        int lcid,
        boolean rhs);

    @VTID(64)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject drawings(
        @MarshalAs(NativeType.VARIANT) java.lang.Object index,
        int lcid);

    @VTID(65)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject drawingObjects(
        @MarshalAs(NativeType.VARIANT) java.lang.Object index,
        int lcid);

    @VTID(66)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject dropDowns(
        @MarshalAs(NativeType.VARIANT) java.lang.Object index,
        int lcid);

    @VTID(67)
    boolean enableAutoFilter(
        int lcid);

    @VTID(68)
    void enableAutoFilter(
        int lcid,
        boolean rhs);

    @VTID(69)
    mol.excel.XlEnableSelection enableSelection();

    @VTID(70)
    void enableSelection(
        mol.excel.XlEnableSelection rhs);

    @VTID(71)
    boolean enableOutlining(
        int lcid);

    @VTID(72)
    void enableOutlining(
        int lcid,
        boolean rhs);

    @VTID(73)
    boolean enablePivotTable(
        int lcid);

    @VTID(74)
    void enablePivotTable(
        int lcid,
        boolean rhs);

    @VTID(75)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object evaluate(
        @MarshalAs(NativeType.VARIANT) java.lang.Object name,
        int lcid);

    @VTID(76)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object _Evaluate(
        @MarshalAs(NativeType.VARIANT) java.lang.Object name,
        int lcid);

    @VTID(77)
    boolean filterMode(
        int lcid);

    @VTID(78)
    void resetAllPageBreaks();

    @VTID(79)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject groupBoxes(
        @MarshalAs(NativeType.VARIANT) java.lang.Object index,
        int lcid);

    @VTID(80)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject groupObjects(
        @MarshalAs(NativeType.VARIANT) java.lang.Object index,
        int lcid);

    @VTID(81)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject labels(
        @MarshalAs(NativeType.VARIANT) java.lang.Object index,
        int lcid);

    @VTID(82)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject lines(
        @MarshalAs(NativeType.VARIANT) java.lang.Object index,
        int lcid);

    @VTID(83)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject listBoxes(
        @MarshalAs(NativeType.VARIANT) java.lang.Object index,
        int lcid);

    @VTID(84)
    mol.excel.Names names();

    @VTID(85)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject oleObjects(
        @MarshalAs(NativeType.VARIANT) java.lang.Object index,
        int lcid);

    @VTID(86)
    java.lang.String onCalculate(
        int lcid);

    @VTID(87)
    void onCalculate(
        int lcid,
        java.lang.String rhs);

    @VTID(88)
    java.lang.String onData(
        int lcid);

    @VTID(89)
    void onData(
        int lcid,
        java.lang.String rhs);

    @VTID(90)
    java.lang.String onEntry(
        int lcid);

    @VTID(91)
    void onEntry(
        int lcid,
        java.lang.String rhs);

    @VTID(92)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject optionButtons(
        @MarshalAs(NativeType.VARIANT) java.lang.Object index,
        int lcid);

    @VTID(93)
    mol.excel.Outline outline();

    @VTID(94)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject ovals(
        @MarshalAs(NativeType.VARIANT) java.lang.Object index,
        int lcid);

    @VTID(95)
    void paste(
        @MarshalAs(NativeType.VARIANT) java.lang.Object destination,
        @MarshalAs(NativeType.VARIANT) java.lang.Object link,
        int lcid);

    @VTID(96)
    void _PasteSpecial(
        @MarshalAs(NativeType.VARIANT) java.lang.Object format,
        @MarshalAs(NativeType.VARIANT) java.lang.Object link,
        @MarshalAs(NativeType.VARIANT) java.lang.Object displayAsIcon,
        @MarshalAs(NativeType.VARIANT) java.lang.Object iconFileName,
        @MarshalAs(NativeType.VARIANT) java.lang.Object iconIndex,
        @MarshalAs(NativeType.VARIANT) java.lang.Object iconLabel,
        int lcid);

    @VTID(97)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject pictures(
        @MarshalAs(NativeType.VARIANT) java.lang.Object index,
        int lcid);

    @VTID(98)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject pivotTables(
        @MarshalAs(NativeType.VARIANT) java.lang.Object index,
        int lcid);

    @VTID(99)
    mol.excel.PivotTable pivotTableWizard(
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
        @MarshalAs(NativeType.VARIANT) java.lang.Object connection,
        int lcid);

    @VTID(100)
    mol.excel.Range range(
        @MarshalAs(NativeType.VARIANT) java.lang.Object cell1,
        @MarshalAs(NativeType.VARIANT) java.lang.Object cell2);

    @VTID(101)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject rectangles(
        @MarshalAs(NativeType.VARIANT) java.lang.Object index,
        int lcid);

    @VTID(102)
    mol.excel.Range rows();

    @VTID(103)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject scenarios(
        @MarshalAs(NativeType.VARIANT) java.lang.Object index,
        int lcid);

    @VTID(104)
    java.lang.String scrollArea();

    @VTID(105)
    void scrollArea(
        java.lang.String rhs);

    @VTID(106)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject scrollBars(
        @MarshalAs(NativeType.VARIANT) java.lang.Object index,
        int lcid);

    @VTID(107)
    void showAllData(
        int lcid);

    @VTID(108)
    void showDataForm(
        int lcid);

    @VTID(109)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject spinners(
        @MarshalAs(NativeType.VARIANT) java.lang.Object index,
        int lcid);

    @VTID(110)
    double standardHeight(
        int lcid);

    @VTID(111)
    double standardWidth(
        int lcid);

    @VTID(112)
    void standardWidth(
        int lcid,
        double rhs);

    @VTID(113)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject textBoxes(
        @MarshalAs(NativeType.VARIANT) java.lang.Object index,
        int lcid);

    @VTID(114)
    boolean transitionFormEntry(
        int lcid);

    @VTID(115)
    void transitionFormEntry(
        int lcid,
        boolean rhs);

    @VTID(116)
    mol.excel.XlSheetType type(
        int lcid);

    @VTID(117)
    mol.excel.Range usedRange(
        int lcid);

    @VTID(118)
    mol.excel.HPageBreaks hPageBreaks();

    @VTID(119)
    mol.excel.VPageBreaks vPageBreaks();

    @VTID(120)
    mol.excel.QueryTables queryTables();

    @VTID(121)
    boolean displayPageBreaks();

    @VTID(122)
    void displayPageBreaks(
        boolean rhs);

    @VTID(123)
    mol.excel.Comments comments();

    @VTID(124)
    mol.excel.Hyperlinks hyperlinks();

    @VTID(125)
    void clearCircles();

    @VTID(126)
    void circleInvalid();

    @VTID(127)
    int _DisplayRightToLeft(
        int lcid);

    @VTID(128)
    void _DisplayRightToLeft(
        int lcid,
        int rhs);

    @VTID(129)
    mol.excel.AutoFilter autoFilter();

    @VTID(130)
    boolean displayRightToLeft(
        int lcid);

    @VTID(131)
    void displayRightToLeft(
        int lcid,
        boolean rhs);

    @VTID(132)
    mol.office.Scripts scripts();

    @VTID(132)
    @ReturnValue(defaultPropertyThrough={mol.office.Scripts.class})
    mol.office.Script scripts(
        @MarshalAs(NativeType.VARIANT) java.lang.Object index);

    @VTID(133)
    void _PrintOut(
        @MarshalAs(NativeType.VARIANT) java.lang.Object from,
        @MarshalAs(NativeType.VARIANT) java.lang.Object to,
        @MarshalAs(NativeType.VARIANT) java.lang.Object copies,
        @MarshalAs(NativeType.VARIANT) java.lang.Object preview,
        @MarshalAs(NativeType.VARIANT) java.lang.Object activePrinter,
        @MarshalAs(NativeType.VARIANT) java.lang.Object printToFile,
        @MarshalAs(NativeType.VARIANT) java.lang.Object collate,
        @MarshalAs(NativeType.VARIANT) java.lang.Object prToFileName,
        int lcid);

    @VTID(134)
    void _CheckSpelling(
        @MarshalAs(NativeType.VARIANT) java.lang.Object customDictionary,
        @MarshalAs(NativeType.VARIANT) java.lang.Object ignoreUppercase,
        @MarshalAs(NativeType.VARIANT) java.lang.Object alwaysSuggest,
        @MarshalAs(NativeType.VARIANT) java.lang.Object spellLang,
        @MarshalAs(NativeType.VARIANT) java.lang.Object ignoreFinalYaa,
        @MarshalAs(NativeType.VARIANT) java.lang.Object spellScript,
        int lcid);

    @VTID(135)
    mol.excel.Tab tab();

    @VTID(136)
    mol.office.IMsoEnvelopeVB mailEnvelope();

    @VTID(137)
    void saveAs(
        java.lang.String filename,
        @MarshalAs(NativeType.VARIANT) java.lang.Object fileFormat,
        @MarshalAs(NativeType.VARIANT) java.lang.Object password,
        @MarshalAs(NativeType.VARIANT) java.lang.Object writeResPassword,
        @MarshalAs(NativeType.VARIANT) java.lang.Object readOnlyRecommended,
        @MarshalAs(NativeType.VARIANT) java.lang.Object createBackup,
        @MarshalAs(NativeType.VARIANT) java.lang.Object addToMru,
        @MarshalAs(NativeType.VARIANT) java.lang.Object textCodepage,
        @MarshalAs(NativeType.VARIANT) java.lang.Object textVisualLayout,
        @MarshalAs(NativeType.VARIANT) java.lang.Object local);

    @VTID(138)
    mol.excel.CustomProperties customProperties();

    @VTID(139)
    mol.excel.SmartTags smartTags();

    @VTID(140)
    mol.excel.Protection protection();

    @VTID(141)
    void pasteSpecial(
        @MarshalAs(NativeType.VARIANT) java.lang.Object format,
        @MarshalAs(NativeType.VARIANT) java.lang.Object link,
        @MarshalAs(NativeType.VARIANT) java.lang.Object displayAsIcon,
        @MarshalAs(NativeType.VARIANT) java.lang.Object iconFileName,
        @MarshalAs(NativeType.VARIANT) java.lang.Object iconIndex,
        @MarshalAs(NativeType.VARIANT) java.lang.Object iconLabel,
        @MarshalAs(NativeType.VARIANT) java.lang.Object noHTMLFormatting,
        int lcid);

    @VTID(142)
    void protect(
        @MarshalAs(NativeType.VARIANT) java.lang.Object password,
        @MarshalAs(NativeType.VARIANT) java.lang.Object drawingObjects,
        @MarshalAs(NativeType.VARIANT) java.lang.Object contents,
        @MarshalAs(NativeType.VARIANT) java.lang.Object scenarios,
        @MarshalAs(NativeType.VARIANT) java.lang.Object userInterfaceOnly,
        @MarshalAs(NativeType.VARIANT) java.lang.Object allowFormattingCells,
        @MarshalAs(NativeType.VARIANT) java.lang.Object allowFormattingColumns,
        @MarshalAs(NativeType.VARIANT) java.lang.Object allowFormattingRows,
        @MarshalAs(NativeType.VARIANT) java.lang.Object allowInsertingColumns,
        @MarshalAs(NativeType.VARIANT) java.lang.Object allowInsertingRows,
        @MarshalAs(NativeType.VARIANT) java.lang.Object allowInsertingHyperlinks,
        @MarshalAs(NativeType.VARIANT) java.lang.Object allowDeletingColumns,
        @MarshalAs(NativeType.VARIANT) java.lang.Object allowDeletingRows,
        @MarshalAs(NativeType.VARIANT) java.lang.Object allowSorting,
        @MarshalAs(NativeType.VARIANT) java.lang.Object allowFiltering,
        @MarshalAs(NativeType.VARIANT) java.lang.Object allowUsingPivotTables);

    @VTID(143)
    mol.excel.ListObjects listObjects();

    @VTID(144)
    mol.excel.Range xmlDataQuery(
        java.lang.String xPath,
        @MarshalAs(NativeType.VARIANT) java.lang.Object selectionNamespaces,
        @MarshalAs(NativeType.VARIANT) java.lang.Object map);

    @VTID(145)
    mol.excel.Range xmlMapQuery(
        java.lang.String xPath,
        @MarshalAs(NativeType.VARIANT) java.lang.Object selectionNamespaces,
        @MarshalAs(NativeType.VARIANT) java.lang.Object map);

    @VTID(146)
    void printOut(
        @MarshalAs(NativeType.VARIANT) java.lang.Object from,
        @MarshalAs(NativeType.VARIANT) java.lang.Object to,
        @MarshalAs(NativeType.VARIANT) java.lang.Object copies,
        @MarshalAs(NativeType.VARIANT) java.lang.Object preview,
        @MarshalAs(NativeType.VARIANT) java.lang.Object activePrinter,
        @MarshalAs(NativeType.VARIANT) java.lang.Object printToFile,
        @MarshalAs(NativeType.VARIANT) java.lang.Object collate,
        @MarshalAs(NativeType.VARIANT) java.lang.Object prToFileName,
        @MarshalAs(NativeType.VARIANT) java.lang.Object ignorePrintAreas,
        int lcid);

    @VTID(147)
    boolean enableFormatConditionsCalculation();

    @VTID(148)
    void enableFormatConditionsCalculation(
        boolean rhs);

    @VTID(149)
    mol.excel.Sort sort();

    @VTID(150)
    void exportAsFixedFormat(
        mol.excel.XlFixedFormatType type,
        @MarshalAs(NativeType.VARIANT) java.lang.Object filename,
        @MarshalAs(NativeType.VARIANT) java.lang.Object quality,
        @MarshalAs(NativeType.VARIANT) java.lang.Object includeDocProperties,
        @MarshalAs(NativeType.VARIANT) java.lang.Object ignorePrintAreas,
        @MarshalAs(NativeType.VARIANT) java.lang.Object from,
        @MarshalAs(NativeType.VARIANT) java.lang.Object to,
        @MarshalAs(NativeType.VARIANT) java.lang.Object openAfterPublish,
        @MarshalAs(NativeType.VARIANT) java.lang.Object fixedFormatExtClassPtr);

}
