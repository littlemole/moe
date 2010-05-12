package mol.excel  ;

import com4j.*;

@IID("{00020400-0000-0000-C000-000000000046}")
public interface MultiThreadedCalculation extends Com4jObject {
    @DISPID(148)
    @PropGet
    mol.excel._Application application();

    @DISPID(149)
    @PropGet
    mol.excel.XlCreator creator();

    @DISPID(150)
    @PropGet
    com4j.Com4jObject parent();

    @DISPID(600)
    @PropGet
    boolean enabled();

    @DISPID(600)
    @PropPut
    void enabled(
        boolean rhs);

    @DISPID(2766)
    @PropGet
    mol.excel.XlThreadMode threadMode();

    @DISPID(2766)
    @PropPut
    void threadMode(
        mol.excel.XlThreadMode rhs);

    @DISPID(2767)
    @PropGet
    int threadCount();

    @DISPID(2767)
    @PropPut
    void threadCount(
        int rhs);

}
