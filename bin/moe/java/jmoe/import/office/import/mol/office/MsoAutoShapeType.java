package mol.office  ;

import com4j.*;

public enum MsoAutoShapeType implements ComEnum {
    msoShapeMixed(-2),
    msoShapeRectangle(1),
    msoShapeParallelogram(2),
    msoShapeTrapezoid(3),
    msoShapeDiamond(4),
    msoShapeRoundedRectangle(5),
    msoShapeOctagon(6),
    msoShapeIsoscelesTriangle(7),
    msoShapeRightTriangle(8),
    msoShapeOval(9),
    msoShapeHexagon(10),
    msoShapeCross(11),
    msoShapeRegularPentagon(12),
    msoShapeCan(13),
    msoShapeCube(14),
    msoShapeBevel(15),
    msoShapeFoldedCorner(16),
    msoShapeSmileyFace(17),
    msoShapeDonut(18),
    msoShapeNoSymbol(19),
    msoShapeBlockArc(20),
    msoShapeHeart(21),
    msoShapeLightningBolt(22),
    msoShapeSun(23),
    msoShapeMoon(24),
    msoShapeArc(25),
    msoShapeDoubleBracket(26),
    msoShapeDoubleBrace(27),
    msoShapePlaque(28),
    msoShapeLeftBracket(29),
    msoShapeRightBracket(30),
    msoShapeLeftBrace(31),
    msoShapeRightBrace(32),
    msoShapeRightArrow(33),
    msoShapeLeftArrow(34),
    msoShapeUpArrow(35),
    msoShapeDownArrow(36),
    msoShapeLeftRightArrow(37),
    msoShapeUpDownArrow(38),
    msoShapeQuadArrow(39),
    msoShapeLeftRightUpArrow(40),
    msoShapeBentArrow(41),
    msoShapeUTurnArrow(42),
    msoShapeLeftUpArrow(43),
    msoShapeBentUpArrow(44),
    msoShapeCurvedRightArrow(45),
    msoShapeCurvedLeftArrow(46),
    msoShapeCurvedUpArrow(47),
    msoShapeCurvedDownArrow(48),
    msoShapeStripedRightArrow(49),
    msoShapeNotchedRightArrow(50),
    msoShapePentagon(51),
    msoShapeChevron(52),
    msoShapeRightArrowCallout(53),
    msoShapeLeftArrowCallout(54),
    msoShapeUpArrowCallout(55),
    msoShapeDownArrowCallout(56),
    msoShapeLeftRightArrowCallout(57),
    msoShapeUpDownArrowCallout(58),
    msoShapeQuadArrowCallout(59),
    msoShapeCircularArrow(60),
    msoShapeFlowchartProcess(61),
    msoShapeFlowchartAlternateProcess(62),
    msoShapeFlowchartDecision(63),
    msoShapeFlowchartData(64),
    msoShapeFlowchartPredefinedProcess(65),
    msoShapeFlowchartInternalStorage(66),
    msoShapeFlowchartDocument(67),
    msoShapeFlowchartMultidocument(68),
    msoShapeFlowchartTerminator(69),
    msoShapeFlowchartPreparation(70),
    msoShapeFlowchartManualInput(71),
    msoShapeFlowchartManualOperation(72),
    msoShapeFlowchartConnector(73),
    msoShapeFlowchartOffpageConnector(74),
    msoShapeFlowchartCard(75),
    msoShapeFlowchartPunchedTape(76),
    msoShapeFlowchartSummingJunction(77),
    msoShapeFlowchartOr(78),
    msoShapeFlowchartCollate(79),
    msoShapeFlowchartSort(80),
    msoShapeFlowchartExtract(81),
    msoShapeFlowchartMerge(82),
    msoShapeFlowchartStoredData(83),
    msoShapeFlowchartDelay(84),
    msoShapeFlowchartSequentialAccessStorage(85),
    msoShapeFlowchartMagneticDisk(86),
    msoShapeFlowchartDirectAccessStorage(87),
    msoShapeFlowchartDisplay(88),
    msoShapeExplosion1(89),
    msoShapeExplosion2(90),
    msoShape4pointStar(91),
    msoShape5pointStar(92),
    msoShape8pointStar(93),
    msoShape16pointStar(94),
    msoShape24pointStar(95),
    msoShape32pointStar(96),
    msoShapeUpRibbon(97),
    msoShapeDownRibbon(98),
    msoShapeCurvedUpRibbon(99),
    msoShapeCurvedDownRibbon(100),
    msoShapeVerticalScroll(101),
    msoShapeHorizontalScroll(102),
    msoShapeWave(103),
    msoShapeDoubleWave(104),
    msoShapeRectangularCallout(105),
    msoShapeRoundedRectangularCallout(106),
    msoShapeOvalCallout(107),
    msoShapeCloudCallout(108),
    msoShapeLineCallout1(109),
    msoShapeLineCallout2(110),
    msoShapeLineCallout3(111),
    msoShapeLineCallout4(112),
    msoShapeLineCallout1AccentBar(113),
    msoShapeLineCallout2AccentBar(114),
    msoShapeLineCallout3AccentBar(115),
    msoShapeLineCallout4AccentBar(116),
    msoShapeLineCallout1NoBorder(117),
    msoShapeLineCallout2NoBorder(118),
    msoShapeLineCallout3NoBorder(119),
    msoShapeLineCallout4NoBorder(120),
    msoShapeLineCallout1BorderandAccentBar(121),
    msoShapeLineCallout2BorderandAccentBar(122),
    msoShapeLineCallout3BorderandAccentBar(123),
    msoShapeLineCallout4BorderandAccentBar(124),
    msoShapeActionButtonCustom(125),
    msoShapeActionButtonHome(126),
    msoShapeActionButtonHelp(127),
    msoShapeActionButtonInformation(128),
    msoShapeActionButtonBackorPrevious(129),
    msoShapeActionButtonForwardorNext(130),
    msoShapeActionButtonBeginning(131),
    msoShapeActionButtonEnd(132),
    msoShapeActionButtonReturn(133),
    msoShapeActionButtonDocument(134),
    msoShapeActionButtonSound(135),
    msoShapeActionButtonMovie(136),
    msoShapeBalloon(137),
    msoShapeNotPrimitive(138),
    msoShapeFlowchartOfflineStorage(139),
    msoShapeLeftRightRibbon(140),
    msoShapeDiagonalStripe(141),
    msoShapePie(142),
    msoShapeNonIsoscelesTrapezoid(143),
    msoShapeDecagon(144),
    msoShapeHeptagon(145),
    msoShapeDodecagon(146),
    msoShape6pointStar(147),
    msoShape7pointStar(148),
    msoShape10pointStar(149),
    msoShape12pointStar(150),
    msoShapeRound1Rectangle(151),
    msoShapeRound2SameRectangle(152),
    msoShapeRound2DiagRectangle(153),
    msoShapeSnipRoundRectangle(154),
    msoShapeSnip1Rectangle(155),
    msoShapeSnip2SameRectangle(156),
    msoShapeSnip2DiagRectangle(157),
    msoShapeFrame(158),
    msoShapeHalfFrame(159),
    msoShapeTear(160),
    msoShapeChord(161),
    msoShapeCorner(162),
    msoShapeMathPlus(163),
    msoShapeMathMinus(164),
    msoShapeMathMultiply(165),
    msoShapeMathDivide(166),
    msoShapeMathEqual(167),
    msoShapeMathNotEqual(168),
    msoShapeCornerTabs(169),
    msoShapeSquareTabs(170),
    msoShapePlaqueTabs(171),
    msoShapeGear6(172),
    msoShapeGear9(173),
    msoShapeFunnel(174),
    msoShapePieWedge(175),
    msoShapeLeftCircularArrow(176),
    msoShapeLeftRightCircularArrow(177),
    msoShapeSwooshArrow(178),
    msoShapeCloud(179),
    msoShapeChartX(180),
    msoShapeChartStar(181),
    msoShapeChartPlus(182),
    msoShapeLineInverse(183),
    ;

    private final int value;
    MsoAutoShapeType(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
