package mol.excel  ;

import com4j.*;

@IID("{00020400-0000-0000-C000-000000000046}")
public interface Characters extends Com4jObject {
    @DISPID(148)
    @PropGet
    mol.excel._Application application();

    @DISPID(149)
    @PropGet
    mol.excel.XlCreator creator();

    @DISPID(150)
    @PropGet
    com4j.Com4jObject parent();

    @DISPID(139)
    @PropGet
    java.lang.String caption();

    @DISPID(139)
    @PropPut
    void caption(
        java.lang.String rhs);

    @DISPID(118)
    @PropGet
    int count();

    @DISPID(117)
    java.lang.Object delete();

    @DISPID(146)
    @PropGet
    mol.excel.Font font();

    @DISPID(252)
    java.lang.Object insert(
        java.lang.String string);

    @DISPID(138)
    @PropGet
    java.lang.String text();

    @DISPID(138)
    @PropPut
    void text(
        java.lang.String rhs);

    @DISPID(1522)
    @PropGet
    java.lang.String phoneticCharacters();

    @DISPID(1522)
    @PropPut
    void phoneticCharacters(
        java.lang.String rhs);

}
