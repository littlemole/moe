package mol.mshtml  ;

import com4j.*;

public enum _styleBorderCollapse implements ComEnum {
    styleBorderCollapseNotSet(0),
    styleBorderCollapseSeparate(1),
    styleBorderCollapseCollapse(2),
    styleBorderCollapse_Max(2147483647),
    ;

    private final int value;
    _styleBorderCollapse(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
