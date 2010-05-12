package mol.excel  ;

import com4j.*;

@IID("{0002446E-0001-0000-C000-000000000046}")
public interface IRTD extends Com4jObject {
    @VTID(7)
    int throttleInterval();

    @VTID(8)
    void throttleInterval(
        int rhs);

    @VTID(9)
    void refreshData();

    @VTID(10)
    void restartServers();

}
