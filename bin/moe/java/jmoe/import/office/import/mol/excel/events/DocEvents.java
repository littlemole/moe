package mol.excel.events;

import com4j.*;

@IID("{00024411-0000-0000-C000-000000000046}")
public abstract class DocEvents {
    @DISPID(1543)
    public void selectionChange(
        mol.excel.Range target) {
            throw new UnsupportedOperationException();
    }

    @DISPID(1537)
    public void beforeDoubleClick(
        mol.excel.Range target,
        Holder<Boolean> cancel) {
            throw new UnsupportedOperationException();
    }

    @DISPID(1534)
    public void beforeRightClick(
        mol.excel.Range target,
        Holder<Boolean> cancel) {
            throw new UnsupportedOperationException();
    }

    @DISPID(304)
    public void activate() {
            throw new UnsupportedOperationException();
    }

    @DISPID(1530)
    public void deactivate() {
            throw new UnsupportedOperationException();
    }

    @DISPID(279)
    public void calculate() {
            throw new UnsupportedOperationException();
    }

    @DISPID(1545)
    public void change(
        mol.excel.Range target) {
            throw new UnsupportedOperationException();
    }

    @DISPID(1470)
    public void followHyperlink(
        mol.excel.Hyperlink target) {
            throw new UnsupportedOperationException();
    }

    @DISPID(2156)
    public void pivotTableUpdate(
        mol.excel.PivotTable target) {
            throw new UnsupportedOperationException();
    }

}
