package mol.excel  ;

import com4j.*;

@IID("{00024410-0001-0000-C000-000000000046}")
public interface IOLEObjectEvents extends Com4jObject {
    @VTID(7)
    void gotFocus();

    @VTID(8)
    void lostFocus();

}