package mol.excel  ;

import com4j.*;

@IID("{00020400-0000-0000-C000-000000000046}")
public interface Panes extends Com4jObject {
    @DISPID(148)
    @PropGet
    mol.excel._Application application();

    @DISPID(149)
    @PropGet
    mol.excel.XlCreator creator();

    @DISPID(150)
    @PropGet
    com4j.Com4jObject parent();

    @DISPID(118)
    @PropGet
    int count();

    @DISPID(170)
    @PropGet
    mol.excel.Pane item(
        int index);

    @DISPID(0)
    @PropGet
    @DefaultMethod
    mol.excel.Pane _Default(
        int index);

}
