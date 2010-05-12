package mol.mshtml  ;

import com4j.*;

@IID("{3050F4E9-98B5-11CF-BB82-00AA00BDCE0B}")
public interface IHTMLControlElement extends Com4jObject {
    @VTID(7)
    void tabIndex(
        short p);

    @VTID(8)
    short tabIndex();

    @VTID(9)
    void focus();

    @VTID(10)
    void accessKey(
        java.lang.String p);

    @VTID(11)
    java.lang.String accessKey();

    @VTID(12)
    void onblur(
        @MarshalAs(NativeType.VARIANT) java.lang.Object p);

    @VTID(13)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object onblur();

    @VTID(14)
    void onfocus(
        @MarshalAs(NativeType.VARIANT) java.lang.Object p);

    @VTID(15)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object onfocus();

    @VTID(16)
    void onresize(
        @MarshalAs(NativeType.VARIANT) java.lang.Object p);

    @VTID(17)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object onresize();

    @VTID(18)
    void blur();

    @VTID(19)
    void addFilter(
        com4j.Com4jObject pUnk);

    @VTID(20)
    void removeFilter(
        com4j.Com4jObject pUnk);

    @VTID(21)
    int clientHeight();

    @VTID(22)
    int clientWidth();

    @VTID(23)
    int clientTop();

    @VTID(24)
    int clientLeft();

}
