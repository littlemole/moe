package mol.excel  ;

import com4j.*;

@IID("{00020400-0000-0000-C000-000000000046}")
public interface Action extends Com4jObject {
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

    @DISPID(139)
    @PropGet
    java.lang.String caption();

    @DISPID(108)
    @PropGet
    mol.excel.XlActionType type();

    @DISPID(2712)
    @PropGet
    java.lang.String coordinate();

    @DISPID(2713)
    @PropGet
    java.lang.String content();

    @DISPID(2211)
    void execute();

}
