package mol.excel  ;

import com4j.*;

@IID("{000208AD-0001-0000-C000-000000000046}")
public interface IModule extends Com4jObject {
    @VTID(7)
    mol.excel._Application application();

    @VTID(8)
    mol.excel.XlCreator creator();

    @VTID(9)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

    @VTID(10)
    void activate(
        int lcid);

    @VTID(11)
    void copy(
        @MarshalAs(NativeType.VARIANT) java.lang.Object before,
        @MarshalAs(NativeType.VARIANT) java.lang.Object after,
        int lcid);

    @VTID(12)
    void delete(
        int lcid);

    @VTID(13)
    java.lang.String codeName();

    @VTID(14)
    java.lang.String _CodeName();

    @VTID(15)
    void _CodeName(
        java.lang.String rhs);

    @VTID(16)
    int index(
        int lcid);

    @VTID(17)
    void move(
        @MarshalAs(NativeType.VARIANT) java.lang.Object before,
        @MarshalAs(NativeType.VARIANT) java.lang.Object after,
        int lcid);

    @VTID(18)
    java.lang.String name();

    @VTID(19)
    void name(
        java.lang.String rhs);

    @VTID(20)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject next();

    @VTID(21)
    java.lang.String onDoubleClick(
        int lcid);

    @VTID(22)
    void onDoubleClick(
        int lcid,
        java.lang.String rhs);

    @VTID(23)
    java.lang.String onSheetActivate(
        int lcid);

    @VTID(24)
    void onSheetActivate(
        int lcid,
        java.lang.String rhs);

    @VTID(25)
    java.lang.String onSheetDeactivate(
        int lcid);

    @VTID(26)
    void onSheetDeactivate(
        int lcid,
        java.lang.String rhs);

    @VTID(27)
    mol.excel.PageSetup pageSetup();

    @VTID(28)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject previous();

    @VTID(29)
    void __PrintOut(
        @MarshalAs(NativeType.VARIANT) java.lang.Object from,
        @MarshalAs(NativeType.VARIANT) java.lang.Object to,
        @MarshalAs(NativeType.VARIANT) java.lang.Object copies,
        @MarshalAs(NativeType.VARIANT) java.lang.Object preview,
        @MarshalAs(NativeType.VARIANT) java.lang.Object activePrinter,
        @MarshalAs(NativeType.VARIANT) java.lang.Object printToFile,
        @MarshalAs(NativeType.VARIANT) java.lang.Object collate,
        int lcid);

    @VTID(30)
    void _Dummy18();

    @VTID(31)
    void _Protect(
        @MarshalAs(NativeType.VARIANT) java.lang.Object password,
        @MarshalAs(NativeType.VARIANT) java.lang.Object drawingObjects,
        @MarshalAs(NativeType.VARIANT) java.lang.Object contents,
        @MarshalAs(NativeType.VARIANT) java.lang.Object scenarios,
        @MarshalAs(NativeType.VARIANT) java.lang.Object userInterfaceOnly,
        int lcid);

    @VTID(32)
    boolean protectContents(
        int lcid);

    @VTID(33)
    void _Dummy21();

    @VTID(34)
    boolean protectionMode(
        int lcid);

    @VTID(35)
    void _Dummy23();

    @VTID(36)
    void _SaveAs(
        java.lang.String filename,
        @MarshalAs(NativeType.VARIANT) java.lang.Object fileFormat,
        @MarshalAs(NativeType.VARIANT) java.lang.Object password,
        @MarshalAs(NativeType.VARIANT) java.lang.Object writeResPassword,
        @MarshalAs(NativeType.VARIANT) java.lang.Object readOnlyRecommended,
        @MarshalAs(NativeType.VARIANT) java.lang.Object createBackup,
        @MarshalAs(NativeType.VARIANT) java.lang.Object addToMru,
        @MarshalAs(NativeType.VARIANT) java.lang.Object textCodepage,
        @MarshalAs(NativeType.VARIANT) java.lang.Object textVisualLayout,
        int lcid);

    @VTID(37)
    void select(
        @MarshalAs(NativeType.VARIANT) java.lang.Object replace,
        int lcid);

    @VTID(38)
    void unprotect(
        @MarshalAs(NativeType.VARIANT) java.lang.Object password,
        int lcid);

    @VTID(39)
    mol.excel.XlSheetVisibility visible(
        int lcid);

    @VTID(40)
    void visible(
        int lcid,
        mol.excel.XlSheetVisibility rhs);

    @VTID(41)
    mol.excel.Shapes shapes();

    @VTID(42)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object insertFile(
        @MarshalAs(NativeType.VARIANT) java.lang.Object filename,
        @MarshalAs(NativeType.VARIANT) java.lang.Object merge);

    @VTID(43)
    void saveAs(
        java.lang.String filename,
        @MarshalAs(NativeType.VARIANT) java.lang.Object fileFormat,
        @MarshalAs(NativeType.VARIANT) java.lang.Object password,
        @MarshalAs(NativeType.VARIANT) java.lang.Object writeResPassword,
        @MarshalAs(NativeType.VARIANT) java.lang.Object readOnlyRecommended,
        @MarshalAs(NativeType.VARIANT) java.lang.Object createBackup,
        @MarshalAs(NativeType.VARIANT) java.lang.Object addToMru,
        @MarshalAs(NativeType.VARIANT) java.lang.Object textCodepage,
        @MarshalAs(NativeType.VARIANT) java.lang.Object textVisualLayout);

    @VTID(44)
    void protect(
        @MarshalAs(NativeType.VARIANT) java.lang.Object password,
        @MarshalAs(NativeType.VARIANT) java.lang.Object drawingObjects,
        @MarshalAs(NativeType.VARIANT) java.lang.Object contents,
        @MarshalAs(NativeType.VARIANT) java.lang.Object scenarios,
        @MarshalAs(NativeType.VARIANT) java.lang.Object userInterfaceOnly);

    @VTID(45)
    void _PrintOut(
        @MarshalAs(NativeType.VARIANT) java.lang.Object from,
        @MarshalAs(NativeType.VARIANT) java.lang.Object to,
        @MarshalAs(NativeType.VARIANT) java.lang.Object copies,
        @MarshalAs(NativeType.VARIANT) java.lang.Object preview,
        @MarshalAs(NativeType.VARIANT) java.lang.Object activePrinter,
        @MarshalAs(NativeType.VARIANT) java.lang.Object printToFile,
        @MarshalAs(NativeType.VARIANT) java.lang.Object collate);

    @VTID(46)
    void printOut(
        @MarshalAs(NativeType.VARIANT) java.lang.Object from,
        @MarshalAs(NativeType.VARIANT) java.lang.Object to,
        @MarshalAs(NativeType.VARIANT) java.lang.Object copies,
        @MarshalAs(NativeType.VARIANT) java.lang.Object preview,
        @MarshalAs(NativeType.VARIANT) java.lang.Object activePrinter,
        @MarshalAs(NativeType.VARIANT) java.lang.Object printToFile,
        @MarshalAs(NativeType.VARIANT) java.lang.Object collate);

}
