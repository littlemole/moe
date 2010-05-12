package mol.word  ;

import com4j.*;

public enum WdTablePosition implements ComEnum {
    wdTableTop(-999999),
    wdTableLeft(-999998),
    wdTableBottom(-999997),
    wdTableRight(-999996),
    wdTableCenter(-999995),
    wdTableInside(-999994),
    wdTableOutside(-999993),
    ;

    private final int value;
    WdTablePosition(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
