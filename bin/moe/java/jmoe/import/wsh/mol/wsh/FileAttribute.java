package mol.wsh  ;

import com4j.*;

public enum FileAttribute implements ComEnum {
    Normal(0),
    ReadOnly(1),
    Hidden(2),
    System(4),
    Volume(8),
    Directory(16),
    Archive(32),
    Alias(1024),
    Compressed(2048),
    ;

    private final int value;
    FileAttribute(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
