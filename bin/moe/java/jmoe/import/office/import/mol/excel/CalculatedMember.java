package mol.excel  ;

import com4j.*;

@IID("{00020400-0000-0000-C000-000000000046}")
public interface CalculatedMember extends Com4jObject {
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

    @DISPID(261)
    @PropGet
    java.lang.String formula();

    @DISPID(721)
    @PropGet
    java.lang.String sourceName();

    @DISPID(2187)
    @PropGet
    int solveOrder();

    @DISPID(2188)
    @PropGet
    boolean isValid();

    @DISPID(0)
    @PropGet
    @DefaultMethod
    java.lang.String _Default();

    @DISPID(117)
    void delete();

    @DISPID(108)
    @PropGet
    mol.excel.XlCalculatedMemberType type();

}
