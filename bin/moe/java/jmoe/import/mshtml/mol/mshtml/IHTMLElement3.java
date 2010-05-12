package mol.mshtml  ;

import com4j.*;

@IID("{3050F673-98B5-11CF-BB82-00AA00BDCE0B}")
public interface IHTMLElement3 extends Com4jObject {
    @VTID(7)
    void mergeAttributes(
        mol.mshtml.IHTMLElement mergeThis,
        java.lang.Object pvarFlags);

    @VTID(8)
    boolean isMultiLine();

    @VTID(9)
    boolean canHaveHTML();

    @VTID(10)
    void onlayoutcomplete(
        @MarshalAs(NativeType.VARIANT) java.lang.Object p);

    @VTID(11)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object onlayoutcomplete();

    @VTID(12)
    void onpage(
        @MarshalAs(NativeType.VARIANT) java.lang.Object p);

    @VTID(13)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object onpage();

    @VTID(14)
    void inflateBlock(
        boolean p);

    @VTID(15)
    boolean inflateBlock();

    @VTID(16)
    void onbeforedeactivate(
        @MarshalAs(NativeType.VARIANT) java.lang.Object p);

    @VTID(17)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object onbeforedeactivate();

    @VTID(18)
    void setActive();

    @VTID(19)
    void contentEditable(
        java.lang.String p);

    @VTID(20)
    java.lang.String contentEditable();

    @VTID(21)
    boolean isContentEditable();

    @VTID(22)
    void hideFocus(
        boolean p);

    @VTID(23)
    boolean hideFocus();

    @VTID(24)
    void disabled(
        boolean p);

    @VTID(25)
    boolean disabled();

    @VTID(26)
    boolean isDisabled();

    @VTID(27)
    void onmove(
        @MarshalAs(NativeType.VARIANT) java.lang.Object p);

    @VTID(28)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object onmove();

    @VTID(29)
    void oncontrolselect(
        @MarshalAs(NativeType.VARIANT) java.lang.Object p);

    @VTID(30)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object oncontrolselect();

    @VTID(31)
    boolean fireEvent(
        java.lang.String bstrEventName,
        java.lang.Object pvarEventObject);

    @VTID(32)
    void onresizestart(
        @MarshalAs(NativeType.VARIANT) java.lang.Object p);

    @VTID(33)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object onresizestart();

    @VTID(34)
    void onresizeend(
        @MarshalAs(NativeType.VARIANT) java.lang.Object p);

    @VTID(35)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object onresizeend();

    @VTID(36)
    void onmovestart(
        @MarshalAs(NativeType.VARIANT) java.lang.Object p);

    @VTID(37)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object onmovestart();

    @VTID(38)
    void onmoveend(
        @MarshalAs(NativeType.VARIANT) java.lang.Object p);

    @VTID(39)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object onmoveend();

    @VTID(40)
    void onmouseenter(
        @MarshalAs(NativeType.VARIANT) java.lang.Object p);

    @VTID(41)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object onmouseenter();

    @VTID(42)
    void onmouseleave(
        @MarshalAs(NativeType.VARIANT) java.lang.Object p);

    @VTID(43)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object onmouseleave();

    @VTID(44)
    void onactivate(
        @MarshalAs(NativeType.VARIANT) java.lang.Object p);

    @VTID(45)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object onactivate();

    @VTID(46)
    void ondeactivate(
        @MarshalAs(NativeType.VARIANT) java.lang.Object p);

    @VTID(47)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object ondeactivate();

    @VTID(48)
    boolean dragDrop();

    @VTID(49)
    int glyphMode();

}
