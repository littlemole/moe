package mol.excel  ;

import com4j.*;
import mol.office.*;
import mol.vba.*;

@IID("{00024413-0001-0000-C000-000000000046}")
public interface IAppEvents extends Com4jObject {
    @VTID(7)
    void newWorkbook(
        mol.excel._Workbook wb);

    @VTID(8)
    void sheetSelectionChange(
        @MarshalAs(NativeType.Dispatch) com4j.Com4jObject sh,
        mol.excel.Range target);

    @VTID(9)
    void sheetBeforeDoubleClick(
        @MarshalAs(NativeType.Dispatch) com4j.Com4jObject sh,
        mol.excel.Range target,
        Holder<Boolean> cancel);

    @VTID(10)
    void sheetBeforeRightClick(
        @MarshalAs(NativeType.Dispatch) com4j.Com4jObject sh,
        mol.excel.Range target,
        Holder<Boolean> cancel);

    @VTID(11)
    void sheetActivate(
        @MarshalAs(NativeType.Dispatch) com4j.Com4jObject sh);

    @VTID(12)
    void sheetDeactivate(
        @MarshalAs(NativeType.Dispatch) com4j.Com4jObject sh);

    @VTID(13)
    void sheetCalculate(
        @MarshalAs(NativeType.Dispatch) com4j.Com4jObject sh);

    @VTID(14)
    void sheetChange(
        @MarshalAs(NativeType.Dispatch) com4j.Com4jObject sh,
        mol.excel.Range target);

    @VTID(15)
    void workbookOpen(
        mol.excel._Workbook wb);

    @VTID(16)
    void workbookActivate(
        mol.excel._Workbook wb);

    @VTID(17)
    void workbookDeactivate(
        mol.excel._Workbook wb);

    @VTID(18)
    void workbookBeforeClose(
        mol.excel._Workbook wb,
        Holder<Boolean> cancel);

    @VTID(19)
    void workbookBeforeSave(
        mol.excel._Workbook wb,
        boolean saveAsUI,
        Holder<Boolean> cancel);

    @VTID(20)
    void workbookBeforePrint(
        mol.excel._Workbook wb,
        Holder<Boolean> cancel);

    @VTID(21)
    void workbookNewSheet(
        mol.excel._Workbook wb,
        @MarshalAs(NativeType.Dispatch) com4j.Com4jObject sh);

    @VTID(22)
    void workbookAddinInstall(
        mol.excel._Workbook wb);

    @VTID(23)
    void workbookAddinUninstall(
        mol.excel._Workbook wb);

    @VTID(24)
    void windowResize(
        mol.excel._Workbook wb,
        mol.excel.Window wn);

    @VTID(25)
    void windowActivate(
        mol.excel._Workbook wb,
        mol.excel.Window wn);

    @VTID(26)
    void windowDeactivate(
        mol.excel._Workbook wb,
        mol.excel.Window wn);

    @VTID(27)
    void sheetFollowHyperlink(
        @MarshalAs(NativeType.Dispatch) com4j.Com4jObject sh,
        mol.excel.Hyperlink target);

    @VTID(28)
    void sheetPivotTableUpdate(
        @MarshalAs(NativeType.Dispatch) com4j.Com4jObject sh,
        mol.excel.PivotTable target);

    @VTID(29)
    void workbookPivotTableCloseConnection(
        mol.excel._Workbook wb,
        mol.excel.PivotTable target);

    @VTID(30)
    void workbookPivotTableOpenConnection(
        mol.excel._Workbook wb,
        mol.excel.PivotTable target);

    @VTID(31)
    void workbookSync(
        mol.excel._Workbook wb,
        mol.office.MsoSyncEventType syncEventType);

    @VTID(32)
    void workbookBeforeXmlImport(
        mol.excel._Workbook wb,
        mol.excel.XmlMap map,
        java.lang.String url,
        boolean isRefresh,
        Holder<Boolean> cancel);

    @VTID(33)
    void workbookAfterXmlImport(
        mol.excel._Workbook wb,
        mol.excel.XmlMap map,
        boolean isRefresh,
        mol.excel.XlXmlImportResult result);

    @VTID(34)
    void workbookBeforeXmlExport(
        mol.excel._Workbook wb,
        mol.excel.XmlMap map,
        java.lang.String url,
        Holder<Boolean> cancel);

    @VTID(35)
    void workbookAfterXmlExport(
        mol.excel._Workbook wb,
        mol.excel.XmlMap map,
        java.lang.String url,
        mol.excel.XlXmlExportResult result);

    @VTID(36)
    void workbookRowsetComplete(
        mol.excel._Workbook wb,
        java.lang.String description,
        java.lang.String sheet,
        boolean success);

    @VTID(37)
    void afterCalculate();

}
