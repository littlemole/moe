package mol.excel  ;

import com4j.*;

@IID("{00020400-0000-0000-C000-000000000046}")
public interface Protection extends Com4jObject {
    @DISPID(2032)
    @PropGet
    boolean allowFormattingCells();

    @DISPID(2033)
    @PropGet
    boolean allowFormattingColumns();

    @DISPID(2034)
    @PropGet
    boolean allowFormattingRows();

    @DISPID(2035)
    @PropGet
    boolean allowInsertingColumns();

    @DISPID(2036)
    @PropGet
    boolean allowInsertingRows();

    @DISPID(2037)
    @PropGet
    boolean allowInsertingHyperlinks();

    @DISPID(2038)
    @PropGet
    boolean allowDeletingColumns();

    @DISPID(2039)
    @PropGet
    boolean allowDeletingRows();

    @DISPID(2040)
    @PropGet
    boolean allowSorting();

    @DISPID(2041)
    @PropGet
    boolean allowFiltering();

    @DISPID(2042)
    @PropGet
    boolean allowUsingPivotTables();

    @DISPID(2236)
    @PropGet
    mol.excel.AllowEditRanges allowEditRanges();

}
