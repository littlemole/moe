package mol.word  ;

import com4j.*;

public enum WdXMLNodeType implements ComEnum {
    wdXMLNodeElement(1),
    wdXMLNodeAttribute(2),
    ;

    private final int value;
    WdXMLNodeType(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
