package mol.office  ;

import com4j.*;

@IID("{000C031C-0000-0000-C000-000000000046}")
public interface Shape extends mol.office._IMsoDispObj {
    @VTID(9)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

    @VTID(10)
    void apply();

    @VTID(11)
    void delete();

    @VTID(12)
    mol.office.Shape duplicate();

    @VTID(13)
    void flip(
        mol.office.MsoFlipCmd flipCmd);

    @VTID(14)
    void incrementLeft(
        float increment);

    @VTID(15)
    void incrementRotation(
        float increment);

    @VTID(16)
    void incrementTop(
        float increment);

    @VTID(17)
    void pickUp();

    @VTID(18)
    void rerouteConnections();

    @VTID(19)
    void scaleHeight(
        float factor,
        mol.office.MsoTriState relativeToOriginalSize,
        mol.office.MsoScaleFrom fScale);

    @VTID(20)
    void scaleWidth(
        float factor,
        mol.office.MsoTriState relativeToOriginalSize,
        mol.office.MsoScaleFrom fScale);

    @VTID(21)
    void select(
        @MarshalAs(NativeType.VARIANT) java.lang.Object replace);

    @VTID(22)
    void setShapesDefaultProperties();

    @VTID(23)
    mol.office.ShapeRange ungroup();

    @VTID(23)
    @ReturnValue(defaultPropertyThrough={mol.office.ShapeRange.class})
    mol.office.Shape ungroup(
        @MarshalAs(NativeType.VARIANT) java.lang.Object index);

    @VTID(24)
    void zOrder(
        mol.office.MsoZOrderCmd zOrderCmd);

    @VTID(25)
    mol.office.Adjustments adjustments();

    @VTID(25)
    @ReturnValue(defaultPropertyThrough={mol.office.Adjustments.class})
    float adjustments(
        int index);

    @VTID(26)
    mol.office.MsoAutoShapeType autoShapeType();

    @VTID(27)
    void autoShapeType(
        mol.office.MsoAutoShapeType autoShapeType);

    @VTID(28)
    mol.office.MsoBlackWhiteMode blackWhiteMode();

    @VTID(29)
    void blackWhiteMode(
        mol.office.MsoBlackWhiteMode blackWhiteMode);

    @VTID(30)
    mol.office.CalloutFormat callout();

    @VTID(31)
    int connectionSiteCount();

    @VTID(32)
    mol.office.MsoTriState connector();

    @VTID(33)
    mol.office.ConnectorFormat connectorFormat();

    @VTID(34)
    mol.office.FillFormat fill();

    @VTID(35)
    mol.office.GroupShapes groupItems();

    @VTID(35)
    @ReturnValue(defaultPropertyThrough={mol.office.GroupShapes.class})
    mol.office.Shape groupItems(
        @MarshalAs(NativeType.VARIANT) java.lang.Object index);

    @VTID(36)
    float height();

    @VTID(37)
    void height(
        float height);

    @VTID(38)
    mol.office.MsoTriState horizontalFlip();

    @VTID(39)
    float left();

    @VTID(40)
    void left(
        float left);

    @VTID(41)
    mol.office.LineFormat line();

    @VTID(42)
    mol.office.MsoTriState lockAspectRatio();

    @VTID(43)
    void lockAspectRatio(
        mol.office.MsoTriState lockAspectRatio);

    @VTID(44)
    java.lang.String name();

    @VTID(45)
    void name(
        java.lang.String name);

    @VTID(46)
    mol.office.ShapeNodes nodes();

    @VTID(46)
    @ReturnValue(defaultPropertyThrough={mol.office.ShapeNodes.class})
    mol.office.ShapeNode nodes(
        @MarshalAs(NativeType.VARIANT) java.lang.Object index);

    @VTID(47)
    float rotation();

    @VTID(48)
    void rotation(
        float rotation);

    @VTID(49)
    mol.office.PictureFormat pictureFormat();

    @VTID(50)
    mol.office.ShadowFormat shadow();

    @VTID(51)
    mol.office.TextEffectFormat textEffect();

    @VTID(52)
    mol.office.TextFrame textFrame();

    @VTID(53)
    mol.office.ThreeDFormat threeD();

    @VTID(54)
    float top();

    @VTID(55)
    void top(
        float top);

    @VTID(56)
    mol.office.MsoShapeType type();

    @VTID(57)
    mol.office.MsoTriState verticalFlip();

    @VTID(58)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object vertices();

    @VTID(59)
    mol.office.MsoTriState visible();

    @VTID(60)
    void visible(
        mol.office.MsoTriState visible);

    @VTID(61)
    float width();

    @VTID(62)
    void width(
        float width);

    @VTID(63)
    int zOrderPosition();

    @VTID(64)
    mol.office.Script script();

    @VTID(65)
    java.lang.String alternativeText();

    @VTID(66)
    void alternativeText(
        java.lang.String alternativeText);

    @VTID(67)
    mol.office.MsoTriState hasDiagram();

    @VTID(68)
    mol.office.IMsoDiagram diagram();

    @VTID(69)
    mol.office.MsoTriState hasDiagramNode();

    @VTID(70)
    mol.office.DiagramNode diagramNode();

    @VTID(71)
    mol.office.MsoTriState child();

    @VTID(72)
    mol.office.Shape parentGroup();

    @VTID(73)
    mol.office.CanvasShapes canvasItems();

    @VTID(73)
    @ReturnValue(defaultPropertyThrough={mol.office.CanvasShapes.class})
    mol.office.Shape canvasItems(
        @MarshalAs(NativeType.VARIANT) java.lang.Object index);

    @VTID(74)
    int id();

    @VTID(75)
    void canvasCropLeft(
        float increment);

    @VTID(76)
    void canvasCropTop(
        float increment);

    @VTID(77)
    void canvasCropRight(
        float increment);

    @VTID(78)
    void canvasCropBottom(
        float increment);

    @VTID(79)
    void rtf(
        java.lang.String rhs);

    @VTID(80)
    mol.office.TextFrame2 textFrame2();

    @VTID(81)
    void cut();

    @VTID(82)
    void copy();

    @VTID(83)
    mol.office.MsoTriState hasChart();

    @VTID(84)
    mol.office.IMsoChart chart();

    @VTID(85)
    mol.office.MsoShapeStyleIndex shapeStyle();

    @VTID(86)
    void shapeStyle(
        mol.office.MsoShapeStyleIndex shapeStyle);

    @VTID(87)
    mol.office.MsoBackgroundStyleIndex backgroundStyle();

    @VTID(88)
    void backgroundStyle(
        mol.office.MsoBackgroundStyleIndex backgroundStyle);

    @VTID(89)
    mol.office.SoftEdgeFormat softEdge();

    @VTID(90)
    mol.office.GlowFormat glow();

    @VTID(91)
    mol.office.ReflectionFormat reflection();

}
