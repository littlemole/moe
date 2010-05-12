package mol.office  ;

import com4j.*;

public enum MsoHTMLProjectOpen implements ComEnum {
    msoHTMLProjectOpenSourceView(1),
    msoHTMLProjectOpenTextView(2),
    ;

    private final int value;
    MsoHTMLProjectOpen(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
