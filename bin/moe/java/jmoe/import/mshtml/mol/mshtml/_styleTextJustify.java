package mol.mshtml  ;

import com4j.*;

public enum _styleTextJustify implements ComEnum {
    styleTextJustifyNotSet(0),
    styleTextJustifyInterWord(1),
    styleTextJustifyNewspaper(2),
    styleTextJustifyDistribute(3),
    styleTextJustifyDistributeAllLines(4),
    styleTextJustifyInterIdeograph(5),
    styleTextJustifyInterCluster(6),
    styleTextJustifyKashida(7),
    styleTextJustifyAuto(8),
    styleTextJustify_Max(2147483647),
    ;

    private final int value;
    _styleTextJustify(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
