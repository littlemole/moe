package mol.excel  ;

import com4j.*;

@IID("{00020400-0000-0000-C000-000000000046}")
public interface PivotCell extends Com4jObject {
    @DISPID(148)
    @PropGet
    mol.excel._Application application();

    @DISPID(149)
    @PropGet
    mol.excel.XlCreator creator();

    @DISPID(150)
    @PropGet
    com4j.Com4jObject parent();

    @DISPID(2189)
    @PropGet
    mol.excel.XlPivotCellType pivotCellType();

    @DISPID(716)
    @PropGet
    mol.excel.PivotTable pivotTable();

    @DISPID(2091)
    @PropGet
    mol.excel.PivotField dataField();

    @DISPID(731)
    @PropGet
    mol.excel.PivotField pivotField();

    @DISPID(740)
    @PropGet
    mol.excel.PivotItem pivotItem();

    @DISPID(2190)
    @PropGet
    mol.excel.PivotItemList rowItems();

    @DISPID(2191)
    @PropGet
    mol.excel.PivotItemList columnItems();

    @DISPID(197)
    @PropGet
    mol.excel.Range range();

    @DISPID(2295)
    @PropGet
    java.lang.String dummy18();

    @DISPID(2193)
    @PropGet
    mol.excel.XlConsolidationFunction customSubtotalFunction();

    @DISPID(2673)
    @PropGet
    mol.excel.PivotLine pivotRowLine();

    @DISPID(2674)
    @PropGet
    mol.excel.PivotLine pivotColumnLine();

}
