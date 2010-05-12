package mol.excel  ;

import com4j.*;

@IID("{00020400-0000-0000-C000-000000000046}")
public interface IconCriteria extends Com4jObject,Iterable<Com4jObject> {
    @DISPID(118)
    @PropGet
    int count();

    @DISPID(0)
    @PropGet
    @DefaultMethod
    mol.excel.IconCriterion _Default(
        java.lang.Object index);

    @DISPID(-4)
    @PropGet
    java.util.Iterator<Com4jObject> iterator();

    @DISPID(170)
    @PropGet
    mol.excel.IconCriterion item(
        java.lang.Object index);

}
