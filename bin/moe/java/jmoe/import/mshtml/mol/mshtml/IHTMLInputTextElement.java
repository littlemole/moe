package mol.mshtml  ;

import com4j.*;

@IID("{3050F2A6-98B5-11CF-BB82-00AA00BDCE0B}")
public interface IHTMLInputTextElement extends Com4jObject {
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
    void size(
        int p);

    @VTID(20)
    int size();

    @VTID(21)
    void maxLength(
        int p);

    @VTID(22)
    int maxLength();

    @VTID(23)
    void select();

    @VTID(24)
    void onchange(
        @MarshalAs(NativeType.VARIANT) java.lang.Object p);

    @VTID(25)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object onchange();

    @VTID(26)
    void onselect(
        @MarshalAs(NativeType.VARIANT) java.lang.Object p);

    @VTID(27)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object onselect();

    @VTID(28)
    void readOnly(
        boolean p);

    @VTID(29)
    boolean readOnly();

    @VTID(30)
    mol.mshtml.IHTMLTxtRange createTextRange();

}
