package mol.word  ;

import com4j.*;

public enum WdCollapseDirection implements ComEnum {
    wdCollapseStart(1),
    wdCollapseEnd(0),
    ;

    private final int value;
    WdCollapseDirection(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
