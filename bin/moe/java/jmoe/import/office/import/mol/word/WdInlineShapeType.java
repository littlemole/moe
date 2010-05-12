package mol.word  ;

import com4j.*;

public enum WdInlineShapeType implements ComEnum {
    wdInlineShapeEmbeddedOLEObject(1),
    wdInlineShapeLinkedOLEObject(2),
    wdInlineShapePicture(3),
    wdInlineShapeLinkedPicture(4),
    wdInlineShapeOLEControlObject(5),
    wdInlineShapeHorizontalLine(6),
    wdInlineShapePictureHorizontalLine(7),
    wdInlineShapeLinkedPictureHorizontalLine(8),
    wdInlineShapePictureBullet(9),
    wdInlineShapeScriptAnchor(10),
    wdInlineShapeOWSAnchor(11),
    wdInlineShapeChart(12),
    wdInlineShapeDiagram(13),
    wdInlineShapeLockedCanvas(14),
    wdInlineShapeSmartArt(15),
    ;

    private final int value;
    WdInlineShapeType(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
