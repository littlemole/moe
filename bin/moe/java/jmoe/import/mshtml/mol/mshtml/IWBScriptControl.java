package mol.mshtml  ;

import com4j.*;

@IID("{A5170870-0CF8-11D1-8B91-0080C744F389}")
public interface IWBScriptControl extends Com4jObject {
    @VTID(7)
    void raiseEvent(
        java.lang.String name,
        @MarshalAs(NativeType.VARIANT) java.lang.Object eventData);

    @VTID(8)
    void bubbleEvent();

    @VTID(9)
    void setContextMenu(
        @MarshalAs(NativeType.VARIANT) java.lang.Object menuItemPairs);

    @VTID(10)
    void selectableContent(
        boolean p);

    @VTID(11)
    boolean selectableContent();

    @VTID(12)
    boolean frozen();

    @VTID(13)
    void scrollbar(
        boolean p);

    @VTID(14)
    boolean scrollbar();

    @VTID(15)
    java.lang.String version();

    @VTID(16)
    boolean visibility();

    @VTID(17)
    void onvisibilitychange(
        @MarshalAs(NativeType.VARIANT) java.lang.Object p);

    @VTID(18)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object onvisibilitychange();

}
