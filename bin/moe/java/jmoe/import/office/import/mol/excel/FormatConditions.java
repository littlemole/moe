package mol.excel  ;

import com4j.*;

@IID("{00020400-0000-0000-C000-000000000046}")
public interface FormatConditions extends Com4jObject,Iterable<Com4jObject> {
    @DISPID(148)
    @PropGet
    mol.excel._Application application();

    @DISPID(149)
    @PropGet
    mol.excel.XlCreator creator();

    @DISPID(150)
    @PropGet
    com4j.Com4jObject parent();

    @DISPID(118)
    @PropGet
    int count();

    @DISPID(170)
    com4j.Com4jObject item(
        java.lang.Object index);

    @DISPID(181)
    com4j.Com4jObject add(
        mol.excel.XlFormatConditionType type,
        java.lang.Object operator,
        java.lang.Object formula1,
        java.lang.Object formula2,
        java.lang.Object string,
        java.lang.Object textOperator,
        java.lang.Object dateOperator,
        java.lang.Object scopeType);

    @DISPID(0)
    @PropGet
    @DefaultMethod
    com4j.Com4jObject _Default(
        java.lang.Object index);

    @DISPID(-4)
    @PropGet
    java.util.Iterator<Com4jObject> iterator();

    @DISPID(117)
    void delete();

    @DISPID(2616)
    com4j.Com4jObject addColorScale(
        int colorScaleType);

    @DISPID(2618)
    com4j.Com4jObject addDatabar();

    @DISPID(2619)
    com4j.Com4jObject addIconSetCondition();

    @DISPID(2620)
    com4j.Com4jObject addTop10();

    @DISPID(2621)
    com4j.Com4jObject addAboveAverage();

    @DISPID(2622)
    com4j.Com4jObject addUniqueValues();

}
