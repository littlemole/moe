package mol.mshtml  ;

import com4j.*;

@IID("{3050F80F-98B5-11CF-BB82-00AA00BDCE0B}")
public interface IHTMLElement4 extends Com4jObject {
    @VTID(7)
    void onmousewheel(
        @MarshalAs(NativeType.VARIANT) java.lang.Object p);

    @VTID(8)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object onmousewheel();

    @VTID(9)
    void normalize();

    @VTID(10)
    mol.mshtml.IHTMLDOMAttribute getAttributeNode(
        java.lang.String bstrName);

    @VTID(11)
    mol.mshtml.IHTMLDOMAttribute setAttributeNode(
        mol.mshtml.IHTMLDOMAttribute pattr);

    @VTID(12)
    mol.mshtml.IHTMLDOMAttribute removeAttributeNode(
        mol.mshtml.IHTMLDOMAttribute pattr);

    @VTID(13)
    void onbeforeactivate(
        @MarshalAs(NativeType.VARIANT) java.lang.Object p);

    @VTID(14)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object onbeforeactivate();

    @VTID(15)
    void onfocusin(
        @MarshalAs(NativeType.VARIANT) java.lang.Object p);

    @VTID(16)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object onfocusin();

    @VTID(17)
    void onfocusout(
        @MarshalAs(NativeType.VARIANT) java.lang.Object p);

    @VTID(18)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object onfocusout();

}
