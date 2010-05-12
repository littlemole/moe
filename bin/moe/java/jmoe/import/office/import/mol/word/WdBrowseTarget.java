package mol.word  ;

import com4j.*;

public enum WdBrowseTarget implements ComEnum {
    wdBrowsePage(1),
    wdBrowseSection(2),
    wdBrowseComment(3),
    wdBrowseFootnote(4),
    wdBrowseEndnote(5),
    wdBrowseField(6),
    wdBrowseTable(7),
    wdBrowseGraphic(8),
    wdBrowseHeading(9),
    wdBrowseEdit(10),
    wdBrowseFind(11),
    wdBrowseGoTo(12),
    ;

    private final int value;
    WdBrowseTarget(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
