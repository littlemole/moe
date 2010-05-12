package mol.mshtml  ;

import com4j.*;

@IID("{3050F2B5-98B5-11CF-BB82-00AA00BDCE0B}")
public interface IHTMLMarqueeElement extends Com4jObject {
    @VTID(7)
    void bgColor(
        @MarshalAs(NativeType.VARIANT) java.lang.Object p);

    @VTID(8)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object bgColor();

    @VTID(9)
    void scrollDelay(
        int p);

    @VTID(10)
    int scrollDelay();

    @VTID(11)
    void direction(
        java.lang.String p);

    @VTID(12)
    java.lang.String direction();

    @VTID(13)
    void behavior(
        java.lang.String p);

    @VTID(14)
    java.lang.String behavior();

    @VTID(15)
    void scrollAmount(
        int p);

    @VTID(16)
    int scrollAmount();

    @VTID(17)
    void loop(
        int p);

    @VTID(18)
    int loop();

    @VTID(19)
    void vspace(
        int p);

    @VTID(20)
    int vspace();

    @VTID(21)
    void hspace(
        int p);

    @VTID(22)
    int hspace();

    @VTID(23)
    void onfinish(
        @MarshalAs(NativeType.VARIANT) java.lang.Object p);

    @VTID(24)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object onfinish();

    @VTID(25)
    void onstart(
        @MarshalAs(NativeType.VARIANT) java.lang.Object p);

    @VTID(26)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object onstart();

    @VTID(27)
    void onbounce(
        @MarshalAs(NativeType.VARIANT) java.lang.Object p);

    @VTID(28)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object onbounce();

    @VTID(29)
    void width(
        @MarshalAs(NativeType.VARIANT) java.lang.Object p);

    @VTID(30)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object width();

    @VTID(31)
    void height(
        @MarshalAs(NativeType.VARIANT) java.lang.Object p);

    @VTID(32)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object height();

    @VTID(33)
    void trueSpeed(
        boolean p);

    @VTID(34)
    boolean trueSpeed();

    @VTID(35)
    void start();

    @VTID(36)
    void stop();

}
