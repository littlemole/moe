package mol.word  ;

import com4j.*;

public enum WdViewTypeOld implements ComEnum {
    wdPageView(3),
    wdOnlineView(6),
    ;

    private final int value;
    WdViewTypeOld(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
