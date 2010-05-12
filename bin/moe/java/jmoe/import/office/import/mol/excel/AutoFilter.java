package mol.excel  ;

import com4j.*;

@IID("{00020400-0000-0000-C000-000000000046}")
public interface AutoFilter extends Com4jObject {
    @DISPID(148)
    @PropGet
    mol.excel._Application application();

    @DISPID(149)
    @PropGet
    mol.excel.XlCreator creator();

    @DISPID(150)
    @PropGet
    com4j.Com4jObject parent();

    @DISPID(197)
    @PropGet
    mol.excel.Range range();

    @DISPID(1617)
    @PropGet
    mol.excel.Filters filters();

    @DISPID(800)
    @PropGet
    boolean filterMode();

    @DISPID(880)
    @PropGet
    mol.excel.Sort sort();

    @DISPID(2640)
    void applyFilter();

    @DISPID(794)
    void showAllData();

}
