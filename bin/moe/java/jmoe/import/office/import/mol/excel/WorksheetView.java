package mol.excel  ;

import com4j.*;

@IID("{00020400-0000-0000-C000-000000000046}")
public interface WorksheetView extends Com4jObject {
    @DISPID(148)
    @PropGet
    mol.excel._Application application();

    @DISPID(149)
    @PropGet
    mol.excel.XlCreator creator();

    @DISPID(150)
    @PropGet
    com4j.Com4jObject parent();

    @DISPID(751)
    @PropGet
    com4j.Com4jObject sheet();

    @DISPID(645)
    @PropGet
    boolean displayGridlines();

    @DISPID(645)
    @PropPut
    void displayGridlines(
        boolean rhs);

    @DISPID(644)
    @PropGet
    boolean displayFormulas();

    @DISPID(644)
    @PropPut
    void displayFormulas(
        boolean rhs);

    @DISPID(646)
    @PropGet
    boolean displayHeadings();

    @DISPID(646)
    @PropPut
    void displayHeadings(
        boolean rhs);

    @DISPID(647)
    @PropGet
    boolean displayOutline();

    @DISPID(647)
    @PropPut
    void displayOutline(
        boolean rhs);

    @DISPID(649)
    @PropGet
    boolean displayZeros();

    @DISPID(649)
    @PropPut
    void displayZeros(
        boolean rhs);

}
