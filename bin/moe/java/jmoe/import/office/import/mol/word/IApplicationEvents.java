package mol.word  ;

import com4j.*;

@IID("{000209F7-0001-0000-C000-000000000046}")
public interface IApplicationEvents extends Com4jObject {
    @VTID(7)
    void startup();

    @VTID(8)
    void quit();

    @VTID(9)
    void documentChange();

}
