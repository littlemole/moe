package mol.word  ;

import com4j.*;

public enum WdGutterStyleOld implements ComEnum {
    wdGutterStyleLatin(-10),
    wdGutterStyleBidi(2),
    ;

    private final int value;
    WdGutterStyleOld(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
