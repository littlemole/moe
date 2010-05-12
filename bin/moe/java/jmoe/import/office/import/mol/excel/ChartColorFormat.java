package mol.excel  ;

import com4j.*;

@IID("{00020400-0000-0000-C000-000000000046}")
public interface ChartColorFormat extends Com4jObject {
    @DISPID(148)
    @PropGet
    mol.excel._Application application();

    @DISPID(149)
    @PropGet
    mol.excel.XlCreator creator();

    @DISPID(150)
    @PropGet
    com4j.Com4jObject parent();

    @DISPID(1646)
    @PropGet
    int schemeColor();

    @DISPID(1646)
    @PropPut
    void schemeColor(
        int rhs);

    @DISPID(1055)
    @PropGet
    int rgb();

    @DISPID(0)
    @PropGet
    @DefaultMethod
    int _Default();

    @DISPID(108)
    @PropGet
    int type();

}
