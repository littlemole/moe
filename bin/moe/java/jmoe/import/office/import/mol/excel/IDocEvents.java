package mol.excel  ;

import com4j.*;

@IID("{00024411-0001-0000-C000-000000000046}")
public interface IDocEvents extends Com4jObject {
    @VTID(7)
    void selectionChange(
        mol.excel.Range target);

    @VTID(8)
    void beforeDoubleClick(
        mol.excel.Range target,
        Holder<Boolean> cancel);

    @VTID(9)
    void beforeRightClick(
        mol.excel.Range target,
        Holder<Boolean> cancel);

    @VTID(10)
    void activate();

    @VTID(11)
    void deactivate();

    @VTID(12)
    void calculate();

    @VTID(13)
    void change(
        mol.excel.Range target);

    @VTID(14)
    void followHyperlink(
        mol.excel.Hyperlink target);

    @VTID(15)
    void pivotTableUpdate(
        mol.excel.PivotTable target);

}
