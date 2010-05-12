package mol.mshtml  ;

import com4j.*;

@IID("{3050F28B-98B5-11CF-BB82-00AA00BDCE0B}")
public interface IHTMLScriptElement extends Com4jObject {
    @VTID(7)
    void src(
        java.lang.String p);

    @VTID(8)
    java.lang.String src();

    @VTID(9)
    void htmlFor(
        java.lang.String p);

    @VTID(10)
    java.lang.String htmlFor();

    @VTID(11)
    void event(
        java.lang.String p);

    @VTID(12)
    java.lang.String event();

    @VTID(13)
    void text(
        java.lang.String p);

    @VTID(14)
    java.lang.String text();

    @VTID(15)
    void defer(
        boolean p);

    @VTID(16)
    boolean defer();

    @VTID(17)
    java.lang.String readyState();

    @VTID(18)
    void onerror(
        @MarshalAs(NativeType.VARIANT) java.lang.Object p);

    @VTID(19)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object onerror();

    @VTID(20)
    void type(
        java.lang.String p);

    @VTID(21)
    java.lang.String type();

}
