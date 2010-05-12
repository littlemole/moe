package mol.excel  ;

import com4j.*;

@IID("{00020400-0000-0000-C000-000000000046}")
public interface Toolbar extends Com4jObject {
    @DISPID(148)
    @PropGet
    mol.excel._Application application();

    @DISPID(149)
    @PropGet
    mol.excel.XlCreator creator();

    @DISPID(150)
    @PropGet
    com4j.Com4jObject parent();

    @DISPID(553)
    @PropGet
    boolean builtIn();

    @DISPID(117)
    void delete();

    @DISPID(123)
    @PropGet
    int height();

    @DISPID(123)
    @PropPut
    void height(
        int rhs);

    @DISPID(127)
    @PropGet
    int left();

    @DISPID(127)
    @PropPut
    void left(
        int rhs);

    @DISPID(110)
    @PropGet
    java.lang.String name();

    @DISPID(133)
    @PropGet
    int position();

    @DISPID(133)
    @PropPut
    void position(
        int rhs);

    @DISPID(176)
    @PropGet
    mol.excel.XlToolbarProtection protection();

    @DISPID(176)
    @PropPut
    void protection(
        mol.excel.XlToolbarProtection rhs);

    @DISPID(555)
    void reset();

    @DISPID(964)
    @PropGet
    mol.excel.ToolbarButtons toolbarButtons();

    @DISPID(126)
    @PropGet
    int top();

    @DISPID(126)
    @PropPut
    void top(
        int rhs);

    @DISPID(558)
    @PropGet
    boolean visible();

    @DISPID(558)
    @PropPut
    void visible(
        boolean rhs);

    @DISPID(122)
    @PropGet
    int width();

    @DISPID(122)
    @PropPut
    void width(
        int rhs);

}
