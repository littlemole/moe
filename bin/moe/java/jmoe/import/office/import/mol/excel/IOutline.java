package mol.excel  ;

import com4j.*;

@IID("{000208AB-0001-0000-C000-000000000046}")
public interface IOutline extends Com4jObject {
    @VTID(7)
    mol.excel._Application application();

    @VTID(8)
    mol.excel.XlCreator creator();

    @VTID(9)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

    @VTID(10)
    boolean automaticStyles();

    @VTID(11)
    void automaticStyles(
        boolean rhs);

    @VTID(12)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object showLevels(
        @MarshalAs(NativeType.VARIANT) java.lang.Object rowLevels,
        @MarshalAs(NativeType.VARIANT) java.lang.Object columnLevels);

    @VTID(13)
    mol.excel.XlSummaryColumn summaryColumn();

    @VTID(14)
    void summaryColumn(
        mol.excel.XlSummaryColumn rhs);

    @VTID(15)
    mol.excel.XlSummaryRow summaryRow();

    @VTID(16)
    void summaryRow(
        mol.excel.XlSummaryRow rhs);

}
