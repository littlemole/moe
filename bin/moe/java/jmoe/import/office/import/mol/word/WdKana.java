package mol.word  ;

import com4j.*;

public enum WdKana implements ComEnum {
    wdKanaKatakana(8),
    wdKanaHiragana(9),
    ;

    private final int value;
    WdKana(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
