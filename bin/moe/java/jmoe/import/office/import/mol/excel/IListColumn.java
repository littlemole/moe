package mol.excel  ;

import com4j.*;

@IID("{00024473-0001-0000-C000-000000000046}")
public interface IListColumn extends Com4jObject {
    @VTID(7)
    mol.excel._Application application();

    @VTID(8)
    mol.excel.XlCreator creator();

    @VTID(9)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

    @VTID(10)
    void delete();

    @VTID(11)
    @DefaultMethod
    java.lang.String _Default();

    @VTID(12)
    mol.excel.ListDataFormat listDataFormat();

    @VTID(13)
    int index();

    @VTID(14)
    java.lang.String name();

    @VTID(15)
    void name(
        java.lang.String rhs);

    @VTID(16)
    mol.excel.Range range();

    @VTID(17)
    mol.excel.XlTotalsCalculation totalsCalculation();

    @VTID(18)
    void totalsCalculation(
        mol.excel.XlTotalsCalculation rhs);

    @VTID(19)
    mol.excel.XPath xPath();

    @VTID(20)
    java.lang.String sharePointFormula();

    @VTID(21)
    mol.excel.Range dataBodyRange();

    @VTID(22)
    mol.excel.Range total();

}
