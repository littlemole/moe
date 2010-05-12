package mol.word  ;

import com4j.*;

public enum WdEmailHTMLFidelity implements ComEnum {
    wdEmailHTMLFidelityLow(1),
    wdEmailHTMLFidelityMedium(2),
    wdEmailHTMLFidelityHigh(3),
    ;

    private final int value;
    WdEmailHTMLFidelity(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
