package mol.excel  ;

import com4j.*;
import mol.office.*;
import mol.vba.*;

@IID("{000208D6-0000-0000-C000-000000000046}")
public interface _Chart extends Com4jObject {
    @VTID(7)
    mol.excel._Application application();

    @VTID(8)
    mol.excel.XlCreator creator();

    @VTID(9)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

    @VTID(10)
    void activate(
        int lcid);

    @VTID(11)
    void copy(
        @MarshalAs(NativeType.VARIANT) java.lang.Object before,
        @MarshalAs(NativeType.VARIANT) java.lang.Object after,
        int lcid);

    @VTID(12)
    void delete(
        int lcid);

    @VTID(13)
    java.lang.String codeName();

    @VTID(14)
    java.lang.String _CodeName();

    @VTID(15)
    void _CodeName(
        java.lang.String rhs);

    @VTID(16)
    int index(
        int lcid);

    @VTID(17)
    void move(
        @MarshalAs(NativeType.VARIANT) java.lang.Object before,
        @MarshalAs(NativeType.VARIANT) java.lang.Object after,
        int lcid);

    @VTID(18)
    java.lang.String name();

    @VTID(19)
    void name(
        java.lang.String rhs);

    @VTID(20)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject next();

    @VTID(21)
    java.lang.String onDoubleClick(
        int lcid);

    @VTID(22)
    void onDoubleClick(
        int lcid,
        java.lang.String rhs);

    @VTID(23)
    java.lang.String onSheetActivate(
        int lcid);

    @VTID(24)
    void onSheetActivate(
        int lcid,
        java.lang.String rhs);

    @VTID(25)
    java.lang.String onSheetDeactivate(
        int lcid);

    @VTID(26)
    void onSheetDeactivate(
        int lcid,
        java.lang.String rhs);

    @VTID(27)
    mol.excel.PageSetup pageSetup();

    @VTID(28)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject previous();

    @VTID(29)
    void __PrintOut(
        @MarshalAs(NativeType.VARIANT) java.lang.Object from,
        @MarshalAs(NativeType.VARIANT) java.lang.Object to,
        @MarshalAs(NativeType.VARIANT) java.lang.Object copies,
        @MarshalAs(NativeType.VARIANT) java.lang.Object preview,
        @MarshalAs(NativeType.VARIANT) java.lang.Object activePrinter,
        @MarshalAs(NativeType.VARIANT) java.lang.Object printToFile,
        @MarshalAs(NativeType.VARIANT) java.lang.Object collate,
        int lcid);

    @VTID(30)
    void printPreview(
        @MarshalAs(NativeType.VARIANT) java.lang.Object enableChanges,
        int lcid);

    @VTID(31)
    void _Protect(
        @MarshalAs(NativeType.VARIANT) java.lang.Object password,
        @MarshalAs(NativeType.VARIANT) java.lang.Object drawingObjects,
        @MarshalAs(NativeType.VARIANT) java.lang.Object contents,
        @MarshalAs(NativeType.VARIANT) java.lang.Object scenarios,
        @MarshalAs(NativeType.VARIANT) java.lang.Object userInterfaceOnly,
        int lcid);

    @VTID(32)
    boolean protectContents(
        int lcid);

    @VTID(33)
    boolean protectDrawingObjects(
        int lcid);

    @VTID(34)
    boolean protectionMode(
        int lcid);

    @VTID(35)
    void _Dummy23();

    @VTID(36)
    void _SaveAs(
        java.lang.String filename,
        @MarshalAs(NativeType.VARIANT) java.lang.Object fileFormat,
        @MarshalAs(NativeType.VARIANT) java.lang.Object password,
        @MarshalAs(NativeType.VARIANT) java.lang.Object writeResPassword,
        @MarshalAs(NativeType.VARIANT) java.lang.Object readOnlyRecommended,
        @MarshalAs(NativeType.VARIANT) java.lang.Object createBackup,
        @MarshalAs(NativeType.VARIANT) java.lang.Object addToMru,
        @MarshalAs(NativeType.VARIANT) java.lang.Object textCodepage,
        @MarshalAs(NativeType.VARIANT) java.lang.Object textVisualLayout,
        int lcid);

    @VTID(37)
    void select(
        @MarshalAs(NativeType.VARIANT) java.lang.Object replace,
        int lcid);

    @VTID(38)
    void unprotect(
        @MarshalAs(NativeType.VARIANT) java.lang.Object password,
        int lcid);

    @VTID(39)
    mol.excel.XlSheetVisibility visible(
        int lcid);

    @VTID(40)
    void visible(
        int lcid,
        mol.excel.XlSheetVisibility rhs);

    @VTID(41)
    mol.excel.Shapes shapes();

    @VTID(42)
    void _ApplyDataLabels(
        mol.excel.XlDataLabelsType type,
        @MarshalAs(NativeType.VARIANT) java.lang.Object legendKey,
        @MarshalAs(NativeType.VARIANT) java.lang.Object autoText,
        @MarshalAs(NativeType.VARIANT) java.lang.Object hasLeaderLines,
        int lcid);

    @VTID(43)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject arcs(
        @MarshalAs(NativeType.VARIANT) java.lang.Object index,
        int lcid);

    @VTID(44)
    mol.excel.ChartGroup area3DGroup(
        int lcid);

    @VTID(45)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject areaGroups(
        @MarshalAs(NativeType.VARIANT) java.lang.Object index,
        int lcid);

    @VTID(46)
    void autoFormat(
        int gallery,
        @MarshalAs(NativeType.VARIANT) java.lang.Object format);

    @VTID(47)
    boolean autoScaling(
        int lcid);

    @VTID(48)
    void autoScaling(
        int lcid,
        boolean rhs);

    @VTID(49)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject axes(
        @MarshalAs(NativeType.VARIANT) java.lang.Object type,
        mol.excel.XlAxisGroup axisGroup,
        int lcid);

    @VTID(50)
    void setBackgroundPicture(
        java.lang.String filename);

    @VTID(51)
    mol.excel.ChartGroup bar3DGroup(
        int lcid);

    @VTID(52)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject barGroups(
        @MarshalAs(NativeType.VARIANT) java.lang.Object index,
        int lcid);

    @VTID(53)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject buttons(
        @MarshalAs(NativeType.VARIANT) java.lang.Object index,
        int lcid);

    @VTID(54)
    mol.excel.ChartArea chartArea(
        int lcid);

    @VTID(55)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject chartGroups(
        @MarshalAs(NativeType.VARIANT) java.lang.Object index,
        int lcid);

    @VTID(56)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject chartObjects(
        @MarshalAs(NativeType.VARIANT) java.lang.Object index,
        int lcid);

    @VTID(57)
    mol.excel.ChartTitle chartTitle(
        int lcid);

    @VTID(58)
    void chartWizard(
        @MarshalAs(NativeType.VARIANT) java.lang.Object source,
        @MarshalAs(NativeType.VARIANT) java.lang.Object gallery,
        @MarshalAs(NativeType.VARIANT) java.lang.Object format,
        @MarshalAs(NativeType.VARIANT) java.lang.Object plotBy,
        @MarshalAs(NativeType.VARIANT) java.lang.Object categoryLabels,
        @MarshalAs(NativeType.VARIANT) java.lang.Object seriesLabels,
        @MarshalAs(NativeType.VARIANT) java.lang.Object hasLegend,
        @MarshalAs(NativeType.VARIANT) java.lang.Object title,
        @MarshalAs(NativeType.VARIANT) java.lang.Object categoryTitle,
        @MarshalAs(NativeType.VARIANT) java.lang.Object valueTitle,
        @MarshalAs(NativeType.VARIANT) java.lang.Object extraTitle,
        int lcid);

    @VTID(59)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject checkBoxes(
        @MarshalAs(NativeType.VARIANT) java.lang.Object index,
        int lcid);

    @VTID(60)
    void checkSpelling(
        @MarshalAs(NativeType.VARIANT) java.lang.Object customDictionary,
        @MarshalAs(NativeType.VARIANT) java.lang.Object ignoreUppercase,
        @MarshalAs(NativeType.VARIANT) java.lang.Object alwaysSuggest,
        @MarshalAs(NativeType.VARIANT) java.lang.Object spellLang,
        int lcid);

    @VTID(61)
    mol.excel.ChartGroup column3DGroup(
        int lcid);

    @VTID(62)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject columnGroups(
        @MarshalAs(NativeType.VARIANT) java.lang.Object index,
        int lcid);

    @VTID(63)
    void copyPicture(
        mol.excel.XlPictureAppearance appearance,
        mol.excel.XlCopyPictureFormat format,
        mol.excel.XlPictureAppearance size,
        int lcid);

    @VTID(64)
    mol.excel.Corners corners(
        int lcid);

    @VTID(65)
    void createPublisher(
        @MarshalAs(NativeType.VARIANT) java.lang.Object edition,
        mol.excel.XlPictureAppearance appearance,
        mol.excel.XlPictureAppearance size,
        @MarshalAs(NativeType.VARIANT) java.lang.Object containsPICT,
        @MarshalAs(NativeType.VARIANT) java.lang.Object containsBIFF,
        @MarshalAs(NativeType.VARIANT) java.lang.Object containsRTF,
        @MarshalAs(NativeType.VARIANT) java.lang.Object containsVALU,
        int lcid);

    @VTID(66)
    mol.excel.DataTable dataTable();

    @VTID(67)
    int depthPercent(
        int lcid);

    @VTID(68)
    void depthPercent(
        int lcid,
        int rhs);

    @VTID(69)
    void deselect(
        int lcid);

    @VTID(70)
    mol.excel.XlDisplayBlanksAs displayBlanksAs(
        int lcid);

    @VTID(71)
    void displayBlanksAs(
        int lcid,
        mol.excel.XlDisplayBlanksAs rhs);

    @VTID(72)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject doughnutGroups(
        @MarshalAs(NativeType.VARIANT) java.lang.Object index,
        int lcid);

    @VTID(73)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject drawings(
        @MarshalAs(NativeType.VARIANT) java.lang.Object index,
        int lcid);

    @VTID(74)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject drawingObjects(
        @MarshalAs(NativeType.VARIANT) java.lang.Object index,
        int lcid);

    @VTID(75)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject dropDowns(
        @MarshalAs(NativeType.VARIANT) java.lang.Object index,
        int lcid);

    @VTID(76)
    int elevation(
        int lcid);

    @VTID(77)
    void elevation(
        int lcid,
        int rhs);

    @VTID(78)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object evaluate(
        @MarshalAs(NativeType.VARIANT) java.lang.Object name,
        int lcid);

    @VTID(79)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object _Evaluate(
        @MarshalAs(NativeType.VARIANT) java.lang.Object name,
        int lcid);

    @VTID(80)
    mol.excel.Floor floor(
        int lcid);

    @VTID(81)
    int gapDepth(
        int lcid);

    @VTID(82)
    void gapDepth(
        int lcid,
        int rhs);

    @VTID(83)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject groupBoxes(
        @MarshalAs(NativeType.VARIANT) java.lang.Object index,
        int lcid);

    @VTID(84)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject groupObjects(
        @MarshalAs(NativeType.VARIANT) java.lang.Object index,
        int lcid);

    @VTID(85)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object hasAxis(
        @MarshalAs(NativeType.VARIANT) java.lang.Object index1,
        @MarshalAs(NativeType.VARIANT) java.lang.Object index2,
        int lcid);

    @VTID(86)
    void hasAxis(
        @MarshalAs(NativeType.VARIANT) java.lang.Object index1,
        @MarshalAs(NativeType.VARIANT) java.lang.Object index2,
        int lcid,
        @MarshalAs(NativeType.VARIANT) java.lang.Object rhs);

    @VTID(87)
    boolean hasDataTable();

    @VTID(88)
    void hasDataTable(
        boolean rhs);

    @VTID(89)
    boolean hasLegend(
        int lcid);

    @VTID(90)
    void hasLegend(
        int lcid,
        boolean rhs);

    @VTID(91)
    boolean hasTitle(
        int lcid);

    @VTID(92)
    void hasTitle(
        int lcid,
        boolean rhs);

    @VTID(93)
    int heightPercent(
        int lcid);

    @VTID(94)
    void heightPercent(
        int lcid,
        int rhs);

    @VTID(95)
    mol.excel.Hyperlinks hyperlinks();

    @VTID(96)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject labels(
        @MarshalAs(NativeType.VARIANT) java.lang.Object index,
        int lcid);

    @VTID(97)
    mol.excel.Legend legend(
        int lcid);

    @VTID(98)
    mol.excel.ChartGroup line3DGroup(
        int lcid);

    @VTID(99)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject lineGroups(
        @MarshalAs(NativeType.VARIANT) java.lang.Object index,
        int lcid);

    @VTID(100)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject lines(
        @MarshalAs(NativeType.VARIANT) java.lang.Object index,
        int lcid);

    @VTID(101)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject listBoxes(
        @MarshalAs(NativeType.VARIANT) java.lang.Object index,
        int lcid);

    @VTID(102)
    mol.excel._Chart location(
        mol.excel.XlChartLocation where,
        @MarshalAs(NativeType.VARIANT) java.lang.Object name);

    @VTID(103)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject oleObjects(
        @MarshalAs(NativeType.VARIANT) java.lang.Object index,
        int lcid);

    @VTID(104)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject optionButtons(
        @MarshalAs(NativeType.VARIANT) java.lang.Object index,
        int lcid);

    @VTID(105)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject ovals(
        @MarshalAs(NativeType.VARIANT) java.lang.Object index,
        int lcid);

    @VTID(106)
    void paste(
        @MarshalAs(NativeType.VARIANT) java.lang.Object type,
        int lcid);

    @VTID(107)
    int perspective(
        int lcid);

    @VTID(108)
    void perspective(
        int lcid,
        int rhs);

    @VTID(109)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject pictures(
        @MarshalAs(NativeType.VARIANT) java.lang.Object index,
        int lcid);

    @VTID(110)
    mol.excel.ChartGroup pie3DGroup(
        int lcid);

    @VTID(111)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject pieGroups(
        @MarshalAs(NativeType.VARIANT) java.lang.Object index,
        int lcid);

    @VTID(112)
    mol.excel.PlotArea plotArea(
        int lcid);

    @VTID(113)
    boolean plotVisibleOnly(
        int lcid);

    @VTID(114)
    void plotVisibleOnly(
        int lcid,
        boolean rhs);

    @VTID(115)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject radarGroups(
        @MarshalAs(NativeType.VARIANT) java.lang.Object index,
        int lcid);

    @VTID(116)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject rectangles(
        @MarshalAs(NativeType.VARIANT) java.lang.Object index,
        int lcid);

    @VTID(117)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object rightAngleAxes(
        int lcid);

    @VTID(118)
    void rightAngleAxes(
        int lcid,
        @MarshalAs(NativeType.VARIANT) java.lang.Object rhs);

    @VTID(119)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object rotation(
        int lcid);

    @VTID(120)
    void rotation(
        int lcid,
        @MarshalAs(NativeType.VARIANT) java.lang.Object rhs);

    @VTID(121)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject scrollBars(
        @MarshalAs(NativeType.VARIANT) java.lang.Object index,
        int lcid);

    @VTID(122)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject seriesCollection(
        @MarshalAs(NativeType.VARIANT) java.lang.Object index,
        int lcid);

    @VTID(123)
    boolean sizeWithWindow(
        int lcid);

    @VTID(124)
    void sizeWithWindow(
        int lcid,
        boolean rhs);

    @VTID(125)
    boolean showWindow();

    @VTID(126)
    void showWindow(
        boolean rhs);

    @VTID(127)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject spinners(
        @MarshalAs(NativeType.VARIANT) java.lang.Object index,
        int lcid);

    @VTID(128)
    int subType(
        int lcid);

    @VTID(129)
    void subType(
        int lcid,
        int rhs);

    @VTID(130)
    mol.excel.ChartGroup surfaceGroup(
        int lcid);

    @VTID(131)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject textBoxes(
        @MarshalAs(NativeType.VARIANT) java.lang.Object index,
        int lcid);

    @VTID(132)
    int type(
        int lcid);

    @VTID(133)
    void type(
        int lcid,
        int rhs);

    @VTID(134)
    mol.excel.XlChartType chartType();

    @VTID(135)
    void chartType(
        mol.excel.XlChartType rhs);

    @VTID(136)
    void applyCustomType(
        mol.excel.XlChartType chartType,
        @MarshalAs(NativeType.VARIANT) java.lang.Object typeName);

    @VTID(137)
    mol.excel.Walls walls(
        int lcid);

    @VTID(138)
    boolean wallsAndGridlines2D(
        int lcid);

    @VTID(139)
    void wallsAndGridlines2D(
        int lcid,
        boolean rhs);

    @VTID(140)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject xyGroups(
        @MarshalAs(NativeType.VARIANT) java.lang.Object index,
        int lcid);

    @VTID(141)
    mol.excel.XlBarShape barShape();

    @VTID(142)
    void barShape(
        mol.excel.XlBarShape rhs);

    @VTID(143)
    mol.excel.XlRowCol plotBy();

    @VTID(144)
    void plotBy(
        mol.excel.XlRowCol rhs);

    @VTID(145)
    void copyChartBuild();

    @VTID(146)
    boolean protectFormatting();

    @VTID(147)
    void protectFormatting(
        boolean rhs);

    @VTID(148)
    boolean protectData();

    @VTID(149)
    void protectData(
        boolean rhs);

    @VTID(150)
    boolean protectGoalSeek();

    @VTID(151)
    void protectGoalSeek(
        boolean rhs);

    @VTID(152)
    boolean protectSelection();

    @VTID(153)
    void protectSelection(
        boolean rhs);

    @VTID(154)
    void getChartElement(
        int x,
        int y,
        Holder<Integer> elementID,
        Holder<Integer> arg1,
        Holder<Integer> arg2);

    @VTID(155)
    void setSourceData(
        mol.excel.Range source,
        @MarshalAs(NativeType.VARIANT) java.lang.Object plotBy);

    @VTID(156)
    boolean export(
        java.lang.String filename,
        @MarshalAs(NativeType.VARIANT) java.lang.Object filterName,
        @MarshalAs(NativeType.VARIANT) java.lang.Object interactive);

    @VTID(157)
    void refresh();

    @VTID(158)
    mol.excel.PivotLayout pivotLayout();

    @VTID(159)
    boolean hasPivotFields();

    @VTID(160)
    void hasPivotFields(
        boolean rhs);

    @VTID(161)
    mol.office.Scripts scripts();

    @VTID(161)
    @ReturnValue(defaultPropertyThrough={mol.office.Scripts.class})
    mol.office.Script scripts(
        @MarshalAs(NativeType.VARIANT) java.lang.Object index);

    @VTID(162)
    void _PrintOut(
        @MarshalAs(NativeType.VARIANT) java.lang.Object from,
        @MarshalAs(NativeType.VARIANT) java.lang.Object to,
        @MarshalAs(NativeType.VARIANT) java.lang.Object copies,
        @MarshalAs(NativeType.VARIANT) java.lang.Object preview,
        @MarshalAs(NativeType.VARIANT) java.lang.Object activePrinter,
        @MarshalAs(NativeType.VARIANT) java.lang.Object printToFile,
        @MarshalAs(NativeType.VARIANT) java.lang.Object collate,
        @MarshalAs(NativeType.VARIANT) java.lang.Object prToFileName,
        int lcid);

    @VTID(163)
    mol.excel.Tab tab();

    @VTID(164)
    mol.office.IMsoEnvelopeVB mailEnvelope();

    @VTID(165)
    void applyDataLabels(
        mol.excel.XlDataLabelsType type,
        @MarshalAs(NativeType.VARIANT) java.lang.Object legendKey,
        @MarshalAs(NativeType.VARIANT) java.lang.Object autoText,
        @MarshalAs(NativeType.VARIANT) java.lang.Object hasLeaderLines,
        @MarshalAs(NativeType.VARIANT) java.lang.Object showSeriesName,
        @MarshalAs(NativeType.VARIANT) java.lang.Object showCategoryName,
        @MarshalAs(NativeType.VARIANT) java.lang.Object showValue,
        @MarshalAs(NativeType.VARIANT) java.lang.Object showPercentage,
        @MarshalAs(NativeType.VARIANT) java.lang.Object showBubbleSize,
        @MarshalAs(NativeType.VARIANT) java.lang.Object separator,
        int lcid);

    @VTID(166)
    void saveAs(
        java.lang.String filename,
        @MarshalAs(NativeType.VARIANT) java.lang.Object fileFormat,
        @MarshalAs(NativeType.VARIANT) java.lang.Object password,
        @MarshalAs(NativeType.VARIANT) java.lang.Object writeResPassword,
        @MarshalAs(NativeType.VARIANT) java.lang.Object readOnlyRecommended,
        @MarshalAs(NativeType.VARIANT) java.lang.Object createBackup,
        @MarshalAs(NativeType.VARIANT) java.lang.Object addToMru,
        @MarshalAs(NativeType.VARIANT) java.lang.Object textCodepage,
        @MarshalAs(NativeType.VARIANT) java.lang.Object textVisualLayout,
        @MarshalAs(NativeType.VARIANT) java.lang.Object local);

    @VTID(167)
    void protect(
        @MarshalAs(NativeType.VARIANT) java.lang.Object password,
        @MarshalAs(NativeType.VARIANT) java.lang.Object drawingObjects,
        @MarshalAs(NativeType.VARIANT) java.lang.Object contents,
        @MarshalAs(NativeType.VARIANT) java.lang.Object scenarios,
        @MarshalAs(NativeType.VARIANT) java.lang.Object userInterfaceOnly);

    @VTID(168)
    void applyLayout(
        int layout,
        @MarshalAs(NativeType.VARIANT) java.lang.Object chartType);

    @VTID(169)
    void setElement(
        mol.office.MsoChartElementType element);

    @VTID(170)
    boolean showDataLabelsOverMaximum();

    @VTID(171)
    void showDataLabelsOverMaximum(
        boolean rhs);

    @VTID(172)
    mol.excel.Walls sideWall();

    @VTID(173)
    mol.excel.Walls backWall();

    @VTID(174)
    void printOut(
        @MarshalAs(NativeType.VARIANT) java.lang.Object from,
        @MarshalAs(NativeType.VARIANT) java.lang.Object to,
        @MarshalAs(NativeType.VARIANT) java.lang.Object copies,
        @MarshalAs(NativeType.VARIANT) java.lang.Object preview,
        @MarshalAs(NativeType.VARIANT) java.lang.Object activePrinter,
        @MarshalAs(NativeType.VARIANT) java.lang.Object printToFile,
        @MarshalAs(NativeType.VARIANT) java.lang.Object collate,
        @MarshalAs(NativeType.VARIANT) java.lang.Object prToFileName,
        int lcid);

    @VTID(175)
    void applyChartTemplate(
        java.lang.String filename);

    @VTID(176)
    void saveChartTemplate(
        java.lang.String filename);

    @VTID(177)
    void setDefaultChart(
        @MarshalAs(NativeType.VARIANT) java.lang.Object name);

    @VTID(178)
    void exportAsFixedFormat(
        mol.excel.XlFixedFormatType type,
        @MarshalAs(NativeType.VARIANT) java.lang.Object filename,
        @MarshalAs(NativeType.VARIANT) java.lang.Object quality,
        @MarshalAs(NativeType.VARIANT) java.lang.Object includeDocProperties,
        @MarshalAs(NativeType.VARIANT) java.lang.Object ignorePrintAreas,
        @MarshalAs(NativeType.VARIANT) java.lang.Object from,
        @MarshalAs(NativeType.VARIANT) java.lang.Object to,
        @MarshalAs(NativeType.VARIANT) java.lang.Object openAfterPublish,
        @MarshalAs(NativeType.VARIANT) java.lang.Object fixedFormatExtClassPtr);

    @VTID(179)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object chartStyle();

    @VTID(180)
    void chartStyle(
        @MarshalAs(NativeType.VARIANT) java.lang.Object rhs);

    @VTID(181)
    void clearToMatchStyle();

}
