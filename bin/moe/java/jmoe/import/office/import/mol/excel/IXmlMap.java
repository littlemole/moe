package mol.excel  ;

import com4j.*;

@IID("{0002447B-0001-0000-C000-000000000046}")
public interface IXmlMap extends Com4jObject {
    @VTID(7)
    mol.excel._Application application();

    @VTID(8)
    mol.excel.XlCreator creator();

    @VTID(9)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

    @VTID(10)
    @DefaultMethod
    java.lang.String _Default();

    @VTID(11)
    java.lang.String name();

    @VTID(12)
    void name(
        java.lang.String rhs);

    @VTID(13)
    boolean isExportable();

    @VTID(14)
    boolean showImportExportValidationErrors();

    @VTID(15)
    void showImportExportValidationErrors(
        boolean rhs);

    @VTID(16)
    boolean saveDataSourceDefinition();

    @VTID(17)
    void saveDataSourceDefinition(
        boolean rhs);

    @VTID(18)
    boolean adjustColumnWidth();

    @VTID(19)
    void adjustColumnWidth(
        boolean rhs);

    @VTID(20)
    boolean preserveColumnFilter();

    @VTID(21)
    void preserveColumnFilter(
        boolean rhs);

    @VTID(22)
    boolean preserveNumberFormatting();

    @VTID(23)
    void preserveNumberFormatting(
        boolean rhs);

    @VTID(24)
    boolean appendOnImport();

    @VTID(25)
    void appendOnImport(
        boolean rhs);

    @VTID(26)
    java.lang.String rootElementName();

    @VTID(27)
    mol.excel.XmlNamespace rootElementNamespace();

    @VTID(28)
    mol.excel.XmlSchemas schemas();

    @VTID(29)
    mol.excel.XmlDataBinding dataBinding();

    @VTID(30)
    void delete();

    @VTID(31)
    mol.excel.XlXmlImportResult _import(
        java.lang.String url,
        @MarshalAs(NativeType.VARIANT) java.lang.Object overwrite);

    @VTID(32)
    mol.excel.XlXmlImportResult importXml(
        java.lang.String xmlData,
        @MarshalAs(NativeType.VARIANT) java.lang.Object overwrite);

    @VTID(33)
    mol.excel.XlXmlExportResult export(
        java.lang.String url,
        @MarshalAs(NativeType.VARIANT) java.lang.Object overwrite);

    @VTID(34)
    mol.excel.XlXmlExportResult exportXml(
        Holder<java.lang.String> data);

    @VTID(35)
    mol.excel.WorkbookConnection workbookConnection();

}
