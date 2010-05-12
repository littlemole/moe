package mol.word  ;

import com4j.*;

public enum WdCaptionLabelID implements ComEnum {
    wdCaptionFigure(-1),
    wdCaptionTable(-2),
    wdCaptionEquation(-3),
    ;

    private final int value;
    WdCaptionLabelID(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
