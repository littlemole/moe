package mol.excel  ;

import com4j.*;

@IID("{00020400-0000-0000-C000-000000000046}")
public interface VPageBreak extends Com4jObject {
    @DISPID(148)
    @PropGet
    mol.excel._Application application();

    @DISPID(149)
    @PropGet
    mol.excel.XlCreator creator();

    @DISPID(150)
    @PropGet
    mol.excel._Worksheet parent();

    @DISPID(117)
    void delete();

    @DISPID(1420)
    void dragOff(
        mol.excel.XlDirection direction,
        int regionIndex);

    @DISPID(108)
    @PropGet
    mol.excel.XlPageBreak type();

    @DISPID(108)
    @PropPut
    void type(
        mol.excel.XlPageBreak rhs);

    @DISPID(1422)
    @PropGet
    mol.excel.XlPageBreakExtent extent();

    @DISPID(1397)
    @PropGet
    mol.excel.Range location();

    @DISPID(1397)
    @PropPut
    void location(
        mol.excel.Range rhs);

}
