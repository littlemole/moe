package mol.excel.events;

import com4j.*;

@IID("{0002440F-0000-0000-C000-000000000046}")
public abstract class ChartEvents {
    @DISPID(304)
    public void activate() {
            throw new UnsupportedOperationException();
    }

    @DISPID(1530)
    public void deactivate() {
            throw new UnsupportedOperationException();
    }

    @DISPID(256)
    public void resize() {
            throw new UnsupportedOperationException();
    }

    @DISPID(1531)
    public void mouseDown(
        int button,
        int shift,
        int x,
        int y) {
            throw new UnsupportedOperationException();
    }

    @DISPID(1532)
    public void mouseUp(
        int button,
        int shift,
        int x,
        int y) {
            throw new UnsupportedOperationException();
    }

    @DISPID(1533)
    public void mouseMove(
        int button,
        int shift,
        int x,
        int y) {
            throw new UnsupportedOperationException();
    }

    @DISPID(1534)
    public void beforeRightClick(
        Holder<Boolean> cancel) {
            throw new UnsupportedOperationException();
    }

    @DISPID(1535)
    public void dragPlot() {
            throw new UnsupportedOperationException();
    }

    @DISPID(1536)
    public void dragOver() {
            throw new UnsupportedOperationException();
    }

    @DISPID(1537)
    public void beforeDoubleClick(
        int elementID,
        int arg1,
        int arg2,
        Holder<Boolean> cancel) {
            throw new UnsupportedOperationException();
    }

    @DISPID(235)
    public void select(
        int elementID,
        int arg1,
        int arg2) {
            throw new UnsupportedOperationException();
    }

    @DISPID(1538)
    public void seriesChange(
        int seriesIndex,
        int pointIndex) {
            throw new UnsupportedOperationException();
    }

    @DISPID(279)
    public void calculate() {
            throw new UnsupportedOperationException();
    }

}
