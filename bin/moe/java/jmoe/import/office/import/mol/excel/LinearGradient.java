package mol.excel  ;

import com4j.*;

@IID("{00020400-0000-0000-C000-000000000046}")
public interface LinearGradient extends Com4jObject {
    @DISPID(148)
    @PropGet
    mol.excel._Application application();

    @DISPID(149)
    @PropGet
    mol.excel.XlCreator creator();

    @DISPID(150)
    @PropGet
    com4j.Com4jObject parent();

    @DISPID(2761)
    @PropGet
    mol.excel.ColorStops colorStops();

    @DISPID(1623)
    @PropGet
    double degree();

    @DISPID(1623)
    @PropPut
    void degree(
        double rhs);

}
