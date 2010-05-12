package mol.excel.events;

import com4j.*;

@IID("{00024412-0000-0000-C000-000000000046}")
public abstract class WorkbookEvents {
    @DISPID(1923)
    public void open() {
            throw new UnsupportedOperationException();
    }

    @DISPID(304)
    public void activate() {
            throw new UnsupportedOperationException();
    }

    @DISPID(1530)
    public void deactivate() {
            throw new UnsupportedOperationException();
    }

    @DISPID(1546)
    public void beforeClose(
        Holder<Boolean> cancel) {
            throw new UnsupportedOperationException();
    }

    @DISPID(1547)
    public void beforeSave(
        boolean saveAsUI,
        Holder<Boolean> cancel) {
            throw new UnsupportedOperationException();
    }

    @DISPID(1549)
    public void beforePrint(
        Holder<Boolean> cancel) {
            throw new UnsupportedOperationException();
    }

    @DISPID(1550)
    public void newSheet(
        com4j.Com4jObject sh) {
            throw new UnsupportedOperationException();
    }

    @DISPID(1552)
    public void addinInstall() {
            throw new UnsupportedOperationException();
    }

    @DISPID(1553)
    public void addinUninstall() {
            throw new UnsupportedOperationException();
    }

    @DISPID(1554)
    public void windowResize(
        mol.excel.Window wn) {
            throw new UnsupportedOperationException();
    }

    @DISPID(1556)
    public void windowActivate(
        mol.excel.Window wn) {
            throw new UnsupportedOperationException();
    }

    @DISPID(1557)
    public void windowDeactivate(
        mol.excel.Window wn) {
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

    @DISPID(2158)
    public void pivotTableCloseConnection(
        mol.excel.PivotTable target) {
            throw new UnsupportedOperationException();
    }

    @DISPID(2159)
    public void pivotTableOpenConnection(
        mol.excel.PivotTable target) {
            throw new UnsupportedOperationException();
    }

    @DISPID(2266)
    public void sync(
        mol.office.MsoSyncEventType syncEventType) {
            throw new UnsupportedOperationException();
    }

    @DISPID(2283)
    public void beforeXmlImport(
        mol.excel.XmlMap map,
        java.lang.String url,
        boolean isRefresh,
        Holder<Boolean> cancel) {
            throw new UnsupportedOperationException();
    }

    @DISPID(2285)
    public void afterXmlImport(
        mol.excel.XmlMap map,
        boolean isRefresh,
        mol.excel.XlXmlImportResult result) {
            throw new UnsupportedOperationException();
    }

    @DISPID(2287)
    public void beforeXmlExport(
        mol.excel.XmlMap map,
        java.lang.String url,
        Holder<Boolean> cancel) {
            throw new UnsupportedOperationException();
    }

    @DISPID(2288)
    public void afterXmlExport(
        mol.excel.XmlMap map,
        java.lang.String url,
        mol.excel.XlXmlExportResult result) {
            throw new UnsupportedOperationException();
    }

    @DISPID(2610)
    public void rowsetComplete(
        java.lang.String description,
        java.lang.String sheet,
        boolean success) {
            throw new UnsupportedOperationException();
    }

}
