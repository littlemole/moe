package mol.excel  ;

import com4j.*;

@IID("{A43788C1-D91B-11D3-8F39-00C04F3651B8}")
public interface IRTDUpdateEvent extends Com4jObject {
    @VTID(7)
    void updateNotify();

    @VTID(8)
    int heartbeatInterval();

    @VTID(9)
    void heartbeatInterval(
        int plRetVal);

    @VTID(10)
    void disconnect();

}
