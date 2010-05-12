package mol.word  ;

import com4j.*;

@IID("{00020933-0000-0000-C000-000000000046}")
public interface OLEFormat extends Com4jObject {
    @VTID(7)
    mol.word._Application application();

    @VTID(8)
    int creator();

    @VTID(9)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

    @VTID(10)
    java.lang.String classType();

    @VTID(11)
    void classType(
        java.lang.String prop);

    @VTID(12)
    boolean displayAsIcon();

    @VTID(13)
    void displayAsIcon(
        boolean prop);

    @VTID(14)
    java.lang.String iconName();

    @VTID(15)
    void iconName(
        java.lang.String prop);

    @VTID(16)
    java.lang.String iconPath();

    @VTID(17)
    int iconIndex();

    @VTID(18)
    void iconIndex(
        int prop);

    @VTID(19)
    java.lang.String iconLabel();

    @VTID(20)
    void iconLabel(
        java.lang.String prop);

    @VTID(21)
    java.lang.String label();

    @VTID(22)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject object();

    @VTID(23)
    java.lang.String progID();

    @VTID(24)
    void activate();

    @VTID(25)
    void edit();

    @VTID(26)
    void open();

    @VTID(27)
    void doVerb(
        java.lang.Object verbIndex);

    @VTID(28)
    void convertTo(
        java.lang.Object classType,
        java.lang.Object displayAsIcon,
        java.lang.Object iconFileName,
        java.lang.Object iconIndex,
        java.lang.Object iconLabel);

    @VTID(29)
    void activateAs(
        java.lang.String classType);

    @VTID(30)
    boolean preserveFormattingOnUpdate();

    @VTID(31)
    void preserveFormattingOnUpdate(
        boolean prop);

}
