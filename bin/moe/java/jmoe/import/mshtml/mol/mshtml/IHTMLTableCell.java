package mol.mshtml  ;

import com4j.*;

@IID("{3050F23D-98B5-11CF-BB82-00AA00BDCE0B}")
public interface IHTMLTableCell extends Com4jObject {
    @VTID(7)
    void rowSpan(
        int p);

    @VTID(8)
    int rowSpan();

    @VTID(9)
    void colSpan(
        int p);

    @VTID(10)
    int colSpan();

    @VTID(11)
    void align(
        java.lang.String p);

    @VTID(12)
    java.lang.String align();

    @VTID(13)
    void vAlign(
        java.lang.String p);

    @VTID(14)
    java.lang.String vAlign();

    @VTID(15)
    void bgColor(
        @MarshalAs(NativeType.VARIANT) java.lang.Object p);

    @VTID(16)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object bgColor();

    @VTID(17)
    void noWrap(
        boolean p);

    @VTID(18)
    boolean noWrap();

    @VTID(19)
    void background(
        java.lang.String p);

    @VTID(20)
    java.lang.String background();

    @VTID(21)
    void borderColor(
        @MarshalAs(NativeType.VARIANT) java.lang.Object p);

    @VTID(22)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object borderColor();

    @VTID(23)
    void borderColorLight(
        @MarshalAs(NativeType.VARIANT) java.lang.Object p);

    @VTID(24)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object borderColorLight();

    @VTID(25)
    void borderColorDark(
        @MarshalAs(NativeType.VARIANT) java.lang.Object p);

    @VTID(26)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object borderColorDark();

    @VTID(27)
    void width(
        @MarshalAs(NativeType.VARIANT) java.lang.Object p);

    @VTID(28)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object width();

    @VTID(29)
    void height(
        @MarshalAs(NativeType.VARIANT) java.lang.Object p);

    @VTID(30)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object height();

    @VTID(31)
    int cellIndex();

}
