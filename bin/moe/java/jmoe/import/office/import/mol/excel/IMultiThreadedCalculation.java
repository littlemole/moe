package mol.excel  ;

import com4j.*;

@IID("{000244B1-0001-0000-C000-000000000046}")
public interface IMultiThreadedCalculation extends Com4jObject {
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
    mol.excel.XlThreadMode threadMode();

    @VTID(13)
    void threadMode(
        mol.excel.XlThreadMode rhs);

    @VTID(14)
    int threadCount();

    @VTID(15)
    void threadCount(
        int rhs);

}
