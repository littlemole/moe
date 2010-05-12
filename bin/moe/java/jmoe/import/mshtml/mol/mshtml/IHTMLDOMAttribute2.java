package mol.mshtml  ;

import com4j.*;

@IID("{3050F810-98B5-11CF-BB82-00AA00BDCE0B}")
public interface IHTMLDOMAttribute2 extends Com4jObject {
    @VTID(7)
    java.lang.String name();

    @VTID(8)
    void value(
        java.lang.String p);

    @VTID(9)
    java.lang.String value();

    @VTID(10)
    boolean expando();

    @VTID(11)
    int nodeType();

    @VTID(12)
    mol.mshtml.IHTMLDOMNode parentNode();

    @VTID(13)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject childNodes();

    @VTID(14)
    mol.mshtml.IHTMLDOMNode firstChild();

    @VTID(15)
    mol.mshtml.IHTMLDOMNode lastChild();

    @VTID(16)
    mol.mshtml.IHTMLDOMNode previousSibling();

    @VTID(17)
    mol.mshtml.IHTMLDOMNode nextSibling();

    @VTID(18)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject attributes();

    @VTID(19)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject ownerDocument();

    @VTID(20)
    mol.mshtml.IHTMLDOMNode insertBefore(
        mol.mshtml.IHTMLDOMNode newChild,
        @MarshalAs(NativeType.VARIANT) java.lang.Object refChild);

    @VTID(21)
    mol.mshtml.IHTMLDOMNode replaceChild(
        mol.mshtml.IHTMLDOMNode newChild,
        mol.mshtml.IHTMLDOMNode oldChild);

    @VTID(22)
    mol.mshtml.IHTMLDOMNode removeChild(
        mol.mshtml.IHTMLDOMNode oldChild);

    @VTID(23)
    mol.mshtml.IHTMLDOMNode appendChild(
        mol.mshtml.IHTMLDOMNode newChild);

    @VTID(24)
    boolean hasChildNodes();

    @VTID(25)
    mol.mshtml.IHTMLDOMAttribute cloneNode(
        boolean fDeep);

}
