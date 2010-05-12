package mol.word  ;

import com4j.*;

public enum WdConstants implements ComEnum {
    wdUndefined(9999999),
    wdToggle(9999998),
    wdForward(1073741823),
    wdBackward(-1073741823),
    wdAutoPosition(0),
    wdFirst(1),
    wdCreatorCode(1297307460),
    ;

    private final int value;
    WdConstants(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
