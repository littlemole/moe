package mol.excel  ;

import com4j.*;

@IID("{00020400-0000-0000-C000-000000000046}")
public interface DialogSheet extends Com4jObject {
    @DISPID(148)
    @PropGet
    mol.excel._Application application();

    @DISPID(149)
    @PropGet
    mol.excel.XlCreator creator();

    @DISPID(150)
    @PropGet
    com4j.Com4jObject parent();

    @DISPID(304)
    void activate();

    @DISPID(551)
    void copy(
        java.lang.Object before,
        java.lang.Object after);

    @DISPID(117)
    void delete();

    @DISPID(1373)
    @PropGet
    java.lang.String codeName();

    @DISPID(-2147418112)
    @PropGet
    java.lang.String _CodeName();

    @DISPID(-2147418112)
    @PropPut
    void _CodeName(
        java.lang.String rhs);

    @DISPID(486)
    @PropGet
    int index();

    @DISPID(637)
    void move(
        java.lang.Object before,
        java.lang.Object after);

    @DISPID(110)
    @PropGet
    java.lang.String name();

    @DISPID(110)
    @PropPut
    void name(
        java.lang.String rhs);

    @DISPID(502)
    @PropGet
    com4j.Com4jObject next();

    @DISPID(628)
    @PropGet
    java.lang.String onDoubleClick();

    @DISPID(628)
    @PropPut
    void onDoubleClick(
        java.lang.String rhs);

    @DISPID(1031)
    @PropGet
    java.lang.String onSheetActivate();

    @DISPID(1031)
    @PropPut
    void onSheetActivate(
        java.lang.String rhs);

    @DISPID(1081)
    @PropGet
    java.lang.String onSheetDeactivate();

    @DISPID(1081)
    @PropPut
    void onSheetDeactivate(
        java.lang.String rhs);

    @DISPID(998)
    @PropGet
    mol.excel.PageSetup pageSetup();

    @DISPID(503)
    @PropGet
    com4j.Com4jObject previous();

    @DISPID(905)
    void __PrintOut(
        java.lang.Object from,
        java.lang.Object to,
        java.lang.Object copies,
        java.lang.Object preview,
        java.lang.Object activePrinter,
        java.lang.Object printToFile,
        java.lang.Object collate);

    @DISPID(281)
    void printPreview(
        java.lang.Object enableChanges);

    @DISPID(282)
    void _Protect(
        java.lang.Object password,
        java.lang.Object drawingObjects,
        java.lang.Object contents,
        java.lang.Object scenarios,
        java.lang.Object userInterfaceOnly);

    @DISPID(292)
    @PropGet
    boolean protectContents();

    @DISPID(293)
    @PropGet
    boolean protectDrawingObjects();

    @DISPID(1159)
    @PropGet
    boolean protectionMode();

    @DISPID(294)
    @PropGet
    boolean protectScenarios();

    @DISPID(284)
    void _SaveAs(
        java.lang.String filename,
        java.lang.Object fileFormat,
        java.lang.Object password,
        java.lang.Object writeResPassword,
        java.lang.Object readOnlyRecommended,
        java.lang.Object createBackup,
        java.lang.Object addToMru,
        java.lang.Object textCodepage,
        java.lang.Object textVisualLayout);

    @DISPID(235)
    void select(
        java.lang.Object replace);

    @DISPID(285)
    void unprotect(
        java.lang.Object password);

    @DISPID(558)
    @PropGet
    mol.excel.XlSheetVisibility visible();

    @DISPID(558)
    @PropPut
    void visible(
        mol.excel.XlSheetVisibility rhs);

    @DISPID(1377)
    @PropGet
    mol.excel.Shapes shapes();

    @DISPID(65565)
    void _Dummy29();

    @DISPID(760)
    com4j.Com4jObject arcs(
        java.lang.Object index);

    @DISPID(65567)
    void _Dummy31();

    @DISPID(65568)
    void _Dummy32();

    @DISPID(557)
    com4j.Com4jObject buttons(
        java.lang.Object index);

    @DISPID(65570)
    void _Dummy34();

    @DISPID(1424)
    @PropGet
    boolean enableCalculation();

    @DISPID(1424)
    @PropPut
    void enableCalculation(
        boolean rhs);

    @DISPID(65572)
    void _Dummy36();

    @DISPID(1060)
    com4j.Com4jObject chartObjects(
        java.lang.Object index);

    @DISPID(824)
    com4j.Com4jObject checkBoxes(
        java.lang.Object index);

    @DISPID(505)
    void checkSpelling(
        java.lang.Object customDictionary,
        java.lang.Object ignoreUppercase,
        java.lang.Object alwaysSuggest,
        java.lang.Object spellLang);

    @DISPID(65576)
    void _Dummy40();

    @DISPID(65577)
    void _Dummy41();

    @DISPID(65578)
    void _Dummy42();

    @DISPID(65579)
    void _Dummy43();

    @DISPID(65580)
    void _Dummy44();

    @DISPID(65581)
    void _Dummy45();

    @DISPID(643)
    @PropGet
    boolean displayAutomaticPageBreaks();

    @DISPID(643)
    @PropPut
    void displayAutomaticPageBreaks(
        boolean rhs);

    @DISPID(772)
    com4j.Com4jObject drawings(
        java.lang.Object index);

    @DISPID(88)
    com4j.Com4jObject drawingObjects(
        java.lang.Object index);

    @DISPID(836)
    com4j.Com4jObject dropDowns(
        java.lang.Object index);

    @DISPID(1156)
    @PropGet
    boolean enableAutoFilter();

    @DISPID(1156)
    @PropPut
    void enableAutoFilter(
        boolean rhs);

    @DISPID(1425)
    @PropGet
    mol.excel.XlEnableSelection enableSelection();

    @DISPID(1425)
    @PropPut
    void enableSelection(
        mol.excel.XlEnableSelection rhs);

    @DISPID(1157)
    @PropGet
    boolean enableOutlining();

    @DISPID(1157)
    @PropPut
    void enableOutlining(
        boolean rhs);

    @DISPID(1158)
    @PropGet
    boolean enablePivotTable();

    @DISPID(1158)
    @PropPut
    void enablePivotTable(
        boolean rhs);

    @DISPID(1)
    java.lang.Object evaluate(
        java.lang.Object name);

    @DISPID(-5)
    java.lang.Object _Evaluate(
        java.lang.Object name);

    @DISPID(65592)
    void _Dummy56();

    @DISPID(1426)
    void resetAllPageBreaks();

    @DISPID(834)
    com4j.Com4jObject groupBoxes(
        java.lang.Object index);

    @DISPID(1113)
    com4j.Com4jObject groupObjects(
        java.lang.Object index);

    @DISPID(841)
    com4j.Com4jObject labels(
        java.lang.Object index);

    @DISPID(767)
    com4j.Com4jObject lines(
        java.lang.Object index);

    @DISPID(832)
    com4j.Com4jObject listBoxes(
        java.lang.Object index);

    @DISPID(442)
    @PropGet
    mol.excel.Names names();

    @DISPID(799)
    com4j.Com4jObject oleObjects(
        java.lang.Object index);

    @DISPID(65601)
    void _Dummy65();

    @DISPID(65602)
    void _Dummy66();

    @DISPID(65603)
    void _Dummy67();

    @DISPID(826)
    com4j.Com4jObject optionButtons(
        java.lang.Object index);

    @DISPID(65605)
    void _Dummy69();

    @DISPID(801)
    com4j.Com4jObject ovals(
        java.lang.Object index);

    @DISPID(211)
    void paste(
        java.lang.Object destination,
        java.lang.Object link);

    @DISPID(1027)
    void _PasteSpecial(
        java.lang.Object format,
        java.lang.Object link,
        java.lang.Object displayAsIcon,
        java.lang.Object iconFileName,
        java.lang.Object iconIndex,
        java.lang.Object iconLabel);

    @DISPID(771)
    com4j.Com4jObject pictures(
        java.lang.Object index);

    @DISPID(65610)
    void _Dummy74();

    @DISPID(65611)
    void _Dummy75();

    @DISPID(65612)
    void _Dummy76();

    @DISPID(774)
    com4j.Com4jObject rectangles(
        java.lang.Object index);

    @DISPID(65614)
    void _Dummy78();

    @DISPID(65615)
    void _Dummy79();

    @DISPID(1433)
    @PropGet
    java.lang.String scrollArea();

    @DISPID(1433)
    @PropPut
    void scrollArea(
        java.lang.String rhs);

    @DISPID(830)
    com4j.Com4jObject scrollBars(
        java.lang.Object index);

    @DISPID(65618)
    void _Dummy82();

    @DISPID(65619)
    void _Dummy83();

    @DISPID(838)
    com4j.Com4jObject spinners(
        java.lang.Object index);

    @DISPID(65621)
    void _Dummy85();

    @DISPID(65622)
    void _Dummy86();

    @DISPID(777)
    com4j.Com4jObject textBoxes(
        java.lang.Object index);

    @DISPID(65624)
    void _Dummy88();

    @DISPID(65625)
    void _Dummy89();

    @DISPID(65626)
    void _Dummy90();

    @DISPID(1418)
    @PropGet
    mol.excel.HPageBreaks hPageBreaks();

    @DISPID(1419)
    @PropGet
    mol.excel.VPageBreaks vPageBreaks();

    @DISPID(1434)
    @PropGet
    mol.excel.QueryTables queryTables();

    @DISPID(1435)
    @PropGet
    boolean displayPageBreaks();

    @DISPID(1435)
    @PropPut
    void displayPageBreaks(
        boolean rhs);

    @DISPID(575)
    @PropGet
    mol.excel.Comments comments();

    @DISPID(1393)
    @PropGet
    mol.excel.Hyperlinks hyperlinks();

    @DISPID(1436)
    void clearCircles();

    @DISPID(1437)
    void circleInvalid();

    @DISPID(648)
    @PropGet
    int _DisplayRightToLeft();

    @DISPID(648)
    @PropPut
    void _DisplayRightToLeft(
        int rhs);

    @DISPID(793)
    @PropGet
    mol.excel.AutoFilter autoFilter();

    @DISPID(1774)
    @PropGet
    boolean displayRightToLeft();

    @DISPID(1774)
    @PropPut
    void displayRightToLeft(
        boolean rhs);

    @DISPID(1816)
    @PropGet
    mol.office.Scripts scripts();

    @DISPID(1772)
    void _PrintOut(
        java.lang.Object from,
        java.lang.Object to,
        java.lang.Object copies,
        java.lang.Object preview,
        java.lang.Object activePrinter,
        java.lang.Object printToFile,
        java.lang.Object collate,
        java.lang.Object prToFileName);

    @DISPID(1817)
    void _CheckSpelling(
        java.lang.Object customDictionary,
        java.lang.Object ignoreUppercase,
        java.lang.Object alwaysSuggest,
        java.lang.Object spellLang,
        java.lang.Object ignoreFinalYaa,
        java.lang.Object spellScript);

    @DISPID(1041)
    @PropGet
    mol.excel.Tab tab();

    @DISPID(2021)
    @PropGet
    mol.office.IMsoEnvelopeVB mailEnvelope();

    @DISPID(1925)
    void saveAs(
        java.lang.String filename,
        java.lang.Object fileFormat,
        java.lang.Object password,
        java.lang.Object writeResPassword,
        java.lang.Object readOnlyRecommended,
        java.lang.Object createBackup,
        java.lang.Object addToMru,
        java.lang.Object textCodepage,
        java.lang.Object textVisualLayout,
        java.lang.Object local);

    @DISPID(2030)
    @PropGet
    mol.excel.CustomProperties customProperties();

    @DISPID(2016)
    @PropGet
    mol.excel.SmartTags smartTags();

    @DISPID(176)
    @PropGet
    mol.excel.Protection protection();

    @DISPID(1928)
    void pasteSpecial(
        java.lang.Object format,
        java.lang.Object link,
        java.lang.Object displayAsIcon,
        java.lang.Object iconFileName,
        java.lang.Object iconIndex,
        java.lang.Object iconLabel,
        java.lang.Object noHTMLFormatting);

    @DISPID(2029)
    void protect(
        java.lang.Object password,
        java.lang.Object drawingObjects,
        java.lang.Object contents,
        java.lang.Object scenarios,
        java.lang.Object userInterfaceOnly,
        java.lang.Object allowFormattingCells,
        java.lang.Object allowFormattingColumns,
        java.lang.Object allowFormattingRows,
        java.lang.Object allowInsertingColumns,
        java.lang.Object allowInsertingRows,
        java.lang.Object allowInsertingHyperlinks,
        java.lang.Object allowDeletingColumns,
        java.lang.Object allowDeletingRows,
        java.lang.Object allowSorting,
        java.lang.Object allowFiltering,
        java.lang.Object allowUsingPivotTables);

    @DISPID(65649)
    void _Dummy113();

    @DISPID(65650)
    void _Dummy114();

    @DISPID(65651)
    void _Dummy115();

    @DISPID(2361)
    void printOut(
        java.lang.Object from,
        java.lang.Object to,
        java.lang.Object copies,
        java.lang.Object preview,
        java.lang.Object activePrinter,
        java.lang.Object printToFile,
        java.lang.Object collate,
        java.lang.Object prToFileName);

    @DISPID(2511)
    @PropGet
    boolean enableFormatConditionsCalculation();

    @DISPID(2511)
    @PropPut
    void enableFormatConditionsCalculation(
        boolean rhs);

    @DISPID(880)
    @PropGet
    mol.excel.Sort sort();

    @DISPID(2493)
    void exportAsFixedFormat(
        mol.excel.XlFixedFormatType type,
        java.lang.Object filename,
        java.lang.Object quality,
        java.lang.Object includeDocProperties,
        java.lang.Object ignorePrintAreas,
        java.lang.Object from,
        java.lang.Object to,
        java.lang.Object openAfterPublish,
        java.lang.Object fixedFormatExtClassPtr);

    @DISPID(857)
    @PropGet
    java.lang.Object defaultButton();

    @DISPID(857)
    @PropPut
    void defaultButton(
        java.lang.Object rhs);

    @DISPID(839)
    @PropGet
    mol.excel.DialogFrame dialogFrame();

    @DISPID(828)
    com4j.Com4jObject editBoxes(
        java.lang.Object index);

    @DISPID(814)
    @PropGet
    java.lang.Object focus();

    @DISPID(814)
    @PropPut
    void focus(
        java.lang.Object rhs);

    @DISPID(813)
    boolean hide(
        java.lang.Object cancel);

    @DISPID(496)
    boolean show();

}
