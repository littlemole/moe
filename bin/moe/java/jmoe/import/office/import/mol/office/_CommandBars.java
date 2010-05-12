package mol.office  ;

import com4j.*;

@IID("{000C0302-0000-0000-C000-000000000046}")
public interface _CommandBars extends mol.office._IMsoDispObj,Iterable<Com4jObject> {
    @VTID(9)
    mol.office.CommandBarControl actionControl();

    @VTID(10)
    mol.office.CommandBar activeMenuBar();

    @VTID(11)
    mol.office.CommandBar add(
        @MarshalAs(NativeType.VARIANT) java.lang.Object name,
        @MarshalAs(NativeType.VARIANT) java.lang.Object position,
        @MarshalAs(NativeType.VARIANT) java.lang.Object menuBar,
        @MarshalAs(NativeType.VARIANT) java.lang.Object temporary);

    @VTID(12)
    int count();

    @VTID(13)
    boolean displayTooltips();

    @VTID(14)
    void displayTooltips(
        boolean pvarfDisplayTooltips);

    @VTID(15)
    boolean displayKeysInTooltips();

    @VTID(16)
    void displayKeysInTooltips(
        boolean pvarfDisplayKeys);

    @VTID(17)
    mol.office.CommandBarControl findControl(
        @MarshalAs(NativeType.VARIANT) java.lang.Object type,
        @MarshalAs(NativeType.VARIANT) java.lang.Object id,
        @MarshalAs(NativeType.VARIANT) java.lang.Object tag,
        @MarshalAs(NativeType.VARIANT) java.lang.Object visible);

    @VTID(18)
    @DefaultMethod
    mol.office.CommandBar item(
        @MarshalAs(NativeType.VARIANT) java.lang.Object index);

    @VTID(19)
    boolean largeButtons();

    @VTID(20)
    void largeButtons(
        boolean pvarfLargeButtons);

    @VTID(21)
    mol.office.MsoMenuAnimation menuAnimationStyle();

    @VTID(22)
    void menuAnimationStyle(
        mol.office.MsoMenuAnimation pma);

    @VTID(23)
    java.util.Iterator<Com4jObject> iterator();

    @VTID(24)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

    @VTID(25)
    void releaseFocus();

    @VTID(26)
    int idsString(
        int ids,
        Holder<java.lang.String> pbstrName);

    @VTID(27)
    int tmcGetName(
        int tmc,
        Holder<java.lang.String> pbstrName);

    @VTID(28)
    boolean adaptiveMenus();

    @VTID(29)
    void adaptiveMenus(
        boolean pvarfAdaptiveMenus);

    @VTID(30)
    mol.office.CommandBarControls findControls(
        @MarshalAs(NativeType.VARIANT) java.lang.Object type,
        @MarshalAs(NativeType.VARIANT) java.lang.Object id,
        @MarshalAs(NativeType.VARIANT) java.lang.Object tag,
        @MarshalAs(NativeType.VARIANT) java.lang.Object visible);

    @VTID(31)
    mol.office.CommandBar addEx(
        @MarshalAs(NativeType.VARIANT) java.lang.Object tbidOrName,
        @MarshalAs(NativeType.VARIANT) java.lang.Object position,
        @MarshalAs(NativeType.VARIANT) java.lang.Object menuBar,
        @MarshalAs(NativeType.VARIANT) java.lang.Object temporary,
        @MarshalAs(NativeType.VARIANT) java.lang.Object tbtrProtection);

    @VTID(32)
    boolean displayFonts();

    @VTID(33)
    void displayFonts(
        boolean pvarfDisplayFonts);

    @VTID(34)
    boolean disableCustomize();

    @VTID(35)
    void disableCustomize(
        boolean pvarfDisableCustomize);

    @VTID(36)
    boolean disableAskAQuestionDropdown();

    @VTID(37)
    void disableAskAQuestionDropdown(
        boolean pvarfDisableAskAQuestionDropdown);

    @VTID(38)
    void executeMso(
        java.lang.String idMso);

    @VTID(39)
    boolean getEnabledMso(
        java.lang.String idMso);

    @VTID(40)
    boolean getVisibleMso(
        java.lang.String idMso);

    @VTID(41)
    boolean getPressedMso(
        java.lang.String idMso);

    @VTID(42)
    java.lang.String getLabelMso(
        java.lang.String idMso);

    @VTID(43)
    java.lang.String getScreentipMso(
        java.lang.String idMso);

    @VTID(44)
    java.lang.String getSupertipMso(
        java.lang.String idMso);

}
