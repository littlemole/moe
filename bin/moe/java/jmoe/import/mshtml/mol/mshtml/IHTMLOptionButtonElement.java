package mol.mshtml  ;

import com4j.*;

@IID("{3050F2BC-98B5-11CF-BB82-00AA00BDCE0B}")
public interface IHTMLOptionButtonElement extends Com4jObject {
    @VTID(7)
    void value(
        java.lang.String p);

    @VTID(8)
    java.lang.String value();

    @VTID(9)
    java.lang.String type();

    @VTID(10)
    void name(
        java.lang.String p);

    @VTID(11)
    java.lang.String name();

    @VTID(12)
    void checked(
        boolean p);

    @VTID(13)
    boolean checked();

    @VTID(14)
    void defaultChecked(
        boolean p);

    @VTID(15)
    boolean defaultChecked();

    @VTID(16)
    void onchange(
        @MarshalAs(NativeType.VARIANT) java.lang.Object p);

    @VTID(17)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object onchange();

    @VTID(18)
    void disabled(
        boolean p);

    @VTID(19)
    boolean disabled();

    @VTID(20)
    void status(
        boolean p);

    @VTID(21)
    boolean status();

    @VTID(22)
    void indeterminate(
        boolean p);

    @VTID(23)
    boolean indeterminate();

    @VTID(24)
    mol.mshtml.IHTMLFormElement form();

    @VTID(24)
    @ReturnValue(type=NativeType.Dispatch,defaultPropertyThrough={mol.mshtml.IHTMLFormElement.class})
    com4j.Com4jObject form(
        @MarshalAs(NativeType.VARIANT) java.lang.Object name,
        @MarshalAs(NativeType.VARIANT) java.lang.Object index);

}
