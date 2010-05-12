package mol.excel  ;

import com4j.*;

@IID("{00020400-0000-0000-C000-000000000046}")
public interface ListRow extends Com4jObject {
    @DISPID(148)
    @PropGet
    mol.excel._Application application();

    @DISPID(149)
    @PropGet
    mol.excel.XlCreator creator();

    @DISPID(150)
    @PropGet
    com4j.Com4jObject parent();

    @DISPID(117)
    void delete();

    @DISPID(486)
    @PropGet
    int index();

    @DISPID(2324)
    @PropGet
    boolean invalidData();

    @DISPID(197)
    @PropGet
    mol.excel.Range range();

}
