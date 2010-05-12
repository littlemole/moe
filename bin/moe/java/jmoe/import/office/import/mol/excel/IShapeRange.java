package mol.excel  ;

import com4j.*;

@IID("{0002443B-0001-0000-C000-000000000046}")
public interface IShapeRange extends Com4jObject,Iterable<Com4jObject> {
    @VTID(7)
    mol.excel._Application application();

    @VTID(8)
    mol.excel.XlCreator creator();

    @VTID(9)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

    @VTID(10)
    int count();

    @VTID(11)
    mol.excel.Shape item(
        @MarshalAs(NativeType.VARIANT) java.lang.Object index);

    @VTID(12)
    @DefaultMethod
    mol.excel.Shape _Default(
        @MarshalAs(NativeType.VARIANT) java.lang.Object index);

    @VTID(13)
    java.util.Iterator<Com4jObject> iterator();

    @VTID(14)
    void align(
        mol.office.MsoAlignCmd alignCmd,
        mol.office.MsoTriState relativeTo);

    @VTID(15)
    void apply();

    @VTID(16)
    void delete();

    @VTID(17)
    void distribute(
        mol.office.MsoDistributeCmd distributeCmd,
        mol.office.MsoTriState relativeTo);

    @VTID(18)
    mol.excel.ShapeRange duplicate();

    @VTID(19)
    void flip(
        mol.office.MsoFlipCmd flipCmd);

    @VTID(20)
    void incrementLeft(
        float increment);

    @VTID(21)
    void incrementRotation(
        float increment);

    @VTID(22)
    void incrementTop(
        float increment);

    @VTID(23)
    mol.excel.Shape group();

    @VTID(24)
    void pickUp();

    @VTID(25)
    void rerouteConnections();

    @VTID(26)
    mol.excel.Shape regroup();

    @VTID(27)
    void scaleHeight(
        float factor,
        mol.office.MsoTriState relativeToOriginalSize,
        @MarshalAs(NativeType.VARIANT) java.lang.Object scale);

    @VTID(28)
    void scaleWidth(
        float factor,
        mol.office.MsoTriState relativeToOriginalSize,
        @MarshalAs(NativeType.VARIANT) java.lang.Object scale);

    @VTID(29)
    void select(
        @MarshalAs(NativeType.VARIANT) java.lang.Object replace);

    @VTID(30)
    void setShapesDefaultProperties();

    @VTID(31)
    mol.excel.ShapeRange ungroup();

    @VTID(32)
    void zOrder(
        mol.office.MsoZOrderCmd zOrderCmd);

    @VTID(33)
    mol.excel.Adjustments adjustments();

    @VTID(33)
    @ReturnValue(defaultPropertyThrough={mol.excel.Adjustments.class})
    float adjustments(
        int index);

    @VTID(34)
    mol.excel.TextFrame textFrame();

    @VTID(35)
    mol.office.MsoAutoShapeType autoShapeType();

    @VTID(36)
    void autoShapeType(
        mol.office.MsoAutoShapeType rhs);

    @VTID(37)
    mol.excel.CalloutFormat callout();

    @VTID(38)
    int connectionSiteCount();

    @VTID(39)
    mol.office.MsoTriState connector();

    @VTID(40)
    mol.excel.ConnectorFormat connectorFormat();

    @VTID(41)
    mol.excel.FillFormat fill();

    @VTID(42)
    mol.excel.GroupShapes groupItems();

    @VTID(43)
    float height();

    @VTID(44)
    void height(
        float rhs);

    @VTID(45)
    mol.office.MsoTriState horizontalFlip();

    @VTID(46)
    float left();

    @VTID(47)
    void left(
        float rhs);

    @VTID(48)
    mol.excel.LineFormat line();

    @VTID(49)
    mol.office.MsoTriState lockAspectRatio();

    @VTID(50)
    void lockAspectRatio(
        mol.office.MsoTriState rhs);

    @VTID(51)
    java.lang.String name();

    @VTID(52)
    void name(
        java.lang.String rhs);

    @VTID(53)
    mol.excel.ShapeNodes nodes();

    @VTID(53)
    @ReturnValue(defaultPropertyThrough={mol.excel.ShapeNodes.class})
    mol.excel.ShapeNode nodes(
        @MarshalAs(NativeType.VARIANT) java.lang.Object index);

    @VTID(54)
    float rotation();

    @VTID(55)
    void rotation(
        float rhs);

    @VTID(56)
    mol.excel.PictureFormat pictureFormat();

    @VTID(57)
    mol.excel.ShadowFormat shadow();

    @VTID(58)
    mol.excel.TextEffectFormat textEffect();

    @VTID(59)
    mol.excel.ThreeDFormat threeD();

    @VTID(60)
    float top();

    @VTID(61)
    void top(
        float rhs);

    @VTID(62)
    mol.office.MsoShapeType type();

    @VTID(63)
    mol.office.MsoTriState verticalFlip();

    @VTID(64)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object vertices();

    @VTID(65)
    mol.office.MsoTriState visible();

    @VTID(66)
    void visible(
        mol.office.MsoTriState rhs);

    @VTID(67)
    float width();

    @VTID(68)
    void width(
        float rhs);

    @VTID(69)
    int zOrderPosition();

    @VTID(70)
    mol.office.MsoBlackWhiteMode blackWhiteMode();

    @VTID(71)
    void blackWhiteMode(
        mol.office.MsoBlackWhiteMode rhs);

    @VTID(72)
    java.lang.String alternativeText();

    @VTID(73)
    void alternativeText(
        java.lang.String rhs);

    @VTID(74)
    mol.excel.DiagramNode diagramNode();

    @VTID(75)
    mol.office.MsoTriState hasDiagramNode();

    @VTID(76)
    mol.excel.Diagram diagram();

    @VTID(77)
    mol.office.MsoTriState hasDiagram();

    @VTID(78)
    mol.office.MsoTriState child();

    @VTID(79)
    mol.excel.Shape parentGroup();

    @VTID(80)
    mol.office.CanvasShapes canvasItems();

    @VTID(80)
    @ReturnValue(defaultPropertyThrough={mol.office.CanvasShapes.class})
    mol.excel.Shape canvasItems(
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
    mol.excel._Chart chart();

    @VTID(87)
    mol.office.MsoTriState hasChart();

    @VTID(88)
    mol.excel.TextFrame2 textFrame2();

    @VTID(89)
    mol.office.MsoShapeStyleIndex shapeStyle();

    @VTID(90)
    void shapeStyle(
        mol.office.MsoShapeStyleIndex rhs);

    @VTID(91)
    mol.office.MsoBackgroundStyleIndex backgroundStyle();

    @VTID(92)
    void backgroundStyle(
        mol.office.MsoBackgroundStyleIndex rhs);

    @VTID(93)
    mol.office.SoftEdgeFormat softEdge();

    @VTID(94)
    mol.office.GlowFormat glow();

    @VTID(95)
    mol.office.ReflectionFormat reflection();

}
