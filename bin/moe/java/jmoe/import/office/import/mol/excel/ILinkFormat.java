package mol.excel  ;

import com4j.*;

@IID("{00024442-0001-0000-C000-000000000046}")
public interface ILinkFormat extends Com4jObject {
    @VTID(7)
    mol.excel._Application application();

    @VTID(8)
    mol.excel.XlCreator creator();

    @VTID(9)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

    @VTID(10)
    boolean autoUpdate();

    @VTID(11)
    void autoUpdate(
        boolean rhs);

    @VTID(12)
    boolean locked();

    @VTID(13)
    void locked(
        boolean rhs);

    @VTID(14)
    void update();

}
