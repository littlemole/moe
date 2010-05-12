package mol.office  ;

import com4j.*;

public enum MsoPictureColorType implements ComEnum {
    msoPictureMixed(-2),
    msoPictureAutomatic(1),
    msoPictureGrayscale(2),
    msoPictureBlackAndWhite(3),
    msoPictureWatermark(4),
    ;

    private final int value;
    MsoPictureColorType(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
