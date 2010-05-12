package mol.mshtml  ;

import com4j.*;

@IID("{3050F2AA-98B5-11CF-BB82-00AA00BDCE0B}")
public interface IHTMLTextAreaElement extends Com4jObject {
    @VTID(7)
    java.lang.String type();

    @VTID(8)
    void value(
        java.lang.String p);

    @VTID(9)
    java.lang.String value();

    @VTID(10)
    void name(
        java.lang.String p);

    @VTID(11)
    java.lang.String name();

    @VTID(12)
    void status(
        @MarshalAs(NativeType.VARIANT) java.lang.Object p);

    @VTID(13)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object status();

    @VTID(14)
    void disabled(
        boolean p);

    @VTID(15)
    boolean disabled();

    @VTID(16)
    mol.mshtml.IHTMLFormElement form();

    @VTID(16)
    @ReturnValue(type=NativeType.Dispatch,defaultPropertyThrough={mol.mshtml.IHTMLFormElement.class})
    com4j.Com4jObject form(
        @MarshalAs(NativeType.VARIANT) java.lang.Object name,
        @MarshalAs(NativeType.VARIANT) java.lang.Object index);

    @VTID(17)
    void defaultValue(
        java.lang.String p);

    @VTID(18)
    java.lang.String defaultValue();

    @VTID(19)
    void select();

    @VTID(20)
    void onchange(
        @MarshalAs(NativeType.VARIANT) java.lang.Object p);

    @VTID(21)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object onchange();

    @VTID(22)
    void onselect(
        @MarshalAs(NativeType.VARIANT) java.lang.Object p);

    @VTID(23)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object onselect();

    @VTID(24)
    void readOnly(
        boolean p);

    @VTID(25)
    boolean readOnly();

    @VTID(26)
    void rows(
        int p);

    @VTID(27)
    int rows();

    @VTID(28)
    void cols(
        int p);

    @VTID(29)
    int cols();

    @VTID(30)
    void wrap(
        java.lang.String p);

    @VTID(31)
    java.lang.String wrap();

    @VTID(32)
    mol.mshtml.IHTMLTxtRange createTextRange();

}
