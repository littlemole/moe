package mol.word  ;

import com4j.*;

public enum WdFramePosition implements ComEnum {
    wdFrameTop(-999999),
    wdFrameLeft(-999998),
    wdFrameBottom(-999997),
    wdFrameRight(-999996),
    wdFrameCenter(-999995),
    wdFrameInside(-999994),
    wdFrameOutside(-999993),
    ;

    private final int value;
    WdFramePosition(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
