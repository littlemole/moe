package mol.excel  ;

import com4j.*;

@IID("{00020400-0000-0000-C000-000000000046}")
public interface MenuBar extends Com4jObject {
    @DISPID(148)
    @PropGet
    mol.excel._Application application();

    @DISPID(149)
    @PropGet
    mol.excel.XlCreator creator();

    @DISPID(150)
    @PropGet
    com4j.Com4jObject parent();

    @DISPID(304)
    void activate();

    @DISPID(553)
    @PropGet
    boolean builtIn();

    @DISPID(139)
    @PropGet
    java.lang.String caption();

    @DISPID(139)
    @PropPut
    void caption(
        java.lang.String rhs);

    @DISPID(117)
    void delete();

    @DISPID(486)
    @PropGet
    int index();

    @DISPID(591)
    @PropGet
    mol.excel.Menus menus();

    @DISPID(555)
    void reset();

}
