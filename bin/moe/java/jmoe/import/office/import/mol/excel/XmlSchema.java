package mol.excel  ;

import com4j.*;

@IID("{00020400-0000-0000-C000-000000000046}")
public interface XmlSchema extends Com4jObject {
    @DISPID(148)
    @PropGet
    mol.excel._Application application();

    @DISPID(149)
    @PropGet
    mol.excel.XlCreator creator();

    @DISPID(150)
    @PropGet
    com4j.Com4jObject parent();

    @DISPID(2332)
    @PropGet
    mol.excel.XmlNamespace namespace();

    @DISPID(2333)
    @PropGet
    java.lang.String xml();

    @DISPID(110)
    @PropGet
    java.lang.String name();

}
