package mol.excel  ;

import com4j.*;

@IID("{0002445E-0001-0000-C000-000000000046}")
public interface ISmartTagAction extends Com4jObject {
    @VTID(7)
    mol.excel._Application application();

    @VTID(8)
    mol.excel.XlCreator creator();

    @VTID(9)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

    @VTID(10)
    java.lang.String name();

    @VTID(11)
    void execute();

    @VTID(12)
    @DefaultMethod
    java.lang.String _Default();

    @VTID(13)
    mol.excel.XlSmartTagControlType type();

    @VTID(14)
    boolean presentInPane();

    @VTID(15)
    boolean expandHelp();

    @VTID(16)
    void expandHelp(
        boolean rhs);

    @VTID(17)
    boolean checkboxState();

    @VTID(18)
    void checkboxState(
        boolean rhs);

    @VTID(19)
    java.lang.String textboxText();

    @VTID(20)
    void textboxText(
        java.lang.String rhs);

    @VTID(21)
    int listSelection();

    @VTID(22)
    void listSelection(
        int rhs);

    @VTID(23)
    int radioGroupSelection();

    @VTID(24)
    void radioGroupSelection(
        int rhs);

    @VTID(25)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject activeXControl();

}
