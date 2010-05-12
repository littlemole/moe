package mol.word  ;

import com4j.*;

@IID("{396F9073-F9FD-11D3-8EA0-0050049A1A01}")
public interface CanvasShapes extends Com4jObject,Iterable<Com4jObject> {
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
        float height);

    @VTID(14)
    mol.word.Shape addConnector(
        mol.office.MsoConnectorType type,
        float beginX,
        float beginY,
        float endX,
        float endY);

    @VTID(15)
    mol.word.Shape addCurve(
        java.lang.Object safeArrayOfPoints);

    @VTID(16)
    mol.word.Shape addLabel(
        mol.office.MsoTextOrientation orientation,
        float left,
        float top,
        float width,
        float height);

    @VTID(17)
    mol.word.Shape addLine(
        float beginX,
        float beginY,
        float endX,
        float endY);

    @VTID(18)
    mol.word.Shape addPicture(
        java.lang.String fileName,
        java.lang.Object linkToFile,
        java.lang.Object saveWithDocument,
        java.lang.Object left,
        java.lang.Object top,
        java.lang.Object width,
        java.lang.Object height);

    @VTID(19)
    mol.word.Shape addPolyline(
        java.lang.Object safeArrayOfPoints);

    @VTID(20)
    mol.word.Shape addShape(
        int type,
        float left,
        float top,
        float width,
        float height);

    @VTID(21)
    mol.word.Shape addTextEffect(
        mol.office.MsoPresetTextEffect presetTextEffect,
        java.lang.String text,
        java.lang.String fontName,
        float fontSize,
        mol.office.MsoTriState fontBold,
        mol.office.MsoTriState fontItalic,
        float left,
        float top);

    @VTID(22)
    mol.word.Shape addTextbox(
        mol.office.MsoTextOrientation orientation,
        float left,
        float top,
        float width,
        float height);

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

}
