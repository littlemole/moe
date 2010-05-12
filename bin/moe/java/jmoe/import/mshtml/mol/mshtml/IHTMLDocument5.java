package mol.mshtml  ;

import com4j.*;

@IID("{3050F80C-98B5-11CF-BB82-00AA00BDCE0B}")
public interface IHTMLDocument5 extends Com4jObject {
    @VTID(7)
    void onmousewheel(
        @MarshalAs(NativeType.VARIANT) java.lang.Object p);

    @VTID(8)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object onmousewheel();

    @VTID(9)
    mol.mshtml.IHTMLDOMNode doctype();

    @VTID(10)
    mol.mshtml.IHTMLDOMImplementation implementation();

    @VTID(11)
    mol.mshtml.IHTMLDOMAttribute createAttribute(
        java.lang.String bstrattrName);

    @VTID(12)
    mol.mshtml.IHTMLDOMNode createComment(
        java.lang.String bstrdata);

    @VTID(13)
    void onfocusin(
        @MarshalAs(NativeType.VARIANT) java.lang.Object p);

    @VTID(14)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object onfocusin();

    @VTID(15)
    void onfocusout(
        @MarshalAs(NativeType.VARIANT) java.lang.Object p);

    @VTID(16)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object onfocusout();

    @VTID(17)
    void onactivate(
        @MarshalAs(NativeType.VARIANT) java.lang.Object p);

    @VTID(18)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object onactivate();

    @VTID(19)
    void ondeactivate(
        @MarshalAs(NativeType.VARIANT) java.lang.Object p);

    @VTID(20)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object ondeactivate();

    @VTID(21)
    void onbeforeactivate(
        @MarshalAs(NativeType.VARIANT) java.lang.Object p);

    @VTID(22)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object onbeforeactivate();

    @VTID(23)
    void onbeforedeactivate(
        @MarshalAs(NativeType.VARIANT) java.lang.Object p);

    @VTID(24)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object onbeforedeactivate();

    @VTID(25)
    java.lang.String compatMode();

}
