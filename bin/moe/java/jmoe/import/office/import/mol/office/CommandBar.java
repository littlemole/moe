package mol.office  ;

import com4j.*;

@IID("{000C0304-0000-0000-C000-000000000046}")
public interface CommandBar extends mol.office._IMsoOleAccDispObj {
    @VTID(30)
    boolean builtIn();

    @VTID(31)
    java.lang.String context();

    @VTID(32)
    void context(
        java.lang.String pbstrContext);

    @VTID(33)
    mol.office.CommandBarControls controls();

    @VTID(33)
    @ReturnValue(defaultPropertyThrough={mol.office.CommandBarControls.class})
    mol.office.CommandBarControl controls(
        @MarshalAs(NativeType.VARIANT) java.lang.Object index);

    @VTID(34)
    void delete();

    @VTID(35)
    boolean enabled();

    @VTID(36)
    void enabled(
        boolean pvarfEnabled);

    @VTID(37)
    mol.office.CommandBarControl findControl(
        @MarshalAs(NativeType.VARIANT) java.lang.Object type,
        @MarshalAs(NativeType.VARIANT) java.lang.Object id,
        @MarshalAs(NativeType.VARIANT) java.lang.Object tag,
        @MarshalAs(NativeType.VARIANT) java.lang.Object visible,
        @MarshalAs(NativeType.VARIANT) java.lang.Object recursive);

    @VTID(38)
    int height();

    @VTID(39)
    void height(
        int pdy);

    @VTID(40)
    int index();

    @VTID(41)
    int instanceId();

    @VTID(42)
    int left();

    @VTID(43)
    void left(
        int pxpLeft);

    @VTID(44)
    java.lang.String name();

    @VTID(45)
    void name(
        java.lang.String pbstrName);

    @VTID(46)
    java.lang.String nameLocal();

    @VTID(47)
    void nameLocal(
        java.lang.String pbstrNameLocal);

    @VTID(48)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

    @VTID(49)
    mol.office.MsoBarPosition position();

    @VTID(50)
    void position(
        mol.office.MsoBarPosition ppos);

    @VTID(51)
    int rowIndex();

    @VTID(52)
    void rowIndex(
        int piRow);

    @VTID(53)
    mol.office.MsoBarProtection protection();

    @VTID(54)
    void protection(
        mol.office.MsoBarProtection pprot);

    @VTID(55)
    void reset();

    @VTID(56)
    void showPopup(
        @MarshalAs(NativeType.VARIANT) java.lang.Object x,
        @MarshalAs(NativeType.VARIANT) java.lang.Object y);

    @VTID(57)
    int top();

    @VTID(58)
    void top(
        int pypTop);

    @VTID(59)
    mol.office.MsoBarType type();

    @VTID(60)
    boolean visible();

    @VTID(61)
    void visible(
        boolean pvarfVisible);

    @VTID(62)
    int width();

    @VTID(63)
    void width(
        int pdx);

    @VTID(64)
    boolean adaptiveMenu();

    @VTID(65)
    void adaptiveMenu(
        boolean pvarfAdaptiveMenu);

    @VTID(66)
    int id();

}
