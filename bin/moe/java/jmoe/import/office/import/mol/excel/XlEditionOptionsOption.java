package mol.excel  ;

import com4j.*;

public enum XlEditionOptionsOption implements ComEnum {
    xlAutomaticUpdate(4),
    xlCancel(1),
    xlChangeAttributes(6),
    xlManualUpdate(5),
    xlOpenSource(3),
    xlSelect(3),
    xlSendPublisher(2),
    xlUpdateSubscriber(2),
    ;

    private final int value;
    XlEditionOptionsOption(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
