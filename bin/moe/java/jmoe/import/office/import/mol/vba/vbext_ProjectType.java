package mol.vba  ;

import com4j.*;

public enum vbext_ProjectType implements ComEnum {
    vbext_pt_HostProject(100),
    vbext_pt_StandAlone(101),
    ;

    private final int value;
    vbext_ProjectType(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
