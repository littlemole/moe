package mol.excel  ;

import com4j.*;

@IID("{00020400-0000-0000-C000-000000000046}")
public interface Phonetic extends Com4jObject {
    @DISPID(148)
    @PropGet
    mol.excel._Application application();

    @DISPID(149)
    @PropGet
    mol.excel.XlCreator creator();

    @DISPID(150)
    @PropGet
    com4j.Com4jObject parent();

    @DISPID(558)
    @PropGet
    boolean visible();

    @DISPID(558)
    @PropPut
    void visible(
        boolean rhs);

    @DISPID(1674)
    @PropGet
    int characterType();

    @DISPID(1674)
    @PropPut
    void characterType(
        int rhs);

    @DISPID(453)
    @PropGet
    int alignment();

    @DISPID(453)
    @PropPut
    void alignment(
        int rhs);

    @DISPID(146)
    @PropGet
    mol.excel.Font font();

    @DISPID(138)
    @PropGet
    java.lang.String text();

    @DISPID(138)
    @PropPut
    void text(
        java.lang.String rhs);

}
