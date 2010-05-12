package mol.excel  ;

import com4j.*;

@IID("{00020400-0000-0000-C000-000000000046}")
public interface Module extends Com4jObject {
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

    @DISPID(65554)
    void _Dummy18();

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

    @DISPID(65557)
    void _Dummy21();

    @DISPID(1159)
    @PropGet
    boolean protectionMode();

    @DISPID(65559)
    void _Dummy23();

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

    @DISPID(584)
    java.lang.Object insertFile(
        java.lang.Object filename,
        java.lang.Object merge);

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
        java.lang.Object textVisualLayout);

    @DISPID(2029)
    void protect(
        java.lang.Object password,
        java.lang.Object drawingObjects,
        java.lang.Object contents,
        java.lang.Object scenarios,
        java.lang.Object userInterfaceOnly);

    @DISPID(1772)
    void _PrintOut(
        java.lang.Object from,
        java.lang.Object to,
        java.lang.Object copies,
        java.lang.Object preview,
        java.lang.Object activePrinter,
        java.lang.Object printToFile,
        java.lang.Object collate);

    @DISPID(2361)
    void printOut(
        java.lang.Object from,
        java.lang.Object to,
        java.lang.Object copies,
        java.lang.Object preview,
        java.lang.Object activePrinter,
        java.lang.Object printToFile,
        java.lang.Object collate);

}
