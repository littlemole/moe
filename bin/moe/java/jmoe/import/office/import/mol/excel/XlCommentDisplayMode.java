package mol.excel  ;

import com4j.*;

public enum XlCommentDisplayMode implements ComEnum {
    xlNoIndicator(0),
    xlCommentIndicatorOnly(-1),
    xlCommentAndIndicator(1),
    ;

    private final int value;
    XlCommentDisplayMode(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
