package mol.word  ;

import com4j.*;

public enum WdLineWidth implements ComEnum {
    wdLineWidth025pt(2),
    wdLineWidth050pt(4),
    wdLineWidth075pt(6),
    wdLineWidth100pt(8),
    wdLineWidth150pt(12),
    wdLineWidth225pt(18),
    wdLineWidth300pt(24),
    wdLineWidth450pt(36),
    wdLineWidth600pt(48),
    ;

    private final int value;
    WdLineWidth(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
