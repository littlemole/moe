package mol.mshtml  ;

import com4j.*;

@IID("{3050F5D2-98B5-11CF-BB82-00AA00BDCE0B}")
public interface IHTMLInputElement extends Com4jObject {
    @VTID(7)
    void type(
        java.lang.String p);

    @VTID(8)
    java.lang.String type();

    @VTID(9)
    void value(
        java.lang.String p);

    @VTID(10)
    java.lang.String value();

    @VTID(11)
    void name(
        java.lang.String p);

    @VTID(12)
    java.lang.String name();

    @VTID(13)
    void status(
        boolean p);

    @VTID(14)
    boolean status();

    @VTID(15)
    void disabled(
        boolean p);

    @VTID(16)
    boolean disabled();

    @VTID(17)
    mol.mshtml.IHTMLFormElement form();

    @VTID(17)
    @ReturnValue(type=NativeType.Dispatch,defaultPropertyThrough={mol.mshtml.IHTMLFormElement.class})
    com4j.Com4jObject form(
        @MarshalAs(NativeType.VARIANT) java.lang.Object name,
        @MarshalAs(NativeType.VARIANT) java.lang.Object index);

    @VTID(18)
    void size(
        int p);

    @VTID(19)
    int size();

    @VTID(20)
    void maxLength(
        int p);

    @VTID(21)
    int maxLength();

    @VTID(22)
    void select();

    @VTID(23)
    void onchange(
        @MarshalAs(NativeType.VARIANT) java.lang.Object p);

    @VTID(24)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object onchange();

    @VTID(25)
    void onselect(
        @MarshalAs(NativeType.VARIANT) java.lang.Object p);

    @VTID(26)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object onselect();

    @VTID(27)
    void defaultValue(
        java.lang.String p);

    @VTID(28)
    java.lang.String defaultValue();

    @VTID(29)
    void readOnly(
        boolean p);

    @VTID(30)
    boolean readOnly();

    @VTID(31)
    mol.mshtml.IHTMLTxtRange createTextRange();

    @VTID(32)
    void indeterminate(
        boolean p);

    @VTID(33)
    boolean indeterminate();

    @VTID(34)
    void defaultChecked(
        boolean p);

    @VTID(35)
    boolean defaultChecked();

    @VTID(36)
    void checked(
        boolean p);

    @VTID(37)
    boolean checked();

    @VTID(38)
    void border(
        @MarshalAs(NativeType.VARIANT) java.lang.Object p);

    @VTID(39)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object border();

    @VTID(40)
    void vspace(
        int p);

    @VTID(41)
    int vspace();

    @VTID(42)
    void hspace(
        int p);

    @VTID(43)
    int hspace();

    @VTID(44)
    void alt(
        java.lang.String p);

    @VTID(45)
    java.lang.String alt();

    @VTID(46)
    void src(
        java.lang.String p);

    @VTID(47)
    java.lang.String src();

    @VTID(48)
    void lowsrc(
        java.lang.String p);

    @VTID(49)
    java.lang.String lowsrc();

    @VTID(50)
    void vrml(
        java.lang.String p);

    @VTID(51)
    java.lang.String vrml();

    @VTID(52)
    void dynsrc(
        java.lang.String p);

    @VTID(53)
    java.lang.String dynsrc();

    @VTID(54)
    java.lang.String readyState();

    @VTID(55)
    boolean complete();

    @VTID(56)
    void loop(
        @MarshalAs(NativeType.VARIANT) java.lang.Object p);

    @VTID(57)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object loop();

    @VTID(58)
    void align(
        java.lang.String p);

    @VTID(59)
    java.lang.String align();

    @VTID(60)
    void onload(
        @MarshalAs(NativeType.VARIANT) java.lang.Object p);

    @VTID(61)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object onload();

    @VTID(62)
    void onerror(
        @MarshalAs(NativeType.VARIANT) java.lang.Object p);

    @VTID(63)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object onerror();

    @VTID(64)
    void onabort(
        @MarshalAs(NativeType.VARIANT) java.lang.Object p);

    @VTID(65)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object onabort();

    @VTID(66)
    void width(
        int p);

    @VTID(67)
    int width();

    @VTID(68)
    void height(
        int p);

    @VTID(69)
    int height();

    @VTID(70)
    void start(
        java.lang.String p);

    @VTID(71)
    java.lang.String start();

}
