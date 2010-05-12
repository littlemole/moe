package mol.excel  ;

import com4j.*;

@IID("{00020400-0000-0000-C000-000000000046}")
public interface WorkbookConnection extends Com4jObject {
    @DISPID(148)
    @PropGet
    mol.excel._Application application();

    @DISPID(149)
    @PropGet
    mol.excel.XlCreator creator();

    @DISPID(150)
    @PropGet
    com4j.Com4jObject parent();

    @DISPID(110)
    @PropGet
    java.lang.String name();

    @DISPID(110)
    @PropPut
    void name(
        java.lang.String rhs);

    @DISPID(218)
    @PropGet
    java.lang.String description();

    @DISPID(218)
    @PropPut
    void description(
        java.lang.String rhs);

    @DISPID(0)
    @PropGet
    @DefaultMethod
    java.lang.String _Default();

    @DISPID(0)
    @PropPut
    @DefaultMethod
    void _Default(
        java.lang.String rhs);

    @DISPID(108)
    @PropGet
    mol.excel.XlConnectionType type();

    @DISPID(2697)
    @PropGet
    mol.excel.OLEDBConnection oledbConnection();

    @DISPID(2698)
    @PropGet
    mol.excel.ODBCConnection odbcConnection();

    @DISPID(2699)
    @PropGet
    mol.excel.Ranges ranges();

    @DISPID(117)
    void delete();

    @DISPID(1417)
    void refresh();

}
