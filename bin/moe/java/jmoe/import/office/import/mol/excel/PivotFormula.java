package mol.excel  ;

import com4j.*;

@IID("{00020400-0000-0000-C000-000000000046}")
public interface PivotFormula extends Com4jObject {
    @DISPID(148)
    @PropGet
    mol.excel._Application application();

    @DISPID(149)
    @PropGet
    mol.excel.XlCreator creator();

    @DISPID(150)
    @PropGet
    com4j.Com4jObject parent();

    @DISPID(117)
    void delete();

    @DISPID(0)
    @PropGet
    @DefaultMethod
    java.lang.String _Default();

    @DISPID(0)
    @PropPut
    @DefaultMethod
    void _Default(
        java.lang.String rhs);

    @DISPID(261)
    @PropGet
    java.lang.String formula();

    @DISPID(261)
    @PropPut
    void formula(
        java.lang.String rhs);

    @DISPID(6)
    @PropGet
    java.lang.String value();

    @DISPID(6)
    @PropPut
    void value(
        java.lang.String rhs);

    @DISPID(486)
    @PropGet
    int index();

    @DISPID(486)
    @PropPut
    void index(
        int rhs);

    @DISPID(2084)
    @PropGet
    java.lang.String standardFormula();

    @DISPID(2084)
    @PropPut
    void standardFormula(
        java.lang.String rhs);

}
