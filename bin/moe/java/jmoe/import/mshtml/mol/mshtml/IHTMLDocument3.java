package mol.mshtml  ;

import com4j.*;

@IID("{3050F485-98B5-11CF-BB82-00AA00BDCE0B}")
public interface IHTMLDocument3 extends Com4jObject {
    @VTID(7)
    void releaseCapture();

    @VTID(8)
    void recalc(
        boolean fForce);

    @VTID(9)
    mol.mshtml.IHTMLDOMNode createTextNode(
        java.lang.String text);

    @VTID(10)
    mol.mshtml.IHTMLElement documentElement();

    @VTID(11)
    java.lang.String uniqueID();

    @VTID(12)
    boolean attachEvent(
        java.lang.String event,
        @MarshalAs(NativeType.Dispatch) com4j.Com4jObject pdisp);

    @VTID(13)
    void detachEvent(
        java.lang.String event,
        @MarshalAs(NativeType.Dispatch) com4j.Com4jObject pdisp);

    @VTID(14)
    void onrowsdelete(
        @MarshalAs(NativeType.VARIANT) java.lang.Object p);

    @VTID(15)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object onrowsdelete();

    @VTID(16)
    void onrowsinserted(
        @MarshalAs(NativeType.VARIANT) java.lang.Object p);

    @VTID(17)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object onrowsinserted();

    @VTID(18)
    void oncellchange(
        @MarshalAs(NativeType.VARIANT) java.lang.Object p);

    @VTID(19)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object oncellchange();

    @VTID(20)
    void ondatasetchanged(
        @MarshalAs(NativeType.VARIANT) java.lang.Object p);

    @VTID(21)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object ondatasetchanged();

    @VTID(22)
    void ondataavailable(
        @MarshalAs(NativeType.VARIANT) java.lang.Object p);

    @VTID(23)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object ondataavailable();

    @VTID(24)
    void ondatasetcomplete(
        @MarshalAs(NativeType.VARIANT) java.lang.Object p);

    @VTID(25)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object ondatasetcomplete();

    @VTID(26)
    void onpropertychange(
        @MarshalAs(NativeType.VARIANT) java.lang.Object p);

    @VTID(27)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object onpropertychange();

    @VTID(28)
    void dir(
        java.lang.String p);

    @VTID(29)
    java.lang.String dir();

    @VTID(30)
    void oncontextmenu(
        @MarshalAs(NativeType.VARIANT) java.lang.Object p);

    @VTID(31)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object oncontextmenu();

    @VTID(32)
    void onstop(
        @MarshalAs(NativeType.VARIANT) java.lang.Object p);

    @VTID(33)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object onstop();

    @VTID(34)
    mol.mshtml.IHTMLDocument2 createDocumentFragment();

    @VTID(35)
    mol.mshtml.IHTMLDocument2 parentDocument();

    @VTID(36)
    void enableDownload(
        boolean p);

    @VTID(37)
    boolean enableDownload();

    @VTID(38)
    void baseUrl(
        java.lang.String p);

    @VTID(39)
    java.lang.String baseUrl();

    @VTID(40)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject childNodes();

    @VTID(41)
    void inheritStyleSheets(
        boolean p);

    @VTID(42)
    boolean inheritStyleSheets();

    @VTID(43)
    void onbeforeeditfocus(
        @MarshalAs(NativeType.VARIANT) java.lang.Object p);

    @VTID(44)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object onbeforeeditfocus();

    @VTID(45)
    mol.mshtml.IHTMLElementCollection getElementsByName(
        java.lang.String v);

    @VTID(46)
    mol.mshtml.IHTMLElement getElementById(
        java.lang.String v);

    @VTID(47)
    mol.mshtml.IHTMLElementCollection getElementsByTagName(
        java.lang.String v);

}
