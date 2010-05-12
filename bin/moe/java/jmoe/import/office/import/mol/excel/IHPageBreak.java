package mol.excel  ;

import com4j.*;

@IID("{00024401-0001-0000-C000-000000000046}")
public interface IHPageBreak extends Com4jObject {
    @VTID(7)
    mol.excel._Application application();

    @VTID(8)
    mol.excel.XlCreator creator();

    @VTID(9)
    mol.excel._Worksheet parent();

    @VTID(10)
    void delete();

    @VTID(11)
    void dragOff(
        mol.excel.XlDirection direction,
        int regionIndex);

    @VTID(12)
    mol.excel.XlPageBreak type();

    @VTID(13)
    void type(
        mol.excel.XlPageBreak rhs);

    @VTID(14)
    mol.excel.XlPageBreakExtent extent();

    @VTID(15)
    mol.excel.Range location();

    @VTID(16)
    void location(
        mol.excel.Range rhs);

}
