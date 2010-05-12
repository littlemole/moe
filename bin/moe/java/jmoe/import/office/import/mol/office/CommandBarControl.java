package mol.office  ;

import com4j.*;

@IID("{000C0308-0000-0000-C000-000000000046}")
public interface CommandBarControl extends mol.office._IMsoOleAccDispObj {
    @VTID(30)
    boolean beginGroup();

    @VTID(31)
    void beginGroup(
        boolean pvarfBeginGroup);

    @VTID(32)
    boolean builtIn();

    @VTID(33)
    java.lang.String caption();

    @VTID(34)
    void caption(
        java.lang.String pbstrCaption);

    @VTID(35)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject control();

    @VTID(36)
    mol.office.CommandBarControl copy(
        @MarshalAs(NativeType.VARIANT) java.lang.Object bar,
        @MarshalAs(NativeType.VARIANT) java.lang.Object before);

    @VTID(37)
    void delete(
        @MarshalAs(NativeType.VARIANT) java.lang.Object temporary);

    @VTID(38)
    java.lang.String descriptionText();

    @VTID(39)
    void descriptionText(
        java.lang.String pbstrText);

    @VTID(40)
    boolean enabled();

    @VTID(41)
    void enabled(
        boolean pvarfEnabled);

    @VTID(42)
    void execute();

    @VTID(43)
    int height();

    @VTID(44)
    void height(
        int pdy);

    @VTID(45)
    int helpContextId();

    @VTID(46)
    void helpContextId(
        int pid);

    @VTID(47)
    java.lang.String helpFile();

    @VTID(48)
    void helpFile(
        java.lang.String pbstrFilename);

    @VTID(49)
    int id();

    @VTID(50)
    int index();

    @VTID(51)
    int instanceId();

    @VTID(52)
    mol.office.CommandBarControl move(
        @MarshalAs(NativeType.VARIANT) java.lang.Object bar,
        @MarshalAs(NativeType.VARIANT) java.lang.Object before);

    @VTID(53)
    int left();

    @VTID(54)
    mol.office.MsoControlOLEUsage oleUsage();

    @VTID(55)
    void oleUsage(
        mol.office.MsoControlOLEUsage pcou);

    @VTID(56)
    java.lang.String onAction();

    @VTID(57)
    void onAction(
        java.lang.String pbstrOnAction);

    @VTID(58)
    mol.office.CommandBar parent();

    @VTID(59)
    java.lang.String parameter();

    @VTID(60)
    void parameter(
        java.lang.String pbstrParam);

    @VTID(61)
    int priority();

    @VTID(62)
    void priority(
        int pnPri);

    @VTID(63)
    void reset();

    @VTID(64)
    void setFocus();

    @VTID(65)
    java.lang.String tag();

    @VTID(66)
    void tag(
        java.lang.String pbstrTag);

    @VTID(67)
    java.lang.String tooltipText();

    @VTID(68)
    void tooltipText(
        java.lang.String pbstrTooltip);

    @VTID(69)
    int top();

    @VTID(70)
    mol.office.MsoControlType type();

    @VTID(71)
    boolean visible();

    @VTID(72)
    void visible(
        boolean pvarfVisible);

    @VTID(73)
    int width();

    @VTID(74)
    void width(
        int pdx);

    @VTID(75)
    boolean isPriorityDropped();

    @VTID(76)
    void reserved1();

    @VTID(77)
    void reserved2();

    @VTID(78)
    void reserved3();

    @VTID(79)
    void reserved4();

    @VTID(80)
    void reserved5();

    @VTID(81)
    void reserved6();

    @VTID(82)
    void reserved7();

}
