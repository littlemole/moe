package mol.mshtml  ;

import com4j.*;

@IID("{3050F1D8-98B5-11CF-BB82-00AA00BDCE0B}")
public interface IHTMLBodyElement extends Com4jObject {
    @VTID(7)
    void background(
        java.lang.String p);

    @VTID(8)
    java.lang.String background();

    @VTID(9)
    void bgProperties(
        java.lang.String p);

    @VTID(10)
    java.lang.String bgProperties();

    @VTID(11)
    void leftMargin(
        @MarshalAs(NativeType.VARIANT) java.lang.Object p);

    @VTID(12)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object leftMargin();

    @VTID(13)
    void topMargin(
        @MarshalAs(NativeType.VARIANT) java.lang.Object p);

    @VTID(14)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object topMargin();

    @VTID(15)
    void rightMargin(
        @MarshalAs(NativeType.VARIANT) java.lang.Object p);

    @VTID(16)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object rightMargin();

    @VTID(17)
    void bottomMargin(
        @MarshalAs(NativeType.VARIANT) java.lang.Object p);

    @VTID(18)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object bottomMargin();

    @VTID(19)
    void noWrap(
        boolean p);

    @VTID(20)
    boolean noWrap();

    @VTID(21)
    void bgColor(
        @MarshalAs(NativeType.VARIANT) java.lang.Object p);

    @VTID(22)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object bgColor();

    @VTID(23)
    void text(
        @MarshalAs(NativeType.VARIANT) java.lang.Object p);

    @VTID(24)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object text();

    @VTID(25)
    void link(
        @MarshalAs(NativeType.VARIANT) java.lang.Object p);

    @VTID(26)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object link();

    @VTID(27)
    void vLink(
        @MarshalAs(NativeType.VARIANT) java.lang.Object p);

    @VTID(28)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object vLink();

    @VTID(29)
    void aLink(
        @MarshalAs(NativeType.VARIANT) java.lang.Object p);

    @VTID(30)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object aLink();

    @VTID(31)
    void onload(
        @MarshalAs(NativeType.VARIANT) java.lang.Object p);

    @VTID(32)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object onload();

    @VTID(33)
    void onunload(
        @MarshalAs(NativeType.VARIANT) java.lang.Object p);

    @VTID(34)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object onunload();

    @VTID(35)
    void scroll(
        java.lang.String p);

    @VTID(36)
    java.lang.String scroll();

    @VTID(37)
    void onselect(
        @MarshalAs(NativeType.VARIANT) java.lang.Object p);

    @VTID(38)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object onselect();

    @VTID(39)
    void onbeforeunload(
        @MarshalAs(NativeType.VARIANT) java.lang.Object p);

    @VTID(40)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object onbeforeunload();

    @VTID(41)
    mol.mshtml.IHTMLTxtRange createTextRange();

}
