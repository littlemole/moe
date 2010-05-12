package mol.office  ;

import com4j.*;

@IID("{000C0371-0000-0000-C000-000000000046}")
public interface CanvasShapes extends mol.office._IMsoDispObj,Iterable<Com4jObject> {
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
    mol.office.Shape addCallout(
        mol.office.MsoCalloutType type,
        float left,
        float top,
        float width,
        float height);

    @VTID(14)
    mol.office.Shape addConnector(
        mol.office.MsoConnectorType type,
        float beginX,
        float beginY,
        float endX,
        float endY);

    @VTID(15)
    mol.office.Shape addCurve(
        @MarshalAs(NativeType.VARIANT) java.lang.Object safeArrayOfPoints);

    @VTID(16)
    mol.office.Shape addLabel(
        mol.office.MsoTextOrientation orientation,
        float left,
        float top,
        float width,
        float height);

    @VTID(17)
    mol.office.Shape addLine(
        float beginX,
        float beginY,
        float endX,
        float endY);

    @VTID(18)
    mol.office.Shape addPicture(
        java.lang.String fileName,
        mol.office.MsoTriState linkToFile,
        mol.office.MsoTriState saveWithDocument,
        float left,
        float top,
        float width,
        float height);

    @VTID(19)
    mol.office.Shape addPolyline(
        @MarshalAs(NativeType.VARIANT) java.lang.Object safeArrayOfPoints);

    @VTID(20)
    mol.office.Shape addShape(
        mol.office.MsoAutoShapeType type,
        float left,
        float top,
        float width,
        float height);

    @VTID(21)
    mol.office.Shape addTextEffect(
        mol.office.MsoPresetTextEffect presetTextEffect,
        java.lang.String text,
        java.lang.String fontName,
        float fontSize,
        mol.office.MsoTriState fontBold,
        mol.office.MsoTriState fontItalic,
        float left,
        float top);

    @VTID(22)
    mol.office.Shape addTextbox(
        mol.office.MsoTextOrientation orientation,
        float left,
        float top,
        float width,
        float height);

    @VTID(23)
    mol.office.FreeformBuilder buildFreeform(
        mol.office.MsoEditingType editingType,
        float x1,
        float y1);

    @VTID(24)
    mol.office.ShapeRange range(
        @MarshalAs(NativeType.VARIANT) java.lang.Object index);

    @VTID(25)
    void selectAll();

    @VTID(26)
    mol.office.Shape background();

}
