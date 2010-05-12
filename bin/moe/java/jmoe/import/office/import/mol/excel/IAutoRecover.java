package mol.excel  ;

import com4j.*;

@IID("{0002445A-0001-0000-C000-000000000046}")
public interface IAutoRecover extends Com4jObject {
    @VTID(7)
    mol.excel._Application application();

    @VTID(8)
    mol.excel.XlCreator creator();

    @VTID(9)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

    @VTID(10)
    boolean enabled();

    @VTID(11)
    void enabled(
        boolean rhs);

    @VTID(12)
    int time();

    @VTID(13)
    void time(
        int rhs);

    @VTID(14)
    java.lang.String path();

    @VTID(15)
    void path(
        java.lang.String rhs);

}
