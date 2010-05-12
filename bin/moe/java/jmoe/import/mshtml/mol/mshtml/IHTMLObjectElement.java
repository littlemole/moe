package mol.mshtml  ;

import com4j.*;

@IID("{3050F24F-98B5-11CF-BB82-00AA00BDCE0B}")
public interface IHTMLObjectElement extends Com4jObject {
    @VTID(7)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject object();

    @VTID(8)
    java.lang.String classid();

    @VTID(9)
    java.lang.String data();

    @VTID(10)
    void recordset(
        @MarshalAs(NativeType.Dispatch) com4j.Com4jObject p);

    @VTID(11)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject recordset();

    @VTID(12)
    void align(
        java.lang.String p);

    @VTID(13)
    java.lang.String align();

    @VTID(14)
    void name(
        java.lang.String p);

    @VTID(15)
    java.lang.String name();

    @VTID(16)
    void codeBase(
        java.lang.String p);

    @VTID(17)
    java.lang.String codeBase();

    @VTID(18)
    void codeType(
        java.lang.String p);

    @VTID(19)
    java.lang.String codeType();

    @VTID(20)
    void code(
        java.lang.String p);

    @VTID(21)
    java.lang.String code();

    @VTID(22)
    java.lang.String baseHref();

    @VTID(23)
    void type(
        java.lang.String p);

    @VTID(24)
    java.lang.String type();

    @VTID(25)
    mol.mshtml.IHTMLFormElement form();

    @VTID(25)
    @ReturnValue(type=NativeType.Dispatch,defaultPropertyThrough={mol.mshtml.IHTMLFormElement.class})
    com4j.Com4jObject form(
        @MarshalAs(NativeType.VARIANT) java.lang.Object name,
        @MarshalAs(NativeType.VARIANT) java.lang.Object index);

    @VTID(26)
    void width(
        @MarshalAs(NativeType.VARIANT) java.lang.Object p);

    @VTID(27)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object width();

    @VTID(28)
    void height(
        @MarshalAs(NativeType.VARIANT) java.lang.Object p);

    @VTID(29)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object height();

    @VTID(30)
    int readyState();

    @VTID(31)
    void onreadystatechange(
        @MarshalAs(NativeType.VARIANT) java.lang.Object p);

    @VTID(32)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object onreadystatechange();

    @VTID(33)
    void onerror(
        @MarshalAs(NativeType.VARIANT) java.lang.Object p);

    @VTID(34)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object onerror();

    @VTID(35)
    void altHtml(
        java.lang.String p);

    @VTID(36)
    java.lang.String altHtml();

    @VTID(37)
    void vspace(
        int p);

    @VTID(38)
    int vspace();

    @VTID(39)
    void hspace(
        int p);

    @VTID(40)
    int hspace();

}
