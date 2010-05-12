package mol.mshtml  ;

import com4j.*;

@IID("{3050F205-98B5-11CF-BB82-00AA00BDCE0B}")
public interface IHTMLLinkElement extends Com4jObject {
    @VTID(7)
    void href(
        java.lang.String p);

    @VTID(8)
    java.lang.String href();

    @VTID(9)
    void rel(
        java.lang.String p);

    @VTID(10)
    java.lang.String rel();

    @VTID(11)
    void rev(
        java.lang.String p);

    @VTID(12)
    java.lang.String rev();

    @VTID(13)
    void type(
        java.lang.String p);

    @VTID(14)
    java.lang.String type();

    @VTID(15)
    java.lang.String readyState();

    @VTID(16)
    void onreadystatechange(
        @MarshalAs(NativeType.VARIANT) java.lang.Object p);

    @VTID(17)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object onreadystatechange();

    @VTID(18)
    void onload(
        @MarshalAs(NativeType.VARIANT) java.lang.Object p);

    @VTID(19)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object onload();

    @VTID(20)
    void onerror(
        @MarshalAs(NativeType.VARIANT) java.lang.Object p);

    @VTID(21)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object onerror();

    @VTID(22)
    mol.mshtml.IHTMLStyleSheet styleSheet();

    @VTID(23)
    void disabled(
        boolean p);

    @VTID(24)
    boolean disabled();

    @VTID(25)
    void media(
        java.lang.String p);

    @VTID(26)
    java.lang.String media();

}
