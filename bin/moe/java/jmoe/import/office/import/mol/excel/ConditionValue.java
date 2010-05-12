package mol.excel  ;

import com4j.*;

@IID("{00020400-0000-0000-C000-000000000046}")
public interface ConditionValue extends Com4jObject {
    @DISPID(148)
    @PropGet
    mol.excel._Application application();

    @DISPID(149)
    @PropGet
    mol.excel.XlCreator creator();

    @DISPID(150)
    @PropGet
    com4j.Com4jObject parent();

    @DISPID(1581)
    void modify(
        mol.excel.XlConditionValueTypes newtype,
        java.lang.Object newvalue);

    @DISPID(108)
    @PropGet
    mol.excel.XlConditionValueTypes type();

    @DISPID(6)
    @PropGet
    java.lang.Object value();

}
