package mol.excel  ;

import com4j.*;

@IID("{00024487-0001-0000-C000-000000000046}")
public interface IWorksheetView extends Com4jObject {
    @VTID(7)
    mol.excel._Application application();

    @VTID(8)
    mol.excel.XlCreator creator();

    @VTID(9)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

    @VTID(10)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject sheet();

    @VTID(11)
    boolean displayGridlines();

    @VTID(12)
    void displayGridlines(
        boolean rhs);

    @VTID(13)
    boolean displayFormulas();

    @VTID(14)
    void displayFormulas(
        boolean rhs);

    @VTID(15)
    boolean displayHeadings();

    @VTID(16)
    void displayHeadings(
        boolean rhs);

    @VTID(17)
    boolean displayOutline();

    @VTID(18)
    void displayOutline(
        boolean rhs);

    @VTID(19)
    boolean displayZeros();

    @VTID(20)
    void displayZeros(
        boolean rhs);

}
