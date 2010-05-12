package mol.mshtml  ;

import com4j.*;

@IID("{3050F6AE-98B5-11CF-BB82-00AA00BDCE0B}")
public interface IHTMLRenderStyle extends Com4jObject {
    @VTID(7)
    void textLineThroughStyle(
        java.lang.String p);

    @VTID(8)
    java.lang.String textLineThroughStyle();

    @VTID(9)
    void textUnderlineStyle(
        java.lang.String p);

    @VTID(10)
    java.lang.String textUnderlineStyle();

    @VTID(11)
    void textEffect(
        java.lang.String p);

    @VTID(12)
    java.lang.String textEffect();

    @VTID(13)
    void textColor(
        @MarshalAs(NativeType.VARIANT) java.lang.Object p);

    @VTID(14)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object textColor();

    @VTID(15)
    void textBackgroundColor(
        @MarshalAs(NativeType.VARIANT) java.lang.Object p);

    @VTID(16)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object textBackgroundColor();

    @VTID(17)
    void textDecorationColor(
        @MarshalAs(NativeType.VARIANT) java.lang.Object p);

    @VTID(18)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object textDecorationColor();

    @VTID(19)
    void renderingPriority(
        int p);

    @VTID(20)
    int renderingPriority();

    @VTID(21)
    void defaultTextSelection(
        java.lang.String p);

    @VTID(22)
    java.lang.String defaultTextSelection();

    @VTID(23)
    void textDecoration(
        java.lang.String p);

    @VTID(24)
    java.lang.String textDecoration();

}
