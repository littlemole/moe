package mol.excel  ;

import com4j.*;

@IID("{00020846-0001-0000-C000-000000000046}")
public interface IRange extends Com4jObject,Iterable<Com4jObject> {
    @VTID(7)
    mol.excel._Application application();

    @VTID(8)
    mol.excel.XlCreator creator();

    @VTID(9)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

    @VTID(10)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object activate();

    @VTID(11)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object addIndent();

    @VTID(12)
    void addIndent(
        @MarshalAs(NativeType.VARIANT) java.lang.Object rhs);

    @VTID(13)
    java.lang.String address(
        @MarshalAs(NativeType.VARIANT) java.lang.Object rowAbsolute,
        @MarshalAs(NativeType.VARIANT) java.lang.Object columnAbsolute,
        mol.excel.XlReferenceStyle referenceStyle,
        @MarshalAs(NativeType.VARIANT) java.lang.Object external,
        @MarshalAs(NativeType.VARIANT) java.lang.Object relativeTo,
        int lcid);

    @VTID(14)
    java.lang.String addressLocal(
        @MarshalAs(NativeType.VARIANT) java.lang.Object rowAbsolute,
        @MarshalAs(NativeType.VARIANT) java.lang.Object columnAbsolute,
        mol.excel.XlReferenceStyle referenceStyle,
        @MarshalAs(NativeType.VARIANT) java.lang.Object external,
        @MarshalAs(NativeType.VARIANT) java.lang.Object relativeTo);

    @VTID(15)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object advancedFilter(
        mol.excel.XlFilterAction action,
        @MarshalAs(NativeType.VARIANT) java.lang.Object criteriaRange,
        @MarshalAs(NativeType.VARIANT) java.lang.Object copyToRange,
        @MarshalAs(NativeType.VARIANT) java.lang.Object unique);

    @VTID(16)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object applyNames(
        @MarshalAs(NativeType.VARIANT) java.lang.Object names,
        @MarshalAs(NativeType.VARIANT) java.lang.Object ignoreRelativeAbsolute,
        @MarshalAs(NativeType.VARIANT) java.lang.Object useRowColumnNames,
        @MarshalAs(NativeType.VARIANT) java.lang.Object omitColumn,
        @MarshalAs(NativeType.VARIANT) java.lang.Object omitRow,
        mol.excel.XlApplyNamesOrder order,
        @MarshalAs(NativeType.VARIANT) java.lang.Object appendLast);

    @VTID(17)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object applyOutlineStyles();

    @VTID(18)
    mol.excel.Areas areas();

    @VTID(19)
    java.lang.String autoComplete(
        java.lang.String string);

    @VTID(20)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object autoFill(
        mol.excel.Range destination,
        mol.excel.XlAutoFillType type);

    @VTID(21)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object autoFilter(
        @MarshalAs(NativeType.VARIANT) java.lang.Object field,
        @MarshalAs(NativeType.VARIANT) java.lang.Object criteria1,
        mol.excel.XlAutoFilterOperator operator,
        @MarshalAs(NativeType.VARIANT) java.lang.Object criteria2,
        @MarshalAs(NativeType.VARIANT) java.lang.Object visibleDropDown);

    @VTID(22)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object autoFit();

    @VTID(23)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object autoFormat(
        mol.excel.XlRangeAutoFormat format,
        @MarshalAs(NativeType.VARIANT) java.lang.Object number,
        @MarshalAs(NativeType.VARIANT) java.lang.Object font,
        @MarshalAs(NativeType.VARIANT) java.lang.Object alignment,
        @MarshalAs(NativeType.VARIANT) java.lang.Object border,
        @MarshalAs(NativeType.VARIANT) java.lang.Object pattern,
        @MarshalAs(NativeType.VARIANT) java.lang.Object width);

    @VTID(24)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object autoOutline();

    @VTID(25)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object borderAround(
        @MarshalAs(NativeType.VARIANT) java.lang.Object lineStyle,
        mol.excel.XlBorderWeight weight,
        mol.excel.XlColorIndex colorIndex,
        @MarshalAs(NativeType.VARIANT) java.lang.Object color);

    @VTID(26)
    mol.excel.Borders borders();

    @VTID(27)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object calculate();

    @VTID(28)
    mol.excel.Range cells();

    @VTID(29)
    mol.excel.Characters characters(
        @MarshalAs(NativeType.VARIANT) java.lang.Object start,
        @MarshalAs(NativeType.VARIANT) java.lang.Object length);

    @VTID(30)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object checkSpelling(
        @MarshalAs(NativeType.VARIANT) java.lang.Object customDictionary,
        @MarshalAs(NativeType.VARIANT) java.lang.Object ignoreUppercase,
        @MarshalAs(NativeType.VARIANT) java.lang.Object alwaysSuggest,
        @MarshalAs(NativeType.VARIANT) java.lang.Object spellLang);

    @VTID(31)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object clear();

    @VTID(32)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object clearContents();

    @VTID(33)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object clearFormats();

    @VTID(34)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object clearNotes();

    @VTID(35)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object clearOutline();

    @VTID(36)
    int column();

    @VTID(37)
    mol.excel.Range columnDifferences(
        @MarshalAs(NativeType.VARIANT) java.lang.Object comparison);

    @VTID(38)
    mol.excel.Range columns();

    @VTID(39)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object columnWidth();

    @VTID(40)
    void columnWidth(
        @MarshalAs(NativeType.VARIANT) java.lang.Object rhs);

    @VTID(41)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object consolidate(
        @MarshalAs(NativeType.VARIANT) java.lang.Object sources,
        @MarshalAs(NativeType.VARIANT) java.lang.Object function,
        @MarshalAs(NativeType.VARIANT) java.lang.Object topRow,
        @MarshalAs(NativeType.VARIANT) java.lang.Object leftColumn,
        @MarshalAs(NativeType.VARIANT) java.lang.Object createLinks);

    @VTID(42)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object copy(
        @MarshalAs(NativeType.VARIANT) java.lang.Object destination);

    @VTID(43)
    int copyFromRecordset(
        com4j.Com4jObject data,
        @MarshalAs(NativeType.VARIANT) java.lang.Object maxRows,
        @MarshalAs(NativeType.VARIANT) java.lang.Object maxColumns);

    @VTID(44)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object copyPicture(
        mol.excel.XlPictureAppearance appearance,
        mol.excel.XlCopyPictureFormat format);

    @VTID(45)
    int count();

    @VTID(46)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object createNames(
        @MarshalAs(NativeType.VARIANT) java.lang.Object top,
        @MarshalAs(NativeType.VARIANT) java.lang.Object left,
        @MarshalAs(NativeType.VARIANT) java.lang.Object bottom,
        @MarshalAs(NativeType.VARIANT) java.lang.Object right);

    @VTID(47)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object createPublisher(
        @MarshalAs(NativeType.VARIANT) java.lang.Object edition,
        mol.excel.XlPictureAppearance appearance,
        @MarshalAs(NativeType.VARIANT) java.lang.Object containsPICT,
        @MarshalAs(NativeType.VARIANT) java.lang.Object containsBIFF,
        @MarshalAs(NativeType.VARIANT) java.lang.Object containsRTF,
        @MarshalAs(NativeType.VARIANT) java.lang.Object containsVALU);

    @VTID(48)
    mol.excel.Range currentArray();

    @VTID(49)
    mol.excel.Range currentRegion();

    @VTID(50)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object cut(
        @MarshalAs(NativeType.VARIANT) java.lang.Object destination);

    @VTID(51)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object dataSeries(
        @MarshalAs(NativeType.VARIANT) java.lang.Object rowcol,
        mol.excel.XlDataSeriesType type,
        mol.excel.XlDataSeriesDate date,
        @MarshalAs(NativeType.VARIANT) java.lang.Object step,
        @MarshalAs(NativeType.VARIANT) java.lang.Object stop,
        @MarshalAs(NativeType.VARIANT) java.lang.Object trend);

    @VTID(52)
    @DefaultMethod
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object _Default(
        @MarshalAs(NativeType.VARIANT) java.lang.Object rowIndex,
        @MarshalAs(NativeType.VARIANT) java.lang.Object columnIndex,
        int lcid);

    @VTID(53)
    @DefaultMethod
    void _Default(
        @MarshalAs(NativeType.VARIANT) java.lang.Object rowIndex,
        @MarshalAs(NativeType.VARIANT) java.lang.Object columnIndex,
        int lcid,
        @MarshalAs(NativeType.VARIANT) java.lang.Object rhs);

    @VTID(54)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object delete(
        @MarshalAs(NativeType.VARIANT) java.lang.Object shift);

    @VTID(55)
    mol.excel.Range dependents();

    @VTID(56)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object dialogBox();

    @VTID(57)
    mol.excel.Range directDependents();

    @VTID(58)
    mol.excel.Range directPrecedents();

    @VTID(59)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object editionOptions(
        mol.excel.XlEditionType type,
        mol.excel.XlEditionOptionsOption option,
        @MarshalAs(NativeType.VARIANT) java.lang.Object name,
        @MarshalAs(NativeType.VARIANT) java.lang.Object reference,
        mol.excel.XlPictureAppearance appearance,
        mol.excel.XlPictureAppearance chartSize,
        @MarshalAs(NativeType.VARIANT) java.lang.Object format);

    @VTID(60)
    mol.excel.Range end(
        mol.excel.XlDirection direction);

    @VTID(61)
    mol.excel.Range entireColumn();

    @VTID(62)
    mol.excel.Range entireRow();

    @VTID(63)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object fillDown();

    @VTID(64)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object fillLeft();

    @VTID(65)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object fillRight();

    @VTID(66)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object fillUp();

    @VTID(67)
    mol.excel.Range find(
        @MarshalAs(NativeType.VARIANT) java.lang.Object what,
        @MarshalAs(NativeType.VARIANT) java.lang.Object after,
        @MarshalAs(NativeType.VARIANT) java.lang.Object lookIn,
        @MarshalAs(NativeType.VARIANT) java.lang.Object lookAt,
        @MarshalAs(NativeType.VARIANT) java.lang.Object searchOrder,
        mol.excel.XlSearchDirection searchDirection,
        @MarshalAs(NativeType.VARIANT) java.lang.Object matchCase,
        @MarshalAs(NativeType.VARIANT) java.lang.Object matchByte,
        @MarshalAs(NativeType.VARIANT) java.lang.Object searchFormat);

    @VTID(68)
    mol.excel.Range findNext(
        @MarshalAs(NativeType.VARIANT) java.lang.Object after);

    @VTID(69)
    mol.excel.Range findPrevious(
        @MarshalAs(NativeType.VARIANT) java.lang.Object after);

    @VTID(70)
    mol.excel.Font font();

    @VTID(71)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object formula(
        int lcid);

    @VTID(72)
    void formula(
        int lcid,
        @MarshalAs(NativeType.VARIANT) java.lang.Object rhs);

    @VTID(73)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object formulaArray();

    @VTID(74)
    void formulaArray(
        @MarshalAs(NativeType.VARIANT) java.lang.Object rhs);

    @VTID(75)
    mol.excel.XlFormulaLabel formulaLabel();

    @VTID(76)
    void formulaLabel(
        mol.excel.XlFormulaLabel rhs);

    @VTID(77)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object formulaHidden();

    @VTID(78)
    void formulaHidden(
        @MarshalAs(NativeType.VARIANT) java.lang.Object rhs);

    @VTID(79)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object formulaLocal();

    @VTID(80)
    void formulaLocal(
        @MarshalAs(NativeType.VARIANT) java.lang.Object rhs);

    @VTID(81)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object formulaR1C1(
        int lcid);

    @VTID(82)
    void formulaR1C1(
        int lcid,
        @MarshalAs(NativeType.VARIANT) java.lang.Object rhs);

    @VTID(83)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object formulaR1C1Local();

    @VTID(84)
    void formulaR1C1Local(
        @MarshalAs(NativeType.VARIANT) java.lang.Object rhs);

    @VTID(85)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object functionWizard();

    @VTID(86)
    boolean goalSeek(
        @MarshalAs(NativeType.VARIANT) java.lang.Object goal,
        mol.excel.Range changingCell);

    @VTID(87)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object group(
        @MarshalAs(NativeType.VARIANT) java.lang.Object start,
        @MarshalAs(NativeType.VARIANT) java.lang.Object end,
        @MarshalAs(NativeType.VARIANT) java.lang.Object by,
        @MarshalAs(NativeType.VARIANT) java.lang.Object periods);

    @VTID(88)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object hasArray();

    @VTID(89)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object hasFormula();

    @VTID(90)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object height();

    @VTID(91)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object hidden();

    @VTID(92)
    void hidden(
        @MarshalAs(NativeType.VARIANT) java.lang.Object rhs);

    @VTID(93)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object horizontalAlignment();

    @VTID(94)
    void horizontalAlignment(
        @MarshalAs(NativeType.VARIANT) java.lang.Object rhs);

    @VTID(95)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object indentLevel();

    @VTID(96)
    void indentLevel(
        @MarshalAs(NativeType.VARIANT) java.lang.Object rhs);

    @VTID(97)
    void insertIndent(
        int insertAmount);

    @VTID(98)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object insert(
        @MarshalAs(NativeType.VARIANT) java.lang.Object shift,
        @MarshalAs(NativeType.VARIANT) java.lang.Object copyOrigin);

    @VTID(99)
    mol.excel.Interior interior();

    @VTID(100)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object item(
        @MarshalAs(NativeType.VARIANT) java.lang.Object rowIndex,
        @MarshalAs(NativeType.VARIANT) java.lang.Object columnIndex,
        int lcid);

    @VTID(101)
    void item(
        @MarshalAs(NativeType.VARIANT) java.lang.Object rowIndex,
        @MarshalAs(NativeType.VARIANT) java.lang.Object columnIndex,
        int lcid,
        @MarshalAs(NativeType.VARIANT) java.lang.Object rhs);

    @VTID(102)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object justify();

    @VTID(103)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object left();

    @VTID(104)
    int listHeaderRows();

    @VTID(105)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object listNames();

    @VTID(106)
    mol.excel.XlLocationInTable locationInTable();

    @VTID(107)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object locked();

    @VTID(108)
    void locked(
        @MarshalAs(NativeType.VARIANT) java.lang.Object rhs);

    @VTID(109)
    void merge(
        @MarshalAs(NativeType.VARIANT) java.lang.Object across);

    @VTID(110)
    void unMerge();

    @VTID(111)
    mol.excel.Range mergeArea();

    @VTID(112)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object mergeCells();

    @VTID(113)
    void mergeCells(
        @MarshalAs(NativeType.VARIANT) java.lang.Object rhs);

    @VTID(114)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object name();

    @VTID(115)
    void name(
        @MarshalAs(NativeType.VARIANT) java.lang.Object rhs);

    @VTID(116)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object navigateArrow(
        @MarshalAs(NativeType.VARIANT) java.lang.Object towardPrecedent,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arrowNumber,
        @MarshalAs(NativeType.VARIANT) java.lang.Object linkNumber);

    @VTID(117)
    java.util.Iterator<Com4jObject> iterator();

    @VTID(118)
    mol.excel.Range next();

    @VTID(119)
    java.lang.String noteText(
        @MarshalAs(NativeType.VARIANT) java.lang.Object text,
        @MarshalAs(NativeType.VARIANT) java.lang.Object start,
        @MarshalAs(NativeType.VARIANT) java.lang.Object length);

    @VTID(120)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object numberFormat();

    @VTID(121)
    void numberFormat(
        @MarshalAs(NativeType.VARIANT) java.lang.Object rhs);

    @VTID(122)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object numberFormatLocal();

    @VTID(123)
    void numberFormatLocal(
        @MarshalAs(NativeType.VARIANT) java.lang.Object rhs);

    @VTID(124)
    mol.excel.Range offset(
        @MarshalAs(NativeType.VARIANT) java.lang.Object rowOffset,
        @MarshalAs(NativeType.VARIANT) java.lang.Object columnOffset);

    @VTID(125)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object orientation();

    @VTID(126)
    void orientation(
        @MarshalAs(NativeType.VARIANT) java.lang.Object rhs);

    @VTID(127)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object outlineLevel();

    @VTID(128)
    void outlineLevel(
        @MarshalAs(NativeType.VARIANT) java.lang.Object rhs);

    @VTID(129)
    int pageBreak();

    @VTID(130)
    void pageBreak(
        int rhs);

    @VTID(131)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object parse(
        @MarshalAs(NativeType.VARIANT) java.lang.Object parseLine,
        @MarshalAs(NativeType.VARIANT) java.lang.Object destination);

    @VTID(132)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object _PasteSpecial(
        mol.excel.XlPasteType paste,
        mol.excel.XlPasteSpecialOperation operation,
        @MarshalAs(NativeType.VARIANT) java.lang.Object skipBlanks,
        @MarshalAs(NativeType.VARIANT) java.lang.Object transpose);

    @VTID(133)
    mol.excel.PivotField pivotField();

    @VTID(134)
    mol.excel.PivotItem pivotItem();

    @VTID(135)
    mol.excel.PivotTable pivotTable();

    @VTID(136)
    mol.excel.Range precedents();

    @VTID(137)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object prefixCharacter();

    @VTID(138)
    mol.excel.Range previous();

    @VTID(139)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object __PrintOut(
        @MarshalAs(NativeType.VARIANT) java.lang.Object from,
        @MarshalAs(NativeType.VARIANT) java.lang.Object to,
        @MarshalAs(NativeType.VARIANT) java.lang.Object copies,
        @MarshalAs(NativeType.VARIANT) java.lang.Object preview,
        @MarshalAs(NativeType.VARIANT) java.lang.Object activePrinter,
        @MarshalAs(NativeType.VARIANT) java.lang.Object printToFile,
        @MarshalAs(NativeType.VARIANT) java.lang.Object collate);

    @VTID(140)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object printPreview(
        @MarshalAs(NativeType.VARIANT) java.lang.Object enableChanges);

    @VTID(141)
    com4j.Com4jObject queryTable();

    @VTID(142)
    mol.excel.Range range(
        @MarshalAs(NativeType.VARIANT) java.lang.Object cell1,
        @MarshalAs(NativeType.VARIANT) java.lang.Object cell2);

    @VTID(143)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object removeSubtotal();

    @VTID(144)
    boolean replace(
        @MarshalAs(NativeType.VARIANT) java.lang.Object what,
        @MarshalAs(NativeType.VARIANT) java.lang.Object replacement,
        @MarshalAs(NativeType.VARIANT) java.lang.Object lookAt,
        @MarshalAs(NativeType.VARIANT) java.lang.Object searchOrder,
        @MarshalAs(NativeType.VARIANT) java.lang.Object matchCase,
        @MarshalAs(NativeType.VARIANT) java.lang.Object matchByte,
        @MarshalAs(NativeType.VARIANT) java.lang.Object searchFormat,
        @MarshalAs(NativeType.VARIANT) java.lang.Object replaceFormat);

    @VTID(145)
    mol.excel.Range resize(
        @MarshalAs(NativeType.VARIANT) java.lang.Object rowSize,
        @MarshalAs(NativeType.VARIANT) java.lang.Object columnSize);

    @VTID(146)
    int row();

    @VTID(147)
    mol.excel.Range rowDifferences(
        @MarshalAs(NativeType.VARIANT) java.lang.Object comparison);

    @VTID(148)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object rowHeight();

    @VTID(149)
    void rowHeight(
        @MarshalAs(NativeType.VARIANT) java.lang.Object rhs);

    @VTID(150)
    mol.excel.Range rows();

    @VTID(151)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object run(
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

    @VTID(152)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object select();

    @VTID(153)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object show();

    @VTID(154)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object showDependents(
        @MarshalAs(NativeType.VARIANT) java.lang.Object remove);

    @VTID(155)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object showDetail();

    @VTID(156)
    void showDetail(
        @MarshalAs(NativeType.VARIANT) java.lang.Object rhs);

    @VTID(157)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object showErrors();

    @VTID(158)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object showPrecedents(
        @MarshalAs(NativeType.VARIANT) java.lang.Object remove);

    @VTID(159)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object shrinkToFit();

    @VTID(160)
    void shrinkToFit(
        @MarshalAs(NativeType.VARIANT) java.lang.Object rhs);

    @VTID(161)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object sort(
        @MarshalAs(NativeType.VARIANT) java.lang.Object key1,
        mol.excel.XlSortOrder order1,
        @MarshalAs(NativeType.VARIANT) java.lang.Object key2,
        @MarshalAs(NativeType.VARIANT) java.lang.Object type,
        mol.excel.XlSortOrder order2,
        @MarshalAs(NativeType.VARIANT) java.lang.Object key3,
        mol.excel.XlSortOrder order3,
        mol.excel.XlYesNoGuess header,
        @MarshalAs(NativeType.VARIANT) java.lang.Object orderCustom,
        @MarshalAs(NativeType.VARIANT) java.lang.Object matchCase,
        mol.excel.XlSortOrientation orientation,
        mol.excel.XlSortMethod sortMethod,
        mol.excel.XlSortDataOption dataOption1,
        mol.excel.XlSortDataOption dataOption2,
        mol.excel.XlSortDataOption dataOption3);

    @VTID(162)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object sortSpecial(
        mol.excel.XlSortMethod sortMethod,
        @MarshalAs(NativeType.VARIANT) java.lang.Object key1,
        mol.excel.XlSortOrder order1,
        @MarshalAs(NativeType.VARIANT) java.lang.Object type,
        @MarshalAs(NativeType.VARIANT) java.lang.Object key2,
        mol.excel.XlSortOrder order2,
        @MarshalAs(NativeType.VARIANT) java.lang.Object key3,
        mol.excel.XlSortOrder order3,
        mol.excel.XlYesNoGuess header,
        @MarshalAs(NativeType.VARIANT) java.lang.Object orderCustom,
        @MarshalAs(NativeType.VARIANT) java.lang.Object matchCase,
        mol.excel.XlSortOrientation orientation,
        mol.excel.XlSortDataOption dataOption1,
        mol.excel.XlSortDataOption dataOption2,
        mol.excel.XlSortDataOption dataOption3);

    @VTID(163)
    mol.excel.SoundNote soundNote();

    @VTID(164)
    mol.excel.Range specialCells(
        mol.excel.XlCellType type,
        @MarshalAs(NativeType.VARIANT) java.lang.Object value);

    @VTID(165)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object style();

    @VTID(166)
    void style(
        @MarshalAs(NativeType.VARIANT) java.lang.Object rhs);

    @VTID(167)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object subscribeTo(
        java.lang.String edition,
        mol.excel.XlSubscribeToFormat format);

    @VTID(168)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object subtotal(
        int groupBy,
        mol.excel.XlConsolidationFunction function,
        @MarshalAs(NativeType.VARIANT) java.lang.Object totalList,
        @MarshalAs(NativeType.VARIANT) java.lang.Object replace,
        @MarshalAs(NativeType.VARIANT) java.lang.Object pageBreaks,
        mol.excel.XlSummaryRow summaryBelowData);

    @VTID(169)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object summary();

    @VTID(170)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object table(
        @MarshalAs(NativeType.VARIANT) java.lang.Object rowInput,
        @MarshalAs(NativeType.VARIANT) java.lang.Object columnInput);

    @VTID(171)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object text();

    @VTID(172)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object textToColumns(
        @MarshalAs(NativeType.VARIANT) java.lang.Object destination,
        mol.excel.XlTextParsingType dataType,
        mol.excel.XlTextQualifier textQualifier,
        @MarshalAs(NativeType.VARIANT) java.lang.Object consecutiveDelimiter,
        @MarshalAs(NativeType.VARIANT) java.lang.Object tab,
        @MarshalAs(NativeType.VARIANT) java.lang.Object semicolon,
        @MarshalAs(NativeType.VARIANT) java.lang.Object comma,
        @MarshalAs(NativeType.VARIANT) java.lang.Object space,
        @MarshalAs(NativeType.VARIANT) java.lang.Object other,
        @MarshalAs(NativeType.VARIANT) java.lang.Object otherChar,
        @MarshalAs(NativeType.VARIANT) java.lang.Object fieldInfo,
        @MarshalAs(NativeType.VARIANT) java.lang.Object decimalSeparator,
        @MarshalAs(NativeType.VARIANT) java.lang.Object thousandsSeparator,
        @MarshalAs(NativeType.VARIANT) java.lang.Object trailingMinusNumbers);

    @VTID(173)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object top();

    @VTID(174)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object ungroup();

    @VTID(175)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object useStandardHeight();

    @VTID(176)
    void useStandardHeight(
        @MarshalAs(NativeType.VARIANT) java.lang.Object rhs);

    @VTID(177)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object useStandardWidth();

    @VTID(178)
    void useStandardWidth(
        @MarshalAs(NativeType.VARIANT) java.lang.Object rhs);

    @VTID(179)
    mol.excel.Validation validation();

    @VTID(180)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object value(
        @MarshalAs(NativeType.VARIANT) java.lang.Object rangeValueDataType,
        int lcid);

    @VTID(181)
    void value(
        @MarshalAs(NativeType.VARIANT) java.lang.Object rangeValueDataType,
        int lcid,
        @MarshalAs(NativeType.VARIANT) java.lang.Object rhs);

    @VTID(182)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object value2(
        int lcid);

    @VTID(183)
    void value2(
        int lcid,
        @MarshalAs(NativeType.VARIANT) java.lang.Object rhs);

    @VTID(184)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object verticalAlignment();

    @VTID(185)
    void verticalAlignment(
        @MarshalAs(NativeType.VARIANT) java.lang.Object rhs);

    @VTID(186)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object width();

    @VTID(187)
    mol.excel._Worksheet worksheet();

    @VTID(188)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object wrapText();

    @VTID(189)
    void wrapText(
        @MarshalAs(NativeType.VARIANT) java.lang.Object rhs);

    @VTID(190)
    mol.excel.Comment addComment(
        @MarshalAs(NativeType.VARIANT) java.lang.Object text);

    @VTID(191)
    mol.excel.Comment comment();

    @VTID(192)
    void clearComments();

    @VTID(193)
    mol.excel.Phonetic phonetic();

    @VTID(194)
    mol.excel.FormatConditions formatConditions();

    @VTID(195)
    int readingOrder();

    @VTID(196)
    void readingOrder(
        int rhs);

    @VTID(197)
    mol.excel.Hyperlinks hyperlinks();

    @VTID(198)
    mol.excel.Phonetics phonetics();

    @VTID(199)
    void setPhonetic();

    @VTID(200)
    java.lang.String id();

    @VTID(201)
    void id(
        java.lang.String rhs);

    @VTID(202)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object _PrintOut(
        @MarshalAs(NativeType.VARIANT) java.lang.Object from,
        @MarshalAs(NativeType.VARIANT) java.lang.Object to,
        @MarshalAs(NativeType.VARIANT) java.lang.Object copies,
        @MarshalAs(NativeType.VARIANT) java.lang.Object preview,
        @MarshalAs(NativeType.VARIANT) java.lang.Object activePrinter,
        @MarshalAs(NativeType.VARIANT) java.lang.Object printToFile,
        @MarshalAs(NativeType.VARIANT) java.lang.Object collate,
        @MarshalAs(NativeType.VARIANT) java.lang.Object prToFileName);

    @VTID(203)
    mol.excel.PivotCell pivotCell();

    @VTID(204)
    void dirty();

    @VTID(205)
    mol.excel.Errors errors();

    @VTID(206)
    mol.excel.SmartTags smartTags();

    @VTID(207)
    void speak(
        @MarshalAs(NativeType.VARIANT) java.lang.Object speakDirection,
        @MarshalAs(NativeType.VARIANT) java.lang.Object speakFormulas);

    @VTID(208)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object pasteSpecial(
        mol.excel.XlPasteType paste,
        mol.excel.XlPasteSpecialOperation operation,
        @MarshalAs(NativeType.VARIANT) java.lang.Object skipBlanks,
        @MarshalAs(NativeType.VARIANT) java.lang.Object transpose);

    @VTID(209)
    boolean allowEdit();

    @VTID(210)
    mol.excel.ListObject listObject();

    @VTID(211)
    mol.excel.XPath xPath();

    @VTID(212)
    mol.excel.Actions serverActions();

    @VTID(213)
    void removeDuplicates(
        @MarshalAs(NativeType.VARIANT) java.lang.Object columns,
        mol.excel.XlYesNoGuess header);

    @VTID(214)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object printOut(
        @MarshalAs(NativeType.VARIANT) java.lang.Object from,
        @MarshalAs(NativeType.VARIANT) java.lang.Object to,
        @MarshalAs(NativeType.VARIANT) java.lang.Object copies,
        @MarshalAs(NativeType.VARIANT) java.lang.Object preview,
        @MarshalAs(NativeType.VARIANT) java.lang.Object activePrinter,
        @MarshalAs(NativeType.VARIANT) java.lang.Object printToFile,
        @MarshalAs(NativeType.VARIANT) java.lang.Object collate,
        @MarshalAs(NativeType.VARIANT) java.lang.Object prToFileName);

    @VTID(215)
    java.lang.String mdx();

    @VTID(216)
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

    @VTID(217)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object countLarge();

    @VTID(218)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object calculateRowMajorOrder();

}
