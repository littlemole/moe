package mol.word  ;

import com4j.*;

@IID("{000209B5-0000-0000-C000-000000000046}")
public interface ShapeRange extends Com4jObject,Iterable<Com4jObject> {
    @VTID(7)
    mol.word._Application application();

    @VTID(8)
    int creator();

    @VTID(9)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

    @VTID(10)
    int count();

    @VTID(11)
    java.util.Iterator<Com4jObject> iterator();

    @VTID(12)
    mol.word.Adjustments adjustments();

    @VTID(12)
    @ReturnValue(defaultPropertyThrough={mol.word.Adjustments.class})
    float adjustments(
        int index);

    @VTID(13)
    mol.office.MsoAutoShapeType autoShapeType();

    @VTID(14)
    void autoShapeType(
        mol.office.MsoAutoShapeType prop);

    @VTID(15)
    mol.word.CalloutFormat callout();

    @VTID(16)
    int connectionSiteCount();

    @VTID(17)
    mol.office.MsoTriState connector();

    @VTID(18)
    mol.word.ConnectorFormat connectorFormat();

    @VTID(19)
    mol.word.FillFormat fill();

    @VTID(20)
    mol.word.GroupShapes groupItems();

    @VTID(20)
    @ReturnValue(defaultPropertyThrough={mol.word.GroupShapes.class})
    mol.word.Shape groupItems(
        java.lang.Object index);

    @VTID(21)
    float height();

    @VTID(22)
    void height(
        float prop);

    @VTID(23)
    mol.office.MsoTriState horizontalFlip();

    @VTID(24)
    float left();

    @VTID(25)
    void left(
        float prop);

    @VTID(26)
    mol.word.LineFormat line();

    @VTID(27)
    mol.office.MsoTriState lockAspectRatio();

    @VTID(28)
    void lockAspectRatio(
        mol.office.MsoTriState prop);

    @VTID(29)
    java.lang.String name();

    @VTID(30)
    void name(
        java.lang.String prop);

    @VTID(31)
    mol.word.ShapeNodes nodes();

    @VTID(31)
    @ReturnValue(defaultPropertyThrough={mol.word.ShapeNodes.class})
    mol.word.ShapeNode nodes(
        java.lang.Object index);

    @VTID(32)
    float rotation();

    @VTID(33)
    void rotation(
        float prop);

    @VTID(34)
    mol.word.PictureFormat pictureFormat();

    @VTID(35)
    mol.word.ShadowFormat shadow();

    @VTID(36)
    mol.word.TextEffectFormat textEffect();

    @VTID(37)
    mol.word.TextFrame textFrame();

    @VTID(38)
    mol.word.ThreeDFormat threeD();

    @VTID(39)
    float top();

    @VTID(40)
    void top(
        float prop);

    @VTID(41)
    mol.office.MsoShapeType type();

    @VTID(42)
    mol.office.MsoTriState verticalFlip();

    @VTID(43)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object vertices();

    @VTID(44)
    mol.office.MsoTriState visible();

    @VTID(45)
    void visible(
        mol.office.MsoTriState prop);

    @VTID(46)
    float width();

    @VTID(47)
    void width(
        float prop);

    @VTID(48)
    int zOrderPosition();

    @VTID(49)
    mol.word.Hyperlink hyperlink();

    @VTID(50)
    mol.word.WdRelativeHorizontalPosition relativeHorizontalPosition();

    @VTID(51)
    void relativeHorizontalPosition(
        mol.word.WdRelativeHorizontalPosition prop);

    @VTID(52)
    mol.word.WdRelativeVerticalPosition relativeVerticalPosition();

    @VTID(53)
    void relativeVerticalPosition(
        mol.word.WdRelativeVerticalPosition prop);

    @VTID(54)
    int lockAnchor();

    @VTID(55)
    void lockAnchor(
        int prop);

    @VTID(56)
    mol.word.WrapFormat wrapFormat();

    @VTID(57)
    mol.word.Range anchor();

    @VTID(58)
    @DefaultMethod
    mol.word.Shape item(
        java.lang.Object index);

    @VTID(59)
    void align(
        mol.office.MsoAlignCmd align,
        int relativeTo);

    @VTID(60)
    void apply();

    @VTID(61)
    void delete();

    @VTID(62)
    void distribute(
        mol.office.MsoDistributeCmd distribute,
        int relativeTo);

    @VTID(63)
    mol.word.ShapeRange duplicate();

    @VTID(63)
    @ReturnValue(defaultPropertyThrough={mol.word.ShapeRange.class})
    mol.word.Shape duplicate(
        java.lang.Object index);

    @VTID(64)
    void flip(
        mol.office.MsoFlipCmd flipCmd);

    @VTID(65)
    void incrementLeft(
        float increment);

    @VTID(66)
    void incrementRotation(
        float increment);

    @VTID(67)
    void incrementTop(
        float increment);

    @VTID(68)
    mol.word.Shape group();

    @VTID(69)
    void pickUp();

    @VTID(70)
    mol.word.Shape regroup();

    @VTID(71)
    void rerouteConnections();

    @VTID(72)
    void scaleHeight(
        float factor,
        mol.office.MsoTriState relativeToOriginalSize,
        mol.office.MsoScaleFrom scale);

    @VTID(73)
    void scaleWidth(
        float factor,
        mol.office.MsoTriState relativeToOriginalSize,
        mol.office.MsoScaleFrom scale);

    @VTID(74)
    void select(
        java.lang.Object replace);

    @VTID(75)
    void setShapesDefaultProperties();

    @VTID(76)
    mol.word.ShapeRange ungroup();

    @VTID(76)
    @ReturnValue(defaultPropertyThrough={mol.word.ShapeRange.class})
    mol.word.Shape ungroup(
        java.lang.Object index);

    @VTID(77)
    void zOrder(
        mol.office.MsoZOrderCmd zOrderCmd);

    @VTID(78)
    mol.word.Frame convertToFrame();

    @VTID(79)
    mol.word.InlineShape convertToInlineShape();

    @VTID(80)
    void activate();

    @VTID(81)
    java.lang.String alternativeText();

    @VTID(82)
    void alternativeText(
        java.lang.String prop);

    @VTID(83)
    mol.office.MsoTriState hasDiagram();

    @VTID(84)
    mol.office.IMsoDiagram diagram();

    @VTID(85)
    mol.office.MsoTriState hasDiagramNode();

    @VTID(86)
    mol.word.DiagramNode diagramNode();

    @VTID(87)
    mol.office.MsoTriState child();

    @VTID(88)
    mol.word.Shape parentGroup();

    @VTID(89)
    mol.word.CanvasShapes canvasItems();

    @VTID(89)
    @ReturnValue(defaultPropertyThrough={mol.word.CanvasShapes.class})
    mol.word.Shape canvasItems(
        java.lang.Object index);

    @VTID(90)
    int id();

    @VTID(91)
    void canvasCropLeft(
        float increment);

    @VTID(92)
    void canvasCropTop(
        float increment);

    @VTID(93)
    void canvasCropRight(
        float increment);

    @VTID(94)
    void canvasCropBottom(
        float increment);

    @VTID(95)
    void rtf(
        java.lang.String rhs);

    @VTID(96)
    int layoutInCell();

    @VTID(97)
    void layoutInCell(
        int prop);

    @VTID(98)
    float leftRelative();

    @VTID(99)
    void leftRelative(
        float prop);

    @VTID(100)
    float topRelative();

    @VTID(101)
    void topRelative(
        float prop);

    @VTID(102)
    float widthRelative();

    @VTID(103)
    void widthRelative(
        float prop);

    @VTID(104)
    float heightRelative();

    @VTID(105)
    void heightRelative(
        float prop);

    @VTID(106)
    mol.word.WdRelativeHorizontalSize relativeHorizontalSize();

    @VTID(107)
    void relativeHorizontalSize(
        mol.word.WdRelativeHorizontalSize prop);

    @VTID(108)
    mol.word.WdRelativeVerticalSize relativeVerticalSize();

    @VTID(109)
    void relativeVerticalSize(
        mol.word.WdRelativeVerticalSize prop);

    @VTID(110)
    mol.word.SoftEdgeFormat softEdge();

    @VTID(111)
    mol.word.GlowFormat glow();

    @VTID(112)
    mol.word.ReflectionFormat reflection();

    @VTID(113)
    mol.office.TextFrame2 textFrame2();

}
