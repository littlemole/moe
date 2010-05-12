package mol.excel  ;

import com4j.*;

@IID("{00020400-0000-0000-C000-000000000046}")
public interface Names extends Com4jObject,Iterable<Com4jObject> {
    @DISPID(148)
    @PropGet
    mol.excel._Application application();

    @DISPID(149)
    @PropGet
    mol.excel.XlCreator creator();

    @DISPID(150)
    @PropGet
    com4j.Com4jObject parent();

    @DISPID(181)
    mol.excel.Name add(
        java.lang.Object name,
        java.lang.Object refersTo,
        java.lang.Object visible,
        java.lang.Object macroType,
        java.lang.Object shortcutKey,
        java.lang.Object category,
        java.lang.Object nameLocal,
        java.lang.Object refersToLocal,
        java.lang.Object categoryLocal,
        java.lang.Object refersToR1C1,
        java.lang.Object refersToR1C1Local);

    @DISPID(170)
    mol.excel.Name item(
        java.lang.Object index,
        java.lang.Object indexLocal,
        java.lang.Object refersTo);

    @DISPID(0)
    @DefaultMethod
    mol.excel.Name _Default(
        java.lang.Object index,
        java.lang.Object indexLocal,
        java.lang.Object refersTo);

    @DISPID(118)
    @PropGet
    int count();

    @DISPID(-4)
    @PropGet
    java.util.Iterator<Com4jObject> iterator();

}
