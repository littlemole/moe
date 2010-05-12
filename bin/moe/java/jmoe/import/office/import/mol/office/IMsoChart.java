package mol.office  ;

import com4j.*;

@IID("{000C1709-0000-0000-C000-000000000046}")
public interface IMsoChart extends Com4jObject {
    @VTID(7)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

    @VTID(8)
    void hasTitle(
        boolean fTitle);

    @VTID(9)
    boolean hasTitle();

    @VTID(10)
    mol.office.IMsoChartTitle chartTitle();

    @VTID(11)
    int depthPercent();

    @VTID(12)
    void depthPercent(
        int pwDepthPercent);

    @VTID(13)
    int elevation();

    @VTID(14)
    void elevation(
        int pwElevation);

    @VTID(15)
    int gapDepth();

    @VTID(16)
    void gapDepth(
        int pwGapDepth);

    @VTID(17)
    int heightPercent();

    @VTID(18)
    void heightPercent(
        int pwHeightPercent);

    @VTID(19)
    int perspective();

    @VTID(20)
    void perspective(
        int pwPerspective);

    @VTID(21)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object rightAngleAxes();

    @VTID(22)
    void rightAngleAxes(
        @MarshalAs(NativeType.VARIANT) java.lang.Object pvarRightAngleAxes);

    @VTID(23)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object rotation();

    @VTID(24)
    void rotation(
        @MarshalAs(NativeType.VARIANT) java.lang.Object pvarRotation);

    @VTID(25)
    void displayBlanksAs(
        mol.office.XlDisplayBlanksAs pres);

    @VTID(26)
    mol.office.XlDisplayBlanksAs displayBlanksAs();

    @VTID(27)
    void protectData(
        boolean pres);

    @VTID(28)
    boolean protectData();

    @VTID(29)
    void protectFormatting(
        boolean pres);

    @VTID(30)
    boolean protectFormatting();

    @VTID(31)
    void protectGoalSeek(
        boolean pres);

    @VTID(32)
    boolean protectGoalSeek();

    @VTID(33)
    void protectSelection(
        boolean pres);

    @VTID(34)
    boolean protectSelection();

    @VTID(35)
    void protectChartObjects(
        boolean pres);

    @VTID(36)
    boolean protectChartObjects();

    @VTID(37)
    void unProtect(
        @MarshalAs(NativeType.VARIANT) java.lang.Object password);

    @VTID(38)
    void protect(
        @MarshalAs(NativeType.VARIANT) java.lang.Object password,
        @MarshalAs(NativeType.VARIANT) java.lang.Object drawingObjects,
        @MarshalAs(NativeType.VARIANT) java.lang.Object contents,
        @MarshalAs(NativeType.VARIANT) java.lang.Object scenarios,
        @MarshalAs(NativeType.VARIANT) java.lang.Object userInterfaceOnly);

    @VTID(39)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject chartGroups(
        java.lang.Object pvarIndex,
        @MarshalAs(NativeType.VARIANT) java.lang.Object varIgallery,
        int lcid);

    @VTID(40)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject seriesCollection(
        @MarshalAs(NativeType.VARIANT) java.lang.Object index);

    @VTID(41)
    void _ApplyDataLabels(
        mol.office.XlDataLabelsType type,
        @MarshalAs(NativeType.VARIANT) java.lang.Object iMsoLegendKey,
        @MarshalAs(NativeType.VARIANT) java.lang.Object autoText,
        @MarshalAs(NativeType.VARIANT) java.lang.Object hasLeaderLines);

    @VTID(42)
    int subType();

    @VTID(43)
    void subType(
        int rhs);

    @VTID(44)
    int type();

    @VTID(45)
    void type(
        int rhs);

    @VTID(46)
    mol.office.IMsoCorners corners();

    @VTID(47)
    void applyDataLabels(
        mol.office.XlDataLabelsType type,
        @MarshalAs(NativeType.VARIANT) java.lang.Object iMsoLegendKey,
        @MarshalAs(NativeType.VARIANT) java.lang.Object autoText,
        @MarshalAs(NativeType.VARIANT) java.lang.Object hasLeaderLines,
        @MarshalAs(NativeType.VARIANT) java.lang.Object showSeriesName,
        @MarshalAs(NativeType.VARIANT) java.lang.Object showCategoryName,
        @MarshalAs(NativeType.VARIANT) java.lang.Object showValue,
        @MarshalAs(NativeType.VARIANT) java.lang.Object showPercentage,
        @MarshalAs(NativeType.VARIANT) java.lang.Object showBubbleSize,
        @MarshalAs(NativeType.VARIANT) java.lang.Object separator);

    @VTID(48)
    mol.office.XlChartType chartType();

    @VTID(49)
    void chartType(
        mol.office.XlChartType rhs);

    @VTID(50)
    boolean hasDataTable();

    @VTID(51)
    void hasDataTable(
        boolean rhs);

    @VTID(52)
    void applyCustomType(
        mol.office.XlChartType chartType,
        @MarshalAs(NativeType.VARIANT) java.lang.Object typeName);

    @VTID(53)
    void getChartElement(
        int x,
        int y,
        Holder<Integer> elementID,
        Holder<Integer> arg1,
        Holder<Integer> arg2);

    @VTID(54)
    void setSourceData(
        java.lang.String source,
        @MarshalAs(NativeType.VARIANT) java.lang.Object plotBy);

    @VTID(55)
    mol.office.XlRowCol plotBy();

    @VTID(56)
    void plotBy(
        mol.office.XlRowCol plotBy);

    @VTID(57)
    boolean hasLegend();

    @VTID(58)
    void hasLegend(
        boolean rhs);

    @VTID(59)
    mol.office.IMsoLegend legend();

    @VTID(60)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject axes(
        @MarshalAs(NativeType.VARIANT) java.lang.Object type,
        mol.office.XlAxisGroup axisGroup);

    @VTID(61)
    void hasAxis(
        @MarshalAs(NativeType.VARIANT) java.lang.Object axisType,
        @MarshalAs(NativeType.VARIANT) java.lang.Object axisGroup,
        @MarshalAs(NativeType.VARIANT) java.lang.Object pval);

    @VTID(62)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object hasAxis(
        @MarshalAs(NativeType.VARIANT) java.lang.Object axisType,
        @MarshalAs(NativeType.VARIANT) java.lang.Object axisGroup);

    @VTID(63)
    mol.office.IMsoWalls walls(
        boolean fBackWall);

    @VTID(64)
    mol.office.IMsoFloor floor();

    @VTID(65)
    mol.office.IMsoPlotArea plotArea();

    @VTID(66)
    boolean plotVisibleOnly();

    @VTID(67)
    void plotVisibleOnly(
        boolean rhs);

    @VTID(68)
    mol.office.IMsoChartArea chartArea();

    @VTID(69)
    void autoFormat(
        int rGallery,
        @MarshalAs(NativeType.VARIANT) java.lang.Object varFormat);

    @VTID(70)
    boolean autoScaling();

    @VTID(71)
    void autoScaling(
        boolean f);

    @VTID(72)
    void setBackgroundPicture(
        java.lang.String bstr);

    @VTID(73)
    void chartWizard(
        @MarshalAs(NativeType.VARIANT) java.lang.Object varSource,
        @MarshalAs(NativeType.VARIANT) java.lang.Object varGallery,
        @MarshalAs(NativeType.VARIANT) java.lang.Object varFormat,
        @MarshalAs(NativeType.VARIANT) java.lang.Object varPlotBy,
        @MarshalAs(NativeType.VARIANT) java.lang.Object varCategoryLabels,
        @MarshalAs(NativeType.VARIANT) java.lang.Object varSeriesLabels,
        @MarshalAs(NativeType.VARIANT) java.lang.Object varHasLegend,
        @MarshalAs(NativeType.VARIANT) java.lang.Object varTitle,
        @MarshalAs(NativeType.VARIANT) java.lang.Object varCategoryTitle,
        @MarshalAs(NativeType.VARIANT) java.lang.Object varValueTitle,
        @MarshalAs(NativeType.VARIANT) java.lang.Object varExtraTitle,
        int localeID);

    @VTID(74)
    void copyPicture(
        int appearance,
        int format,
        int size,
        int localeID);

    @VTID(75)
    mol.office.IMsoDataTable dataTable();

    @VTID(76)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object evaluate(
        @MarshalAs(NativeType.VARIANT) java.lang.Object varName,
        int localeID,
        Holder<Integer> objType);

    @VTID(77)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object _Evaluate(
        @MarshalAs(NativeType.VARIANT) java.lang.Object varName,
        int localeID);

    @VTID(78)
    void paste(
        @MarshalAs(NativeType.VARIANT) java.lang.Object varType,
        int localeID);

    @VTID(79)
    mol.office.XlBarShape barShape();

    @VTID(80)
    void barShape(
        mol.office.XlBarShape pShape);

    @VTID(81)
    boolean export(
        java.lang.String bstr,
        @MarshalAs(NativeType.VARIANT) java.lang.Object varFilterName,
        @MarshalAs(NativeType.VARIANT) java.lang.Object varInteractive);

    @VTID(82)
    void setDefaultChart(
        @MarshalAs(NativeType.VARIANT) java.lang.Object varName);

    @VTID(83)
    void applyChartTemplate(
        java.lang.String bstrFileName);

    @VTID(84)
    void saveChartTemplate(
        java.lang.String bstrFileName);

    @VTID(85)
    mol.office.IMsoWalls sideWall();

    @VTID(86)
    mol.office.IMsoWalls backWall();

    @VTID(87)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object chartStyle();

    @VTID(88)
    void chartStyle(
        @MarshalAs(NativeType.VARIANT) java.lang.Object rhs);

    @VTID(89)
    void clearToMatchStyle();

    @VTID(90)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject pivotLayout();

    @VTID(91)
    boolean hasPivotFields();

    @VTID(92)
    void hasPivotFields(
        boolean rhs);

    @VTID(93)
    void refreshPivotTable();

    @VTID(94)
    void showDataLabelsOverMaximum(
        boolean pRHS);

    @VTID(95)
    boolean showDataLabelsOverMaximum();

    @VTID(96)
    void applyLayout(
        int layout,
        @MarshalAs(NativeType.VARIANT) java.lang.Object varChartType);

    @VTID(97)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject selection();

    @VTID(98)
    void refresh();

    @VTID(99)
    void setElement(
        mol.office.MsoChartElementType rhs);

    @VTID(100)
    mol.office.IMsoChartData chartData();

    @VTID(101)
    mol.office.IMsoChartFormat format();

    @VTID(102)
    mol.office.Shapes shapes();

    @VTID(102)
    @ReturnValue(defaultPropertyThrough={mol.office.Shapes.class})
    mol.office.Shape shapes(
        @MarshalAs(NativeType.VARIANT) java.lang.Object index);

}
