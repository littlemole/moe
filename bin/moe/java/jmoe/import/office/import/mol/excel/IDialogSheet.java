package mol.excel  ;

import com4j.*;

@IID("{000208AF-0001-0000-C000-000000000046}")
public interface IDialogSheet extends Com4jObject {
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
    void _Dummy29();

    @VTID(43)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject arcs(
        @MarshalAs(NativeType.VARIANT) java.lang.Object index,
        int lcid);

    @VTID(44)
    void _Dummy31();

    @VTID(45)
    void _Dummy32();

    @VTID(46)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject buttons(
        @MarshalAs(NativeType.VARIANT) java.lang.Object index,
        int lcid);

    @VTID(47)
    void _Dummy34();

    @VTID(48)
    boolean enableCalculation();

    @VTID(49)
    void enableCalculation(
        boolean rhs);

    @VTID(50)
    void _Dummy36();

    @VTID(51)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject chartObjects(
        @MarshalAs(NativeType.VARIANT) java.lang.Object index,
        int lcid);

    @VTID(52)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject checkBoxes(
        @MarshalAs(NativeType.VARIANT) java.lang.Object index,
        int lcid);

    @VTID(53)
    void checkSpelling(
        @MarshalAs(NativeType.VARIANT) java.lang.Object customDictionary,
        @MarshalAs(NativeType.VARIANT) java.lang.Object ignoreUppercase,
        @MarshalAs(NativeType.VARIANT) java.lang.Object alwaysSuggest,
        @MarshalAs(NativeType.VARIANT) java.lang.Object spellLang,
        int lcid);

    @VTID(54)
    void _Dummy40();

    @VTID(55)
    void _Dummy41();

    @VTID(56)
    void _Dummy42();

    @VTID(57)
    void _Dummy43();

    @VTID(58)
    void _Dummy44();

    @VTID(59)
    void _Dummy45();

    @VTID(60)
    boolean displayAutomaticPageBreaks(
        int lcid);

    @VTID(61)
    void displayAutomaticPageBreaks(
        int lcid,
        boolean rhs);

    @VTID(62)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject drawings(
        @MarshalAs(NativeType.VARIANT) java.lang.Object index,
        int lcid);

    @VTID(63)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject drawingObjects(
        @MarshalAs(NativeType.VARIANT) java.lang.Object index,
        int lcid);

    @VTID(64)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject dropDowns(
        @MarshalAs(NativeType.VARIANT) java.lang.Object index,
        int lcid);

    @VTID(65)
    boolean enableAutoFilter(
        int lcid);

    @VTID(66)
    void enableAutoFilter(
        int lcid,
        boolean rhs);

    @VTID(67)
    mol.excel.XlEnableSelection enableSelection();

    @VTID(68)
    void enableSelection(
        mol.excel.XlEnableSelection rhs);

    @VTID(69)
    boolean enableOutlining(
        int lcid);

    @VTID(70)
    void enableOutlining(
        int lcid,
        boolean rhs);

    @VTID(71)
    boolean enablePivotTable(
        int lcid);

    @VTID(72)
    void enablePivotTable(
        int lcid,
        boolean rhs);

    @VTID(73)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object evaluate(
        @MarshalAs(NativeType.VARIANT) java.lang.Object name,
        int lcid);

    @VTID(74)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object _Evaluate(
        @MarshalAs(NativeType.VARIANT) java.lang.Object name,
        int lcid);

    @VTID(75)
    void _Dummy56();

    @VTID(76)
    void resetAllPageBreaks();

    @VTID(77)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject groupBoxes(
        @MarshalAs(NativeType.VARIANT) java.lang.Object index,
        int lcid);

    @VTID(78)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject groupObjects(
        @MarshalAs(NativeType.VARIANT) java.lang.Object index,
        int lcid);

    @VTID(79)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject labels(
        @MarshalAs(NativeType.VARIANT) java.lang.Object index,
        int lcid);

    @VTID(80)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject lines(
        @MarshalAs(NativeType.VARIANT) java.lang.Object index,
        int lcid);

    @VTID(81)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject listBoxes(
        @MarshalAs(NativeType.VARIANT) java.lang.Object index,
        int lcid);

    @VTID(82)
    mol.excel.Names names();

    @VTID(83)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject oleObjects(
        @MarshalAs(NativeType.VARIANT) java.lang.Object index,
        int lcid);

    @VTID(84)
    void _Dummy65();

    @VTID(85)
    void _Dummy66();

    @VTID(86)
    void _Dummy67();

    @VTID(87)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject optionButtons(
        @MarshalAs(NativeType.VARIANT) java.lang.Object index,
        int lcid);

    @VTID(88)
    void _Dummy69();

    @VTID(89)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject ovals(
        @MarshalAs(NativeType.VARIANT) java.lang.Object index,
        int lcid);

    @VTID(90)
    void paste(
        @MarshalAs(NativeType.VARIANT) java.lang.Object destination,
        @MarshalAs(NativeType.VARIANT) java.lang.Object link,
        int lcid);

    @VTID(91)
    void _PasteSpecial(
        @MarshalAs(NativeType.VARIANT) java.lang.Object format,
        @MarshalAs(NativeType.VARIANT) java.lang.Object link,
        @MarshalAs(NativeType.VARIANT) java.lang.Object displayAsIcon,
        @MarshalAs(NativeType.VARIANT) java.lang.Object iconFileName,
        @MarshalAs(NativeType.VARIANT) java.lang.Object iconIndex,
        @MarshalAs(NativeType.VARIANT) java.lang.Object iconLabel,
        int lcid);

    @VTID(92)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject pictures(
        @MarshalAs(NativeType.VARIANT) java.lang.Object index,
        int lcid);

    @VTID(93)
    void _Dummy74();

    @VTID(94)
    void _Dummy75();

    @VTID(95)
    void _Dummy76();

    @VTID(96)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject rectangles(
        @MarshalAs(NativeType.VARIANT) java.lang.Object index,
        int lcid);

    @VTID(97)
    void _Dummy78();

    @VTID(98)
    void _Dummy79();

    @VTID(99)
    java.lang.String scrollArea();

    @VTID(100)
    void scrollArea(
        java.lang.String rhs);

    @VTID(101)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject scrollBars(
        @MarshalAs(NativeType.VARIANT) java.lang.Object index,
        int lcid);

    @VTID(102)
    void _Dummy82();

    @VTID(103)
    void _Dummy83();

    @VTID(104)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject spinners(
        @MarshalAs(NativeType.VARIANT) java.lang.Object index,
        int lcid);

    @VTID(105)
    void _Dummy85();

    @VTID(106)
    void _Dummy86();

    @VTID(107)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject textBoxes(
        @MarshalAs(NativeType.VARIANT) java.lang.Object index,
        int lcid);

    @VTID(108)
    void _Dummy88();

    @VTID(109)
    void _Dummy89();

    @VTID(110)
    void _Dummy90();

    @VTID(111)
    mol.excel.HPageBreaks hPageBreaks();

    @VTID(112)
    mol.excel.VPageBreaks vPageBreaks();

    @VTID(113)
    mol.excel.QueryTables queryTables();

    @VTID(114)
    boolean displayPageBreaks();

    @VTID(115)
    void displayPageBreaks(
        boolean rhs);

    @VTID(116)
    mol.excel.Comments comments();

    @VTID(117)
    mol.excel.Hyperlinks hyperlinks();

    @VTID(118)
    void clearCircles();

    @VTID(119)
    void circleInvalid();

    @VTID(120)
    int _DisplayRightToLeft(
        int lcid);

    @VTID(121)
    void _DisplayRightToLeft(
        int lcid,
        int rhs);

    @VTID(122)
    mol.excel.AutoFilter autoFilter();

    @VTID(123)
    boolean displayRightToLeft(
        int lcid);

    @VTID(124)
    void displayRightToLeft(
        int lcid,
        boolean rhs);

    @VTID(125)
    mol.office.Scripts scripts();

    @VTID(125)
    @ReturnValue(defaultPropertyThrough={mol.office.Scripts.class})
    mol.office.Script scripts(
        @MarshalAs(NativeType.VARIANT) java.lang.Object index);

    @VTID(126)
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

    @VTID(127)
    void _CheckSpelling(
        @MarshalAs(NativeType.VARIANT) java.lang.Object customDictionary,
        @MarshalAs(NativeType.VARIANT) java.lang.Object ignoreUppercase,
        @MarshalAs(NativeType.VARIANT) java.lang.Object alwaysSuggest,
        @MarshalAs(NativeType.VARIANT) java.lang.Object spellLang,
        @MarshalAs(NativeType.VARIANT) java.lang.Object ignoreFinalYaa,
        @MarshalAs(NativeType.VARIANT) java.lang.Object spellScript,
        int lcid);

    @VTID(128)
    mol.excel.Tab tab();

    @VTID(129)
    mol.office.IMsoEnvelopeVB mailEnvelope();

    @VTID(130)
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

    @VTID(131)
    mol.excel.CustomProperties customProperties();

    @VTID(132)
    mol.excel.SmartTags smartTags();

    @VTID(133)
    mol.excel.Protection protection();

    @VTID(134)
    void pasteSpecial(
        @MarshalAs(NativeType.VARIANT) java.lang.Object format,
        @MarshalAs(NativeType.VARIANT) java.lang.Object link,
        @MarshalAs(NativeType.VARIANT) java.lang.Object displayAsIcon,
        @MarshalAs(NativeType.VARIANT) java.lang.Object iconFileName,
        @MarshalAs(NativeType.VARIANT) java.lang.Object iconIndex,
        @MarshalAs(NativeType.VARIANT) java.lang.Object iconLabel,
        @MarshalAs(NativeType.VARIANT) java.lang.Object noHTMLFormatting,
        int lcid);

    @VTID(135)
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

    @VTID(136)
    void _Dummy113();

    @VTID(137)
    void _Dummy114();

    @VTID(138)
    void _Dummy115();

    @VTID(139)
    void printOut(
        @MarshalAs(NativeType.VARIANT) java.lang.Object from,
        @MarshalAs(NativeType.VARIANT) java.lang.Object to,
        @MarshalAs(NativeType.VARIANT) java.lang.Object copies,
        @MarshalAs(NativeType.VARIANT) java.lang.Object preview,
        @MarshalAs(NativeType.VARIANT) java.lang.Object activePrinter,
        @MarshalAs(NativeType.VARIANT) java.lang.Object printToFile,
        @MarshalAs(NativeType.VARIANT) java.lang.Object collate,
        @MarshalAs(NativeType.VARIANT) java.lang.Object prToFileName);

    @VTID(140)
    boolean enableFormatConditionsCalculation();

    @VTID(141)
    void enableFormatConditionsCalculation(
        boolean rhs);

    @VTID(142)
    mol.excel.Sort sort();

    @VTID(143)
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

    @VTID(144)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object defaultButton();

    @VTID(145)
    void defaultButton(
        @MarshalAs(NativeType.VARIANT) java.lang.Object rhs);

    @VTID(146)
    mol.excel.DialogFrame dialogFrame();

    @VTID(147)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject editBoxes(
        @MarshalAs(NativeType.VARIANT) java.lang.Object index);

    @VTID(148)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object focus();

    @VTID(149)
    void focus(
        @MarshalAs(NativeType.VARIANT) java.lang.Object rhs);

    @VTID(150)
    boolean hide(
        @MarshalAs(NativeType.VARIANT) java.lang.Object cancel);

    @VTID(151)
    boolean show();

}
