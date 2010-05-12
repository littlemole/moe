package mol.word  ;

import com4j.*;

public enum WdListGalleryType implements ComEnum {
    wdBulletGallery(1),
    wdNumberGallery(2),
    wdOutlineNumberGallery(3),
    ;

    private final int value;
    WdListGalleryType(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
