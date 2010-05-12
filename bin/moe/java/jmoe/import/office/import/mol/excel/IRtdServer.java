package mol.excel  ;

import com4j.*;

@IID("{EC0E6191-DB51-11D3-8F3E-00C04F3651B8}")
public interface IRtdServer extends Com4jObject {
    @VTID(7)
    int serverStart(
        mol.excel.IRTDUpdateEvent callbackObject);

        @VTID(9)
        java.lang.Object[] refreshData(
            Holder<Integer> topicCount);

        @VTID(10)
        void disconnectData(
            int topicID);

        @VTID(11)
        int heartbeat();

        @VTID(12)
        void serverTerminate();

    }
