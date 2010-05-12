package mol.mshtml  ;

import com4j.*;

@IID("{3050F5DA-98B5-11CF-BB82-00AA00BDCE0B}")
public interface IHTMLDOMNode extends Com4jObject {
    @VTID(7)
    int nodeType();

    @VTID(8)
    mol.mshtml.IHTMLDOMNode parentNode();

    @VTID(9)
    boolean hasChildNodes();

    @VTID(10)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject childNodes();

    @VTID(11)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject attributes();

    @VTID(12)
    mol.mshtml.IHTMLDOMNode insertBefore(
        mol.mshtml.IHTMLDOMNode newChild,
        @MarshalAs(NativeType.VARIANT) java.lang.Object refChild);

    @VTID(13)
    mol.mshtml.IHTMLDOMNode removeChild(
        mol.mshtml.IHTMLDOMNode oldChild);

    @VTID(14)
    mol.mshtml.IHTMLDOMNode replaceChild(
        mol.mshtml.IHTMLDOMNode newChild,
        mol.mshtml.IHTMLDOMNode oldChild);

    @VTID(15)
    mol.mshtml.IHTMLDOMNode cloneNode(
        boolean fDeep);

    @VTID(16)
    mol.mshtml.IHTMLDOMNode removeNode(
        boolean fDeep);

    @VTID(17)
    mol.mshtml.IHTMLDOMNode swapNode(
        mol.mshtml.IHTMLDOMNode otherNode);

    @VTID(18)
    mol.mshtml.IHTMLDOMNode replaceNode(
        mol.mshtml.IHTMLDOMNode replacement);

    @VTID(19)
    mol.mshtml.IHTMLDOMNode appendChild(
        mol.mshtml.IHTMLDOMNode newChild);

    @VTID(20)
    java.lang.String nodeName();

    @VTID(21)
    void nodeValue(
        @MarshalAs(NativeType.VARIANT) java.lang.Object p);

    @VTID(22)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object nodeValue();

    @VTID(23)
    mol.mshtml.IHTMLDOMNode firstChild();

    @VTID(24)
    mol.mshtml.IHTMLDOMNode lastChild();

    @VTID(25)
    mol.mshtml.IHTMLDOMNode previousSibling();

    @VTID(26)
    mol.mshtml.IHTMLDOMNode nextSibling();

}
