package mol.excel  ;

import com4j.*;

@IID("{00020400-0000-0000-C000-000000000046}")
public interface ListColumn extends Com4jObject {
    @DISPID(148)
    @PropGet
    mol.excel._Application application();

    @DISPID(149)
    @PropGet
    mol.excel.XlCreator creator();

    @DISPID(150)
    @PropGet
    com4j.Com4jObject parent();

    @DISPID(117)
    void delete();

    @DISPID(0)
    @PropGet
    @DefaultMethod
    java.lang.String _Default();

    @DISPID(2321)
    @PropGet
    mol.excel.ListDataFormat listDataFormat();

    @DISPID(486)
    @PropGet
    int index();

    @DISPID(110)
    @PropGet
    java.lang.String name();

    @DISPID(110)
    @PropPut
    void name(
        java.lang.String rhs);

    @DISPID(197)
    @PropGet
    mol.excel.Range range();

    @DISPID(2322)
    @PropGet
    mol.excel.XlTotalsCalculation totalsCalculation();

    @DISPID(2322)
    @PropPut
    void totalsCalculation(
        mol.excel.XlTotalsCalculation rhs);

    @DISPID(2258)
    @PropGet
    mol.excel.XPath xPath();

    @DISPID(2323)
    @PropGet
    java.lang.String sharePointFormula();

    @DISPID(705)
    @PropGet
    mol.excel.Range dataBodyRange();

    @DISPID(2681)
    @PropGet
    mol.excel.Range total();

}
