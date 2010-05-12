package mol.excel  ;

import com4j.*;
import mol.office.*;
import mol.vba.*;

@IID("{000208D5-0000-0000-C000-000000000046}")
public interface _Application extends Com4jObject {
    @VTID(7)
    mol.excel._Application application();

    @VTID(8)
    mol.excel.XlCreator creator();

    @VTID(9)
    mol.excel._Application parent();

    @VTID(10)
    mol.excel.Range activeCell();

    @VTID(11)
    mol.excel._Chart activeChart();

    @VTID(12)
    mol.excel.DialogSheet activeDialog();

    @VTID(13)
    mol.excel.MenuBar activeMenuBar();

    @VTID(14)
    java.lang.String activePrinter(
        int lcid);

    @VTID(15)
    void activePrinter(
        int lcid,
        java.lang.String rhs);

    @VTID(16)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject activeSheet();

    @VTID(17)
    mol.excel.Window activeWindow();

    @VTID(18)
    mol.excel._Workbook activeWorkbook();

    @VTID(19)
    mol.excel.AddIns addIns();

    @VTID(20)
    mol.office.Assistant assistant();

    @VTID(21)
    void calculate(
        int lcid);

    @VTID(22)
    mol.excel.Range cells();

    @VTID(23)
    mol.excel.Sheets charts();

    @VTID(23)
    @ReturnValue(type=NativeType.Dispatch,defaultPropertyThrough={mol.excel.Sheets.class})
    com4j.Com4jObject charts(
        @MarshalAs(NativeType.VARIANT) java.lang.Object index);

    @VTID(24)
    mol.excel.Range columns();

    @VTID(25)
    mol.office._CommandBars commandBars();

    @VTID(26)
    int ddeAppReturnCode(
        int lcid);

    @VTID(27)
    void ddeExecute(
        int channel,
        java.lang.String string,
        int lcid);

    @VTID(28)
    int ddeInitiate(
        java.lang.String app,
        java.lang.String topic,
        int lcid);

    @VTID(29)
    void ddePoke(
        int channel,
        @MarshalAs(NativeType.VARIANT) java.lang.Object item,
        @MarshalAs(NativeType.VARIANT) java.lang.Object data,
        int lcid);

    @VTID(30)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object ddeRequest(
        int channel,
        java.lang.String item,
        int lcid);

    @VTID(31)
    void ddeTerminate(
        int channel,
        int lcid);

    @VTID(32)
    mol.excel.Sheets dialogSheets();

    @VTID(32)
    @ReturnValue(type=NativeType.Dispatch,defaultPropertyThrough={mol.excel.Sheets.class})
    com4j.Com4jObject dialogSheets(
        @MarshalAs(NativeType.VARIANT) java.lang.Object index);

    @VTID(33)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object evaluate(
        @MarshalAs(NativeType.VARIANT) java.lang.Object name,
        int lcid);

    @VTID(34)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object _Evaluate(
        @MarshalAs(NativeType.VARIANT) java.lang.Object name,
        int lcid);

    @VTID(35)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object executeExcel4Macro(
        java.lang.String string,
        int lcid);

    @VTID(36)
    mol.excel.Range intersect(
        mol.excel.Range arg1,
        mol.excel.Range arg2,
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
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg30,
        int lcid);

    @VTID(37)
    mol.excel.MenuBars menuBars();

    @VTID(38)
    mol.excel.Modules modules();

    @VTID(39)
    mol.excel.Names names();

    @VTID(40)
    mol.excel.Range range(
        @MarshalAs(NativeType.VARIANT) java.lang.Object cell1,
        @MarshalAs(NativeType.VARIANT) java.lang.Object cell2);

    @VTID(41)
    mol.excel.Range rows();

    @VTID(42)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object run(
        @MarshalAs(NativeType.VARIANT) java.lang.Object macro,
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

    @VTID(43)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object _Run2(
        @MarshalAs(NativeType.VARIANT) java.lang.Object macro,
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
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg30,
        int lcid);

    @VTID(44)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject selection(
        int lcid);

    @VTID(45)
    void sendKeys(
        @MarshalAs(NativeType.VARIANT) java.lang.Object keys,
        @MarshalAs(NativeType.VARIANT) java.lang.Object wait,
        int lcid);

    @VTID(46)
    mol.excel.Sheets sheets();

    @VTID(46)
    @ReturnValue(type=NativeType.Dispatch,defaultPropertyThrough={mol.excel.Sheets.class})
    com4j.Com4jObject sheets(
        @MarshalAs(NativeType.VARIANT) java.lang.Object index);

    @VTID(47)
    mol.excel.Menu shortcutMenus(
        int index);

    @VTID(48)
    mol.excel._Workbook thisWorkbook(
        int lcid);

    @VTID(49)
    mol.excel.Toolbars toolbars();

    @VTID(50)
    mol.excel.Range union(
        mol.excel.Range arg1,
        mol.excel.Range arg2,
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
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg30,
        int lcid);

    @VTID(51)
    mol.excel.Windows windows();

    @VTID(52)
    mol.excel.Workbooks workbooks();

    @VTID(52)
    @ReturnValue(defaultPropertyThrough={mol.excel.Workbooks.class})
    mol.excel._Workbook workbooks(
        @MarshalAs(NativeType.VARIANT) java.lang.Object index);

    @VTID(53)
    mol.excel.WorksheetFunction worksheetFunction();

    @VTID(54)
    mol.excel.Sheets worksheets();

    @VTID(54)
    @ReturnValue(type=NativeType.Dispatch,defaultPropertyThrough={mol.excel.Sheets.class})
    com4j.Com4jObject worksheets(
        @MarshalAs(NativeType.VARIANT) java.lang.Object index);

    @VTID(55)
    mol.excel.Sheets excel4IntlMacroSheets();

    @VTID(55)
    @ReturnValue(type=NativeType.Dispatch,defaultPropertyThrough={mol.excel.Sheets.class})
    com4j.Com4jObject excel4IntlMacroSheets(
        @MarshalAs(NativeType.VARIANT) java.lang.Object index);

    @VTID(56)
    mol.excel.Sheets excel4MacroSheets();

    @VTID(56)
    @ReturnValue(type=NativeType.Dispatch,defaultPropertyThrough={mol.excel.Sheets.class})
    com4j.Com4jObject excel4MacroSheets(
        @MarshalAs(NativeType.VARIANT) java.lang.Object index);

    @VTID(57)
    void activateMicrosoftApp(
        mol.excel.XlMSApplication index,
        int lcid);

    @VTID(58)
    void addChartAutoFormat(
        @MarshalAs(NativeType.VARIANT) java.lang.Object chart,
        java.lang.String name,
        @MarshalAs(NativeType.VARIANT) java.lang.Object description,
        int lcid);

    @VTID(59)
    void addCustomList(
        @MarshalAs(NativeType.VARIANT) java.lang.Object listArray,
        @MarshalAs(NativeType.VARIANT) java.lang.Object byRow,
        int lcid);

    @VTID(60)
    boolean alertBeforeOverwriting(
        int lcid);

    @VTID(61)
    void alertBeforeOverwriting(
        int lcid,
        boolean rhs);

    @VTID(62)
    java.lang.String altStartupPath(
        int lcid);

    @VTID(63)
    void altStartupPath(
        int lcid,
        java.lang.String rhs);

    @VTID(64)
    boolean askToUpdateLinks(
        int lcid);

    @VTID(65)
    void askToUpdateLinks(
        int lcid,
        boolean rhs);

    @VTID(66)
    boolean enableAnimations(
        int lcid);

    @VTID(67)
    void enableAnimations(
        int lcid,
        boolean rhs);

    @VTID(68)
    mol.excel.AutoCorrect autoCorrect();

    @VTID(69)
    int build(
        int lcid);

    @VTID(70)
    boolean calculateBeforeSave(
        int lcid);

    @VTID(71)
    void calculateBeforeSave(
        int lcid,
        boolean rhs);

    @VTID(72)
    mol.excel.XlCalculation calculation(
        int lcid);

    @VTID(73)
    void calculation(
        int lcid,
        mol.excel.XlCalculation rhs);

    @VTID(74)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object caller(
        @MarshalAs(NativeType.VARIANT) java.lang.Object index,
        int lcid);

    @VTID(75)
    boolean canPlaySounds(
        int lcid);

    @VTID(76)
    boolean canRecordSounds(
        int lcid);

    @VTID(77)
    java.lang.String caption();

    @VTID(78)
    void caption(
        java.lang.String rhs);

    @VTID(79)
    boolean cellDragAndDrop(
        int lcid);

    @VTID(80)
    void cellDragAndDrop(
        int lcid,
        boolean rhs);

    @VTID(81)
    double centimetersToPoints(
        double centimeters,
        int lcid);

    @VTID(82)
    boolean checkSpelling(
        java.lang.String word,
        @MarshalAs(NativeType.VARIANT) java.lang.Object customDictionary,
        @MarshalAs(NativeType.VARIANT) java.lang.Object ignoreUppercase,
        int lcid);

    @VTID(83)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object clipboardFormats(
        @MarshalAs(NativeType.VARIANT) java.lang.Object index,
        int lcid);

    @VTID(84)
    boolean displayClipboardWindow(
        int lcid);

    @VTID(85)
    void displayClipboardWindow(
        int lcid,
        boolean rhs);

    @VTID(86)
    boolean colorButtons();

    @VTID(87)
    void colorButtons(
        boolean rhs);

    @VTID(88)
    mol.excel.XlCommandUnderlines commandUnderlines(
        int lcid);

    @VTID(89)
    void commandUnderlines(
        int lcid,
        mol.excel.XlCommandUnderlines rhs);

    @VTID(90)
    boolean constrainNumeric(
        int lcid);

    @VTID(91)
    void constrainNumeric(
        int lcid,
        boolean rhs);

    @VTID(92)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object convertFormula(
        @MarshalAs(NativeType.VARIANT) java.lang.Object formula,
        mol.excel.XlReferenceStyle fromReferenceStyle,
        @MarshalAs(NativeType.VARIANT) java.lang.Object toReferenceStyle,
        @MarshalAs(NativeType.VARIANT) java.lang.Object toAbsolute,
        @MarshalAs(NativeType.VARIANT) java.lang.Object relativeTo,
        int lcid);

    @VTID(93)
    boolean copyObjectsWithCells(
        int lcid);

    @VTID(94)
    void copyObjectsWithCells(
        int lcid,
        boolean rhs);

    @VTID(95)
    mol.excel.XlMousePointer cursor(
        int lcid);

    @VTID(96)
    void cursor(
        int lcid,
        mol.excel.XlMousePointer rhs);

    @VTID(97)
    int customListCount(
        int lcid);

    @VTID(98)
    mol.excel.XlCutCopyMode cutCopyMode(
        int lcid);

    @VTID(99)
    void cutCopyMode(
        int lcid,
        mol.excel.XlCutCopyMode rhs);

    @VTID(100)
    int dataEntryMode(
        int lcid);

    @VTID(101)
    void dataEntryMode(
        int lcid,
        int rhs);

    @VTID(102)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object dummy1(
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg1,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg2,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg3,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg4);

    @VTID(103)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object dummy2(
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg1,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg2,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg3,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg4,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg5,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg6,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg7,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg8);

    @VTID(104)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object dummy3();

    @VTID(105)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object dummy4(
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
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg15);

    @VTID(106)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object dummy5(
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
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg13);

    @VTID(107)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object dummy6();

    @VTID(108)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object dummy7();

    @VTID(109)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object dummy8(
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg1);

    @VTID(110)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object dummy9();

    @VTID(111)
    boolean dummy10(
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg);

    @VTID(112)
    void dummy11();

    @VTID(113)
    @DefaultMethod
    java.lang.String _Default();

    @VTID(114)
    java.lang.String defaultFilePath(
        int lcid);

    @VTID(115)
    void defaultFilePath(
        int lcid,
        java.lang.String rhs);

    @VTID(116)
    void deleteChartAutoFormat(
        java.lang.String name,
        int lcid);

    @VTID(117)
    void deleteCustomList(
        int listNum,
        int lcid);

    @VTID(118)
    mol.excel.Dialogs dialogs();

    @VTID(119)
    boolean displayAlerts(
        int lcid);

    @VTID(120)
    void displayAlerts(
        int lcid,
        boolean rhs);

    @VTID(121)
    boolean displayFormulaBar(
        int lcid);

    @VTID(122)
    void displayFormulaBar(
        int lcid,
        boolean rhs);

    @VTID(123)
    boolean displayFullScreen(
        int lcid);

    @VTID(124)
    void displayFullScreen(
        int lcid,
        boolean rhs);

    @VTID(125)
    boolean displayNoteIndicator();

    @VTID(126)
    void displayNoteIndicator(
        boolean rhs);

    @VTID(127)
    mol.excel.XlCommentDisplayMode displayCommentIndicator();

    @VTID(128)
    void displayCommentIndicator(
        mol.excel.XlCommentDisplayMode rhs);

    @VTID(129)
    boolean displayExcel4Menus(
        int lcid);

    @VTID(130)
    void displayExcel4Menus(
        int lcid,
        boolean rhs);

    @VTID(131)
    boolean displayRecentFiles();

    @VTID(132)
    void displayRecentFiles(
        boolean rhs);

    @VTID(133)
    boolean displayScrollBars(
        int lcid);

    @VTID(134)
    void displayScrollBars(
        int lcid,
        boolean rhs);

    @VTID(135)
    boolean displayStatusBar(
        int lcid);

    @VTID(136)
    void displayStatusBar(
        int lcid,
        boolean rhs);

    @VTID(137)
    void doubleClick(
        int lcid);

    @VTID(138)
    boolean editDirectlyInCell(
        int lcid);

    @VTID(139)
    void editDirectlyInCell(
        int lcid,
        boolean rhs);

    @VTID(140)
    boolean enableAutoComplete();

    @VTID(141)
    void enableAutoComplete(
        boolean rhs);

    @VTID(142)
    mol.excel.XlEnableCancelKey enableCancelKey(
        int lcid);

    @VTID(143)
    void enableCancelKey(
        int lcid,
        mol.excel.XlEnableCancelKey rhs);

    @VTID(144)
    boolean enableSound();

    @VTID(145)
    void enableSound(
        boolean rhs);

    @VTID(146)
    boolean enableTipWizard(
        int lcid);

    @VTID(147)
    void enableTipWizard(
        int lcid,
        boolean rhs);

    @VTID(148)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object fileConverters(
        @MarshalAs(NativeType.VARIANT) java.lang.Object index1,
        @MarshalAs(NativeType.VARIANT) java.lang.Object index2,
        int lcid);

    @VTID(149)
    mol.office.FileSearch fileSearch();

    @VTID(150)
    mol.office.IFind fileFind();

    @VTID(151)
    void _FindFile(
        int lcid);

    @VTID(152)
    boolean fixedDecimal(
        int lcid);

    @VTID(153)
    void fixedDecimal(
        int lcid,
        boolean rhs);

    @VTID(154)
    int fixedDecimalPlaces(
        int lcid);

    @VTID(155)
    void fixedDecimalPlaces(
        int lcid,
        int rhs);

    @VTID(156)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object getCustomListContents(
        int listNum,
        int lcid);

    @VTID(157)
    int getCustomListNum(
        @MarshalAs(NativeType.VARIANT) java.lang.Object listArray,
        int lcid);

    @VTID(158)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object getOpenFilename(
        @MarshalAs(NativeType.VARIANT) java.lang.Object fileFilter,
        @MarshalAs(NativeType.VARIANT) java.lang.Object filterIndex,
        @MarshalAs(NativeType.VARIANT) java.lang.Object title,
        @MarshalAs(NativeType.VARIANT) java.lang.Object buttonText,
        @MarshalAs(NativeType.VARIANT) java.lang.Object multiSelect,
        int lcid);

    @VTID(159)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object getSaveAsFilename(
        @MarshalAs(NativeType.VARIANT) java.lang.Object initialFilename,
        @MarshalAs(NativeType.VARIANT) java.lang.Object fileFilter,
        @MarshalAs(NativeType.VARIANT) java.lang.Object filterIndex,
        @MarshalAs(NativeType.VARIANT) java.lang.Object title,
        @MarshalAs(NativeType.VARIANT) java.lang.Object buttonText,
        int lcid);

    @VTID(160)
    void _goto(
        @MarshalAs(NativeType.VARIANT) java.lang.Object reference,
        @MarshalAs(NativeType.VARIANT) java.lang.Object scroll,
        int lcid);

    @VTID(161)
    double height(
        int lcid);

    @VTID(162)
    void height(
        int lcid,
        double rhs);

    @VTID(163)
    void help(
        @MarshalAs(NativeType.VARIANT) java.lang.Object helpFile,
        @MarshalAs(NativeType.VARIANT) java.lang.Object helpContextID,
        int lcid);

    @VTID(164)
    boolean ignoreRemoteRequests(
        int lcid);

    @VTID(165)
    void ignoreRemoteRequests(
        int lcid,
        boolean rhs);

    @VTID(166)
    double inchesToPoints(
        double inches,
        int lcid);

    @VTID(167)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object inputBox(
        java.lang.String prompt,
        @MarshalAs(NativeType.VARIANT) java.lang.Object title,
        @MarshalAs(NativeType.VARIANT) java.lang.Object _default,
        @MarshalAs(NativeType.VARIANT) java.lang.Object left,
        @MarshalAs(NativeType.VARIANT) java.lang.Object top,
        @MarshalAs(NativeType.VARIANT) java.lang.Object helpFile,
        @MarshalAs(NativeType.VARIANT) java.lang.Object helpContextID,
        @MarshalAs(NativeType.VARIANT) java.lang.Object type,
        int lcid);

    @VTID(168)
    boolean interactive(
        int lcid);

    @VTID(169)
    void interactive(
        int lcid,
        boolean rhs);

    @VTID(170)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object international(
        @MarshalAs(NativeType.VARIANT) java.lang.Object index,
        int lcid);

    @VTID(171)
    boolean iteration(
        int lcid);

    @VTID(172)
    void iteration(
        int lcid,
        boolean rhs);

    @VTID(173)
    boolean largeButtons();

    @VTID(174)
    void largeButtons(
        boolean rhs);

    @VTID(175)
    double left(
        int lcid);

    @VTID(176)
    void left(
        int lcid,
        double rhs);

    @VTID(177)
    java.lang.String libraryPath(
        int lcid);

    @VTID(178)
    void macroOptions(
        @MarshalAs(NativeType.VARIANT) java.lang.Object macro,
        @MarshalAs(NativeType.VARIANT) java.lang.Object description,
        @MarshalAs(NativeType.VARIANT) java.lang.Object hasMenu,
        @MarshalAs(NativeType.VARIANT) java.lang.Object menuText,
        @MarshalAs(NativeType.VARIANT) java.lang.Object hasShortcutKey,
        @MarshalAs(NativeType.VARIANT) java.lang.Object shortcutKey,
        @MarshalAs(NativeType.VARIANT) java.lang.Object category,
        @MarshalAs(NativeType.VARIANT) java.lang.Object statusBar,
        @MarshalAs(NativeType.VARIANT) java.lang.Object helpContextID,
        @MarshalAs(NativeType.VARIANT) java.lang.Object helpFile,
        int lcid);

    @VTID(179)
    void mailLogoff(
        int lcid);

    @VTID(180)
    void mailLogon(
        @MarshalAs(NativeType.VARIANT) java.lang.Object name,
        @MarshalAs(NativeType.VARIANT) java.lang.Object password,
        @MarshalAs(NativeType.VARIANT) java.lang.Object downloadNewMail,
        int lcid);

    @VTID(181)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object mailSession(
        int lcid);

    @VTID(182)
    mol.excel.XlMailSystem mailSystem(
        int lcid);

    @VTID(183)
    boolean mathCoprocessorAvailable(
        int lcid);

    @VTID(184)
    double maxChange(
        int lcid);

    @VTID(185)
    void maxChange(
        int lcid,
        double rhs);

    @VTID(186)
    int maxIterations(
        int lcid);

    @VTID(187)
    void maxIterations(
        int lcid,
        int rhs);

    @VTID(188)
    int memoryFree(
        int lcid);

    @VTID(189)
    int memoryTotal(
        int lcid);

    @VTID(190)
    int memoryUsed(
        int lcid);

    @VTID(191)
    boolean mouseAvailable(
        int lcid);

    @VTID(192)
    boolean moveAfterReturn(
        int lcid);

    @VTID(193)
    void moveAfterReturn(
        int lcid,
        boolean rhs);

    @VTID(194)
    mol.excel.XlDirection moveAfterReturnDirection(
        int lcid);

    @VTID(195)
    void moveAfterReturnDirection(
        int lcid,
        mol.excel.XlDirection rhs);

    @VTID(196)
    mol.excel.RecentFiles recentFiles();

    @VTID(197)
    java.lang.String name();

    @VTID(198)
    mol.excel._Workbook nextLetter(
        int lcid);

    @VTID(199)
    java.lang.String networkTemplatesPath(
        int lcid);

    @VTID(200)
    mol.excel.ODBCErrors odbcErrors();

    @VTID(201)
    int odbcTimeout();

    @VTID(202)
    void odbcTimeout(
        int rhs);

    @VTID(203)
    java.lang.String onCalculate(
        int lcid);

    @VTID(204)
    void onCalculate(
        int lcid,
        java.lang.String rhs);

    @VTID(205)
    java.lang.String onData(
        int lcid);

    @VTID(206)
    void onData(
        int lcid,
        java.lang.String rhs);

    @VTID(207)
    java.lang.String onDoubleClick(
        int lcid);

    @VTID(208)
    void onDoubleClick(
        int lcid,
        java.lang.String rhs);

    @VTID(209)
    java.lang.String onEntry(
        int lcid);

    @VTID(210)
    void onEntry(
        int lcid,
        java.lang.String rhs);

    @VTID(211)
    void onKey(
        java.lang.String key,
        @MarshalAs(NativeType.VARIANT) java.lang.Object procedure,
        int lcid);

    @VTID(212)
    void onRepeat(
        java.lang.String text,
        java.lang.String procedure,
        int lcid);

    @VTID(213)
    java.lang.String onSheetActivate(
        int lcid);

    @VTID(214)
    void onSheetActivate(
        int lcid,
        java.lang.String rhs);

    @VTID(215)
    java.lang.String onSheetDeactivate(
        int lcid);

    @VTID(216)
    void onSheetDeactivate(
        int lcid,
        java.lang.String rhs);

    @VTID(217)
    void onTime(
        @MarshalAs(NativeType.VARIANT) java.lang.Object earliestTime,
        java.lang.String procedure,
        @MarshalAs(NativeType.VARIANT) java.lang.Object latestTime,
        @MarshalAs(NativeType.VARIANT) java.lang.Object schedule,
        int lcid);

    @VTID(218)
    void onUndo(
        java.lang.String text,
        java.lang.String procedure,
        int lcid);

    @VTID(219)
    java.lang.String onWindow(
        int lcid);

    @VTID(220)
    void onWindow(
        int lcid,
        java.lang.String rhs);

    @VTID(221)
    java.lang.String operatingSystem(
        int lcid);

    @VTID(222)
    java.lang.String organizationName(
        int lcid);

    @VTID(223)
    java.lang.String path(
        int lcid);

    @VTID(224)
    java.lang.String pathSeparator(
        int lcid);

    @VTID(225)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object previousSelections(
        @MarshalAs(NativeType.VARIANT) java.lang.Object index,
        int lcid);

    @VTID(226)
    boolean pivotTableSelection();

    @VTID(227)
    void pivotTableSelection(
        boolean rhs);

    @VTID(228)
    boolean promptForSummaryInfo(
        int lcid);

    @VTID(229)
    void promptForSummaryInfo(
        int lcid,
        boolean rhs);

    @VTID(230)
    void quit();

    @VTID(231)
    void recordMacro(
        @MarshalAs(NativeType.VARIANT) java.lang.Object basicCode,
        @MarshalAs(NativeType.VARIANT) java.lang.Object xlmCode,
        int lcid);

    @VTID(232)
    boolean recordRelative(
        int lcid);

    @VTID(233)
    mol.excel.XlReferenceStyle referenceStyle(
        int lcid);

    @VTID(234)
    void referenceStyle(
        int lcid,
        mol.excel.XlReferenceStyle rhs);

    @VTID(235)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object registeredFunctions(
        @MarshalAs(NativeType.VARIANT) java.lang.Object index1,
        @MarshalAs(NativeType.VARIANT) java.lang.Object index2,
        int lcid);

    @VTID(236)
    boolean registerXLL(
        java.lang.String filename,
        int lcid);

    @VTID(237)
    void repeat(
        int lcid);

    @VTID(238)
    void resetTipWizard(
        int lcid);

    @VTID(239)
    boolean rollZoom();

    @VTID(240)
    void rollZoom(
        boolean rhs);

    @VTID(241)
    void save(
        @MarshalAs(NativeType.VARIANT) java.lang.Object filename,
        int lcid);

    @VTID(242)
    void saveWorkspace(
        @MarshalAs(NativeType.VARIANT) java.lang.Object filename,
        int lcid);

    @VTID(243)
    boolean screenUpdating(
        int lcid);

    @VTID(244)
    void screenUpdating(
        int lcid,
        boolean rhs);

    @VTID(245)
    void setDefaultChart(
        @MarshalAs(NativeType.VARIANT) java.lang.Object formatName,
        @MarshalAs(NativeType.VARIANT) java.lang.Object gallery);

    @VTID(246)
    int sheetsInNewWorkbook(
        int lcid);

    @VTID(247)
    void sheetsInNewWorkbook(
        int lcid,
        int rhs);

    @VTID(248)
    boolean showChartTipNames();

    @VTID(249)
    void showChartTipNames(
        boolean rhs);

    @VTID(250)
    boolean showChartTipValues();

    @VTID(251)
    void showChartTipValues(
        boolean rhs);

    @VTID(252)
    java.lang.String standardFont(
        int lcid);

    @VTID(253)
    void standardFont(
        int lcid,
        java.lang.String rhs);

    @VTID(254)
    double standardFontSize(
        int lcid);

    @VTID(255)
    void standardFontSize(
        int lcid,
        double rhs);

    @VTID(256)
    java.lang.String startupPath(
        int lcid);

    @VTID(257)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object statusBar(
        int lcid);

    @VTID(258)
    void statusBar(
        int lcid,
        @MarshalAs(NativeType.VARIANT) java.lang.Object rhs);

    @VTID(259)
    java.lang.String templatesPath(
        int lcid);

    @VTID(260)
    boolean showToolTips();

    @VTID(261)
    void showToolTips(
        boolean rhs);

    @VTID(262)
    double top(
        int lcid);

    @VTID(263)
    void top(
        int lcid,
        double rhs);

    @VTID(264)
    mol.excel.XlFileFormat defaultSaveFormat();

    @VTID(265)
    void defaultSaveFormat(
        mol.excel.XlFileFormat rhs);

    @VTID(266)
    java.lang.String transitionMenuKey(
        int lcid);

    @VTID(267)
    void transitionMenuKey(
        int lcid,
        java.lang.String rhs);

    @VTID(268)
    int transitionMenuKeyAction(
        int lcid);

    @VTID(269)
    void transitionMenuKeyAction(
        int lcid,
        int rhs);

    @VTID(270)
    boolean transitionNavigKeys(
        int lcid);

    @VTID(271)
    void transitionNavigKeys(
        int lcid,
        boolean rhs);

    @VTID(272)
    void undo(
        int lcid);

    @VTID(273)
    double usableHeight(
        int lcid);

    @VTID(274)
    double usableWidth(
        int lcid);

    @VTID(275)
    boolean userControl();

    @VTID(276)
    void userControl(
        boolean rhs);

    @VTID(277)
    java.lang.String userName(
        int lcid);

    @VTID(278)
    void userName(
        int lcid,
        java.lang.String rhs);

    @VTID(279)
    java.lang.String value();

    @VTID(280)
    mol.vba.VBE vbe();

    @VTID(281)
    java.lang.String version(
        int lcid);

    @VTID(282)
    boolean visible(
        int lcid);

    @VTID(283)
    void visible(
        int lcid,
        boolean rhs);

    @VTID(284)
    void _volatile(
        @MarshalAs(NativeType.VARIANT) java.lang.Object _volatile,
        int lcid);

    @VTID(285)
    void _Wait(
        @MarshalAs(NativeType.VARIANT) java.lang.Object time,
        int lcid);

    @VTID(286)
    double width(
        int lcid);

    @VTID(287)
    void width(
        int lcid,
        double rhs);

    @VTID(288)
    boolean windowsForPens(
        int lcid);

    @VTID(289)
    mol.excel.XlWindowState windowState(
        int lcid);

    @VTID(290)
    void windowState(
        int lcid,
        mol.excel.XlWindowState rhs);

    @VTID(291)
    int uiLanguage(
        int lcid);

    @VTID(292)
    void uiLanguage(
        int lcid,
        int rhs);

    @VTID(293)
    int defaultSheetDirection(
        int lcid);

    @VTID(294)
    void defaultSheetDirection(
        int lcid,
        int rhs);

    @VTID(295)
    int cursorMovement(
        int lcid);

    @VTID(296)
    void cursorMovement(
        int lcid,
        int rhs);

    @VTID(297)
    boolean controlCharacters(
        int lcid);

    @VTID(298)
    void controlCharacters(
        int lcid,
        boolean rhs);

    @VTID(299)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object _WSFunction(
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
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg30,
        int lcid);

    @VTID(300)
    boolean enableEvents();

    @VTID(301)
    void enableEvents(
        boolean rhs);

    @VTID(302)
    boolean displayInfoWindow();

    @VTID(303)
    void displayInfoWindow(
        boolean rhs);

    @VTID(304)
    boolean wait_(
        @MarshalAs(NativeType.VARIANT) java.lang.Object time,
        int lcid);

    @VTID(305)
    boolean extendList();

    @VTID(306)
    void extendList(
        boolean rhs);

    @VTID(307)
    mol.excel.OLEDBErrors oledbErrors();

    @VTID(308)
    java.lang.String getPhonetic(
        @MarshalAs(NativeType.VARIANT) java.lang.Object text);

    @VTID(309)
    mol.office.COMAddIns comAddIns();

    @VTID(309)
    @ReturnValue(defaultPropertyThrough={mol.office.COMAddIns.class})
    mol.office.COMAddIn comAddIns(
        java.lang.Object index);

    @VTID(310)
    mol.excel.DefaultWebOptions defaultWebOptions();

    @VTID(311)
    java.lang.String productCode();

    @VTID(312)
    java.lang.String userLibraryPath();

    @VTID(313)
    boolean autoPercentEntry();

    @VTID(314)
    void autoPercentEntry(
        boolean rhs);

    @VTID(315)
    mol.office.LanguageSettings languageSettings();

    @VTID(316)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject dummy101();

    @VTID(317)
    void dummy12(
        mol.excel.PivotTable p1,
        mol.excel.PivotTable p2);

    @VTID(318)
    mol.office.AnswerWizard answerWizard();

    @VTID(319)
    void calculateFull();

    @VTID(320)
    boolean findFile(
        int lcid);

    @VTID(321)
    int calculationVersion();

    @VTID(322)
    boolean showWindowsInTaskbar();

    @VTID(323)
    void showWindowsInTaskbar(
        boolean rhs);

    @VTID(324)
    mol.office.MsoFeatureInstall featureInstall();

    @VTID(325)
    void featureInstall(
        mol.office.MsoFeatureInstall rhs);

    @VTID(326)
    boolean ready();

    @VTID(327)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object dummy13(
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

    @VTID(328)
    mol.excel.CellFormat findFormat();

    @VTID(329)
    void findFormat(
        mol.excel.CellFormat rhs);

    @VTID(330)
    mol.excel.CellFormat replaceFormat();

    @VTID(331)
    void replaceFormat(
        mol.excel.CellFormat rhs);

    @VTID(332)
    mol.excel.UsedObjects usedObjects();

    @VTID(333)
    mol.excel.XlCalculationState calculationState();

    @VTID(334)
    mol.excel.XlCalculationInterruptKey calculationInterruptKey();

    @VTID(335)
    void calculationInterruptKey(
        mol.excel.XlCalculationInterruptKey rhs);

    @VTID(336)
    mol.excel.Watches watches();

    @VTID(337)
    boolean displayFunctionToolTips();

    @VTID(338)
    void displayFunctionToolTips(
        boolean rhs);

    @VTID(339)
    mol.office.MsoAutomationSecurity automationSecurity();

    @VTID(340)
    void automationSecurity(
        mol.office.MsoAutomationSecurity rhs);

    @VTID(341)
    mol.office.FileDialog fileDialog(
        mol.office.MsoFileDialogType fileDialogType);

    @VTID(342)
    void dummy14();

    @VTID(343)
    void calculateFullRebuild();

    @VTID(344)
    boolean displayPasteOptions();

    @VTID(345)
    void displayPasteOptions(
        boolean rhs);

    @VTID(346)
    boolean displayInsertOptions();

    @VTID(347)
    void displayInsertOptions(
        boolean rhs);

    @VTID(348)
    boolean generateGetPivotData();

    @VTID(349)
    void generateGetPivotData(
        boolean rhs);

    @VTID(350)
    mol.excel.AutoRecover autoRecover();

    @VTID(351)
    int hwnd();

    @VTID(352)
    int hinstance();

    @VTID(353)
    void checkAbort(
        @MarshalAs(NativeType.VARIANT) java.lang.Object keepAbort);

    @VTID(354)
    mol.excel.ErrorCheckingOptions errorCheckingOptions();

    @VTID(355)
    boolean autoFormatAsYouTypeReplaceHyperlinks();

    @VTID(356)
    void autoFormatAsYouTypeReplaceHyperlinks(
        boolean rhs);

    @VTID(357)
    mol.excel.SmartTagRecognizers smartTagRecognizers();

    @VTID(358)
    mol.office.NewFile newWorkbook();

    @VTID(359)
    mol.excel.SpellingOptions spellingOptions();

    @VTID(360)
    mol.excel.Speech speech();

    @VTID(361)
    boolean mapPaperSize();

    @VTID(362)
    void mapPaperSize(
        boolean rhs);

    @VTID(363)
    boolean showStartupDialog();

    @VTID(364)
    void showStartupDialog(
        boolean rhs);

    @VTID(365)
    java.lang.String decimalSeparator();

    @VTID(366)
    void decimalSeparator(
        java.lang.String rhs);

    @VTID(367)
    java.lang.String thousandsSeparator();

    @VTID(368)
    void thousandsSeparator(
        java.lang.String rhs);

    @VTID(369)
    boolean useSystemSeparators();

    @VTID(370)
    void useSystemSeparators(
        boolean rhs);

    @VTID(371)
    mol.excel.Range thisCell();

    @VTID(372)
    mol.excel.RTD rtd();

    @VTID(373)
    boolean displayDocumentActionTaskPane();

    @VTID(374)
    void displayDocumentActionTaskPane(
        boolean rhs);

    @VTID(375)
    void displayXMLSourcePane(
        @MarshalAs(NativeType.VARIANT) java.lang.Object xmlMap);

    @VTID(376)
    boolean arbitraryXMLSupportAvailable();

    @VTID(377)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object support(
        @MarshalAs(NativeType.Dispatch) com4j.Com4jObject object,
        int id,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg);

    @VTID(378)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object dummy20(
        int grfCompareFunctions);

    @VTID(379)
    int measurementUnit();

    @VTID(380)
    void measurementUnit(
        int rhs);

    @VTID(381)
    boolean showSelectionFloaties();

    @VTID(382)
    void showSelectionFloaties(
        boolean rhs);

    @VTID(383)
    boolean showMenuFloaties();

    @VTID(384)
    void showMenuFloaties(
        boolean rhs);

    @VTID(385)
    boolean showDevTools();

    @VTID(386)
    void showDevTools(
        boolean rhs);

    @VTID(387)
    boolean enableLivePreview();

    @VTID(388)
    void enableLivePreview(
        boolean rhs);

    @VTID(389)
    boolean displayDocumentInformationPanel();

    @VTID(390)
    void displayDocumentInformationPanel(
        boolean rhs);

    @VTID(391)
    boolean alwaysUseClearType();

    @VTID(392)
    void alwaysUseClearType(
        boolean rhs);

    @VTID(393)
    boolean warnOnFunctionNameConflict();

    @VTID(394)
    void warnOnFunctionNameConflict(
        boolean rhs);

    @VTID(395)
    int formulaBarHeight();

    @VTID(396)
    void formulaBarHeight(
        int rhs);

    @VTID(397)
    boolean displayFormulaAutoComplete();

    @VTID(398)
    void displayFormulaAutoComplete(
        boolean rhs);

    @VTID(399)
    mol.excel.XlGenerateTableRefs generateTableRefs(
        int lcid);

    @VTID(400)
    void generateTableRefs(
        int lcid,
        mol.excel.XlGenerateTableRefs rhs);

    @VTID(401)
    mol.office.IAssistance assistance();

    @VTID(402)
    void calculateUntilAsyncQueriesDone();

    @VTID(403)
    boolean enableLargeOperationAlert();

    @VTID(404)
    void enableLargeOperationAlert(
        boolean rhs);

    @VTID(405)
    int largeOperationCellThousandCount();

    @VTID(406)
    void largeOperationCellThousandCount(
        int rhs);

    @VTID(407)
    boolean deferAsyncQueries();

    @VTID(408)
    void deferAsyncQueries(
        boolean rhs);

    @VTID(409)
    mol.excel.MultiThreadedCalculation multiThreadedCalculation();

    @VTID(410)
    int sharePointVersion(
        java.lang.String bstrUrl);

    @VTID(411)
    int activeEncryptionSession();

    @VTID(412)
    boolean highQualityModeForGraphics();

    @VTID(413)
    void highQualityModeForGraphics(
        boolean rhs);

}
