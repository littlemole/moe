package mol.office  ;

import com4j.*;

@IID("{000C0324-0000-0000-C000-000000000046}")
public interface Balloon extends mol.office._IMsoDispObj {
    @VTID(9)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

    @VTID(10)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject checkboxes();

    @VTID(11)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject labels();

    @VTID(12)
    void balloonType(
        mol.office.MsoBalloonType pbty);

    @VTID(13)
    mol.office.MsoBalloonType balloonType();

    @VTID(14)
    void icon(
        mol.office.MsoIconType picn);

    @VTID(15)
    mol.office.MsoIconType icon();

    @VTID(16)
    void heading(
        java.lang.String pbstr);

    @VTID(17)
    java.lang.String heading();

    @VTID(18)
    void text(
        java.lang.String pbstr);

    @VTID(19)
    java.lang.String text();

    @VTID(20)
    void mode(
        mol.office.MsoModeType pmd);

    @VTID(21)
    mol.office.MsoModeType mode();

    @VTID(22)
    void animation(
        mol.office.MsoAnimationType pfca);

    @VTID(23)
    mol.office.MsoAnimationType animation();

    @VTID(24)
    void button(
        mol.office.MsoButtonSetType psbs);

    @VTID(25)
    mol.office.MsoButtonSetType button();

    @VTID(26)
    void callback(
        java.lang.String pbstr);

    @VTID(27)
    java.lang.String callback();

    @VTID(28)
    void _private(
        int plPrivate);

    @VTID(29)
    int _private();

    @VTID(30)
    void setAvoidRectangle(
        int left,
        int top,
        int right,
        int bottom);

    @VTID(31)
    java.lang.String name();

    @VTID(32)
    mol.office.MsoBalloonButtonType show();

    @VTID(33)
    void close();

}
