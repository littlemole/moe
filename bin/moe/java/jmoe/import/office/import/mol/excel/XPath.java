package mol.excel  ;

import com4j.*;

@IID("{00020400-0000-0000-C000-000000000046}")
public interface XPath extends Com4jObject {
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

    @DISPID(6)
    @PropGet
    java.lang.String value();

    @DISPID(2262)
    @PropGet
    mol.excel.XmlMap map();

    @DISPID(2358)
    void setValue(
        mol.excel.XmlMap map,
        java.lang.String xPath,
        java.lang.Object selectionNamespace,
        java.lang.Object repeating);

    @DISPID(111)
    void clear();

    @DISPID(2360)
    @PropGet
    boolean repeating();

}
