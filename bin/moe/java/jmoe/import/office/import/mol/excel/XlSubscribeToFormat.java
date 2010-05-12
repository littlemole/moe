package mol.excel  ;

import com4j.*;

public enum XlSubscribeToFormat implements ComEnum {
    xlSubscribeToPicture(-4147),
    xlSubscribeToText(-4158),
    ;

    private final int value;
    XlSubscribeToFormat(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
