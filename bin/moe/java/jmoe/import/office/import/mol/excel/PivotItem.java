package mol.excel  ;

import com4j.*;

@IID("{00020400-0000-0000-C000-000000000046}")
public interface PivotItem extends Com4jObject {
    @DISPID(148)
    @PropGet
    mol.excel._Application application();

    @DISPID(149)
    @PropGet
    mol.excel.XlCreator creator();

    @DISPID(150)
    @PropGet
    mol.excel.PivotField parent();

    @DISPID(730)
    @PropGet
    java.lang.Object childItems(
        java.lang.Object index);

    @DISPID(720)
    @PropGet
    mol.excel.Range dataRange();

    @DISPID(0)
    @PropGet
    @DefaultMethod
    java.lang.String _Default();

    @DISPID(0)
    @PropPut
    @DefaultMethod
    void _Default(
        java.lang.String rhs);

    @DISPID(719)
    @PropGet
    mol.excel.Range labelRange();

    @DISPID(110)
    @PropGet
    java.lang.String name();

    @DISPID(110)
    @PropPut
    void name(
        java.lang.String rhs);

    @DISPID(741)
    @PropGet
    mol.excel.PivotItem parentItem();

    @DISPID(739)
    @PropGet
    boolean parentShowDetail();

    @DISPID(133)
    @PropGet
    int position();

    @DISPID(133)
    @PropPut
    void position(
        int rhs);

    @DISPID(585)
    @PropGet
    boolean showDetail();

    @DISPID(585)
    @PropPut
    void showDetail(
        boolean rhs);

    @DISPID(721)
    @PropGet
    java.lang.Object sourceName();

    @DISPID(6)
    @PropGet
    java.lang.String value();

    @DISPID(6)
    @PropPut
    void value(
        java.lang.String rhs);

    @DISPID(558)
    @PropGet
    boolean visible();

    @DISPID(558)
    @PropPut
    void visible(
        boolean rhs);

    @DISPID(117)
    void delete();

    @DISPID(1512)
    @PropGet
    boolean isCalculated();

    @DISPID(1478)
    @PropGet
    int recordCount();

    @DISPID(261)
    @PropGet
    java.lang.String formula();

    @DISPID(261)
    @PropPut
    void formula(
        java.lang.String rhs);

    @DISPID(139)
    @PropGet
    java.lang.String caption();

    @DISPID(139)
    @PropPut
    void caption(
        java.lang.String rhs);

    @DISPID(1850)
    @PropGet
    boolean drilledDown();

    @DISPID(1850)
    @PropPut
    void drilledDown(
        boolean rhs);

    @DISPID(2084)
    @PropGet
    java.lang.String standardFormula();

    @DISPID(2084)
    @PropPut
    void standardFormula(
        java.lang.String rhs);

    @DISPID(2148)
    @PropGet
    java.lang.String sourceNameStandard();

    @DISPID(2580)
    void drillTo(
        java.lang.String field);

}
