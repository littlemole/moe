package mol.office  ;

import com4j.*;

@IID("{000C03A7-0000-0000-C000-000000000046}")
public interface IRibbonUI extends Com4jObject {
    @VTID(7)
    void invalidate();

    @VTID(8)
    void invalidateControl(
        java.lang.String controlID);

}
