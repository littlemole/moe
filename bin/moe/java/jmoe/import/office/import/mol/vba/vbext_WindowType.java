package mol.vba  ;

import com4j.*;

public enum vbext_WindowType implements ComEnum {
    vbext_wt_CodeWindow(0),
    vbext_wt_Designer(1),
    vbext_wt_Browser(2),
    vbext_wt_Watch(3),
    vbext_wt_Locals(4),
    vbext_wt_Immediate(5),
    vbext_wt_ProjectWindow(6),
    vbext_wt_PropertyWindow(7),
    vbext_wt_Find(8),
    vbext_wt_FindReplace(9),
    vbext_wt_Toolbox(10),
    vbext_wt_LinkedWindowFrame(11),
    vbext_wt_MainWindow(12),
    vbext_wt_ToolWindow(15),
    ;

    private final int value;
    vbext_WindowType(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
