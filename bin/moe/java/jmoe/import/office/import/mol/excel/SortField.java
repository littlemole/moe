package mol.excel  ;

import com4j.*;

@IID("{00020400-0000-0000-C000-000000000046}")
public interface SortField extends Com4jObject {
    @DISPID(148)
    @PropGet
    mol.excel._Application application();

    @DISPID(149)
    @PropGet
    mol.excel.XlCreator creator();

    @DISPID(150)
    @PropGet
    com4j.Com4jObject parent();

    @DISPID(2741)
    @PropGet
    mol.excel.XlSortOn sortOn();

    @DISPID(2741)
    @PropPut
    void sortOn(
        mol.excel.XlSortOn rhs);

    @DISPID(2742)
    @PropGet
    com4j.Com4jObject sortOnValue();

    @DISPID(155)
    @PropGet
    mol.excel.Range key();

    @DISPID(192)
    @PropGet
    mol.excel.XlSortOrder order();

    @DISPID(192)
    @PropPut
    void order(
        mol.excel.XlSortOrder rhs);

    @DISPID(2743)
    @PropGet
    java.lang.Object customOrder();

    @DISPID(2743)
    @PropPut
    void customOrder(
        java.lang.Object rhs);

    @DISPID(2744)
    @PropGet
    mol.excel.XlSortDataOption dataOption();

    @DISPID(2744)
    @PropPut
    void dataOption(
        mol.excel.XlSortDataOption rhs);

    @DISPID(985)
    @PropGet
    int priority();

    @DISPID(985)
    @PropPut
    void priority(
        int rhs);

    @DISPID(117)
    void delete();

    @DISPID(2745)
    void modifyKey(
        mol.excel.Range key);

    @DISPID(2746)
    void setIcon(
        mol.excel.Icon icon);

}
