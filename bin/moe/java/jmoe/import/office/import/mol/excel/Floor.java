package mol.excel  ;

import com4j.*;

@IID("{00020400-0000-0000-C000-000000000046}")
public interface Floor extends Com4jObject {
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

    @DISPID(112)
    java.lang.Object clearFormats();

    @DISPID(129)
    @PropGet
    mol.excel.Interior interior();

    @DISPID(1663)
    @PropGet
    mol.excel.ChartFillFormat fill();

    @DISPID(161)
    @PropGet
    java.lang.Object pictureType();

    @DISPID(161)
    @PropPut
    void pictureType(
        java.lang.Object rhs);

    @DISPID(211)
    void paste();

    @DISPID(2652)
    @PropGet
    int thickness();

    @DISPID(2652)
    @PropPut
    void thickness(
        int rhs);

    @DISPID(116)
    @PropGet
    mol.excel.ChartFormat format();

}
