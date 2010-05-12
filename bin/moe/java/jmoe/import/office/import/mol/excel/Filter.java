package mol.excel  ;

import com4j.*;

@IID("{00020400-0000-0000-C000-000000000046}")
public interface Filter extends Com4jObject {
    @DISPID(148)
    @PropGet
    mol.excel._Application application();

    @DISPID(149)
    @PropGet
    mol.excel.XlCreator creator();

    @DISPID(150)
    @PropGet
    com4j.Com4jObject parent();

    @DISPID(1618)
    @PropGet
    boolean on();

    @DISPID(796)
    @PropGet
    java.lang.Object criteria1();

    @DISPID(2641)
    @PropGet
    mol.excel.XlAutoFilterOperator _Operator();

    @DISPID(798)
    @PropGet
    java.lang.Object criteria2();

    @DISPID(797)
    @PropGet
    mol.excel.XlAutoFilterOperator operator();

    @DISPID(797)
    @PropPut
    void operator(
        mol.excel.XlAutoFilterOperator rhs);

    @DISPID(118)
    @PropGet
    int count();

}
