package mol.excel  ;

import com4j.*;

@IID("{00020866-0001-0000-C000-000000000046}")
public interface IMenu extends Com4jObject {
    @VTID(7)
    mol.excel._Application application();

    @VTID(8)
    mol.excel.XlCreator creator();

    @VTID(9)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

    @VTID(10)
    java.lang.String caption();

    @VTID(11)
    void caption(
        java.lang.String rhs);

    @VTID(12)
    void delete();

    @VTID(13)
    boolean enabled();

    @VTID(14)
    void enabled(
        boolean rhs);

    @VTID(15)
    int index();

    @VTID(16)
    mol.excel.MenuItems menuItems();

}
