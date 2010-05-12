package mol.moe  ;

import com4j.*;

/**
 * IMoeFrame Xmoe Interface - Html Frame
 */
@IID("{BF8832A5-AE58-4C26-BBC4-CECCF910149C}")
public interface IMoeFrame extends Com4jObject {
    /**
     * Get the HTML Document for this User Frame
     */
    @VTID(7)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject document();

    /**
     * Get/Set Top position of HTML window
     */
    @VTID(8)
    void top(
        int t);

    /**
     * Get/Set Top position of HTML window
     */
    @VTID(9)
    int top();

    /**
     * Get/Set Left position of HTML window
     */
    @VTID(10)
    void left(
        int l);

    /**
     * Get/Set Left position of HTML window
     */
    @VTID(11)
    int left();

    /**
     * Get/Set Height of HTML window
     */
    @VTID(12)
    void height(
        int h);

    /**
     * Get/Set Height of HTML window
     */
    @VTID(13)
    int height();

    /**
     * Get/Set Width of HTML window
     */
    @VTID(14)
    void width(
        int w);

    /**
     * Get/Set Width of HTML window
     */
    @VTID(15)
    int width();

    /**
     * Get/Set Title of HTML window
     */
    @VTID(16)
    void title(
        java.lang.String t);

    /**
     * Get/Set Title of HTML window
     */
    @VTID(17)
    java.lang.String title();

    /**
     * Get embeded HTML Scripts IDpispatch interface
     */
    @VTID(18)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject scripts();

    /**
     * Set Code Behind Reference - for .NET CodeBehind Clients
     */
    @VTID(19)
    void codeBehind(
        @MarshalAs(NativeType.Dispatch) com4j.Com4jObject rhs);

    /**
     * Close the HTML User Frame Window
     */
    @VTID(20)
    void close();

    /**
     * Eval(uate) a User Script in the HTML Frame document context
     */
    @VTID(21)
    void eval(
        java.lang.String src,
        java.lang.String scrptLanguage);

    /**
     * Call OLE CMDID ( Save, Close, Print) of embedded webbrowser control 
     */
    @VTID(22)
    void oleCmd(
        int cmd);

}
