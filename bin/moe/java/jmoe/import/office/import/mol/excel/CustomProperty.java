package mol.excel  ;

import com4j.*;

@IID("{00020400-0000-0000-C000-000000000046}")
public interface CustomProperty extends Com4jObject {
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

    @DISPID(6)
    @PropGet
    java.lang.Object value();

    @DISPID(6)
    @PropPut
    void value(
        java.lang.Object rhs);

    @DISPID(0)
    @PropGet
    @DefaultMethod
    java.lang.Object _Default();

    @DISPID(117)
    void delete();

}
