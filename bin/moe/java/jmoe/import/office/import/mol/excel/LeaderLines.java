package mol.excel  ;

import com4j.*;

@IID("{00020400-0000-0000-C000-000000000046}")
public interface LeaderLines extends Com4jObject {
    @DISPID(148)
    @PropGet
    mol.excel._Application application();

    @DISPID(149)
    @PropGet
    mol.excel.XlCreator creator();

    @DISPID(150)
    @PropGet
    com4j.Com4jObject parent();

    @DISPID(128)
    @PropGet
    mol.excel.Border border();

    @DISPID(117)
    void delete();

    @DISPID(235)
    void select();

    @DISPID(116)
    @PropGet
    mol.excel.ChartFormat format();

}
