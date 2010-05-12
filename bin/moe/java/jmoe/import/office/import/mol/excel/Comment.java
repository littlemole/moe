package mol.excel  ;

import com4j.*;

@IID("{00020400-0000-0000-C000-000000000046}")
public interface Comment extends Com4jObject {
    @DISPID(148)
    @PropGet
    mol.excel._Application application();

    @DISPID(149)
    @PropGet
    mol.excel.XlCreator creator();

    @DISPID(150)
    @PropGet
    com4j.Com4jObject parent();

    @DISPID(574)
    @PropGet
    java.lang.String author();

    @DISPID(1582)
    @PropGet
    mol.excel.Shape shape();

    @DISPID(558)
    @PropGet
    boolean visible();

    @DISPID(558)
    @PropPut
    void visible(
        boolean rhs);

    @DISPID(138)
    java.lang.String text(
        java.lang.Object text,
        java.lang.Object start,
        java.lang.Object overwrite);

    @DISPID(117)
    void delete();

    @DISPID(502)
    mol.excel.Comment next();

    @DISPID(503)
    mol.excel.Comment previous();

}
