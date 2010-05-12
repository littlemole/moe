package mol.excel  ;

import com4j.*;

@IID("{00024467-0001-0000-C000-000000000046}")
public interface IProtection extends Com4jObject {
    @VTID(7)
    boolean allowFormattingCells();

    @VTID(8)
    boolean allowFormattingColumns();

    @VTID(9)
    boolean allowFormattingRows();

    @VTID(10)
    boolean allowInsertingColumns();

    @VTID(11)
    boolean allowInsertingRows();

    @VTID(12)
    boolean allowInsertingHyperlinks();

    @VTID(13)
    boolean allowDeletingColumns();

    @VTID(14)
    boolean allowDeletingRows();

    @VTID(15)
    boolean allowSorting();

    @VTID(16)
    boolean allowFiltering();

    @VTID(17)
    boolean allowUsingPivotTables();

    @VTID(18)
    mol.excel.AllowEditRanges allowEditRanges();

}
