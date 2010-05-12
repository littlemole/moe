package mol.word  ;

import com4j.*;

public enum WdDefaultFilePath implements ComEnum {
    wdDocumentsPath(0),
    wdPicturesPath(1),
    wdUserTemplatesPath(2),
    wdWorkgroupTemplatesPath(3),
    wdUserOptionsPath(4),
    wdAutoRecoverPath(5),
    wdToolsPath(6),
    wdTutorialPath(7),
    wdStartupPath(8),
    wdProgramPath(9),
    wdGraphicsFiltersPath(10),
    wdTextConvertersPath(11),
    wdProofingToolsPath(12),
    wdTempFilePath(13),
    wdCurrentFolderPath(14),
    wdStyleGalleryPath(15),
    wdBorderArtPath(19),
    ;

    private final int value;
    WdDefaultFilePath(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
