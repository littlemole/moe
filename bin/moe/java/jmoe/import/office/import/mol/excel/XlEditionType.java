package mol.excel  ;

import com4j.*;

public enum XlEditionType implements ComEnum {
    xlPublisher(1),
    xlSubscriber(2),
    ;

    private final int value;
    XlEditionType(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
