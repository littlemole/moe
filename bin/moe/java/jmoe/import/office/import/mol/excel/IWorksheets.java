package mol.excel  ;

import com4j.*;

@IID("{000208B1-0001-0000-C000-000000000046}")
public interface IWorksheets extends Com4jObject,Iterable<Com4jObject> {
    @VTID(7)
    mol.excel._Application application();

    @VTID(8)
    mol.excel.XlCreator creator();

    @VTID(9)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

    @VTID(10)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject add(
        @MarshalAs(NativeType.VARIANT) java.lang.Object before,
        @MarshalAs(NativeType.VARIANT) java.lang.Object after,
        @MarshalAs(NativeType.VARIANT) java.lang.Object count,
        @MarshalAs(NativeType.VARIANT) java.lang.Object type,
        int lcid);

    @VTID(11)
    void copy(
        @MarshalAs(NativeType.VARIANT) java.lang.Object before,
        @MarshalAs(NativeType.VARIANT) java.lang.Object after,
        int lcid);

    @VTID(12)
    int count();

    @VTID(13)
    void delete(
        int lcid);

    @VTID(14)
    void fillAcrossSheets(
        mol.excel.Range range,
        mol.excel.XlFillWith type,
        int lcid);

    @VTID(15)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject item(
        @MarshalAs(NativeType.VARIANT) java.lang.Object index);

    @VTID(16)
    void move(
        @MarshalAs(NativeType.VARIANT) java.lang.Object before,
        @MarshalAs(NativeType.VARIANT) java.lang.Object after,
        int lcid);

    @VTID(17)
    java.util.Iterator<Com4jObject> iterator();

    @VTID(18)
    void __PrintOut(
        @MarshalAs(NativeType.VARIANT) java.lang.Object from,
        @MarshalAs(NativeType.VARIANT) java.lang.Object to,
        @MarshalAs(NativeType.VARIANT) java.lang.Object copies,
        @MarshalAs(NativeType.VARIANT) java.lang.Object preview,
        @MarshalAs(NativeType.VARIANT) java.lang.Object activePrinter,
        @MarshalAs(NativeType.VARIANT) java.lang.Object printToFile,
        @MarshalAs(NativeType.VARIANT) java.lang.Object collate,
        int lcid);

    @VTID(19)
    void printPreview(
        @MarshalAs(NativeType.VARIANT) java.lang.Object enableChanges,
        int lcid);

    @VTID(20)
    void select(
        @MarshalAs(NativeType.VARIANT) java.lang.Object replace,
        int lcid);

    @VTID(21)
    mol.excel.HPageBreaks hPageBreaks();

    @VTID(22)
    mol.excel.VPageBreaks vPageBreaks();

    @VTID(23)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object visible(
        int lcid);

    @VTID(24)
    void visible(
        int lcid,
        @MarshalAs(NativeType.VARIANT) java.lang.Object rhs);

    @VTID(25)
    @DefaultMethod
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject _Default(
        @MarshalAs(NativeType.VARIANT) java.lang.Object index);

    @VTID(26)
    void _PrintOut(
        @MarshalAs(NativeType.VARIANT) java.lang.Object from,
        @MarshalAs(NativeType.VARIANT) java.lang.Object to,
        @MarshalAs(NativeType.VARIANT) java.lang.Object copies,
        @MarshalAs(NativeType.VARIANT) java.lang.Object preview,
        @MarshalAs(NativeType.VARIANT) java.lang.Object activePrinter,
        @MarshalAs(NativeType.VARIANT) java.lang.Object printToFile,
        @MarshalAs(NativeType.VARIANT) java.lang.Object collate,
        @MarshalAs(NativeType.VARIANT) java.lang.Object prToFileName,
        int lcid);

    @VTID(27)
    void printOut(
        @MarshalAs(NativeType.VARIANT) java.lang.Object from,
        @MarshalAs(NativeType.VARIANT) java.lang.Object to,
        @MarshalAs(NativeType.VARIANT) java.lang.Object copies,
        @MarshalAs(NativeType.VARIANT) java.lang.Object preview,
        @MarshalAs(NativeType.VARIANT) java.lang.Object activePrinter,
        @MarshalAs(NativeType.VARIANT) java.lang.Object printToFile,
        @MarshalAs(NativeType.VARIANT) java.lang.Object collate,
        @MarshalAs(NativeType.VARIANT) java.lang.Object prToFileName,
        @MarshalAs(NativeType.VARIANT) java.lang.Object ignorePrintAreas,
        int lcid);

}
