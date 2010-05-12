package mol.excel  ;

import com4j.*;

public enum XlCategoryType implements ComEnum {
    xlCategoryScale(2),
    xlTimeScale(3),
    xlAutomaticScale(-4105),
    ;

    private final int value;
    XlCategoryType(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
