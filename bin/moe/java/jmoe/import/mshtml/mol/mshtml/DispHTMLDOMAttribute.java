package mol.mshtml  ;

import com4j.*;

@IID("{00020400-0000-0000-C000-000000000046}")
public interface DispHTMLDOMAttribute extends Com4jObject {
    @DISPID(1000)
    @PropGet
    java.lang.String nodeName();

    @DISPID(1002)
    @PropPut
    void nodeValue(
        java.lang.Object rhs);

    @DISPID(1002)
    @PropGet
    java.lang.Object nodeValue();

    @DISPID(1001)
    @PropGet
    boolean specified();

    @DISPID(1003)
    @PropGet
    java.lang.String name();

    @DISPID(1004)
    @PropPut
    void value(
        java.lang.String rhs);

    @DISPID(1004)
    @PropGet
    java.lang.String value();

    @DISPID(1005)
    @PropGet
    boolean expando();

    @DISPID(1006)
    @PropGet
    int nodeType();

    @DISPID(1007)
    @PropGet
    mol.mshtml.IHTMLDOMNode parentNode();

    @DISPID(1008)
    @PropGet
    com4j.Com4jObject childNodes();

    @DISPID(1009)
    @PropGet
    mol.mshtml.IHTMLDOMNode firstChild();

    @DISPID(1010)
    @PropGet
    mol.mshtml.IHTMLDOMNode lastChild();

    @DISPID(1011)
    @PropGet
    mol.mshtml.IHTMLDOMNode previousSibling();

    @DISPID(1012)
    @PropGet
    mol.mshtml.IHTMLDOMNode nextSibling();

    @DISPID(1013)
    @PropGet
    com4j.Com4jObject attributes();

    @DISPID(1014)
    @PropGet
    com4j.Com4jObject ownerDocument();

    @DISPID(1015)
    mol.mshtml.IHTMLDOMNode insertBefore(
        mol.mshtml.IHTMLDOMNode newChild,
        java.lang.Object refChild);

    @DISPID(1016)
    mol.mshtml.IHTMLDOMNode replaceChild(
        mol.mshtml.IHTMLDOMNode newChild,
        mol.mshtml.IHTMLDOMNode oldChild);

    @DISPID(1017)
    mol.mshtml.IHTMLDOMNode removeChild(
        mol.mshtml.IHTMLDOMNode oldChild);

    @DISPID(1018)
    mol.mshtml.IHTMLDOMNode appendChild(
        mol.mshtml.IHTMLDOMNode newChild);

    @DISPID(1019)
    boolean hasChildNodes();

    @DISPID(1020)
    mol.mshtml.IHTMLDOMAttribute cloneNode(
        boolean fDeep);

}
