package mol.office  ;

import com4j.*;

@IID("{000C031D-0000-0000-C000-000000000046}")
public interface ShapeRange extends mol.office._IMsoDispObj,Iterable<Com4jObject> {
    @VTID(9)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

    @VTID(10)
    int count();

    @VTID(11)
    @DefaultMethod
    mol.office.Shape item(
        @MarshalAs(NativeType.VARIANT) java.lang.Object index);

    @VTID(12)
    java.util.Iterator<Com4jObject> iterator();

    @VTID(13)
    void align(
        mol.office.MsoAlignCmd alignCmd,
        mol.office.MsoTriState relativeTo);

    @VTID(14)
    void apply();

    @VTID(15)
    void delete();

    @VTID(16)
    void distribute(
        mol.office.MsoDistributeCmd distributeCmd,
        mol.office.MsoTriState relativeTo);

    @VTID(17)
    mol.office.ShapeRange duplicate();

    @VTID(17)
    @ReturnValue(defaultPropertyThrough={mol.office.ShapeRange.class})
    mol.office.Shape duplicate(
        @MarshalAs(NativeType.VARIANT) java.lang.Object index);

    @VTID(18)
    void flip(
        mol.office.MsoFlipCmd flipCmd);

    @VTID(19)
    void incrementLeft(
        float increment);

    @VTID(20)
    void incrementRotation(
        float increment);

    @VTID(21)
    void incrementTop(
        float increment);

    @VTID(22)
    mol.office.Shape group();

    @VTID(23)
    void pickUp();

    @VTID(24)
    mol.office.Shape regroup();

    @VTID(25)
    void rerouteConnections();

    @VTID(26)
    void scaleHeight(
        float factor,
        mol.office.MsoTriState relativeToOriginalSize,
        mol.office.MsoScaleFrom fScale);

    @VTID(27)
    void scaleWidth(
        float factor,
        mol.office.MsoTriState relativeToOriginalSize,
        mol.office.MsoScaleFrom fScale);

    @VTID(28)
    void select(
        @MarshalAs(NativeType.VARIANT) java.lang.Object replace);

    @VTID(29)
    void setShapesDefaultProperties();

    @VTID(30)
    mol.office.ShapeRange ungroup();

    @VTID(30)
    @ReturnValue(defaultPropertyThrough={mol.office.ShapeRange.class})
    mol.office.Shape ungroup(
        @MarshalAs(NativeType.VARIANT) java.lang.Object index);

    @VTID(31)
    void zOrder(
        mol.office.MsoZOrderCmd zOrderCmd);

    @VTID(32)
    mol.office.Adjustments adjustments();

    @VTID(32)
    @ReturnValue(defaultPropertyThrough={mol.office.Adjustments.class})
    float adjustments(
        int index);

    @VTID(33)
    mol.office.MsoAutoShapeType autoShapeType();

    @VTID(34)
    void autoShapeType(
        mol.office.MsoAutoShapeType autoShapeType);

    @VTID(35)
    mol.office.MsoBlackWhiteMode blackWhiteMode();

    @VTID(36)
    void blackWhiteMode(
        mol.office.MsoBlackWhiteMode blackWhiteMode);

    @VTID(37)
    mol.office.CalloutFormat callout();

    @VTID(38)
    int connectionSiteCount();

    @VTID(39)
    mol.office.MsoTriState connector();

    @VTID(40)
    mol.office.ConnectorFormat connectorFormat();

    @VTID(41)
    mol.office.FillFormat fill();

    @VTID(42)
    mol.office.GroupShapes groupItems();

    @VTID(42)
    @ReturnValue(defaultPropertyThrough={mol.office.GroupShapes.class})
    mol.office.Shape groupItems(
        @MarshalAs(NativeType.VARIANT) java.lang.Object index);

    @VTID(43)
    float height();

    @VTID(44)
    void height(
        float height);

    @VTID(45)
    mol.office.MsoTriState horizontalFlip();

    @VTID(46)
    float left();

    @VTID(47)
    void left(
        float left);

    @VTID(48)
    mol.office.LineFormat line();

    @VTID(49)
    mol.office.MsoTriState lockAspectRatio();

    @VTID(50)
    void lockAspectRatio(
        mol.office.MsoTriState lockAspectRatio);

    @VTID(51)
    java.lang.String name();

    @VTID(52)
    void name(
        java.lang.String name);

    @VTID(53)
    mol.office.ShapeNodes nodes();

    @VTID(53)
    @ReturnValue(defaultPropertyThrough={mol.office.ShapeNodes.class})
    mol.office.ShapeNode nodes(
        @MarshalAs(NativeType.VARIANT) java.lang.Object index);

    @VTID(54)
    float rotation();

    @VTID(55)
    void rotation(
        float rotation);

    @VTID(56)
    mol.office.PictureFormat pictureFormat();

    @VTID(57)
    mol.office.ShadowFormat shadow();

    @VTID(58)
    mol.office.TextEffectFormat textEffect();

    @VTID(59)
    mol.office.TextFrame textFrame();

    @VTID(60)
    mol.office.ThreeDFormat threeD();

    @VTID(61)
    float top();

    @VTID(62)
    void top(
        float top);

    @VTID(63)
    mol.office.MsoShapeType type();

    @VTID(64)
    mol.office.MsoTriState verticalFlip();

    @VTID(65)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object vertices();

    @VTID(66)
    mol.office.MsoTriState visible();

    @VTID(67)
    void visible(
        mol.office.MsoTriState visible);

    @VTID(68)
    float width();

    @VTID(69)
    void width(
        float width);

    @VTID(70)
    int zOrderPosition();

    @VTID(71)
    mol.office.Script script();

    @VTID(72)
    java.lang.String alternativeText();

    @VTID(73)
    void alternativeText(
        java.lang.String alternativeText);

    @VTID(74)
    mol.office.MsoTriState hasDiagram();

    @VTID(75)
    mol.office.IMsoDiagram diagram();

    @VTID(76)
    mol.office.MsoTriState hasDiagramNode();

    @VTID(77)
    mol.office.DiagramNode diagramNode();

    @VTID(78)
    mol.office.MsoTriState child();

    @VTID(79)
    mol.office.Shape parentGroup();

    @VTID(80)
    mol.office.CanvasShapes canvasItems();

    @VTID(80)
    @ReturnValue(defaultPropertyThrough={mol.office.CanvasShapes.class})
    mol.office.Shape canvasItems(
        @MarshalAs(NativeType.VARIANT) java.lang.Object index);

    @VTID(81)
    int id();

    @VTID(82)
    void canvasCropLeft(
        float increment);

    @VTID(83)
    void canvasCropTop(
        float increment);

    @VTID(84)
    void canvasCropRight(
        float increment);

    @VTID(85)
    void canvasCropBottom(
        float increment);

    @VTID(86)
    void rtf(
        java.lang.String rhs);

    @VTID(87)
    mol.office.TextFrame2 textFrame2();

    @VTID(88)
    void cut();

    @VTID(89)
    void copy();

    @VTID(90)
    mol.office.MsoTriState hasChart();

    @VTID(91)
    mol.office.IMsoChart chart();

    @VTID(92)
    mol.office.MsoShapeStyleIndex shapeStyle();

    @VTID(93)
    void shapeStyle(
        mol.office.MsoShapeStyleIndex shapeStyle);

    @VTID(94)
    mol.office.MsoBackgroundStyleIndex backgroundStyle();

    @VTID(95)
    void backgroundStyle(
        mol.office.MsoBackgroundStyleIndex backgroundStyle);

    @VTID(96)
    mol.office.SoftEdgeFormat softEdge();

    @VTID(97)
    mol.office.GlowFormat glow();

    @VTID(98)
    mol.office.ReflectionFormat reflection();

}
