package mol.excel  ;

import com4j.*;

@IID("{00020400-0000-0000-C000-000000000046}")
public interface IconCriterion extends Com4jObject {
    @DISPID(486)
    @PropGet
    int index();

    @DISPID(108)
    @PropGet
    mol.excel.XlConditionValueTypes type();

    @DISPID(108)
    @PropPut
    void type(
        mol.excel.XlConditionValueTypes rhs);

    @DISPID(6)
    @PropGet
    java.lang.Object value();

    @DISPID(6)
    @PropPut
    void value(
        java.lang.Object rhs);

    @DISPID(797)
    @PropGet
    int operator();

    @DISPID(797)
    @PropPut
    void operator(
        int rhs);

}
