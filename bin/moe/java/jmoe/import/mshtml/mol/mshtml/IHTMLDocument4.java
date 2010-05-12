package mol.mshtml  ;

import com4j.*;

@IID("{3050F69A-98B5-11CF-BB82-00AA00BDCE0B}")
public interface IHTMLDocument4 extends Com4jObject {
    @VTID(7)
    void focus();

    @VTID(8)
    boolean hasFocus();

    @VTID(9)
    void onselectionchange(
        @MarshalAs(NativeType.VARIANT) java.lang.Object p);

    @VTID(10)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object onselectionchange();

    @VTID(11)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject namespaces();

    @VTID(12)
    mol.mshtml.IHTMLDocument2 createDocumentFromUrl(
        java.lang.String bstrUrl,
        java.lang.String bstrOptions);

    @VTID(13)
    void media(
        java.lang.String p);

    @VTID(14)
    java.lang.String media();

    @VTID(15)
    mol.mshtml.IHTMLEventObj createEventObject(
        java.lang.Object pvarEventObject);

    @VTID(16)
    boolean fireEvent(
        java.lang.String bstrEventName,
        java.lang.Object pvarEventObject);

    @VTID(17)
    mol.mshtml.IHTMLRenderStyle createRenderStyle(
        java.lang.String v);

    @VTID(18)
    void oncontrolselect(
        @MarshalAs(NativeType.VARIANT) java.lang.Object p);

    @VTID(19)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object oncontrolselect();

    @VTID(20)
    java.lang.String urlUnencoded();

}
