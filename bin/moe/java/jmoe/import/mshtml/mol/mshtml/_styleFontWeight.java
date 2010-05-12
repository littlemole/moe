package mol.mshtml  ;

import com4j.*;

public enum _styleFontWeight implements ComEnum {
    styleFontWeightNotSet(0),
    styleFontWeight100(1),
    styleFontWeight200(2),
    styleFontWeight300(3),
    styleFontWeight400(4),
    styleFontWeight500(5),
    styleFontWeight600(6),
    styleFontWeight700(7),
    styleFontWeight800(8),
    styleFontWeight900(9),
    styleFontWeightNormal(10),
    styleFontWeightBold(11),
    styleFontWeightBolder(12),
    styleFontWeightLighter(13),
    styleFontWeight_Max(2147483647),
    ;

    private final int value;
    _styleFontWeight(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
