package mol.excel  ;

import com4j.*;

@IID("{00020400-0000-0000-C000-000000000046}")
public interface ErrorBars extends Com4jObject {
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

    @DISPID(235)
    java.lang.Object select();

    @DISPID(128)
    @PropGet
    mol.excel.Border border();

    @DISPID(117)
    java.lang.Object delete();

    @DISPID(112)
    java.lang.Object clearFormats();

    @DISPID(1124)
    @PropGet
    mol.excel.XlEndStyleCap endStyle();

    @DISPID(1124)
    @PropPut
    void endStyle(
        mol.excel.XlEndStyleCap rhs);

    @DISPID(116)
    @PropGet
    mol.excel.ChartFormat format();

}
