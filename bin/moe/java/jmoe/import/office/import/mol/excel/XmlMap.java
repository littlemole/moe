package mol.excel  ;

import com4j.*;

@IID("{00020400-0000-0000-C000-000000000046}")
public interface XmlMap extends Com4jObject {
    @DISPID(148)
    @PropGet
    mol.excel._Application application();

    @DISPID(149)
    @PropGet
    mol.excel.XlCreator creator();

    @DISPID(150)
    @PropGet
    com4j.Com4jObject parent();

    @DISPID(0)
    @PropGet
    @DefaultMethod
    java.lang.String _Default();

    @DISPID(110)
    @PropGet
    java.lang.String name();

    @DISPID(110)
    @PropPut
    void name(
        java.lang.String rhs);

    @DISPID(2334)
    @PropGet
    boolean isExportable();

    @DISPID(2335)
    @PropGet
    boolean showImportExportValidationErrors();

    @DISPID(2335)
    @PropPut
    void showImportExportValidationErrors(
        boolean rhs);

    @DISPID(2336)
    @PropGet
    boolean saveDataSourceDefinition();

    @DISPID(2336)
    @PropPut
    void saveDataSourceDefinition(
        boolean rhs);

    @DISPID(1868)
    @PropGet
    boolean adjustColumnWidth();

    @DISPID(1868)
    @PropPut
    void adjustColumnWidth(
        boolean rhs);

    @DISPID(2337)
    @PropGet
    boolean preserveColumnFilter();

    @DISPID(2337)
    @PropPut
    void preserveColumnFilter(
        boolean rhs);

    @DISPID(2338)
    @PropGet
    boolean preserveNumberFormatting();

    @DISPID(2338)
    @PropPut
    void preserveNumberFormatting(
        boolean rhs);

    @DISPID(2339)
    @PropGet
    boolean appendOnImport();

    @DISPID(2339)
    @PropPut
    void appendOnImport(
        boolean rhs);

    @DISPID(2340)
    @PropGet
    java.lang.String rootElementName();

    @DISPID(2341)
    @PropGet
    mol.excel.XmlNamespace rootElementNamespace();

    @DISPID(2342)
    @PropGet
    mol.excel.XmlSchemas schemas();

    @DISPID(2343)
    @PropGet
    mol.excel.XmlDataBinding dataBinding();

    @DISPID(117)
    void delete();

    @DISPID(917)
    mol.excel.XlXmlImportResult _import(
        java.lang.String url,
        java.lang.Object overwrite);

    @DISPID(2344)
    mol.excel.XlXmlImportResult importXml(
        java.lang.String xmlData,
        java.lang.Object overwrite);

    @DISPID(1414)
    mol.excel.XlXmlExportResult export(
        java.lang.String url,
        java.lang.Object overwrite);

    @DISPID(2346)
    mol.excel.XlXmlExportResult exportXml();

    @DISPID(2544)
    @PropGet
    mol.excel.WorkbookConnection workbookConnection();

}
