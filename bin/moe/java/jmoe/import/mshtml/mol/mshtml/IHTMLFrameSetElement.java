package mol.mshtml  ;

import com4j.*;

@IID("{3050F319-98B5-11CF-BB82-00AA00BDCE0B}")
public interface IHTMLFrameSetElement extends Com4jObject {
    @VTID(7)
    void rows(
        java.lang.String p);

    @VTID(8)
    java.lang.String rows();

    @VTID(9)
    void cols(
        java.lang.String p);

    @VTID(10)
    java.lang.String cols();

    @VTID(11)
    void border(
        @MarshalAs(NativeType.VARIANT) java.lang.Object p);

    @VTID(12)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object border();

    @VTID(13)
    void borderColor(
        @MarshalAs(NativeType.VARIANT) java.lang.Object p);

    @VTID(14)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object borderColor();

    @VTID(15)
    void frameBorder(
        java.lang.String p);

    @VTID(16)
    java.lang.String frameBorder();

    @VTID(17)
    void frameSpacing(
        @MarshalAs(NativeType.VARIANT) java.lang.Object p);

    @VTID(18)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object frameSpacing();

    @VTID(19)
    void name(
        java.lang.String p);

    @VTID(20)
    java.lang.String name();

    @VTID(21)
    void onload(
        @MarshalAs(NativeType.VARIANT) java.lang.Object p);

    @VTID(22)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object onload();

    @VTID(23)
    void onunload(
        @MarshalAs(NativeType.VARIANT) java.lang.Object p);

    @VTID(24)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object onunload();

    @VTID(25)
    void onbeforeunload(
        @MarshalAs(NativeType.VARIANT) java.lang.Object p);

    @VTID(26)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object onbeforeunload();

}
