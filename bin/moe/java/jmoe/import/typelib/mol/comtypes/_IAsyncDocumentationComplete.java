package mol.comtypes  ;

import com4j.*;

/**
 * _IAsyncDocumentationComplete - async doc generation completed
 */
@IID("{00020400-0000-0000-C000-000000000046}")
public interface _IAsyncDocumentationComplete extends Com4jObject {
    /**
     * async doc generation completed
     */
    @DISPID(1)
    void onComplete();

    /**
     * async doc generation status message
     */
    @DISPID(2)
    void onStatus(
        java.lang.Object msg);

}
