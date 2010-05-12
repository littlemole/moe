package mol.excel  ;

import com4j.*;

@IID("{0002440F-0001-0000-C000-000000000046}")
public interface IChartEvents extends Com4jObject {
    @VTID(7)
    void activate();

    @VTID(8)
    void deactivate();

    @VTID(9)
    void resize();

    @VTID(10)
    void mouseDown(
        int button,
        int shift,
        int x,
        int y);

    @VTID(11)
    void mouseUp(
        int button,
        int shift,
        int x,
        int y);

    @VTID(12)
    void mouseMove(
        int button,
        int shift,
        int x,
        int y);

    @VTID(13)
    void beforeRightClick(
        Holder<Boolean> cancel);

    @VTID(14)
    void dragPlot();

    @VTID(15)
    void dragOver();

    @VTID(16)
    void beforeDoubleClick(
        int elementID,
        int arg1,
        int arg2,
        Holder<Boolean> cancel);

    @VTID(17)
    void select(
        int elementID,
        int arg1,
        int arg2);

    @VTID(18)
    void seriesChange(
        int seriesIndex,
        int pointIndex);

    @VTID(19)
    void calculate();

}
