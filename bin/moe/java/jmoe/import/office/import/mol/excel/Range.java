package mol.excel  ;

import com4j.*;

@IID("{00020400-0000-0000-C000-000000000046}")
public interface Range extends Com4jObject,Iterable<Com4jObject> {
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
    java.lang.Object activate();

    @DISPID(1063)
    @PropGet
    java.lang.Object addIndent();

    @DISPID(1063)
    @PropPut
    void addIndent(
        java.lang.Object rhs);

    @DISPID(236)
    @PropGet
    java.lang.String address(
        java.lang.Object rowAbsolute,
        java.lang.Object columnAbsolute,
        mol.excel.XlReferenceStyle referenceStyle,
        java.lang.Object external,
        java.lang.Object relativeTo);

    @DISPID(437)
    @PropGet
    java.lang.String addressLocal(
        java.lang.Object rowAbsolute,
        java.lang.Object columnAbsolute,
        mol.excel.XlReferenceStyle referenceStyle,
        java.lang.Object external,
        java.lang.Object relativeTo);

    @DISPID(876)
    java.lang.Object advancedFilter(
        mol.excel.XlFilterAction action,
        java.lang.Object criteriaRange,
        java.lang.Object copyToRange,
        java.lang.Object unique);

    @DISPID(441)
    java.lang.Object applyNames(
        java.lang.Object names,
        java.lang.Object ignoreRelativeAbsolute,
        java.lang.Object useRowColumnNames,
        java.lang.Object omitColumn,
        java.lang.Object omitRow,
        mol.excel.XlApplyNamesOrder order,
        java.lang.Object appendLast);

    @DISPID(448)
    java.lang.Object applyOutlineStyles();

    @DISPID(568)
    @PropGet
    mol.excel.Areas areas();

    @DISPID(1185)
    java.lang.String autoComplete(
        java.lang.String string);

    @DISPID(449)
    java.lang.Object autoFill(
        mol.excel.Range destination,
        mol.excel.XlAutoFillType type);

    @DISPID(793)
    java.lang.Object autoFilter(
        java.lang.Object field,
        java.lang.Object criteria1,
        mol.excel.XlAutoFilterOperator operator,
        java.lang.Object criteria2,
        java.lang.Object visibleDropDown);

    @DISPID(237)
    java.lang.Object autoFit();

    @DISPID(114)
    java.lang.Object autoFormat(
        mol.excel.XlRangeAutoFormat format,
        java.lang.Object number,
        java.lang.Object font,
        java.lang.Object alignment,
        java.lang.Object border,
        java.lang.Object pattern,
        java.lang.Object width);

    @DISPID(1036)
    java.lang.Object autoOutline();

    @DISPID(1067)
    java.lang.Object borderAround(
        java.lang.Object lineStyle,
        mol.excel.XlBorderWeight weight,
        mol.excel.XlColorIndex colorIndex,
        java.lang.Object color);

    @DISPID(435)
    @PropGet
    mol.excel.Borders borders();

    @DISPID(279)
    java.lang.Object calculate();

    @DISPID(238)
    @PropGet
    mol.excel.Range cells();

    @DISPID(603)
    @PropGet
    mol.excel.Characters characters(
        java.lang.Object start,
        java.lang.Object length);

    @DISPID(505)
    java.lang.Object checkSpelling(
        java.lang.Object customDictionary,
        java.lang.Object ignoreUppercase,
        java.lang.Object alwaysSuggest,
        java.lang.Object spellLang);

    @DISPID(111)
    java.lang.Object clear();

    @DISPID(113)
    java.lang.Object clearContents();

    @DISPID(112)
    java.lang.Object clearFormats();

    @DISPID(239)
    java.lang.Object clearNotes();

    @DISPID(1037)
    java.lang.Object clearOutline();

    @DISPID(240)
    @PropGet
    int column();

    @DISPID(510)
    mol.excel.Range columnDifferences(
        java.lang.Object comparison);

    @DISPID(241)
    @PropGet
    mol.excel.Range columns();

    @DISPID(242)
    @PropGet
    java.lang.Object columnWidth();

    @DISPID(242)
    @PropPut
    void columnWidth(
        java.lang.Object rhs);

    @DISPID(482)
    java.lang.Object consolidate(
        java.lang.Object sources,
        java.lang.Object function,
        java.lang.Object topRow,
        java.lang.Object leftColumn,
        java.lang.Object createLinks);

    @DISPID(551)
    java.lang.Object copy(
        java.lang.Object destination);

    @DISPID(1152)
    int copyFromRecordset(
        com4j.Com4jObject data,
        java.lang.Object maxRows,
        java.lang.Object maxColumns);

    @DISPID(213)
    java.lang.Object copyPicture(
        mol.excel.XlPictureAppearance appearance,
        mol.excel.XlCopyPictureFormat format);

    @DISPID(118)
    @PropGet
    int count();

    @DISPID(457)
    java.lang.Object createNames(
        java.lang.Object top,
        java.lang.Object left,
        java.lang.Object bottom,
        java.lang.Object right);

    @DISPID(458)
    java.lang.Object createPublisher(
        java.lang.Object edition,
        mol.excel.XlPictureAppearance appearance,
        java.lang.Object containsPICT,
        java.lang.Object containsBIFF,
        java.lang.Object containsRTF,
        java.lang.Object containsVALU);

    @DISPID(501)
    @PropGet
    mol.excel.Range currentArray();

    @DISPID(243)
    @PropGet
    mol.excel.Range currentRegion();

    @DISPID(565)
    java.lang.Object cut(
        java.lang.Object destination);

    @DISPID(464)
    java.lang.Object dataSeries(
        java.lang.Object rowcol,
        mol.excel.XlDataSeriesType type,
        mol.excel.XlDataSeriesDate date,
        java.lang.Object step,
        java.lang.Object stop,
        java.lang.Object trend);

    @DISPID(0)
    @PropGet
    @DefaultMethod
    java.lang.Object _Default(
        java.lang.Object rowIndex,
        java.lang.Object columnIndex);

    @DISPID(0)
    @PropPut
    @DefaultMethod
    void _Default(
        java.lang.Object rowIndex,
        java.lang.Object columnIndex,
        java.lang.Object rhs);

    @DISPID(117)
    java.lang.Object delete(
        java.lang.Object shift);

    @DISPID(543)
    @PropGet
    mol.excel.Range dependents();

    @DISPID(245)
    java.lang.Object dialogBox();

    @DISPID(545)
    @PropGet
    mol.excel.Range directDependents();

    @DISPID(546)
    @PropGet
    mol.excel.Range directPrecedents();

    @DISPID(1131)
    java.lang.Object editionOptions(
        mol.excel.XlEditionType type,
        mol.excel.XlEditionOptionsOption option,
        java.lang.Object name,
        java.lang.Object reference,
        mol.excel.XlPictureAppearance appearance,
        mol.excel.XlPictureAppearance chartSize,
        java.lang.Object format);

    @DISPID(500)
    @PropGet
    mol.excel.Range end(
        mol.excel.XlDirection direction);

    @DISPID(246)
    @PropGet
    mol.excel.Range entireColumn();

    @DISPID(247)
    @PropGet
    mol.excel.Range entireRow();

    @DISPID(248)
    java.lang.Object fillDown();

    @DISPID(249)
    java.lang.Object fillLeft();

    @DISPID(250)
    java.lang.Object fillRight();

    @DISPID(251)
    java.lang.Object fillUp();

    @DISPID(398)
    mol.excel.Range find(
        java.lang.Object what,
        java.lang.Object after,
        java.lang.Object lookIn,
        java.lang.Object lookAt,
        java.lang.Object searchOrder,
        mol.excel.XlSearchDirection searchDirection,
        java.lang.Object matchCase,
        java.lang.Object matchByte,
        java.lang.Object searchFormat);

    @DISPID(399)
    mol.excel.Range findNext(
        java.lang.Object after);

    @DISPID(400)
    mol.excel.Range findPrevious(
        java.lang.Object after);

    @DISPID(146)
    @PropGet
    mol.excel.Font font();

    @DISPID(261)
    @PropGet
    java.lang.Object formula();

    @DISPID(261)
    @PropPut
    void formula(
        java.lang.Object rhs);

    @DISPID(586)
    @PropGet
    java.lang.Object formulaArray();

    @DISPID(586)
    @PropPut
    void formulaArray(
        java.lang.Object rhs);

    @DISPID(1380)
    @PropGet
    mol.excel.XlFormulaLabel formulaLabel();

    @DISPID(1380)
    @PropPut
    void formulaLabel(
        mol.excel.XlFormulaLabel rhs);

    @DISPID(262)
    @PropGet
    java.lang.Object formulaHidden();

    @DISPID(262)
    @PropPut
    void formulaHidden(
        java.lang.Object rhs);

    @DISPID(263)
    @PropGet
    java.lang.Object formulaLocal();

    @DISPID(263)
    @PropPut
    void formulaLocal(
        java.lang.Object rhs);

    @DISPID(264)
    @PropGet
    java.lang.Object formulaR1C1();

    @DISPID(264)
    @PropPut
    void formulaR1C1(
        java.lang.Object rhs);

    @DISPID(265)
    @PropGet
    java.lang.Object formulaR1C1Local();

    @DISPID(265)
    @PropPut
    void formulaR1C1Local(
        java.lang.Object rhs);

    @DISPID(571)
    java.lang.Object functionWizard();

    @DISPID(472)
    boolean goalSeek(
        java.lang.Object goal,
        mol.excel.Range changingCell);

    @DISPID(46)
    java.lang.Object group(
        java.lang.Object start,
        java.lang.Object end,
        java.lang.Object by,
        java.lang.Object periods);

    @DISPID(266)
    @PropGet
    java.lang.Object hasArray();

    @DISPID(267)
    @PropGet
    java.lang.Object hasFormula();

    @DISPID(123)
    @PropGet
    java.lang.Object height();

    @DISPID(268)
    @PropGet
    java.lang.Object hidden();

    @DISPID(268)
    @PropPut
    void hidden(
        java.lang.Object rhs);

    @DISPID(136)
    @PropGet
    java.lang.Object horizontalAlignment();

    @DISPID(136)
    @PropPut
    void horizontalAlignment(
        java.lang.Object rhs);

    @DISPID(201)
    @PropGet
    java.lang.Object indentLevel();

    @DISPID(201)
    @PropPut
    void indentLevel(
        java.lang.Object rhs);

    @DISPID(1381)
    void insertIndent(
        int insertAmount);

    @DISPID(252)
    java.lang.Object insert(
        java.lang.Object shift,
        java.lang.Object copyOrigin);

    @DISPID(129)
    @PropGet
    mol.excel.Interior interior();

    @DISPID(170)
    @PropGet
    java.lang.Object item(
        java.lang.Object rowIndex,
        java.lang.Object columnIndex);

    @DISPID(170)
    @PropPut
    void item(
        java.lang.Object rowIndex,
        java.lang.Object columnIndex,
        java.lang.Object rhs);

    @DISPID(495)
    java.lang.Object justify();

    @DISPID(127)
    @PropGet
    java.lang.Object left();

    @DISPID(1187)
    @PropGet
    int listHeaderRows();

    @DISPID(253)
    java.lang.Object listNames();

    @DISPID(691)
    @PropGet
    mol.excel.XlLocationInTable locationInTable();

    @DISPID(269)
    @PropGet
    java.lang.Object locked();

    @DISPID(269)
    @PropPut
    void locked(
        java.lang.Object rhs);

    @DISPID(564)
    void merge(
        java.lang.Object across);

    @DISPID(1384)
    void unMerge();

    @DISPID(1385)
    @PropGet
    mol.excel.Range mergeArea();

    @DISPID(208)
    @PropGet
    java.lang.Object mergeCells();

    @DISPID(208)
    @PropPut
    void mergeCells(
        java.lang.Object rhs);

    @DISPID(110)
    @PropGet
    java.lang.Object name();

    @DISPID(110)
    @PropPut
    void name(
        java.lang.Object rhs);

    @DISPID(1032)
    java.lang.Object navigateArrow(
        java.lang.Object towardPrecedent,
        java.lang.Object arrowNumber,
        java.lang.Object linkNumber);

    @DISPID(-4)
    @PropGet
    java.util.Iterator<Com4jObject> iterator();

    @DISPID(502)
    @PropGet
    mol.excel.Range next();

    @DISPID(1127)
    java.lang.String noteText(
        java.lang.Object text,
        java.lang.Object start,
        java.lang.Object length);

    @DISPID(193)
    @PropGet
    java.lang.Object numberFormat();

    @DISPID(193)
    @PropPut
    void numberFormat(
        java.lang.Object rhs);

    @DISPID(1097)
    @PropGet
    java.lang.Object numberFormatLocal();

    @DISPID(1097)
    @PropPut
    void numberFormatLocal(
        java.lang.Object rhs);

    @DISPID(254)
    @PropGet
    mol.excel.Range offset(
        java.lang.Object rowOffset,
        java.lang.Object columnOffset);

    @DISPID(134)
    @PropGet
    java.lang.Object orientation();

    @DISPID(134)
    @PropPut
    void orientation(
        java.lang.Object rhs);

    @DISPID(271)
    @PropGet
    java.lang.Object outlineLevel();

    @DISPID(271)
    @PropPut
    void outlineLevel(
        java.lang.Object rhs);

    @DISPID(255)
    @PropGet
    int pageBreak();

    @DISPID(255)
    @PropPut
    void pageBreak(
        int rhs);

    @DISPID(477)
    java.lang.Object parse(
        java.lang.Object parseLine,
        java.lang.Object destination);

    @DISPID(1027)
    java.lang.Object _PasteSpecial(
        mol.excel.XlPasteType paste,
        mol.excel.XlPasteSpecialOperation operation,
        java.lang.Object skipBlanks,
        java.lang.Object transpose);

    @DISPID(731)
    @PropGet
    mol.excel.PivotField pivotField();

    @DISPID(740)
    @PropGet
    mol.excel.PivotItem pivotItem();

    @DISPID(716)
    @PropGet
    mol.excel.PivotTable pivotTable();

    @DISPID(544)
    @PropGet
    mol.excel.Range precedents();

    @DISPID(504)
    @PropGet
    java.lang.Object prefixCharacter();

    @DISPID(503)
    @PropGet
    mol.excel.Range previous();

    @DISPID(905)
    java.lang.Object __PrintOut(
        java.lang.Object from,
        java.lang.Object to,
        java.lang.Object copies,
        java.lang.Object preview,
        java.lang.Object activePrinter,
        java.lang.Object printToFile,
        java.lang.Object collate);

    @DISPID(281)
    java.lang.Object printPreview(
        java.lang.Object enableChanges);

    @DISPID(1386)
    @PropGet
    com4j.Com4jObject queryTable();

    @DISPID(197)
    @PropGet
    mol.excel.Range range(
        java.lang.Object cell1,
        java.lang.Object cell2);

    @DISPID(883)
    java.lang.Object removeSubtotal();

    @DISPID(226)
    boolean replace(
        java.lang.Object what,
        java.lang.Object replacement,
        java.lang.Object lookAt,
        java.lang.Object searchOrder,
        java.lang.Object matchCase,
        java.lang.Object matchByte,
        java.lang.Object searchFormat,
        java.lang.Object replaceFormat);

    @DISPID(256)
    @PropGet
    mol.excel.Range resize(
        java.lang.Object rowSize,
        java.lang.Object columnSize);

    @DISPID(257)
    @PropGet
    int row();

    @DISPID(511)
    mol.excel.Range rowDifferences(
        java.lang.Object comparison);

    @DISPID(272)
    @PropGet
    java.lang.Object rowHeight();

    @DISPID(272)
    @PropPut
    void rowHeight(
        java.lang.Object rhs);

    @DISPID(258)
    @PropGet
    mol.excel.Range rows();

    @DISPID(259)
    java.lang.Object run(
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

    @DISPID(235)
    java.lang.Object select();

    @DISPID(496)
    java.lang.Object show();

    @DISPID(877)
    java.lang.Object showDependents(
        java.lang.Object remove);

    @DISPID(585)
    @PropGet
    java.lang.Object showDetail();

    @DISPID(585)
    @PropPut
    void showDetail(
        java.lang.Object rhs);

    @DISPID(878)
    java.lang.Object showErrors();

    @DISPID(879)
    java.lang.Object showPrecedents(
        java.lang.Object remove);

    @DISPID(209)
    @PropGet
    java.lang.Object shrinkToFit();

    @DISPID(209)
    @PropPut
    void shrinkToFit(
        java.lang.Object rhs);

    @DISPID(880)
    java.lang.Object sort(
        java.lang.Object key1,
        mol.excel.XlSortOrder order1,
        java.lang.Object key2,
        java.lang.Object type,
        mol.excel.XlSortOrder order2,
        java.lang.Object key3,
        mol.excel.XlSortOrder order3,
        mol.excel.XlYesNoGuess header,
        java.lang.Object orderCustom,
        java.lang.Object matchCase,
        mol.excel.XlSortOrientation orientation,
        mol.excel.XlSortMethod sortMethod,
        mol.excel.XlSortDataOption dataOption1,
        mol.excel.XlSortDataOption dataOption2,
        mol.excel.XlSortDataOption dataOption3);

    @DISPID(881)
    java.lang.Object sortSpecial(
        mol.excel.XlSortMethod sortMethod,
        java.lang.Object key1,
        mol.excel.XlSortOrder order1,
        java.lang.Object type,
        java.lang.Object key2,
        mol.excel.XlSortOrder order2,
        java.lang.Object key3,
        mol.excel.XlSortOrder order3,
        mol.excel.XlYesNoGuess header,
        java.lang.Object orderCustom,
        java.lang.Object matchCase,
        mol.excel.XlSortOrientation orientation,
        mol.excel.XlSortDataOption dataOption1,
        mol.excel.XlSortDataOption dataOption2,
        mol.excel.XlSortDataOption dataOption3);

    @DISPID(916)
    @PropGet
    mol.excel.SoundNote soundNote();

    @DISPID(410)
    mol.excel.Range specialCells(
        mol.excel.XlCellType type,
        java.lang.Object value);

    @DISPID(260)
    @PropGet
    java.lang.Object style();

    @DISPID(260)
    @PropPut
    void style(
        java.lang.Object rhs);

    @DISPID(481)
    java.lang.Object subscribeTo(
        java.lang.String edition,
        mol.excel.XlSubscribeToFormat format);

    @DISPID(882)
    java.lang.Object subtotal(
        int groupBy,
        mol.excel.XlConsolidationFunction function,
        java.lang.Object totalList,
        java.lang.Object replace,
        java.lang.Object pageBreaks,
        mol.excel.XlSummaryRow summaryBelowData);

    @DISPID(273)
    @PropGet
    java.lang.Object summary();

    @DISPID(497)
    java.lang.Object table(
        java.lang.Object rowInput,
        java.lang.Object columnInput);

    @DISPID(138)
    @PropGet
    java.lang.Object text();

    @DISPID(1040)
    java.lang.Object textToColumns(
        java.lang.Object destination,
        mol.excel.XlTextParsingType dataType,
        mol.excel.XlTextQualifier textQualifier,
        java.lang.Object consecutiveDelimiter,
        java.lang.Object tab,
        java.lang.Object semicolon,
        java.lang.Object comma,
        java.lang.Object space,
        java.lang.Object other,
        java.lang.Object otherChar,
        java.lang.Object fieldInfo,
        java.lang.Object decimalSeparator,
        java.lang.Object thousandsSeparator,
        java.lang.Object trailingMinusNumbers);

    @DISPID(126)
    @PropGet
    java.lang.Object top();

    @DISPID(244)
    java.lang.Object ungroup();

    @DISPID(274)
    @PropGet
    java.lang.Object useStandardHeight();

    @DISPID(274)
    @PropPut
    void useStandardHeight(
        java.lang.Object rhs);

    @DISPID(275)
    @PropGet
    java.lang.Object useStandardWidth();

    @DISPID(275)
    @PropPut
    void useStandardWidth(
        java.lang.Object rhs);

    @DISPID(1387)
    @PropGet
    mol.excel.Validation validation();

    @DISPID(6)
    @PropGet
    java.lang.Object value(
        java.lang.Object rangeValueDataType);

    @DISPID(6)
    @PropPut
    void value(
        java.lang.Object rangeValueDataType,
        java.lang.Object rhs);

    @DISPID(1388)
    @PropGet
    java.lang.Object value2();

    @DISPID(1388)
    @PropPut
    void value2(
        java.lang.Object rhs);

    @DISPID(137)
    @PropGet
    java.lang.Object verticalAlignment();

    @DISPID(137)
    @PropPut
    void verticalAlignment(
        java.lang.Object rhs);

    @DISPID(122)
    @PropGet
    java.lang.Object width();

    @DISPID(348)
    @PropGet
    mol.excel._Worksheet worksheet();

    @DISPID(276)
    @PropGet
    java.lang.Object wrapText();

    @DISPID(276)
    @PropPut
    void wrapText(
        java.lang.Object rhs);

    @DISPID(1389)
    mol.excel.Comment addComment(
        java.lang.Object text);

    @DISPID(910)
    @PropGet
    mol.excel.Comment comment();

    @DISPID(1390)
    void clearComments();

    @DISPID(1391)
    @PropGet
    mol.excel.Phonetic phonetic();

    @DISPID(1392)
    @PropGet
    mol.excel.FormatConditions formatConditions();

    @DISPID(975)
    @PropGet
    int readingOrder();

    @DISPID(975)
    @PropPut
    void readingOrder(
        int rhs);

    @DISPID(1393)
    @PropGet
    mol.excel.Hyperlinks hyperlinks();

    @DISPID(1811)
    @PropGet
    mol.excel.Phonetics phonetics();

    @DISPID(1812)
    void setPhonetic();

    @DISPID(1813)
    @PropGet
    java.lang.String id();

    @DISPID(1813)
    @PropPut
    void id(
        java.lang.String rhs);

    @DISPID(1772)
    java.lang.Object _PrintOut(
        java.lang.Object from,
        java.lang.Object to,
        java.lang.Object copies,
        java.lang.Object preview,
        java.lang.Object activePrinter,
        java.lang.Object printToFile,
        java.lang.Object collate,
        java.lang.Object prToFileName);

    @DISPID(2013)
    @PropGet
    mol.excel.PivotCell pivotCell();

    @DISPID(2014)
    void dirty();

    @DISPID(2015)
    @PropGet
    mol.excel.Errors errors();

    @DISPID(2016)
    @PropGet
    mol.excel.SmartTags smartTags();

    @DISPID(2017)
    void speak(
        java.lang.Object speakDirection,
        java.lang.Object speakFormulas);

    @DISPID(1928)
    java.lang.Object pasteSpecial(
        mol.excel.XlPasteType paste,
        mol.excel.XlPasteSpecialOperation operation,
        java.lang.Object skipBlanks,
        java.lang.Object transpose);

    @DISPID(2020)
    @PropGet
    boolean allowEdit();

    @DISPID(2257)
    @PropGet
    mol.excel.ListObject listObject();

    @DISPID(2258)
    @PropGet
    mol.excel.XPath xPath();

    @DISPID(2491)
    @PropGet
    mol.excel.Actions serverActions();

    @DISPID(2492)
    void removeDuplicates(
        java.lang.Object columns,
        mol.excel.XlYesNoGuess header);

    @DISPID(2361)
    java.lang.Object printOut(
        java.lang.Object from,
        java.lang.Object to,
        java.lang.Object copies,
        java.lang.Object preview,
        java.lang.Object activePrinter,
        java.lang.Object printToFile,
        java.lang.Object collate,
        java.lang.Object prToFileName);

    @DISPID(2123)
    @PropGet
    java.lang.String mdx();

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

    @DISPID(2499)
    @PropGet
    java.lang.Object countLarge();

    @DISPID(2364)
    java.lang.Object calculateRowMajorOrder();

}
