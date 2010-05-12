package mol.excel  ;

import com4j.*;

@IID("{00020400-0000-0000-C000-000000000046}")
public interface PivotLayout extends Com4jObject {
    @DISPID(148)
    @PropGet
    mol.excel._Application application();

    @DISPID(149)
    @PropGet
    mol.excel.XlCreator creator();

    @DISPID(150)
    @PropGet
    com4j.Com4jObject parent();

    @DISPID(713)
    @PropGet
    com4j.Com4jObject columnFields(
        java.lang.Object index);

    @DISPID(715)
    @PropGet
    com4j.Com4jObject dataFields(
        java.lang.Object index);

    @DISPID(714)
    @PropGet
    com4j.Com4jObject pageFields(
        java.lang.Object index);

    @DISPID(712)
    @PropGet
    com4j.Com4jObject rowFields(
        java.lang.Object index);

    @DISPID(711)
    @PropGet
    com4j.Com4jObject hiddenFields(
        java.lang.Object index);

    @DISPID(710)
    @PropGet
    com4j.Com4jObject visibleFields(
        java.lang.Object index);

    @DISPID(718)
    @PropGet
    com4j.Com4jObject pivotFields(
        java.lang.Object index);

    @DISPID(1839)
    @PropGet
    mol.excel.CubeFields cubeFields();

    @DISPID(1496)
    @PropGet
    mol.excel.PivotCache pivotCache();

    @DISPID(716)
    @PropGet
    mol.excel.PivotTable pivotTable();

    @DISPID(698)
    @PropGet
    java.lang.String innerDetail();

    @DISPID(698)
    @PropPut
    void innerDetail(
        java.lang.String rhs);

    @DISPID(708)
    void addFields(
        java.lang.Object rowFields,
        java.lang.Object columnFields,
        java.lang.Object pageFields,
        java.lang.Object appendField);

}
