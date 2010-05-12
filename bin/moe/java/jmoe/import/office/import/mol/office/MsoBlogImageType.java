package mol.office  ;

import com4j.*;

public enum MsoBlogImageType implements ComEnum {
    msoblogImageTypeJPEG(1),
    msoblogImageTypeGIF(2),
    msoblogImageTypePNG(3),
    ;

    private final int value;
    MsoBlogImageType(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
