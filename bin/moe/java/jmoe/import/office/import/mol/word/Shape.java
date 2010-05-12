package mol.word  ;

import com4j.*;

@IID("{000209A0-0000-0000-C000-000000000046}")
public interface Shape extends Com4jObject {
    @VTID(7)
    mol.word._Application application();

    @VTID(8)
    int creator();

    @VTID(9)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

    @VTID(10)
    mol.word.Adjustments adjustments();

    @VTID(10)
    @ReturnValue(defaultPropertyThrough={mol.word.Adjustments.class})
    float adjustments(
        int index);

    @VTID(11)
    mol.office.MsoAutoShapeType autoShapeType();

    @VTID(12)
    void autoShapeType(
        mol.office.MsoAutoShapeType prop);

    @VTID(13)
    mol.word.CalloutFormat callout();

    @VTID(14)
    int connectionSiteCount();

    @VTID(15)
    mol.office.MsoTriState connector();

    @VTID(16)
    mol.word.ConnectorFormat connectorFormat();

    @VTID(17)
    mol.word.FillFormat fill();

    @VTID(18)
    mol.word.GroupShapes groupItems();

    @VTID(18)
    @ReturnValue(defaultPropertyThrough={mol.word.GroupShapes.class})
    mol.word.Shape groupItems(
        java.lang.Object index);

    @VTID(19)
    float height();

    @VTID(20)
    void height(
        float prop);

    @VTID(21)
    mol.office.MsoTriState horizontalFlip();

    @VTID(22)
    float left();

    @VTID(23)
    void left(
        float prop);

    @VTID(24)
    mol.word.LineFormat line();

    @VTID(25)
    mol.office.MsoTriState lockAspectRatio();

    @VTID(26)
    void lockAspectRatio(
        mol.office.MsoTriState prop);

    @VTID(27)
    java.lang.String name();

    @VTID(28)
    void name(
        java.lang.String prop);

    @VTID(29)
    mol.word.ShapeNodes nodes();

    @VTID(29)
    @ReturnValue(defaultPropertyThrough={mol.word.ShapeNodes.class})
    mol.word.ShapeNode nodes(
        java.lang.Object index);

    @VTID(30)
    float rotation();

    @VTID(31)
    void rotation(
        float prop);

    @VTID(32)
    mol.word.PictureFormat pictureFormat();

    @VTID(33)
    mol.word.ShadowFormat shadow();

    @VTID(34)
    mol.word.TextEffectFormat textEffect();

    @VTID(35)
    mol.word.TextFrame textFrame();

    @VTID(36)
    mol.word.ThreeDFormat threeD();

    @VTID(37)
    float top();

    @VTID(38)
    void top(
        float prop);

    @VTID(39)
    mol.office.MsoShapeType type();

    @VTID(40)
    mol.office.MsoTriState verticalFlip();

    @VTID(41)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object vertices();

    @VTID(42)
    mol.office.MsoTriState visible();

    @VTID(43)
    void visible(
        mol.office.MsoTriState prop);

    @VTID(44)
    float width();

    @VTID(45)
    void width(
        float prop);

    @VTID(46)
    int zOrderPosition();

    @VTID(47)
    mol.word.Hyperlink hyperlink();

    @VTID(48)
    mol.word.WdRelativeHorizontalPosition relativeHorizontalPosition();

    @VTID(49)
    void relativeHorizontalPosition(
        mol.word.WdRelativeHorizontalPosition prop);

    @VTID(50)
    mol.word.WdRelativeVerticalPosition relativeVerticalPosition();

    @VTID(51)
    void relativeVerticalPosition(
        mol.word.WdRelativeVerticalPosition prop);

    @VTID(52)
    int lockAnchor();

    @VTID(53)
    void lockAnchor(
        int prop);

    @VTID(54)
    mol.word.WrapFormat wrapFormat();

    @VTID(55)
    mol.word.OLEFormat oleFormat();

    @VTID(56)
    mol.word.Range anchor();

    @VTID(57)
    mol.word.LinkFormat linkFormat();

    @VTID(58)
    void apply();

    @VTID(59)
    void delete();

    @VTID(60)
    mol.word.Shape duplicate();

    @VTID(61)
    void flip(
        mol.office.MsoFlipCmd flipCmd);

    @VTID(62)
    void incrementLeft(
        float increment);

    @VTID(63)
    void incrementRotation(
        float increment);

    @VTID(64)
    void incrementTop(
        float increment);

    @VTID(65)
    void pickUp();

    @VTID(66)
    void rerouteConnections();

    @VTID(67)
    void scaleHeight(
        float factor,
        mol.office.MsoTriState relativeToOriginalSize,
        mol.office.MsoScaleFrom scale);

    @VTID(68)
    void scaleWidth(
        float factor,
        mol.office.MsoTriState relativeToOriginalSize,
        mol.office.MsoScaleFrom scale);

    @VTID(69)
    void select(
        java.lang.Object replace);

    @VTID(70)
    void setShapesDefaultProperties();

    @VTID(71)
    mol.word.ShapeRange ungroup();

    @VTID(71)
    @ReturnValue(defaultPropertyThrough={mol.word.ShapeRange.class})
    mol.word.Shape ungroup(
        java.lang.Object index);

    @VTID(72)
    void zOrder(
        mol.office.MsoZOrderCmd zOrderCmd);

    @VTID(73)
    mol.word.InlineShape convertToInlineShape();

    @VTID(74)
    mol.word.Frame convertToFrame();

    @VTID(75)
    void activate();

    @VTID(76)
    java.lang.String alternativeText();

    @VTID(77)
    void alternativeText(
        java.lang.String prop);

    @VTID(78)
    mol.office.Script script();

    @VTID(79)
    mol.office.MsoTriState hasDiagram();

    @VTID(80)
    mol.office.IMsoDiagram diagram();

    @VTID(81)
    mol.office.MsoTriState hasDiagramNode();

    @VTID(82)
    mol.word.DiagramNode diagramNode();

    @VTID(83)
    mol.office.MsoTriState child();

    @VTID(84)
    mol.word.Shape parentGroup();

    @VTID(85)
    mol.word.CanvasShapes canvasItems();

    @VTID(85)
    @ReturnValue(defaultPropertyThrough={mol.word.CanvasShapes.class})
    mol.word.Shape canvasItems(
        java.lang.Object index);

    @VTID(86)
    int id();

    @VTID(87)
    void canvasCropLeft(
        float increment);

    @VTID(88)
    void canvasCropTop(
        float increment);

    @VTID(89)
    void canvasCropRight(
        float increment);

    @VTID(90)
    void canvasCropBottom(
        float increment);

    @VTID(91)
    void rtf(
        java.lang.String rhs);

    @VTID(92)
    int layoutInCell();

    @VTID(93)
    void layoutInCell(
        int prop);

    @VTID(94)
    mol.office.MsoTriState hasChart();

    @VTID(95)
    boolean dummy1();

    @VTID(96)
    float leftRelative();

    @VTID(97)
    void leftRelative(
        float prop);

    @VTID(98)
    float topRelative();

    @VTID(99)
    void topRelative(
        float prop);

    @VTID(100)
    float widthRelative();

    @VTID(101)
    void widthRelative(
        float prop);

    @VTID(102)
    float heightRelative();

    @VTID(103)
    void heightRelative(
        float prop);

    @VTID(104)
    mol.word.WdRelativeHorizontalSize relativeHorizontalSize();

    @VTID(105)
    void relativeHorizontalSize(
        mol.word.WdRelativeHorizontalSize prop);

    @VTID(106)
    mol.word.WdRelativeVerticalSize relativeVerticalSize();

    @VTID(107)
    void relativeVerticalSize(
        mol.word.WdRelativeVerticalSize prop);

    @VTID(108)
    mol.word.SoftEdgeFormat softEdge();

    @VTID(109)
    mol.word.GlowFormat glow();

    @VTID(110)
    mol.word.ReflectionFormat reflection();

    @VTID(111)
    mol.office.TextFrame2 textFrame2();

}
