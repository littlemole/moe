package mol.vba  ;

import com4j.*;

public enum vbext_ComponentType implements ComEnum {
    vbext_ct_StdModule(1),
    vbext_ct_ClassModule(2),
    vbext_ct_MSForm(3),
    vbext_ct_ActiveXDesigner(11),
    vbext_ct_Document(100),
    ;

    private final int value;
    vbext_ComponentType(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
