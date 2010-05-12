package mol.word  ;

import com4j.*;

public enum WdXMLValidationStatus implements ComEnum {
    wdXMLValidationStatusOK(0),
    wdXMLValidationStatusCustom(-1072898048),
    ;

    private final int value;
    WdXMLValidationStatus(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
