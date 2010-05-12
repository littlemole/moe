package mol.mshtml  ;

import com4j.*;

@IID("{00020400-0000-0000-C000-000000000046}")
public interface DispHTCDefaultDispatch extends Com4jObject {
    @DISPID(-2147412969)
    @PropGet
    mol.mshtml.IHTMLElement element();

    @DISPID(-2147412968)
    mol.mshtml.IHTMLEventObj createEventObject();

    @DISPID(-2147412947)
    @PropGet
    com4j.Com4jObject defaults();

    @DISPID(-2147412970)
    @PropGet
    com4j.Com4jObject document();

}
