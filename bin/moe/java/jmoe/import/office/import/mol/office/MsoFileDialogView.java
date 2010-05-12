package mol.office  ;

import com4j.*;

public enum MsoFileDialogView implements ComEnum {
    msoFileDialogViewList(1),
    msoFileDialogViewDetails(2),
    msoFileDialogViewProperties(3),
    msoFileDialogViewPreview(4),
    msoFileDialogViewThumbnail(5),
    msoFileDialogViewLargeIcons(6),
    msoFileDialogViewSmallIcons(7),
    msoFileDialogViewWebView(8),
    msoFileDialogViewTiles(9),
    ;

    private final int value;
    MsoFileDialogView(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
