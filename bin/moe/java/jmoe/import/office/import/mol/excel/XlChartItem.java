package mol.excel  ;

import com4j.*;

public enum XlChartItem implements ComEnum {
    xlDataLabel(0),
    xlChartArea(2),
    xlSeries(3),
    xlChartTitle(4),
    xlWalls(5),
    xlCorners(6),
    xlDataTable(7),
    xlTrendline(8),
    xlErrorBars(9),
    xlXErrorBars(10),
    xlYErrorBars(11),
    xlLegendEntry(12),
    xlLegendKey(13),
    xlShape(14),
    xlMajorGridlines(15),
    xlMinorGridlines(16),
    xlAxisTitle(17),
    xlUpBars(18),
    xlPlotArea(19),
    xlDownBars(20),
    xlAxis(21),
    xlSeriesLines(22),
    xlFloor(23),
    xlLegend(24),
    xlHiLoLines(25),
    xlDropLines(26),
    xlRadarAxisLabels(27),
    xlNothing(28),
    xlLeaderLines(29),
    xlDisplayUnitLabel(30),
    xlPivotChartFieldButton(31),
    xlPivotChartDropZone(32),
    ;

    private final int value;
    XlChartItem(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
