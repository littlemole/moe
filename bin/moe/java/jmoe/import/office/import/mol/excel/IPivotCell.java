package mol.excel  ;

import com4j.*;

@IID("{00024458-0001-0000-C000-000000000046}")
public interface IPivotCell extends Com4jObject {
    @VTID(7)
    mol.excel._Application application();

    @VTID(8)
    mol.excel.XlCreator creator();

    @VTID(9)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

    @VTID(10)
    mol.excel.XlPivotCellType pivotCellType();

    @VTID(11)
    mol.excel.PivotTable pivotTable();

    @VTID(12)
    mol.excel.PivotField dataField();

    @VTID(13)
    mol.excel.PivotField pivotField();

    @VTID(14)
    mol.excel.PivotItem pivotItem();

    @VTID(15)
    mol.excel.PivotItemList rowItems();

    @VTID(16)
    mol.excel.PivotItemList columnItems();

    @VTID(17)
    mol.excel.Range range();

    @VTID(18)
    java.lang.String dummy18();

    @VTID(19)
    mol.excel.XlConsolidationFunction customSubtotalFunction();

    @VTID(20)
    mol.excel.PivotLine pivotRowLine();

    @VTID(21)
    mol.excel.PivotLine pivotColumnLine();

}
