package mol.excel  ;

import com4j.*;

@IID("{00020400-0000-0000-C000-000000000046}")
public interface Error extends Com4jObject {
    @DISPID(148)
    @PropGet
    mol.excel._Application application();

    @DISPID(149)
    @PropGet
    mol.excel.XlCreator creator();

    @DISPID(150)
    @PropGet
    com4j.Com4jObject parent();

    @DISPID(6)
    @PropGet
    boolean value();

    @DISPID(2210)
    @PropGet
    boolean ignore();

    @DISPID(2210)
    @PropPut
    void ignore(
        boolean rhs);

}
