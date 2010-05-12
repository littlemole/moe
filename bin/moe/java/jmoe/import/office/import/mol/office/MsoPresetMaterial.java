package mol.office  ;

import com4j.*;

public enum MsoPresetMaterial implements ComEnum {
    msoPresetMaterialMixed(-2),
    msoMaterialMatte(1),
    msoMaterialPlastic(2),
    msoMaterialMetal(3),
    msoMaterialWireFrame(4),
    msoMaterialMatte2(5),
    msoMaterialPlastic2(6),
    msoMaterialMetal2(7),
    msoMaterialWarmMatte(8),
    msoMaterialTranslucentPowder(9),
    msoMaterialPowder(10),
    msoMaterialDarkEdge(11),
    msoMaterialSoftEdge(12),
    msoMaterialClear(13),
    msoMaterialFlat(14),
    msoMaterialSoftMetal(15),
    ;

    private final int value;
    MsoPresetMaterial(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
