package mol.excel  ;

import com4j.*;
import mol.office.*;
import mol.vba.*;

@IID("{00020400-0000-0000-C000-000000000046}")
public interface Shapes extends Com4jObject,Iterable<Com4jObject> {
    @DISPID(148)
    @PropGet
    mol.excel._Application application();

    @DISPID(149)
    @PropGet
    mol.excel.XlCreator creator();

    @DISPID(150)
    @PropGet
    com4j.Com4jObject parent();

    @DISPID(118)
    @PropGet
    int count();

    @DISPID(170)
    mol.excel.Shape item(
        java.lang.Object index);

    @DISPID(0)
    @DefaultMethod
    mol.excel.Shape _Default(
        java.lang.Object index);

    @DISPID(-4)
    @PropGet
    java.util.Iterator<Com4jObject> iterator();

    @DISPID(1713)
    mol.excel.Shape addCallout(
        mol.office.MsoCalloutType type,
        float left,
        float top,
        float width,
        float height);

    @DISPID(1714)
    mol.excel.Shape addConnector(
        mol.office.MsoConnectorType type,
        float beginX,
        float beginY,
        float endX,
        float endY);

    @DISPID(1719)
    mol.excel.Shape addCurve(
        java.lang.Object safeArrayOfPoints);

    @DISPID(1721)
    mol.excel.Shape addLabel(
        mol.office.MsoTextOrientation orientation,
        float left,
        float top,
        float width,
        float height);

    @DISPID(1722)
    mol.excel.Shape addLine(
        float beginX,
        float beginY,
        float endX,
        float endY);

    @DISPID(1723)
    mol.excel.Shape addPicture(
        java.lang.String filename,
        mol.office.MsoTriState linkToFile,
        mol.office.MsoTriState saveWithDocument,
        float left,
        float top,
        float width,
        float height);

    @DISPID(1726)
    mol.excel.Shape addPolyline(
        java.lang.Object safeArrayOfPoints);

    @DISPID(1727)
    mol.excel.Shape addShape(
        mol.office.MsoAutoShapeType type,
        float left,
        float top,
        float width,
        float height);

    @DISPID(1728)
    mol.excel.Shape addTextEffect(
        mol.office.MsoPresetTextEffect presetTextEffect,
        java.lang.String text,
        java.lang.String fontName,
        float fontSize,
        mol.office.MsoTriState fontBold,
        mol.office.MsoTriState fontItalic,
        float left,
        float top);

    @DISPID(1734)
    mol.excel.Shape addTextbox(
        mol.office.MsoTextOrientation orientation,
        float left,
        float top,
        float width,
        float height);

    @DISPID(1735)
    mol.excel.FreeformBuilder buildFreeform(
        mol.office.MsoEditingType editingType,
        float x1,
        float y1);

    @DISPID(197)
    @PropGet
    mol.excel.ShapeRange range(
        java.lang.Object index);

    @DISPID(1737)
    void selectAll();

    @DISPID(1738)
    mol.excel.Shape addFormControl(
        mol.excel.XlFormControl type,
        int left,
        int top,
        int width,
        int height);

    @DISPID(1739)
    mol.excel.Shape addOLEObject(
        java.lang.Object classType,
        java.lang.Object filename,
        java.lang.Object link,
        java.lang.Object displayAsIcon,
        java.lang.Object iconFileName,
        java.lang.Object iconIndex,
        java.lang.Object iconLabel,
        java.lang.Object left,
        java.lang.Object top,
        java.lang.Object width,
        java.lang.Object height);

    @DISPID(2176)
    mol.excel.Shape addDiagram(
        mol.office.MsoDiagramType type,
        float left,
        float top,
        float width,
        float height);

    @DISPID(2177)
    mol.excel.Shape addCanvas(
        float left,
        float top,
        float width,
        float height);

    @DISPID(2665)
    mol.excel.Shape addChart(
        java.lang.Object xlChartType,
        java.lang.Object left,
        java.lang.Object top,
        java.lang.Object width,
        java.lang.Object height);

}
