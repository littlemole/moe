package mol.mshtml  ;

import com4j.*;

@IID("{00020400-0000-0000-C000-000000000046}")
public interface DispHTMLAttributeCollection extends Com4jObject {
    @DISPID(1500)
    @PropGet
    int length();

    @DISPID(-4)
    @PropGet
    com4j.Com4jObject _newEnum();

    @DISPID(0)
    @DefaultMethod
    com4j.Com4jObject item(
        java.lang.Object name);

    @DISPID(1501)
    mol.mshtml.IHTMLDOMAttribute getNamedItem(
        java.lang.String bstrName);

    @DISPID(1502)
    mol.mshtml.IHTMLDOMAttribute setNamedItem(
        mol.mshtml.IHTMLDOMAttribute ppNode);

    @DISPID(1503)
    mol.mshtml.IHTMLDOMAttribute removeNamedItem(
        java.lang.String bstrName);

}
