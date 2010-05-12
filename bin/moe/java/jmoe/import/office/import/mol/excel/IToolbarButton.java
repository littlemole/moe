package mol.excel  ;

import com4j.*;

@IID("{0002085E-0001-0000-C000-000000000046}")
public interface IToolbarButton extends Com4jObject {
    @VTID(7)
    mol.excel._Application application();

    @VTID(8)
    mol.excel.XlCreator creator();

    @VTID(9)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

    @VTID(10)
    boolean builtIn();

    @VTID(11)
    boolean builtInFace();

    @VTID(12)
    void builtInFace(
        boolean rhs);

    @VTID(13)
    void copy(
        mol.excel.Toolbar toolbar,
        int before);

    @VTID(14)
    void copyFace();

    @VTID(15)
    void delete();

    @VTID(16)
    void edit();

    @VTID(17)
    boolean enabled();

    @VTID(18)
    void enabled(
        boolean rhs);

    @VTID(19)
    int helpContextID();

    @VTID(20)
    void helpContextID(
        int rhs);

    @VTID(21)
    java.lang.String helpFile();

    @VTID(22)
    void helpFile(
        java.lang.String rhs);

    @VTID(23)
    int id();

    @VTID(24)
    boolean isGap();

    @VTID(25)
    void move(
        mol.excel.Toolbar toolbar,
        int before);

    @VTID(26)
    java.lang.String name();

    @VTID(27)
    void name(
        java.lang.String rhs);

    @VTID(28)
    java.lang.String onAction();

    @VTID(29)
    void onAction(
        java.lang.String rhs);

    @VTID(30)
    void pasteFace();

    @VTID(31)
    boolean pushed();

    @VTID(32)
    void pushed(
        boolean rhs);

    @VTID(33)
    void reset();

    @VTID(34)
    java.lang.String statusBar();

    @VTID(35)
    void statusBar(
        java.lang.String rhs);

    @VTID(36)
    int width();

    @VTID(37)
    void width(
        int rhs);

}
