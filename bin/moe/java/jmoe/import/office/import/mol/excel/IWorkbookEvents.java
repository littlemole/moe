package mol.excel  ;

import com4j.*;

@IID("{00024412-0001-0000-C000-000000000046}")
public interface IWorkbookEvents extends Com4jObject {
    @VTID(7)
    void open();

    @VTID(8)
    void activate();

    @VTID(9)
    void deactivate();

    @VTID(10)
    void beforeClose(
        Holder<Boolean> cancel);

    @VTID(11)
    void beforeSave(
        boolean saveAsUI,
        Holder<Boolean> cancel);

    @VTID(12)
    void beforePrint(
        Holder<Boolean> cancel);

    @VTID(13)
    void newSheet(
        @MarshalAs(NativeType.Dispatch) com4j.Com4jObject sh);

    @VTID(14)
    void addinInstall();

    @VTID(15)
    void addinUninstall();

    @VTID(16)
    void windowResize(
        mol.excel.Window wn);

    @VTID(17)
    void windowActivate(
        mol.excel.Window wn);

    @VTID(18)
    void windowDeactivate(
        mol.excel.Window wn);

    @VTID(19)
    void sheetSelectionChange(
        @MarshalAs(NativeType.Dispatch) com4j.Com4jObject sh,
        mol.excel.Range target);

    @VTID(20)
    void sheetBeforeDoubleClick(
        @MarshalAs(NativeType.Dispatch) com4j.Com4jObject sh,
        mol.excel.Range target,
        Holder<Boolean> cancel);

    @VTID(21)
    void sheetBeforeRightClick(
        @MarshalAs(NativeType.Dispatch) com4j.Com4jObject sh,
        mol.excel.Range target,
        Holder<Boolean> cancel);

    @VTID(22)
    void sheetActivate(
        @MarshalAs(NativeType.Dispatch) com4j.Com4jObject sh);

    @VTID(23)
    void sheetDeactivate(
        @MarshalAs(NativeType.Dispatch) com4j.Com4jObject sh);

    @VTID(24)
    void sheetCalculate(
        @MarshalAs(NativeType.Dispatch) com4j.Com4jObject sh);

    @VTID(25)
    void sheetChange(
        @MarshalAs(NativeType.Dispatch) com4j.Com4jObject sh,
        mol.excel.Range target);

    @VTID(26)
    void sheetFollowHyperlink(
        @MarshalAs(NativeType.Dispatch) com4j.Com4jObject sh,
        mol.excel.Hyperlink target);

    @VTID(27)
    void sheetPivotTableUpdate(
        @MarshalAs(NativeType.Dispatch) com4j.Com4jObject sh,
        mol.excel.PivotTable target);

    @VTID(28)
    void pivotTableCloseConnection(
        mol.excel.PivotTable target);

    @VTID(29)
    void pivotTableOpenConnection(
        mol.excel.PivotTable target);

    @VTID(30)
    void sync(
        mol.office.MsoSyncEventType syncEventType);

    @VTID(31)
    void beforeXmlImport(
        mol.excel.XmlMap map,
        java.lang.String url,
        boolean isRefresh,
        Holder<Boolean> cancel);

    @VTID(32)
    void afterXmlImport(
        mol.excel.XmlMap map,
        boolean isRefresh,
        mol.excel.XlXmlImportResult result);

    @VTID(33)
    void beforeXmlExport(
        mol.excel.XmlMap map,
        java.lang.String url,
        Holder<Boolean> cancel);

    @VTID(34)
    void afterXmlExport(
        mol.excel.XmlMap map,
        java.lang.String url,
        mol.excel.XlXmlExportResult result);

    @VTID(35)
    void rowsetComplete(
        java.lang.String description,
        java.lang.String sheet,
        boolean success);

}
