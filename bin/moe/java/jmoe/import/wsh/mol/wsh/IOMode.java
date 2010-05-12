package mol.wsh  ;

import com4j.*;

public enum IOMode implements ComEnum {
    ForReading(1),
    ForWriting(2),
    ForAppending(8),
    ;

    private final int value;
    IOMode(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
