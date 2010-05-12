package mol.excel  ;

import com4j.*;

@IID("{00020400-0000-0000-C000-000000000046}")
public interface XmlDataBinding extends Com4jObject {
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

    @DISPID(1417)
    mol.excel.XlXmlImportResult refresh();

    @DISPID(2329)
    void loadSettings(
        java.lang.String url);

    @DISPID(2330)
    void clearSettings();

    @DISPID(2331)
    @PropGet
    java.lang.String sourceUrl();

}
