package mol.mshtml  ;

import com4j.*;

public enum _mediaType implements ComEnum {
    mediaTypeNotSet(0),
    mediaTypeAll(511),
    mediaTypeAural(1),
    mediaTypeBraille(2),
    mediaTypeEmbossed(4),
    mediaTypeHandheld(8),
    mediaTypePrint(16),
    mediaTypeProjection(32),
    mediaTypeScreen(64),
    mediaTypeTty(128),
    mediaTypeTv(256),
    mediaType_Max(2147483647),
    ;

    private final int value;
    _mediaType(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
