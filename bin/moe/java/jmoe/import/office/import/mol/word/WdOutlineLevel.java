package mol.word  ;

import com4j.*;

public enum WdOutlineLevel implements ComEnum {
    wdOutlineLevel1(1),
    wdOutlineLevel2(2),
    wdOutlineLevel3(3),
    wdOutlineLevel4(4),
    wdOutlineLevel5(5),
    wdOutlineLevel6(6),
    wdOutlineLevel7(7),
    wdOutlineLevel8(8),
    wdOutlineLevel9(9),
    wdOutlineLevelBodyText(10),
    ;

    private final int value;
    WdOutlineLevel(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
