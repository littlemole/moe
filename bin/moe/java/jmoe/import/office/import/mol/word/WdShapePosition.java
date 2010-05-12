package mol.word  ;

import com4j.*;

public enum WdShapePosition implements ComEnum {
    wdShapeTop(-999999),
    wdShapeLeft(-999998),
    wdShapeBottom(-999997),
    wdShapeRight(-999996),
    wdShapeCenter(-999995),
    wdShapeInside(-999994),
    wdShapeOutside(-999993),
    ;

    private final int value;
    WdShapePosition(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
