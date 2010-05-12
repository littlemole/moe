package mol.excel  ;

import com4j.*;
import mol.office.*;
import mol.vba.*;

@IID("{00020400-0000-0000-C000-000000000046}")
public interface Shape extends Com4jObject {
    @DISPID(148)
    @PropGet
    mol.excel._Application application();

    @DISPID(149)
    @PropGet
    mol.excel.XlCreator creator();

    @DISPID(150)
    @PropGet
    com4j.Com4jObject parent();

    @DISPID(1675)
    void apply();

    @DISPID(117)
    void delete();

    @DISPID(1039)
    mol.excel.Shape duplicate();

    @DISPID(1676)
    void flip(
        mol.office.MsoFlipCmd flipCmd);

    @DISPID(1678)
    void incrementLeft(
        float increment);

    @DISPID(1680)
    void incrementRotation(
        float increment);

    @DISPID(1681)
    void incrementTop(
        float increment);

    @DISPID(1682)
    void pickUp();

    @DISPID(1683)
    void rerouteConnections();

    @DISPID(1684)
    void scaleHeight(
        float factor,
        mol.office.MsoTriState relativeToOriginalSize,
        java.lang.Object scale);

    @DISPID(1688)
    void scaleWidth(
        float factor,
        mol.office.MsoTriState relativeToOriginalSize,
        java.lang.Object scale);

    @DISPID(235)
    void select(
        java.lang.Object replace);

    @DISPID(1689)
    void setShapesDefaultProperties();

    @DISPID(244)
    mol.excel.ShapeRange ungroup();

    @DISPID(622)
    void zOrder(
        mol.office.MsoZOrderCmd zOrderCmd);

    @DISPID(1691)
    @PropGet
    mol.excel.Adjustments adjustments();

    @DISPID(1692)
    @PropGet
    mol.excel.TextFrame textFrame();

    @DISPID(1693)
    @PropGet
    mol.office.MsoAutoShapeType autoShapeType();

    @DISPID(1693)
    @PropPut
    void autoShapeType(
        mol.office.MsoAutoShapeType rhs);

    @DISPID(1694)
    @PropGet
    mol.excel.CalloutFormat callout();

    @DISPID(1695)
    @PropGet
    int connectionSiteCount();

    @DISPID(1696)
    @PropGet
    mol.office.MsoTriState connector();

    @DISPID(1697)
    @PropGet
    mol.excel.ConnectorFormat connectorFormat();

    @DISPID(1663)
    @PropGet
    mol.excel.FillFormat fill();

    @DISPID(1698)
    @PropGet
    mol.excel.GroupShapes groupItems();

    @DISPID(123)
    @PropGet
    float height();

    @DISPID(123)
    @PropPut
    void height(
        float rhs);

    @DISPID(1699)
    @PropGet
    mol.office.MsoTriState horizontalFlip();

    @DISPID(127)
    @PropGet
    float left();

    @DISPID(127)
    @PropPut
    void left(
        float rhs);

    @DISPID(817)
    @PropGet
    mol.excel.LineFormat line();

    @DISPID(1700)
    @PropGet
    mol.office.MsoTriState lockAspectRatio();

    @DISPID(1700)
    @PropPut
    void lockAspectRatio(
        mol.office.MsoTriState rhs);

    @DISPID(110)
    @PropGet
    java.lang.String name();

    @DISPID(110)
    @PropPut
    void name(
        java.lang.String rhs);

    @DISPID(1701)
    @PropGet
    mol.excel.ShapeNodes nodes();

    @DISPID(59)
    @PropGet
    float rotation();

    @DISPID(59)
    @PropPut
    void rotation(
        float rhs);

    @DISPID(1631)
    @PropGet
    mol.excel.PictureFormat pictureFormat();

    @DISPID(103)
    @PropGet
    mol.excel.ShadowFormat shadow();

    @DISPID(1702)
    @PropGet
    mol.excel.TextEffectFormat textEffect();

    @DISPID(1703)
    @PropGet
    mol.excel.ThreeDFormat threeD();

    @DISPID(126)
    @PropGet
    float top();

    @DISPID(126)
    @PropPut
    void top(
        float rhs);

    @DISPID(108)
    @PropGet
    mol.office.MsoShapeType type();

    @DISPID(1704)
    @PropGet
    mol.office.MsoTriState verticalFlip();

    @DISPID(621)
    @PropGet
    java.lang.Object vertices();

    @DISPID(558)
    @PropGet
    mol.office.MsoTriState visible();

    @DISPID(558)
    @PropPut
    void visible(
        mol.office.MsoTriState rhs);

    @DISPID(122)
    @PropGet
    float width();

    @DISPID(122)
    @PropPut
    void width(
        float rhs);

    @DISPID(1705)
    @PropGet
    int zOrderPosition();

    @DISPID(1706)
    @PropGet
    mol.excel.Hyperlink hyperlink();

    @DISPID(1707)
    @PropGet
    mol.office.MsoBlackWhiteMode blackWhiteMode();

    @DISPID(1707)
    @PropPut
    void blackWhiteMode(
        mol.office.MsoBlackWhiteMode rhs);

    @DISPID(1708)
    @PropGet
    com4j.Com4jObject drawingObject();

    @DISPID(596)
    @PropGet
    java.lang.String onAction();

    @DISPID(596)
    @PropPut
    void onAction(
        java.lang.String rhs);

    @DISPID(269)
    @PropGet
    boolean locked();

    @DISPID(269)
    @PropPut
    void locked(
        boolean rhs);

    @DISPID(620)
    @PropGet
    mol.excel.Range topLeftCell();

    @DISPID(615)
    @PropGet
    mol.excel.Range bottomRightCell();

    @DISPID(617)
    @PropGet
    mol.excel.XlPlacement placement();

    @DISPID(617)
    @PropPut
    void placement(
        mol.excel.XlPlacement rhs);

    @DISPID(551)
    void copy();

    @DISPID(565)
    void cut();

    @DISPID(213)
    void copyPicture(
        java.lang.Object appearance,
        java.lang.Object format);

    @DISPID(1709)
    @PropGet
    mol.excel.ControlFormat controlFormat();

    @DISPID(1710)
    @PropGet
    mol.excel.LinkFormat linkFormat();

    @DISPID(1711)
    @PropGet
    mol.excel.OLEFormat oleFormat();

    @DISPID(1712)
    @PropGet
    mol.excel.XlFormControl formControlType();

    @DISPID(1891)
    @PropGet
    java.lang.String alternativeText();

    @DISPID(1891)
    @PropPut
    void alternativeText(
        java.lang.String rhs);

    @DISPID(1892)
    @PropGet
    mol.office.Script script();

    @DISPID(2165)
    @PropGet
    mol.excel.DiagramNode diagramNode();

    @DISPID(2166)
    @PropGet
    mol.office.MsoTriState hasDiagramNode();

    @DISPID(2167)
    @PropGet
    mol.excel.Diagram diagram();

    @DISPID(2168)
    @PropGet
    mol.office.MsoTriState hasDiagram();

    @DISPID(2169)
    @PropGet
    mol.office.MsoTriState child();

    @DISPID(2170)
    @PropGet
    mol.excel.Shape parentGroup();

    @DISPID(2171)
    @PropGet
    mol.office.CanvasShapes canvasItems();

    @DISPID(570)
    @PropGet
    int id();

    @DISPID(2172)
    void canvasCropLeft(
        float increment);

    @DISPID(2173)
    void canvasCropTop(
        float increment);

    @DISPID(2174)
    void canvasCropRight(
        float increment);

    @DISPID(2175)
    void canvasCropBottom(
        float increment);

    @DISPID(7)
    @PropGet
    mol.excel._Chart chart();

    @DISPID(2658)
    @PropGet
    mol.office.MsoTriState hasChart();

    @DISPID(2659)
    @PropGet
    mol.excel.TextFrame2 textFrame2();

    @DISPID(2660)
    @PropGet
    mol.office.MsoShapeStyleIndex shapeStyle();

    @DISPID(2660)
    @PropPut
    void shapeStyle(
        mol.office.MsoShapeStyleIndex rhs);

    @DISPID(2661)
    @PropGet
    mol.office.MsoBackgroundStyleIndex backgroundStyle();

    @DISPID(2661)
    @PropPut
    void backgroundStyle(
        mol.office.MsoBackgroundStyleIndex rhs);

    @DISPID(2662)
    @PropGet
    mol.office.SoftEdgeFormat softEdge();

    @DISPID(2663)
    @PropGet
    mol.office.GlowFormat glow();

    @DISPID(2664)
    @PropGet
    mol.office.ReflectionFormat reflection();

}
