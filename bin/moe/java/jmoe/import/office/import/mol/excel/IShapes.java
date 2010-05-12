package mol.excel  ;

import com4j.*;

@IID("{0002443A-0001-0000-C000-000000000046}")
public interface IShapes extends Com4jObject,Iterable<Com4jObject> {
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
    mol.excel.Shape addCallout(
        mol.office.MsoCalloutType type,
        float left,
        float top,
        float width,
        float height);

    @VTID(15)
    mol.excel.Shape addConnector(
        mol.office.MsoConnectorType type,
        float beginX,
        float beginY,
        float endX,
        float endY);

    @VTID(16)
    mol.excel.Shape addCurve(
        @MarshalAs(NativeType.VARIANT) java.lang.Object safeArrayOfPoints);

    @VTID(17)
    mol.excel.Shape addLabel(
        mol.office.MsoTextOrientation orientation,
        float left,
        float top,
        float width,
        float height);

    @VTID(18)
    mol.excel.Shape addLine(
        float beginX,
        float beginY,
        float endX,
        float endY);

    @VTID(19)
    mol.excel.Shape addPicture(
        java.lang.String filename,
        mol.office.MsoTriState linkToFile,
        mol.office.MsoTriState saveWithDocument,
        float left,
        float top,
        float width,
        float height);

    @VTID(20)
    mol.excel.Shape addPolyline(
        @MarshalAs(NativeType.VARIANT) java.lang.Object safeArrayOfPoints);

    @VTID(21)
    mol.excel.Shape addShape(
        mol.office.MsoAutoShapeType type,
        float left,
        float top,
        float width,
        float height);

    @VTID(22)
    mol.excel.Shape addTextEffect(
        mol.office.MsoPresetTextEffect presetTextEffect,
        java.lang.String text,
        java.lang.String fontName,
        float fontSize,
        mol.office.MsoTriState fontBold,
        mol.office.MsoTriState fontItalic,
        float left,
        float top);

    @VTID(23)
    mol.excel.Shape addTextbox(
        mol.office.MsoTextOrientation orientation,
        float left,
        float top,
        float width,
        float height);

    @VTID(24)
    mol.excel.FreeformBuilder buildFreeform(
        mol.office.MsoEditingType editingType,
        float x1,
        float y1);

    @VTID(25)
    mol.excel.ShapeRange range(
        @MarshalAs(NativeType.VARIANT) java.lang.Object index);

    @VTID(26)
    void selectAll();

    @VTID(27)
    mol.excel.Shape addFormControl(
        mol.excel.XlFormControl type,
        int left,
        int top,
        int width,
        int height);

    @VTID(28)
    mol.excel.Shape addOLEObject(
        @MarshalAs(NativeType.VARIANT) java.lang.Object classType,
        @MarshalAs(NativeType.VARIANT) java.lang.Object filename,
        @MarshalAs(NativeType.VARIANT) java.lang.Object link,
        @MarshalAs(NativeType.VARIANT) java.lang.Object displayAsIcon,
        @MarshalAs(NativeType.VARIANT) java.lang.Object iconFileName,
        @MarshalAs(NativeType.VARIANT) java.lang.Object iconIndex,
        @MarshalAs(NativeType.VARIANT) java.lang.Object iconLabel,
        @MarshalAs(NativeType.VARIANT) java.lang.Object left,
        @MarshalAs(NativeType.VARIANT) java.lang.Object top,
        @MarshalAs(NativeType.VARIANT) java.lang.Object width,
        @MarshalAs(NativeType.VARIANT) java.lang.Object height);

    @VTID(29)
    mol.excel.Shape addDiagram(
        mol.office.MsoDiagramType type,
        float left,
        float top,
        float width,
        float height);

    @VTID(30)
    mol.excel.Shape addCanvas(
        float left,
        float top,
        float width,
        float height);

    @VTID(31)
    mol.excel.Shape addChart(
        @MarshalAs(NativeType.VARIANT) java.lang.Object xlChartType,
        @MarshalAs(NativeType.VARIANT) java.lang.Object left,
        @MarshalAs(NativeType.VARIANT) java.lang.Object top,
        @MarshalAs(NativeType.VARIANT) java.lang.Object width,
        @MarshalAs(NativeType.VARIANT) java.lang.Object height);

}
