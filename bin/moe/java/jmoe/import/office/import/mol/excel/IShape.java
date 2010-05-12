package mol.excel  ;

import com4j.*;

@IID("{00024439-0001-0000-C000-000000000046}")
public interface IShape extends Com4jObject {
    @VTID(7)
    mol.excel._Application application();

    @VTID(8)
    mol.excel.XlCreator creator();

    @VTID(9)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

    @VTID(10)
    void apply();

    @VTID(11)
    void delete();

    @VTID(12)
    mol.excel.Shape duplicate();

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
        @MarshalAs(NativeType.VARIANT) java.lang.Object scale);

    @VTID(20)
    void scaleWidth(
        float factor,
        mol.office.MsoTriState relativeToOriginalSize,
        @MarshalAs(NativeType.VARIANT) java.lang.Object scale);

    @VTID(21)
    void select(
        @MarshalAs(NativeType.VARIANT) java.lang.Object replace);

    @VTID(22)
    void setShapesDefaultProperties();

    @VTID(23)
    mol.excel.ShapeRange ungroup();

    @VTID(24)
    void zOrder(
        mol.office.MsoZOrderCmd zOrderCmd);

    @VTID(25)
    mol.excel.Adjustments adjustments();

    @VTID(25)
    @ReturnValue(defaultPropertyThrough={mol.excel.Adjustments.class})
    float adjustments(
        int index);

    @VTID(26)
    mol.excel.TextFrame textFrame();

    @VTID(27)
    mol.office.MsoAutoShapeType autoShapeType();

    @VTID(28)
    void autoShapeType(
        mol.office.MsoAutoShapeType rhs);

    @VTID(29)
    mol.excel.CalloutFormat callout();

    @VTID(30)
    int connectionSiteCount();

    @VTID(31)
    mol.office.MsoTriState connector();

    @VTID(32)
    mol.excel.ConnectorFormat connectorFormat();

    @VTID(33)
    mol.excel.FillFormat fill();

    @VTID(34)
    mol.excel.GroupShapes groupItems();

    @VTID(35)
    float height();

    @VTID(36)
    void height(
        float rhs);

    @VTID(37)
    mol.office.MsoTriState horizontalFlip();

    @VTID(38)
    float left();

    @VTID(39)
    void left(
        float rhs);

    @VTID(40)
    mol.excel.LineFormat line();

    @VTID(41)
    mol.office.MsoTriState lockAspectRatio();

    @VTID(42)
    void lockAspectRatio(
        mol.office.MsoTriState rhs);

    @VTID(43)
    java.lang.String name();

    @VTID(44)
    void name(
        java.lang.String rhs);

    @VTID(45)
    mol.excel.ShapeNodes nodes();

    @VTID(45)
    @ReturnValue(defaultPropertyThrough={mol.excel.ShapeNodes.class})
    mol.excel.ShapeNode nodes(
        @MarshalAs(NativeType.VARIANT) java.lang.Object index);

    @VTID(46)
    float rotation();

    @VTID(47)
    void rotation(
        float rhs);

    @VTID(48)
    mol.excel.PictureFormat pictureFormat();

    @VTID(49)
    mol.excel.ShadowFormat shadow();

    @VTID(50)
    mol.excel.TextEffectFormat textEffect();

    @VTID(51)
    mol.excel.ThreeDFormat threeD();

    @VTID(52)
    float top();

    @VTID(53)
    void top(
        float rhs);

    @VTID(54)
    mol.office.MsoShapeType type();

    @VTID(55)
    mol.office.MsoTriState verticalFlip();

    @VTID(56)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object vertices();

    @VTID(57)
    mol.office.MsoTriState visible();

    @VTID(58)
    void visible(
        mol.office.MsoTriState rhs);

    @VTID(59)
    float width();

    @VTID(60)
    void width(
        float rhs);

    @VTID(61)
    int zOrderPosition();

    @VTID(62)
    mol.excel.Hyperlink hyperlink();

    @VTID(63)
    mol.office.MsoBlackWhiteMode blackWhiteMode();

    @VTID(64)
    void blackWhiteMode(
        mol.office.MsoBlackWhiteMode rhs);

    @VTID(65)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject drawingObject();

    @VTID(66)
    java.lang.String onAction();

    @VTID(67)
    void onAction(
        java.lang.String rhs);

    @VTID(68)
    boolean locked();

    @VTID(69)
    void locked(
        boolean rhs);

    @VTID(70)
    mol.excel.Range topLeftCell();

    @VTID(71)
    mol.excel.Range bottomRightCell();

    @VTID(72)
    mol.excel.XlPlacement placement();

    @VTID(73)
    void placement(
        mol.excel.XlPlacement rhs);

    @VTID(74)
    void copy();

    @VTID(75)
    void cut();

    @VTID(76)
    void copyPicture(
        @MarshalAs(NativeType.VARIANT) java.lang.Object appearance,
        @MarshalAs(NativeType.VARIANT) java.lang.Object format);

    @VTID(77)
    mol.excel.ControlFormat controlFormat();

    @VTID(78)
    mol.excel.LinkFormat linkFormat();

    @VTID(79)
    mol.excel.OLEFormat oleFormat();

    @VTID(80)
    mol.excel.XlFormControl formControlType();

    @VTID(81)
    java.lang.String alternativeText();

    @VTID(82)
    void alternativeText(
        java.lang.String rhs);

    @VTID(83)
    mol.office.Script script();

    @VTID(84)
    mol.excel.DiagramNode diagramNode();

    @VTID(85)
    mol.office.MsoTriState hasDiagramNode();

    @VTID(86)
    mol.excel.Diagram diagram();

    @VTID(87)
    mol.office.MsoTriState hasDiagram();

    @VTID(88)
    mol.office.MsoTriState child();

    @VTID(89)
    mol.excel.Shape parentGroup();

    @VTID(90)
    mol.office.CanvasShapes canvasItems();

    @VTID(90)
    @ReturnValue(defaultPropertyThrough={mol.office.CanvasShapes.class})
    mol.excel.Shape canvasItems(
        @MarshalAs(NativeType.VARIANT) java.lang.Object index);

    @VTID(91)
    int id();

    @VTID(92)
    void canvasCropLeft(
        float increment);

    @VTID(93)
    void canvasCropTop(
        float increment);

    @VTID(94)
    void canvasCropRight(
        float increment);

    @VTID(95)
    void canvasCropBottom(
        float increment);

    @VTID(96)
    mol.excel._Chart chart();

    @VTID(97)
    mol.office.MsoTriState hasChart();

    @VTID(98)
    mol.excel.TextFrame2 textFrame2();

    @VTID(99)
    mol.office.MsoShapeStyleIndex shapeStyle();

    @VTID(100)
    void shapeStyle(
        mol.office.MsoShapeStyleIndex rhs);

    @VTID(101)
    mol.office.MsoBackgroundStyleIndex backgroundStyle();

    @VTID(102)
    void backgroundStyle(
        mol.office.MsoBackgroundStyleIndex rhs);

    @VTID(103)
    mol.office.SoftEdgeFormat softEdge();

    @VTID(104)
    mol.office.GlowFormat glow();

    @VTID(105)
    mol.office.ReflectionFormat reflection();

}
