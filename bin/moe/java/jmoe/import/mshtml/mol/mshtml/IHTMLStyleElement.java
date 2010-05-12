package mol.mshtml  ;

import com4j.*;

@IID("{3050F375-98B5-11CF-BB82-00AA00BDCE0B}")
public interface IHTMLStyleElement extends Com4jObject {
    @VTID(7)
    void type(
        java.lang.String p);

    @VTID(8)
    java.lang.String type();

    @VTID(9)
    java.lang.String readyState();

    @VTID(10)
    void onreadystatechange(
        @MarshalAs(NativeType.VARIANT) java.lang.Object p);

    @VTID(11)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object onreadystatechange();

    @VTID(12)
    void onload(
        @MarshalAs(NativeType.VARIANT) java.lang.Object p);

    @VTID(13)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object onload();

    @VTID(14)
    void onerror(
        @MarshalAs(NativeType.VARIANT) java.lang.Object p);

    @VTID(15)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object onerror();

    @VTID(16)
    mol.mshtml.IHTMLStyleSheet styleSheet();

    @VTID(17)
    void disabled(
        boolean p);

    @VTID(18)
    boolean disabled();

    @VTID(19)
    void media(
        java.lang.String p);

    @VTID(20)
    java.lang.String media();

}
