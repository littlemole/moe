package mol.office  ;

import com4j.*;

public enum MsoShapeType implements ComEnum {
    msoShapeTypeMixed(-2),
    msoAutoShape(1),
    msoCallout(2),
    msoChart(3),
    msoComment(4),
    msoFreeform(5),
    msoGroup(6),
    msoEmbeddedOLEObject(7),
    msoFormControl(8),
    msoLine(9),
    msoLinkedOLEObject(10),
    msoLinkedPicture(11),
    msoOLEControlObject(12),
    msoPicture(13),
    msoPlaceholder(14),
    msoTextEffect(15),
    msoMedia(16),
    msoTextBox(17),
    msoScriptAnchor(18),
    msoTable(19),
    msoCanvas(20),
    msoDiagram(21),
    msoInk(22),
    msoInkComment(23),
    msoSmartArt(24),
    ;

    private final int value;
    MsoShapeType(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
