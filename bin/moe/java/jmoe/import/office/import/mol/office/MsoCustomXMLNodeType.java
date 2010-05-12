package mol.office  ;

import com4j.*;

public enum MsoCustomXMLNodeType implements ComEnum {
    msoCustomXMLNodeElement(1),
    msoCustomXMLNodeAttribute(2),
    msoCustomXMLNodeText(3),
    msoCustomXMLNodeCData(4),
    msoCustomXMLNodeProcessingInstruction(7),
    msoCustomXMLNodeComment(8),
    msoCustomXMLNodeDocument(9),
    ;

    private final int value;
    MsoCustomXMLNodeType(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
