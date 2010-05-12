package mol.mshtml  ;

import com4j.*;

@IID("{3050F21E-98B5-11CF-BB82-00AA00BDCE0B}")
public interface IHTMLTable extends Com4jObject {
    @VTID(7)
    void cols(
        int p);

    @VTID(8)
    int cols();

    @VTID(9)
    void border(
        @MarshalAs(NativeType.VARIANT) java.lang.Object p);

    @VTID(10)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object border();

    @VTID(11)
    void frame(
        java.lang.String p);

    @VTID(12)
    java.lang.String frame();

    @VTID(13)
    void rules(
        java.lang.String p);

    @VTID(14)
    java.lang.String rules();

    @VTID(15)
    void cellSpacing(
        @MarshalAs(NativeType.VARIANT) java.lang.Object p);

    @VTID(16)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object cellSpacing();

    @VTID(17)
    void cellPadding(
        @MarshalAs(NativeType.VARIANT) java.lang.Object p);

    @VTID(18)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object cellPadding();

    @VTID(19)
    void background(
        java.lang.String p);

    @VTID(20)
    java.lang.String background();

    @VTID(21)
    void bgColor(
        @MarshalAs(NativeType.VARIANT) java.lang.Object p);

    @VTID(22)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object bgColor();

    @VTID(23)
    void borderColor(
        @MarshalAs(NativeType.VARIANT) java.lang.Object p);

    @VTID(24)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object borderColor();

    @VTID(25)
    void borderColorLight(
        @MarshalAs(NativeType.VARIANT) java.lang.Object p);

    @VTID(26)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object borderColorLight();

    @VTID(27)
    void borderColorDark(
        @MarshalAs(NativeType.VARIANT) java.lang.Object p);

    @VTID(28)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object borderColorDark();

    @VTID(29)
    void align(
        java.lang.String p);

    @VTID(30)
    java.lang.String align();

    @VTID(31)
    void refresh();

    @VTID(32)
    mol.mshtml.IHTMLElementCollection rows();

    @VTID(32)
    @ReturnValue(type=NativeType.Dispatch,defaultPropertyThrough={mol.mshtml.IHTMLElementCollection.class})
    com4j.Com4jObject rows(
        @MarshalAs(NativeType.VARIANT) java.lang.Object name,
        @MarshalAs(NativeType.VARIANT) java.lang.Object index);

    @VTID(33)
    void width(
        @MarshalAs(NativeType.VARIANT) java.lang.Object p);

    @VTID(34)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object width();

    @VTID(35)
    void height(
        @MarshalAs(NativeType.VARIANT) java.lang.Object p);

    @VTID(36)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object height();

    @VTID(37)
    void dataPageSize(
        int p);

    @VTID(38)
    int dataPageSize();

    @VTID(39)
    void nextPage();

    @VTID(40)
    void previousPage();

    @VTID(41)
    mol.mshtml.IHTMLTableSection tHead();

    @VTID(42)
    mol.mshtml.IHTMLTableSection tFoot();

    @VTID(43)
    mol.mshtml.IHTMLElementCollection tBodies();

    @VTID(43)
    @ReturnValue(type=NativeType.Dispatch,defaultPropertyThrough={mol.mshtml.IHTMLElementCollection.class})
    com4j.Com4jObject tBodies(
        @MarshalAs(NativeType.VARIANT) java.lang.Object name,
        @MarshalAs(NativeType.VARIANT) java.lang.Object index);

    @VTID(44)
    mol.mshtml.IHTMLTableCaption caption();

    @VTID(45)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject createTHead();

    @VTID(46)
    void deleteTHead();

    @VTID(47)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject createTFoot();

    @VTID(48)
    void deleteTFoot();

    @VTID(49)
    mol.mshtml.IHTMLTableCaption createCaption();

    @VTID(50)
    void deleteCaption();

    @VTID(51)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject insertRow(
        int index);

    @VTID(52)
    void deleteRow(
        int index);

    @VTID(53)
    java.lang.String readyState();

    @VTID(54)
    void onreadystatechange(
        @MarshalAs(NativeType.VARIANT) java.lang.Object p);

    @VTID(55)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object onreadystatechange();

}
