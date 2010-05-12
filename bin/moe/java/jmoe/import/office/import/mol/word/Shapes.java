package mol.word  ;

import com4j.*;

@IID("{0002099F-0000-0000-C000-000000000046}")
public interface Shapes extends Com4jObject,Iterable<Com4jObject> {
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
    @DefaultMethod
    mol.word.Shape item(
        java.lang.Object index);

    @VTID(13)
    mol.word.Shape addCallout(
        mol.office.MsoCalloutType type,
        float left,
        float top,
        float width,
        float height,
        java.lang.Object anchor);

    @VTID(14)
    mol.word.Shape addConnector(
        mol.office.MsoConnectorType type,
        float beginX,
        float beginY,
        float endX,
        float endY);

    @VTID(15)
    mol.word.Shape addCurve(
        java.lang.Object safeArrayOfPoints,
        java.lang.Object anchor);

    @VTID(16)
    mol.word.Shape addLabel(
        mol.office.MsoTextOrientation orientation,
        float left,
        float top,
        float width,
        float height,
        java.lang.Object anchor);

    @VTID(17)
    mol.word.Shape addLine(
        float beginX,
        float beginY,
        float endX,
        float endY,
        java.lang.Object anchor);

    @VTID(18)
    mol.word.Shape addPicture(
        java.lang.String fileName,
        java.lang.Object linkToFile,
        java.lang.Object saveWithDocument,
        java.lang.Object left,
        java.lang.Object top,
        java.lang.Object width,
        java.lang.Object height,
        java.lang.Object anchor);

    @VTID(19)
    mol.word.Shape addPolyline(
        java.lang.Object safeArrayOfPoints,
        java.lang.Object anchor);

    @VTID(20)
    mol.word.Shape addShape(
        int type,
        float left,
        float top,
        float width,
        float height,
        java.lang.Object anchor);

    @VTID(21)
    mol.word.Shape addTextEffect(
        mol.office.MsoPresetTextEffect presetTextEffect,
        java.lang.String text,
        java.lang.String fontName,
        float fontSize,
        mol.office.MsoTriState fontBold,
        mol.office.MsoTriState fontItalic,
        float left,
        float top,
        java.lang.Object anchor);

    @VTID(22)
    mol.word.Shape addTextbox(
        mol.office.MsoTextOrientation orientation,
        float left,
        float top,
        float width,
        float height,
        java.lang.Object anchor);

    @VTID(23)
    mol.word.FreeformBuilder buildFreeform(
        mol.office.MsoEditingType editingType,
        float x1,
        float y1);

    @VTID(24)
    mol.word.ShapeRange range(
        java.lang.Object index);

    @VTID(25)
    void selectAll();

    @VTID(26)
    mol.word.Shape addOLEObject(
        java.lang.Object classType,
        java.lang.Object fileName,
        java.lang.Object linkToFile,
        java.lang.Object displayAsIcon,
        java.lang.Object iconFileName,
        java.lang.Object iconIndex,
        java.lang.Object iconLabel,
        java.lang.Object left,
        java.lang.Object top,
        java.lang.Object width,
        java.lang.Object height,
        java.lang.Object anchor);

    @VTID(27)
    mol.word.Shape addOLEControl(
        java.lang.Object classType,
        java.lang.Object left,
        java.lang.Object top,
        java.lang.Object width,
        java.lang.Object height,
        java.lang.Object anchor);

    @VTID(28)
    mol.word.Shape addDiagram(
        mol.office.MsoDiagramType type,
        float left,
        float top,
        float width,
        float height,
        java.lang.Object anchor);

    @VTID(29)
    mol.word.Shape addCanvas(
        float left,
        float top,
        float width,
        float height,
        java.lang.Object anchor);

    @VTID(30)
    mol.word.Shape addChart(
        mol.excel.XlChartType type,
        java.lang.Object left,
        java.lang.Object top,
        java.lang.Object width,
        java.lang.Object height,
        java.lang.Object anchor);

}
