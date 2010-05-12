package mol.moe  ;

import com4j.*;

/**
 * IDoc Xmoe Interface - Common Interface for moe's MDI Child windows
 */
@IID("{25867097-B5C3-4D5E-999F-417FCBAE218C}")
public interface IDoc extends Com4jObject {
    /**
     * Get filename of document
     */
    @VTID(7)
    java.lang.String filename();

    /**
     * Get directory path of document
     */
    @VTID(8)
    java.lang.String path();

    /**
     * Get/Set Top position of document
     */
    @VTID(9)
    void top(
        int t);

    /**
     * Get/Set Top position of document
     */
    @VTID(10)
    int top();

    /**
     * Get/Set Left position of document
     */
    @VTID(11)
    void left(
        int l);

    /**
     * Get/Set Left position of document
     */
    @VTID(12)
    int left();

    /**
     * Get/Set Height of document
     */
    @VTID(13)
    void height(
        int h);

    /**
     * Get/Set Height of document
     */
    @VTID(14)
    int height();

    /**
     * Get/Set Width of document
     */
    @VTID(15)
    void width(
        int w);

    /**
     * Get/Set Width of document
     */
    @VTID(16)
    int width();

    /**
     * Get Application (Moe) Object Reference
     */
    @VTID(17)
    mol.moe.IXmoe app();

    /**
     * Get Document Type (XMOE_DOCTYPE)
     */
    @VTID(18)
    int type();

    /**
     * Get Editor document object 
     */
    @VTID(19)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject document();

    /**
     * Show MDI Document
     */
    @VTID(20)
    void show();

    /**
     * Hide MDI Document
     */
    @VTID(21)
    void hide();

    /**
     * Minimize MDI Document
     */
    @VTID(22)
    void minimize();

    /**
     * Maximize MDI Document
     */
    @VTID(23)
    void maximize();

    /**
     * Restore MDI Document
     */
    @VTID(24)
    void restore();

    /**
     * Close MDI Document
     */
    @VTID(25)
    void close();

    /**
     * Activate MDI Document
     */
    @VTID(26)
    void activate();

}
