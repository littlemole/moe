package mol.mshtml  ;

import com4j.*;

@IID("{AE24FDAD-03C6-11D1-8B76-0080C744F389}")
public interface IWebBridge extends Com4jObject {
    @VTID(7)
    void url(
        java.lang.String p);

    @VTID(8)
    java.lang.String url();

    @VTID(9)
    void scrollbar(
        boolean p);

    @VTID(10)
    boolean scrollbar();

    @VTID(11)
    void embed(
        boolean p);

    @VTID(12)
    boolean embed();

    @VTID(13)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject event();

    @VTID(14)
    int readyState();

    @VTID(15)
    void aboutBox();

}
