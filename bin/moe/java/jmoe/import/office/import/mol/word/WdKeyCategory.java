package mol.word  ;

import com4j.*;

public enum WdKeyCategory implements ComEnum {
    wdKeyCategoryNil(-1),
    wdKeyCategoryDisable(0),
    wdKeyCategoryCommand(1),
    wdKeyCategoryMacro(2),
    wdKeyCategoryFont(3),
    wdKeyCategoryAutoText(4),
    wdKeyCategoryStyle(5),
    wdKeyCategorySymbol(6),
    wdKeyCategoryPrefix(7),
    ;

    private final int value;
    WdKeyCategory(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
