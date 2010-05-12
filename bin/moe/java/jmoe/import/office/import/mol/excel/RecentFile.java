package mol.excel  ;

import com4j.*;

@IID("{00020400-0000-0000-C000-000000000046}")
public interface RecentFile extends Com4jObject {
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

    @DISPID(291)
    @PropGet
    java.lang.String path();

    @DISPID(486)
    @PropGet
    int index();

    @DISPID(1923)
    mol.excel._Workbook open();

    @DISPID(117)
    void delete();

}
