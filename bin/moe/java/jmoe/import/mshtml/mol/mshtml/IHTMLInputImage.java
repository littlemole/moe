package mol.mshtml  ;

import com4j.*;

@IID("{3050F2C2-98B5-11CF-BB82-00AA00BDCE0B}")
public interface IHTMLInputImage extends Com4jObject {
    @VTID(7)
    java.lang.String type();

    @VTID(8)
    void disabled(
        boolean p);

    @VTID(9)
    boolean disabled();

    @VTID(10)
    void border(
        @MarshalAs(NativeType.VARIANT) java.lang.Object p);

    @VTID(11)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object border();

    @VTID(12)
    void vspace(
        int p);

    @VTID(13)
    int vspace();

    @VTID(14)
    void hspace(
        int p);

    @VTID(15)
    int hspace();

    @VTID(16)
    void alt(
        java.lang.String p);

    @VTID(17)
    java.lang.String alt();

    @VTID(18)
    void src(
        java.lang.String p);

    @VTID(19)
    java.lang.String src();

    @VTID(20)
    void lowsrc(
        java.lang.String p);

    @VTID(21)
    java.lang.String lowsrc();

    @VTID(22)
    void vrml(
        java.lang.String p);

    @VTID(23)
    java.lang.String vrml();

    @VTID(24)
    void dynsrc(
        java.lang.String p);

    @VTID(25)
    java.lang.String dynsrc();

    @VTID(26)
    java.lang.String readyState();

    @VTID(27)
    boolean complete();

    @VTID(28)
    void loop(
        @MarshalAs(NativeType.VARIANT) java.lang.Object p);

    @VTID(29)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object loop();

    @VTID(30)
    void align(
        java.lang.String p);

    @VTID(31)
    java.lang.String align();

    @VTID(32)
    void onload(
        @MarshalAs(NativeType.VARIANT) java.lang.Object p);

    @VTID(33)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object onload();

    @VTID(34)
    void onerror(
        @MarshalAs(NativeType.VARIANT) java.lang.Object p);

    @VTID(35)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object onerror();

    @VTID(36)
    void onabort(
        @MarshalAs(NativeType.VARIANT) java.lang.Object p);

    @VTID(37)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object onabort();

    @VTID(38)
    void name(
        java.lang.String p);

    @VTID(39)
    java.lang.String name();

    @VTID(40)
    void width(
        int p);

    @VTID(41)
    int width();

    @VTID(42)
    void height(
        int p);

    @VTID(43)
    int height();

    @VTID(44)
    void start(
        java.lang.String p);

    @VTID(45)
    java.lang.String start();

}
