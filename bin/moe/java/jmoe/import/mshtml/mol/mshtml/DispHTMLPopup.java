package mol.mshtml  ;

import com4j.*;

@IID("{00020400-0000-0000-C000-000000000046}")
public interface DispHTMLPopup extends Com4jObject {
    @DISPID(27001)
    void show(
        int x,
        int y,
        int w,
        int h,
        java.lang.Object pElement);

    @DISPID(27002)
    void hide();

    @DISPID(27003)
    @PropGet
    mol.mshtml.IHTMLDocument document();

    @DISPID(27004)
    @PropGet
    boolean isOpen();

}
