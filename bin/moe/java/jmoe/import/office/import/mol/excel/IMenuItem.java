package mol.excel  ;

import com4j.*;

@IID("{00020868-0001-0000-C000-000000000046}")
public interface IMenuItem extends Com4jObject {
    @VTID(7)
    mol.excel._Application application();

    @VTID(8)
    mol.excel.XlCreator creator();

    @VTID(9)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

    @VTID(10)
    java.lang.String caption();

    @VTID(11)
    void caption(
        java.lang.String rhs);

    @VTID(12)
    boolean checked();

    @VTID(13)
    void checked(
        boolean rhs);

    @VTID(14)
    void delete();

    @VTID(15)
    boolean enabled();

    @VTID(16)
    void enabled(
        boolean rhs);

    @VTID(17)
    int helpContextID();

    @VTID(18)
    void helpContextID(
        int rhs);

    @VTID(19)
    java.lang.String helpFile();

    @VTID(20)
    void helpFile(
        java.lang.String rhs);

    @VTID(21)
    int index();

    @VTID(22)
    java.lang.String onAction();

    @VTID(23)
    void onAction(
        java.lang.String rhs);

    @VTID(24)
    java.lang.String statusBar();

    @VTID(25)
    void statusBar(
        java.lang.String rhs);

}
