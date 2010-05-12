package mol.excel  ;

import com4j.*;

@IID("{00020864-0001-0000-C000-000000000046}")
public interface IMenuBar extends Com4jObject {
    @VTID(7)
    mol.excel._Application application();

    @VTID(8)
    mol.excel.XlCreator creator();

    @VTID(9)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

    @VTID(10)
    void activate();

    @VTID(11)
    boolean builtIn();

    @VTID(12)
    java.lang.String caption();

    @VTID(13)
    void caption(
        java.lang.String rhs);

    @VTID(14)
    void delete();

    @VTID(15)
    int index();

    @VTID(16)
    mol.excel.Menus menus();

    @VTID(17)
    void reset();

}
