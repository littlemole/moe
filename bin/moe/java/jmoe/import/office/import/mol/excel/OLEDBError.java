package mol.excel  ;

import com4j.*;

@IID("{00020400-0000-0000-C000-000000000046}")
public interface OLEDBError extends Com4jObject {
    @DISPID(148)
    @PropGet
    mol.excel._Application application();

    @DISPID(149)
    @PropGet
    mol.excel.XlCreator creator();

    @DISPID(150)
    @PropGet
    com4j.Com4jObject parent();

    @DISPID(1603)
    @PropGet
    java.lang.String sqlState();

    @DISPID(1490)
    @PropGet
    java.lang.String errorString();

    @DISPID(1897)
    @PropGet
    int _native();

    @DISPID(451)
    @PropGet
    int number();

    @DISPID(1898)
    @PropGet
    int stage();

}
