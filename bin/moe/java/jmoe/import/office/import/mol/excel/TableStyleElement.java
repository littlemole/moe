package mol.excel  ;

import com4j.*;

@IID("{00020400-0000-0000-C000-000000000046}")
public interface TableStyleElement extends Com4jObject {
    @DISPID(148)
    @PropGet
    mol.excel._Application application();

    @DISPID(149)
    @PropGet
    mol.excel.XlCreator creator();

    @DISPID(150)
    @PropGet
    com4j.Com4jObject parent();

    @DISPID(2735)
    @PropGet
    boolean hasFormat();

    @DISPID(129)
    @PropGet
    mol.excel.Interior interior();

    @DISPID(435)
    @PropGet
    mol.excel.Borders borders();

    @DISPID(146)
    @PropGet
    mol.excel.Font font();

    @DISPID(2736)
    @PropGet
    int stripeSize();

    @DISPID(2736)
    @PropPut
    void stripeSize(
        int rhs);

    @DISPID(111)
    void clear();

}
