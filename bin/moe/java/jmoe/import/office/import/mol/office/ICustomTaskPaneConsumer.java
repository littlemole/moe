package mol.office  ;

import com4j.*;

@IID("{000C033E-0000-0000-C000-000000000046}")
public interface ICustomTaskPaneConsumer extends Com4jObject {
    @VTID(7)
    void ctpFactoryAvailable(
        mol.office.ICTPFactory ctpFactoryInst);

}
