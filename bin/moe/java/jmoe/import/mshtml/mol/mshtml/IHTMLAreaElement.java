package mol.mshtml  ;

import com4j.*;

@IID("{3050F265-98B5-11CF-BB82-00AA00BDCE0B}")
public interface IHTMLAreaElement extends Com4jObject {
    @VTID(7)
    void shape(
        java.lang.String p);

    @VTID(8)
    java.lang.String shape();

    @VTID(9)
    void coords(
        java.lang.String p);

    @VTID(10)
    java.lang.String coords();

    @VTID(11)
    @DefaultMethod
    void href(
        java.lang.String p);

    @VTID(12)
    @DefaultMethod
    java.lang.String href();

    @VTID(13)
    void target(
        java.lang.String p);

    @VTID(14)
    java.lang.String target();

    @VTID(15)
    void alt(
        java.lang.String p);

    @VTID(16)
    java.lang.String alt();

    @VTID(17)
    void noHref(
        boolean p);

    @VTID(18)
    boolean noHref();

    @VTID(19)
    void host(
        java.lang.String p);

    @VTID(20)
    java.lang.String host();

    @VTID(21)
    void hostname(
        java.lang.String p);

    @VTID(22)
    java.lang.String hostname();

    @VTID(23)
    void pathname(
        java.lang.String p);

    @VTID(24)
    java.lang.String pathname();

    @VTID(25)
    void port(
        java.lang.String p);

    @VTID(26)
    java.lang.String port();

    @VTID(27)
    void protocol(
        java.lang.String p);

    @VTID(28)
    java.lang.String protocol();

    @VTID(29)
    void search(
        java.lang.String p);

    @VTID(30)
    java.lang.String search();

    @VTID(31)
    void hash(
        java.lang.String p);

    @VTID(32)
    java.lang.String hash();

    @VTID(33)
    void onblur(
        @MarshalAs(NativeType.VARIANT) java.lang.Object p);

    @VTID(34)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object onblur();

    @VTID(35)
    void onfocus(
        @MarshalAs(NativeType.VARIANT) java.lang.Object p);

    @VTID(36)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object onfocus();

    @VTID(37)
    void tabIndex(
        short p);

    @VTID(38)
    short tabIndex();

    @VTID(39)
    void focus();

    @VTID(40)
    void blur();

}
