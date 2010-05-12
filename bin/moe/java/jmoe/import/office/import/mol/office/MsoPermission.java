package mol.office  ;

import com4j.*;

public enum MsoPermission implements ComEnum {
    msoPermissionView(1),
    msoPermissionRead(1),
    msoPermissionEdit(2),
    msoPermissionSave(4),
    msoPermissionExtract(8),
    msoPermissionChange(15),
    msoPermissionPrint(16),
    msoPermissionObjModel(32),
    msoPermissionFullControl(64),
    msoPermissionAllCommon(127),
    ;

    private final int value;
    MsoPermission(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
