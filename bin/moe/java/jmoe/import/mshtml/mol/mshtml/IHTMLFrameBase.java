package mol.mshtml  ;

import com4j.*;

@IID("{3050F311-98B5-11CF-BB82-00AA00BDCE0B}")
public interface IHTMLFrameBase extends Com4jObject {
    @VTID(7)
    void src(
        java.lang.String p);

    @VTID(8)
    java.lang.String src();

    @VTID(9)
    void name(
        java.lang.String p);

    @VTID(10)
    java.lang.String name();

    @VTID(11)
    void border(
        @MarshalAs(NativeType.VARIANT) java.lang.Object p);

    @VTID(12)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object border();

    @VTID(13)
    void frameBorder(
        java.lang.String p);

    @VTID(14)
    java.lang.String frameBorder();

    @VTID(15)
    void frameSpacing(
        @MarshalAs(NativeType.VARIANT) java.lang.Object p);

    @VTID(16)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object frameSpacing();

    @VTID(17)
    void marginWidth(
        @MarshalAs(NativeType.VARIANT) java.lang.Object p);

    @VTID(18)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object marginWidth();

    @VTID(19)
    void marginHeight(
        @MarshalAs(NativeType.VARIANT) java.lang.Object p);

    @VTID(20)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object marginHeight();

    @VTID(21)
    void noResize(
        boolean p);

    @VTID(22)
    boolean noResize();

    @VTID(23)
    void scrolling(
        java.lang.String p);

    @VTID(24)
    java.lang.String scrolling();

}
