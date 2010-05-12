package mol.office  ;

import com4j.*;

public enum MsoFileDialogType implements ComEnum {
    msoFileDialogOpen(1),
    msoFileDialogSaveAs(2),
    msoFileDialogFilePicker(3),
    msoFileDialogFolderPicker(4),
    ;

    private final int value;
    MsoFileDialogType(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
