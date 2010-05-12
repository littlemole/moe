package mol.mshtml  ;

import com4j.*;

@IID("{00020400-0000-0000-C000-000000000046}")
public interface DispHTMLDOMTextNode extends Com4jObject {
    @DISPID(1000)
    @PropPut
    void data(
        java.lang.String rhs);

    @DISPID(1000)
    @PropGet
    java.lang.String data();

    @DISPID(1001)
    java.lang.String toString_();

    @DISPID(1002)
    @PropGet
    int length();

    @DISPID(1003)
    mol.mshtml.IHTMLDOMNode splitText(
        int offset);

    @DISPID(1004)
    java.lang.String substringData(
        int offset,
        int count);

    @DISPID(1005)
    void appendData(
        java.lang.String bstrstring);

    @DISPID(1006)
    void insertData(
        int offset,
        java.lang.String bstrstring);

    @DISPID(1007)
    void deleteData(
        int offset,
        int count);

    @DISPID(1008)
    void replaceData(
        int offset,
        int count,
        java.lang.String bstrstring);

    @DISPID(-2147417066)
    @PropGet
    int nodeType();

    @DISPID(-2147417065)
    @PropGet
    mol.mshtml.IHTMLDOMNode parentNode();

    @DISPID(-2147417064)
    boolean hasChildNodes();

    @DISPID(-2147417063)
    @PropGet
    com4j.Com4jObject childNodes();

    @DISPID(-2147417062)
    @PropGet
    com4j.Com4jObject attributes();

    @DISPID(-2147417061)
    mol.mshtml.IHTMLDOMNode insertBefore(
        mol.mshtml.IHTMLDOMNode newChild,
        java.lang.Object refChild);

    @DISPID(-2147417060)
    mol.mshtml.IHTMLDOMNode removeChild(
        mol.mshtml.IHTMLDOMNode oldChild);

    @DISPID(-2147417059)
    mol.mshtml.IHTMLDOMNode replaceChild(
        mol.mshtml.IHTMLDOMNode newChild,
        mol.mshtml.IHTMLDOMNode oldChild);

    @DISPID(-2147417051)
    mol.mshtml.IHTMLDOMNode cloneNode(
        boolean fDeep);

    @DISPID(-2147417046)
    mol.mshtml.IHTMLDOMNode removeNode(
        boolean fDeep);

    @DISPID(-2147417044)
    mol.mshtml.IHTMLDOMNode swapNode(
        mol.mshtml.IHTMLDOMNode otherNode);

    @DISPID(-2147417045)
    mol.mshtml.IHTMLDOMNode replaceNode(
        mol.mshtml.IHTMLDOMNode replacement);

    @DISPID(-2147417039)
    mol.mshtml.IHTMLDOMNode appendChild(
        mol.mshtml.IHTMLDOMNode newChild);

    @DISPID(-2147417038)
    @PropGet
    java.lang.String nodeName();

    @DISPID(-2147417037)
    @PropPut
    void nodeValue(
        java.lang.Object rhs);

    @DISPID(-2147417037)
    @PropGet
    java.lang.Object nodeValue();

    @DISPID(-2147417036)
    @PropGet
    mol.mshtml.IHTMLDOMNode firstChild();

    @DISPID(-2147417035)
    @PropGet
    mol.mshtml.IHTMLDOMNode lastChild();

    @DISPID(-2147417034)
    @PropGet
    mol.mshtml.IHTMLDOMNode previousSibling();

    @DISPID(-2147417033)
    @PropGet
    mol.mshtml.IHTMLDOMNode nextSibling();

    @DISPID(-2147416999)
    @PropGet
    com4j.Com4jObject ownerDocument();

}
