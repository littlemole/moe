package mol.mshtml  ;

import com4j.*;

@IID("{00020400-0000-0000-C000-000000000046}")
public interface DispHTMLScreen extends Com4jObject {
    @DISPID(1001)
    @PropGet
    int colorDepth();

    @DISPID(1002)
    @PropPut
    void bufferDepth(
        int rhs);

    @DISPID(1002)
    @PropGet
    int bufferDepth();

    @DISPID(1003)
    @PropGet
    int width();

    @DISPID(1004)
    @PropGet
    int height();

    @DISPID(1005)
    @PropPut
    void updateInterval(
        int rhs);

    @DISPID(1005)
    @PropGet
    int updateInterval();

    @DISPID(1006)
    @PropGet
    int availHeight();

    @DISPID(1007)
    @PropGet
    int availWidth();

    @DISPID(1008)
    @PropGet
    boolean fontSmoothingEnabled();

    @DISPID(1009)
    @PropGet
    int logicalXDPI();

    @DISPID(1010)
    @PropGet
    int logicalYDPI();

    @DISPID(1011)
    @PropGet
    int deviceXDPI();

    @DISPID(1012)
    @PropGet
    int deviceYDPI();

}
