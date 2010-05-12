package mol.excel  ;

import com4j.*;

@IID("{00020400-0000-0000-C000-000000000046}")
public interface CustomViews extends Com4jObject,Iterable<Com4jObject> {
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
    mol.excel.CustomView item(
        java.lang.Object viewName);

    @DISPID(181)
    mol.excel.CustomView add(
        java.lang.String viewName,
        java.lang.Object printSettings,
        java.lang.Object rowColSettings);

    @DISPID(0)
    @PropGet
    @DefaultMethod
    mol.excel.CustomView _Default(
        java.lang.Object viewName);

    @DISPID(-4)
    @PropGet
    java.util.Iterator<Com4jObject> iterator();

}
