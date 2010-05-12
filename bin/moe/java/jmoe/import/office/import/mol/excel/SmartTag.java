package mol.excel  ;

import com4j.*;

@IID("{00020400-0000-0000-C000-000000000046}")
public interface SmartTag extends Com4jObject {
    @DISPID(148)
    @PropGet
    mol.excel._Application application();

    @DISPID(149)
    @PropGet
    mol.excel.XlCreator creator();

    @DISPID(150)
    @PropGet
    com4j.Com4jObject parent();

    @DISPID(2212)
    @PropGet
    java.lang.String downloadURL();

    @DISPID(110)
    @PropGet
    java.lang.String name();

    @DISPID(0)
    @PropGet
    @DefaultMethod
    java.lang.String _Default();

    @DISPID(2213)
    @PropGet
    java.lang.String xml();

    @DISPID(197)
    @PropGet
    mol.excel.Range range();

    @DISPID(117)
    void delete();

    @DISPID(2214)
    @PropGet
    mol.excel.SmartTagActions smartTagActions();

    @DISPID(2135)
    @PropGet
    mol.excel.CustomProperties properties();

}
