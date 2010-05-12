package mol.mshtml  ;

import com4j.*;

@IID("{3050F244-98B5-11CF-BB82-00AA00BDCE0B}")
public interface IHTMLSelectElement extends Com4jObject {
    @VTID(7)
    void size(
        int p);

    @VTID(8)
    int size();

    @VTID(9)
    void multiple(
        boolean p);

    @VTID(10)
    boolean multiple();

    @VTID(11)
    void name(
        java.lang.String p);

    @VTID(12)
    java.lang.String name();

    @VTID(13)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject options();

    @VTID(14)
    void onchange(
        @MarshalAs(NativeType.VARIANT) java.lang.Object p);

    @VTID(15)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object onchange();

    @VTID(16)
    void selectedIndex(
        int p);

    @VTID(17)
    int selectedIndex();

    @VTID(18)
    java.lang.String type();

    @VTID(19)
    void value(
        java.lang.String p);

    @VTID(20)
    java.lang.String value();

    @VTID(21)
    void disabled(
        boolean p);

    @VTID(22)
    boolean disabled();

    @VTID(23)
    mol.mshtml.IHTMLFormElement form();

    @VTID(23)
    @ReturnValue(type=NativeType.Dispatch,defaultPropertyThrough={mol.mshtml.IHTMLFormElement.class})
    com4j.Com4jObject form(
        @MarshalAs(NativeType.VARIANT) java.lang.Object name,
        @MarshalAs(NativeType.VARIANT) java.lang.Object index);

    @VTID(24)
    void add(
        mol.mshtml.IHTMLElement element,
        @MarshalAs(NativeType.VARIANT) java.lang.Object before);

    @VTID(25)
    void remove(
        int index);

    @VTID(26)
    void length(
        int p);

    @VTID(27)
    int length();

    @VTID(28)
    com4j.Com4jObject _newEnum();

    @VTID(29)
    @DefaultMethod
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject item(
        @MarshalAs(NativeType.VARIANT) java.lang.Object name,
        @MarshalAs(NativeType.VARIANT) java.lang.Object index);

    @VTID(30)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject tags(
        @MarshalAs(NativeType.VARIANT) java.lang.Object tagName);

}
