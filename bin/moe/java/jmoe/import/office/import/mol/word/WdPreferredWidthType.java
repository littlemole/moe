package mol.word  ;

import com4j.*;

public enum WdPreferredWidthType implements ComEnum {
    wdPreferredWidthAuto(1),
    wdPreferredWidthPercent(2),
    wdPreferredWidthPoints(3),
    ;

    private final int value;
    WdPreferredWidthType(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
