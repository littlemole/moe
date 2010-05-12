package mol.excel  ;

import com4j.*;

public enum XlRoutingSlipDelivery implements ComEnum {
    xlAllAtOnce(2),
    xlOneAfterAnother(1),
    ;

    private final int value;
    XlRoutingSlipDelivery(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
