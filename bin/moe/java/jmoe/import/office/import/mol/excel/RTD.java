package mol.excel  ;

import com4j.*;

@IID("{00020400-0000-0000-C000-000000000046}")
public interface RTD extends Com4jObject {
    @DISPID(2240)
    @PropGet
    int throttleInterval();

    @DISPID(2240)
    @PropPut
    void throttleInterval(
        int rhs);

    @DISPID(2241)
    void refreshData();

    @DISPID(2242)
    void restartServers();

}
