package mol.mshtml  ;

import com4j.*;

@IID("{3050F2AD-98B5-11CF-BB82-00AA00BDCE0B}")
public interface IHTMLInputFileElement extends Com4jObject {
    @VTID(7)
    java.lang.String type();

    @VTID(8)
    void name(
        java.lang.String p);

    @VTID(9)
    java.lang.String name();

    @VTID(10)
    void status(
        @MarshalAs(NativeType.VARIANT) java.lang.Object p);

    @VTID(11)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object status();

    @VTID(12)
    void disabled(
        boolean p);

    @VTID(13)
    boolean disabled();

    @VTID(14)
    mol.mshtml.IHTMLFormElement form();

    @VTID(14)
    @ReturnValue(type=NativeType.Dispatch,defaultPropertyThrough={mol.mshtml.IHTMLFormElement.class})
    com4j.Com4jObject form(
        @MarshalAs(NativeType.VARIANT) java.lang.Object name,
        @MarshalAs(NativeType.VARIANT) java.lang.Object index);

    @VTID(15)
    void size(
        int p);

    @VTID(16)
    int size();

    @VTID(17)
    void maxLength(
        int p);

    @VTID(18)
    int maxLength();

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
    void value(
        java.lang.String p);

    @VTID(25)
    java.lang.String value();

}
