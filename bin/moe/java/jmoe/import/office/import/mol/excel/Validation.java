package mol.excel  ;

import com4j.*;

@IID("{00020400-0000-0000-C000-000000000046}")
public interface Validation extends Com4jObject {
    @DISPID(148)
    @PropGet
    mol.excel._Application application();

    @DISPID(149)
    @PropGet
    mol.excel.XlCreator creator();

    @DISPID(150)
    @PropGet
    com4j.Com4jObject parent();

    @DISPID(181)
    void add(
        mol.excel.XlDVType type,
        java.lang.Object alertStyle,
        java.lang.Object operator,
        java.lang.Object formula1,
        java.lang.Object formula2);

    @DISPID(1605)
    @PropGet
    int alertStyle();

    @DISPID(1606)
    @PropGet
    boolean ignoreBlank();

    @DISPID(1606)
    @PropPut
    void ignoreBlank(
        boolean rhs);

    @DISPID(1607)
    @PropGet
    int imeMode();

    @DISPID(1607)
    @PropPut
    void imeMode(
        int rhs);

    @DISPID(1608)
    @PropGet
    boolean inCellDropdown();

    @DISPID(1608)
    @PropPut
    void inCellDropdown(
        boolean rhs);

    @DISPID(117)
    void delete();

    @DISPID(1609)
    @PropGet
    java.lang.String errorMessage();

    @DISPID(1609)
    @PropPut
    void errorMessage(
        java.lang.String rhs);

    @DISPID(1610)
    @PropGet
    java.lang.String errorTitle();

    @DISPID(1610)
    @PropPut
    void errorTitle(
        java.lang.String rhs);

    @DISPID(1611)
    @PropGet
    java.lang.String inputMessage();

    @DISPID(1611)
    @PropPut
    void inputMessage(
        java.lang.String rhs);

    @DISPID(1612)
    @PropGet
    java.lang.String inputTitle();

    @DISPID(1612)
    @PropPut
    void inputTitle(
        java.lang.String rhs);

    @DISPID(1579)
    @PropGet
    java.lang.String formula1();

    @DISPID(1580)
    @PropGet
    java.lang.String formula2();

    @DISPID(1581)
    void modify(
        java.lang.Object type,
        java.lang.Object alertStyle,
        java.lang.Object operator,
        java.lang.Object formula1,
        java.lang.Object formula2);

    @DISPID(797)
    @PropGet
    int operator();

    @DISPID(1613)
    @PropGet
    boolean showError();

    @DISPID(1613)
    @PropPut
    void showError(
        boolean rhs);

    @DISPID(1614)
    @PropGet
    boolean showInput();

    @DISPID(1614)
    @PropPut
    void showInput(
        boolean rhs);

    @DISPID(108)
    @PropGet
    int type();

    @DISPID(6)
    @PropGet
    boolean value();

}
