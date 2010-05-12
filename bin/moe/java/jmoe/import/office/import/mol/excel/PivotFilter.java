package mol.excel  ;

import com4j.*;

@IID("{00020400-0000-0000-C000-000000000046}")
public interface PivotFilter extends Com4jObject {
    @DISPID(148)
    @PropGet
    mol.excel._Application application();

    @DISPID(149)
    @PropGet
    mol.excel.XlCreator creator();

    @DISPID(150)
    @PropGet
    com4j.Com4jObject parent();

    @DISPID(192)
    @PropGet
    int order();

    @DISPID(192)
    @PropPut
    void order(
        int rhs);

    @DISPID(2686)
    @PropGet
    mol.excel.XlPivotFilterType filterType();

    @DISPID(110)
    @PropGet
    java.lang.String name();

    @DISPID(218)
    @PropGet
    java.lang.String description();

    @DISPID(117)
    void delete();

    @DISPID(2312)
    @PropGet
    boolean active();

    @DISPID(731)
    @PropGet
    mol.excel.PivotField pivotField();

    @DISPID(2091)
    @PropGet
    mol.excel.PivotField dataField();

    @DISPID(2687)
    @PropGet
    mol.excel.CubeField dataCubeField();

    @DISPID(2688)
    @PropGet
    java.lang.Object value1();

    @DISPID(1388)
    @PropGet
    java.lang.Object value2();

    @DISPID(2689)
    @PropGet
    mol.excel.PivotField memberPropertyField();

    @DISPID(2690)
    @PropGet
    boolean isMemberPropertyFilter();

}
