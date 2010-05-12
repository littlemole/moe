package mol.word  ;

import com4j.*;

public enum WdOMathJc implements ComEnum {
    wdOMathJcCenterGroup(1),
    wdOMathJcCenter(2),
    wdOMathJcLeft(3),
    wdOMathJcRight(4),
    wdOMathJcInline(7),
    ;

    private final int value;
    WdOMathJc(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
