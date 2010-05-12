package mol.excel  ;

import com4j.*;

@IID("{00020400-0000-0000-C000-000000000046}")
public interface Outline extends Com4jObject {
    @DISPID(148)
    @PropGet
    mol.excel._Application application();

    @DISPID(149)
    @PropGet
    mol.excel.XlCreator creator();

    @DISPID(150)
    @PropGet
    com4j.Com4jObject parent();

    @DISPID(959)
    @PropGet
    boolean automaticStyles();

    @DISPID(959)
    @PropPut
    void automaticStyles(
        boolean rhs);

    @DISPID(960)
    java.lang.Object showLevels(
        java.lang.Object rowLevels,
        java.lang.Object columnLevels);

    @DISPID(961)
    @PropGet
    mol.excel.XlSummaryColumn summaryColumn();

    @DISPID(961)
    @PropPut
    void summaryColumn(
        mol.excel.XlSummaryColumn rhs);

    @DISPID(902)
    @PropGet
    mol.excel.XlSummaryRow summaryRow();

    @DISPID(902)
    @PropPut
    void summaryRow(
        mol.excel.XlSummaryRow rhs);

}
