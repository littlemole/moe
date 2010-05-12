package mol.excel.events;

import com4j.*;

@IID("{00024413-0000-0000-C000-000000000046}")
public abstract class AppEvents {
    @DISPID(1565)
    public void newWorkbook(
        mol.excel._Workbook wb) {
            throw new UnsupportedOperationException();
    }

    @DISPID(1558)
    public void sheetSelectionChange(
        com4j.Com4jObject sh,
        mol.excel.Range target) {
            throw new UnsupportedOperationException();
    }

    @DISPID(1559)
    public void sheetBeforeDoubleClick(
        com4j.Com4jObject sh,
        mol.excel.Range target,
        Holder<Boolean> cancel) {
            throw new UnsupportedOperationException();
    }

    @DISPID(1560)
    public void sheetBeforeRightClick(
        com4j.Com4jObject sh,
        mol.excel.Range target,
        Holder<Boolean> cancel) {
            throw new UnsupportedOperationException();
    }

    @DISPID(1561)
    public void sheetActivate(
        com4j.Com4jObject sh) {
            throw new UnsupportedOperationException();
    }

    @DISPID(1562)
    public void sheetDeactivate(
        com4j.Com4jObject sh) {
            throw new UnsupportedOperationException();
    }

    @DISPID(1563)
    public void sheetCalculate(
        com4j.Com4jObject sh) {
            throw new UnsupportedOperationException();
    }

    @DISPID(1564)
    public void sheetChange(
        com4j.Com4jObject sh,
        mol.excel.Range target) {
            throw new UnsupportedOperationException();
    }

    @DISPID(1567)
    public void workbookOpen(
        mol.excel._Workbook wb) {
            throw new UnsupportedOperationException();
    }

    @DISPID(1568)
    public void workbookActivate(
        mol.excel._Workbook wb) {
            throw new UnsupportedOperationException();
    }

    @DISPID(1569)
    public void workbookDeactivate(
        mol.excel._Workbook wb) {
            throw new UnsupportedOperationException();
    }

    @DISPID(1570)
    public void workbookBeforeClose(
        mol.excel._Workbook wb,
        Holder<Boolean> cancel) {
            throw new UnsupportedOperationException();
    }

    @DISPID(1571)
    public void workbookBeforeSave(
        mol.excel._Workbook wb,
        boolean saveAsUI,
        Holder<Boolean> cancel) {
            throw new UnsupportedOperationException();
    }

    @DISPID(1572)
    public void workbookBeforePrint(
        mol.excel._Workbook wb,
        Holder<Boolean> cancel) {
            throw new UnsupportedOperationException();
    }

    @DISPID(1573)
    public void workbookNewSheet(
        mol.excel._Workbook wb,
        com4j.Com4jObject sh) {
            throw new UnsupportedOperationException();
    }

    @DISPID(1574)
    public void workbookAddinInstall(
        mol.excel._Workbook wb) {
            throw new UnsupportedOperationException();
    }

    @DISPID(1575)
    public void workbookAddinUninstall(
        mol.excel._Workbook wb) {
            throw new UnsupportedOperationException();
    }

    @DISPID(1554)
    public void windowResize(
        mol.excel._Workbook wb,
        mol.excel.Window wn) {
            throw new UnsupportedOperationException();
    }

    @DISPID(1556)
    public void windowActivate(
        mol.excel._Workbook wb,
        mol.excel.Window wn) {
            throw new UnsupportedOperationException();
    }

    @DISPID(1557)
    public void windowDeactivate(
        mol.excel._Workbook wb,
        mol.excel.Window wn) {
            throw new UnsupportedOperationException();
    }

    @DISPID(1854)
    public void sheetFollowHyperlink(
        com4j.Com4jObject sh,
        mol.excel.Hyperlink target) {
            throw new UnsupportedOperationException();
    }

    @DISPID(2157)
    public void sheetPivotTableUpdate(
        com4j.Com4jObject sh,
        mol.excel.PivotTable target) {
            throw new UnsupportedOperationException();
    }

    @DISPID(2160)
    public void workbookPivotTableCloseConnection(
        mol.excel._Workbook wb,
        mol.excel.PivotTable target) {
            throw new UnsupportedOperationException();
    }

    @DISPID(2161)
    public void workbookPivotTableOpenConnection(
        mol.excel._Workbook wb,
        mol.excel.PivotTable target) {
            throw new UnsupportedOperationException();
    }

    @DISPID(2289)
    public void workbookSync(
        mol.excel._Workbook wb,
        mol.office.MsoSyncEventType syncEventType) {
            throw new UnsupportedOperationException();
    }

    @DISPID(2290)
    public void workbookBeforeXmlImport(
        mol.excel._Workbook wb,
        mol.excel.XmlMap map,
        java.lang.String url,
        boolean isRefresh,
        Holder<Boolean> cancel) {
            throw new UnsupportedOperationException();
    }

    @DISPID(2291)
    public void workbookAfterXmlImport(
        mol.excel._Workbook wb,
        mol.excel.XmlMap map,
        boolean isRefresh,
        mol.excel.XlXmlImportResult result) {
            throw new UnsupportedOperationException();
    }

    @DISPID(2292)
    public void workbookBeforeXmlExport(
        mol.excel._Workbook wb,
        mol.excel.XmlMap map,
        java.lang.String url,
        Holder<Boolean> cancel) {
            throw new UnsupportedOperationException();
    }

    @DISPID(2293)
    public void workbookAfterXmlExport(
        mol.excel._Workbook wb,
        mol.excel.XmlMap map,
        java.lang.String url,
        mol.excel.XlXmlExportResult result) {
            throw new UnsupportedOperationException();
    }

    @DISPID(2611)
    public void workbookRowsetComplete(
        mol.excel._Workbook wb,
        java.lang.String description,
        java.lang.String sheet,
        boolean success) {
            throw new UnsupportedOperationException();
    }

    @DISPID(2612)
    public void afterCalculate() {
            throw new UnsupportedOperationException();
    }

}
