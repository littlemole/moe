package mol.excel  ;

import com4j.*;

@IID("{000208DB-0000-0000-C000-000000000046}")
public interface Workbooks extends Com4jObject,Iterable<Com4jObject> {
    @VTID(7)
    mol.excel._Application application();

    @VTID(8)
    mol.excel.XlCreator creator();

    @VTID(9)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

    @VTID(10)
    mol.excel._Workbook add(
        @MarshalAs(NativeType.VARIANT) java.lang.Object template,
        int lcid);

    @VTID(11)
    void close(
        int lcid);

    @VTID(12)
    int count();

    @VTID(13)
    mol.excel._Workbook item(
        @MarshalAs(NativeType.VARIANT) java.lang.Object index);

    @VTID(14)
    java.util.Iterator<Com4jObject> iterator();

    @VTID(15)
    mol.excel._Workbook _Open(
        java.lang.String filename,
        @MarshalAs(NativeType.VARIANT) java.lang.Object updateLinks,
        @MarshalAs(NativeType.VARIANT) java.lang.Object readOnly,
        @MarshalAs(NativeType.VARIANT) java.lang.Object format,
        @MarshalAs(NativeType.VARIANT) java.lang.Object password,
        @MarshalAs(NativeType.VARIANT) java.lang.Object writeResPassword,
        @MarshalAs(NativeType.VARIANT) java.lang.Object ignoreReadOnlyRecommended,
        @MarshalAs(NativeType.VARIANT) java.lang.Object origin,
        @MarshalAs(NativeType.VARIANT) java.lang.Object delimiter,
        @MarshalAs(NativeType.VARIANT) java.lang.Object editable,
        @MarshalAs(NativeType.VARIANT) java.lang.Object notify,
        @MarshalAs(NativeType.VARIANT) java.lang.Object converter,
        @MarshalAs(NativeType.VARIANT) java.lang.Object addToMru,
        int lcid);

    @VTID(16)
    void __OpenText(
        java.lang.String filename,
        @MarshalAs(NativeType.VARIANT) java.lang.Object origin,
        @MarshalAs(NativeType.VARIANT) java.lang.Object startRow,
        @MarshalAs(NativeType.VARIANT) java.lang.Object dataType,
        mol.excel.XlTextQualifier textQualifier,
        @MarshalAs(NativeType.VARIANT) java.lang.Object consecutiveDelimiter,
        @MarshalAs(NativeType.VARIANT) java.lang.Object tab,
        @MarshalAs(NativeType.VARIANT) java.lang.Object semicolon,
        @MarshalAs(NativeType.VARIANT) java.lang.Object comma,
        @MarshalAs(NativeType.VARIANT) java.lang.Object space,
        @MarshalAs(NativeType.VARIANT) java.lang.Object other,
        @MarshalAs(NativeType.VARIANT) java.lang.Object otherChar,
        @MarshalAs(NativeType.VARIANT) java.lang.Object fieldInfo,
        @MarshalAs(NativeType.VARIANT) java.lang.Object textVisualLayout,
        int lcid);

    @VTID(17)
    @DefaultMethod
    mol.excel._Workbook _Default(
        @MarshalAs(NativeType.VARIANT) java.lang.Object index);

    @VTID(18)
    void _OpenText(
        java.lang.String filename,
        @MarshalAs(NativeType.VARIANT) java.lang.Object origin,
        @MarshalAs(NativeType.VARIANT) java.lang.Object startRow,
        @MarshalAs(NativeType.VARIANT) java.lang.Object dataType,
        mol.excel.XlTextQualifier textQualifier,
        @MarshalAs(NativeType.VARIANT) java.lang.Object consecutiveDelimiter,
        @MarshalAs(NativeType.VARIANT) java.lang.Object tab,
        @MarshalAs(NativeType.VARIANT) java.lang.Object semicolon,
        @MarshalAs(NativeType.VARIANT) java.lang.Object comma,
        @MarshalAs(NativeType.VARIANT) java.lang.Object space,
        @MarshalAs(NativeType.VARIANT) java.lang.Object other,
        @MarshalAs(NativeType.VARIANT) java.lang.Object otherChar,
        @MarshalAs(NativeType.VARIANT) java.lang.Object fieldInfo,
        @MarshalAs(NativeType.VARIANT) java.lang.Object textVisualLayout,
        @MarshalAs(NativeType.VARIANT) java.lang.Object decimalSeparator,
        @MarshalAs(NativeType.VARIANT) java.lang.Object thousandsSeparator,
        int lcid);

    @VTID(19)
    mol.excel._Workbook open(
        java.lang.String filename,
        @MarshalAs(NativeType.VARIANT) java.lang.Object updateLinks,
        @MarshalAs(NativeType.VARIANT) java.lang.Object readOnly,
        @MarshalAs(NativeType.VARIANT) java.lang.Object format,
        @MarshalAs(NativeType.VARIANT) java.lang.Object password,
        @MarshalAs(NativeType.VARIANT) java.lang.Object writeResPassword,
        @MarshalAs(NativeType.VARIANT) java.lang.Object ignoreReadOnlyRecommended,
        @MarshalAs(NativeType.VARIANT) java.lang.Object origin,
        @MarshalAs(NativeType.VARIANT) java.lang.Object delimiter,
        @MarshalAs(NativeType.VARIANT) java.lang.Object editable,
        @MarshalAs(NativeType.VARIANT) java.lang.Object notify,
        @MarshalAs(NativeType.VARIANT) java.lang.Object converter,
        @MarshalAs(NativeType.VARIANT) java.lang.Object addToMru,
        @MarshalAs(NativeType.VARIANT) java.lang.Object local,
        @MarshalAs(NativeType.VARIANT) java.lang.Object corruptLoad,
        int lcid);

    @VTID(20)
    void openText(
        java.lang.String filename,
        @MarshalAs(NativeType.VARIANT) java.lang.Object origin,
        @MarshalAs(NativeType.VARIANT) java.lang.Object startRow,
        @MarshalAs(NativeType.VARIANT) java.lang.Object dataType,
        mol.excel.XlTextQualifier textQualifier,
        @MarshalAs(NativeType.VARIANT) java.lang.Object consecutiveDelimiter,
        @MarshalAs(NativeType.VARIANT) java.lang.Object tab,
        @MarshalAs(NativeType.VARIANT) java.lang.Object semicolon,
        @MarshalAs(NativeType.VARIANT) java.lang.Object comma,
        @MarshalAs(NativeType.VARIANT) java.lang.Object space,
        @MarshalAs(NativeType.VARIANT) java.lang.Object other,
        @MarshalAs(NativeType.VARIANT) java.lang.Object otherChar,
        @MarshalAs(NativeType.VARIANT) java.lang.Object fieldInfo,
        @MarshalAs(NativeType.VARIANT) java.lang.Object textVisualLayout,
        @MarshalAs(NativeType.VARIANT) java.lang.Object decimalSeparator,
        @MarshalAs(NativeType.VARIANT) java.lang.Object thousandsSeparator,
        @MarshalAs(NativeType.VARIANT) java.lang.Object trailingMinusNumbers,
        @MarshalAs(NativeType.VARIANT) java.lang.Object local,
        int lcid);

    @VTID(21)
    mol.excel._Workbook openDatabase(
        java.lang.String filename,
        @MarshalAs(NativeType.VARIANT) java.lang.Object commandText,
        @MarshalAs(NativeType.VARIANT) java.lang.Object commandType,
        @MarshalAs(NativeType.VARIANT) java.lang.Object backgroundQuery,
        @MarshalAs(NativeType.VARIANT) java.lang.Object importDataAs);

    @VTID(22)
    void checkOut(
        java.lang.String filename);

    @VTID(23)
    boolean canCheckOut(
        java.lang.String filename);

    @VTID(24)
    mol.excel._Workbook _OpenXML(
        java.lang.String filename,
        @MarshalAs(NativeType.VARIANT) java.lang.Object stylesheets);

    @VTID(25)
    mol.excel._Workbook openXML(
        java.lang.String filename,
        @MarshalAs(NativeType.VARIANT) java.lang.Object stylesheets,
        @MarshalAs(NativeType.VARIANT) java.lang.Object loadOption);

}
