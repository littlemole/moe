package mol.excel  ;

import com4j.*;

public enum XlRoutingSlipStatus implements ComEnum {
    xlNotYetRouted(0),
    xlRoutingComplete(2),
    xlRoutingInProgress(1),
    ;

    private final int value;
    XlRoutingSlipStatus(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
