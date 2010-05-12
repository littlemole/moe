package mol.office  ;

import com4j.*;

public enum MsoPresetTexture implements ComEnum {
    msoPresetTextureMixed(-2),
    msoTexturePapyrus(1),
    msoTextureCanvas(2),
    msoTextureDenim(3),
    msoTextureWovenMat(4),
    msoTextureWaterDroplets(5),
    msoTexturePaperBag(6),
    msoTextureFishFossil(7),
    msoTextureSand(8),
    msoTextureGreenMarble(9),
    msoTextureWhiteMarble(10),
    msoTextureBrownMarble(11),
    msoTextureGranite(12),
    msoTextureNewsprint(13),
    msoTextureRecycledPaper(14),
    msoTextureParchment(15),
    msoTextureStationery(16),
    msoTextureBlueTissuePaper(17),
    msoTexturePinkTissuePaper(18),
    msoTexturePurpleMesh(19),
    msoTextureBouquet(20),
    msoTextureCork(21),
    msoTextureWalnut(22),
    msoTextureOak(23),
    msoTextureMediumWood(24),
    ;

    private final int value;
    MsoPresetTexture(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
