package mol.excel  ;

import com4j.*;

@IID("{00020400-0000-0000-C000-000000000046}")
public interface Parameter extends Com4jObject {
    @DISPID(148)
    @PropGet
    mol.excel._Application application();

    @DISPID(149)
    @PropGet
    mol.excel.XlCreator creator();

    @DISPID(150)
    @PropGet
    com4j.Com4jObject parent();

    @DISPID(722)
    @PropGet
    mol.excel.XlParameterDataType dataType();

    @DISPID(722)
    @PropPut
    void dataType(
        mol.excel.XlParameterDataType rhs);

    @DISPID(108)
    @PropGet
    mol.excel.XlParameterType type();

    @DISPID(1599)
    @PropGet
    java.lang.String promptString();

    @DISPID(6)
    @PropGet
    java.lang.Object value();

    @DISPID(1600)
    @PropGet
    mol.excel.Range sourceRange();

    @DISPID(110)
    @PropGet
    java.lang.String name();

    @DISPID(110)
    @PropPut
    void name(
        java.lang.String rhs);

    @DISPID(1601)
    void setParam(
        mol.excel.XlParameterType type,
        java.lang.Object value);

    @DISPID(1879)
    @PropGet
    boolean refreshOnChange();

    @DISPID(1879)
    @PropPut
    void refreshOnChange(
        boolean rhs);

}
