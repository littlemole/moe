package mol.word  ;

import com4j.*;

public enum WdSubscriberFormats implements ComEnum {
    wdSubscriberBestFormat(0),
    wdSubscriberRTF(1),
    wdSubscriberText(2),
    wdSubscriberPict(4),
    ;

    private final int value;
    WdSubscriberFormats(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
