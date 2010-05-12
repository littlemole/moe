package mol.excel  ;

import com4j.*;
import mol.office.*;
import mol.vba.*;

@IID("{000208D9-0000-0000-C000-000000000046}")
public interface _Global extends Com4jObject {
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

}
