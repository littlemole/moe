package mol.wsh  ;

import com4j.*;

/**
 * Network Object
 */
@IID("{24BE5A31-EDFE-11D2-B933-00104B365C9F}")
public interface IWshNetwork2 extends mol.wsh.IWshNetwork {
    @VTID(20)
    void addWindowsPrinterConnection(
        java.lang.String printerName,
        java.lang.String driverName,
        java.lang.String port);

}
