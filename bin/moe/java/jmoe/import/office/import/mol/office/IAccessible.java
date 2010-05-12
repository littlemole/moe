package mol.office  ;

import com4j.*;

@IID("{618736E0-3C3D-11CF-810C-00AA00389B71}")
public interface IAccessible extends Com4jObject {
    @VTID(7)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject accParent();

    @VTID(8)
    int accChildCount();

    @VTID(9)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject accChild(
        @MarshalAs(NativeType.VARIANT) java.lang.Object varChild);

    @VTID(10)
    java.lang.String accName(
        @MarshalAs(NativeType.VARIANT) java.lang.Object varChild);

    @VTID(11)
    java.lang.String accValue(
        @MarshalAs(NativeType.VARIANT) java.lang.Object varChild);

    @VTID(12)
    java.lang.String accDescription(
        @MarshalAs(NativeType.VARIANT) java.lang.Object varChild);

    @VTID(13)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object accRole(
        @MarshalAs(NativeType.VARIANT) java.lang.Object varChild);

    @VTID(14)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object accState(
        @MarshalAs(NativeType.VARIANT) java.lang.Object varChild);

    @VTID(15)
    java.lang.String accHelp(
        @MarshalAs(NativeType.VARIANT) java.lang.Object varChild);

    @VTID(16)
    int accHelpTopic(
        Holder<java.lang.String> pszHelpFile,
        @MarshalAs(NativeType.VARIANT) java.lang.Object varChild);

    @VTID(17)
    java.lang.String accKeyboardShortcut(
        @MarshalAs(NativeType.VARIANT) java.lang.Object varChild);

    @VTID(18)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object accFocus();

    @VTID(19)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object accSelection();

    @VTID(20)
    java.lang.String accDefaultAction(
        @MarshalAs(NativeType.VARIANT) java.lang.Object varChild);

    @VTID(21)
    void accSelect(
        int flagsSelect,
        @MarshalAs(NativeType.VARIANT) java.lang.Object varChild);

    @VTID(22)
    void accLocation(
        Holder<Integer> pxLeft,
        Holder<Integer> pyTop,
        Holder<Integer> pcxWidth,
        Holder<Integer> pcyHeight,
        @MarshalAs(NativeType.VARIANT) java.lang.Object varChild);

    @VTID(23)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object accNavigate(
        int navDir,
        @MarshalAs(NativeType.VARIANT) java.lang.Object varStart);

    @VTID(24)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object accHitTest(
        int xLeft,
        int yTop);

    @VTID(25)
    void accDoDefaultAction(
        @MarshalAs(NativeType.VARIANT) java.lang.Object varChild);

    @VTID(26)
    void accName(
        @MarshalAs(NativeType.VARIANT) java.lang.Object varChild,
        java.lang.String pszName);

    @VTID(27)
    void accValue(
        @MarshalAs(NativeType.VARIANT) java.lang.Object varChild,
        java.lang.String pszValue);

}
