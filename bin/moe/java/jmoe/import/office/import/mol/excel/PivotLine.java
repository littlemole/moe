package mol.excel  ;

import com4j.*;

@IID("{00020400-0000-0000-C000-000000000046}")
public interface PivotLine extends Com4jObject {
    @DISPID(148)
    @PropGet
    mol.excel._Application application();

    @DISPID(149)
    @PropGet
    mol.excel.XlCreator creator();

    @DISPID(150)
    @PropGet
    com4j.Com4jObject parent();

    @DISPID(2683)
    @PropGet
    mol.excel.XlPivotLineType lineType();

    @DISPID(133)
    @PropGet
    int position();

    @DISPID(2684)
    @PropGet
    mol.excel.PivotLineCells pivotLineCells();

}
