package mol.excel  ;

import com4j.*;

@IID("{00024445-0001-0000-C000-000000000046}")
public interface IOLEDBError extends Com4jObject {
    @VTID(7)
    mol.excel._Application application();

    @VTID(8)
    mol.excel.XlCreator creator();

    @VTID(9)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

    @VTID(10)
    java.lang.String sqlState();

    @VTID(11)
    java.lang.String errorString();

    @VTID(12)
    int _native();

    @VTID(13)
    int number();

    @VTID(14)
    int stage();

}
