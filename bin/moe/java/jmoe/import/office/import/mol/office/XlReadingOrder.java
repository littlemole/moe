package mol.office  ;

import com4j.*;

public enum XlReadingOrder implements ComEnum {
    xlContext(-5002),
    xlLTR(-5003),
    xlRTL(-5004),
    ;

    private final int value;
    XlReadingOrder(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
