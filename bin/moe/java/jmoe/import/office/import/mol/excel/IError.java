package mol.excel  ;

import com4j.*;

@IID("{0002445D-0001-0000-C000-000000000046}")
public interface IError extends Com4jObject {
    @VTID(7)
    mol.excel._Application application();

    @VTID(8)
    mol.excel.XlCreator creator();

    @VTID(9)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

    @VTID(10)
    boolean value();

    @VTID(11)
    boolean ignore();

    @VTID(12)
    void ignore(
        boolean rhs);

}