package mol.excel  ;

import com4j.*;

@IID("{0002085C-0001-0000-C000-000000000046}")
public interface IToolbar extends Com4jObject {
    @VTID(7)
    mol.excel._Application application();

    @VTID(8)
    mol.excel.XlCreator creator();

    @VTID(9)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

    @VTID(10)
    boolean builtIn();

    @VTID(11)
    void delete();

    @VTID(12)
    int height();

    @VTID(13)
    void height(
        int rhs);

    @VTID(14)
    int left();

    @VTID(15)
    void left(
        int rhs);

    @VTID(16)
    java.lang.String name();

    @VTID(17)
    int position();

    @VTID(18)
    void position(
        int rhs);

    @VTID(19)
    mol.excel.XlToolbarProtection protection();

    @VTID(20)
    void protection(
        mol.excel.XlToolbarProtection rhs);

    @VTID(21)
    void reset();

    @VTID(22)
    mol.excel.ToolbarButtons toolbarButtons();

    @VTID(23)
    int top();

    @VTID(24)
    void top(
        int rhs);

    @VTID(25)
    boolean visible();

    @VTID(26)
    void visible(
        boolean rhs);

    @VTID(27)
    int width();

    @VTID(28)
    void width(
        int rhs);

}
