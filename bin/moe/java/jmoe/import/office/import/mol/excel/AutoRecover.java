package mol.excel  ;

import com4j.*;

@IID("{00020400-0000-0000-C000-000000000046}")
public interface AutoRecover extends Com4jObject {
    @DISPID(148)
    @PropGet
    mol.excel._Application application();

    @DISPID(149)
    @PropGet
    mol.excel.XlCreator creator();

    @DISPID(150)
    @PropGet
    com4j.Com4jObject parent();

    @DISPID(600)
    @PropGet
    boolean enabled();

    @DISPID(600)
    @PropPut
    void enabled(
        boolean rhs);

    @DISPID(394)
    @PropGet
    int time();

    @DISPID(394)
    @PropPut
    void time(
        int rhs);

    @DISPID(291)
    @PropGet
    java.lang.String path();

    @DISPID(291)
    @PropPut
    void path(
        java.lang.String rhs);

}
