package mol.excel  ;

import com4j.*;

@IID("{00020400-0000-0000-C000-000000000046}")
public interface Phonetics extends Com4jObject,Iterable<Com4jObject> {
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

    @DISPID(608)
    @PropGet
    int start();

    @DISPID(609)
    @PropGet
    int length();

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

    @DISPID(170)
    @PropGet
    com4j.Com4jObject item(
        int index);

    @DISPID(117)
    void delete();

    @DISPID(181)
    void add(
        int start,
        int length,
        java.lang.String text);

    @DISPID(138)
    @PropGet
    java.lang.String text();

    @DISPID(138)
    @PropPut
    void text(
        java.lang.String rhs);

    @DISPID(0)
    @PropGet
    @DefaultMethod
    com4j.Com4jObject _Default(
        int index);

    @DISPID(-4)
    @PropGet
    java.util.Iterator<Com4jObject> iterator();

}
