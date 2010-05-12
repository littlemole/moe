package mol.excel  ;

import com4j.*;

public enum XlIconSet implements ComEnum {
    xl3Arrows(1),
    xl3ArrowsGray(2),
    xl3Flags(3),
    xl3TrafficLights1(4),
    xl3TrafficLights2(5),
    xl3Signs(6),
    xl3Symbols(7),
    xl3Symbols2(8),
    xl4Arrows(9),
    xl4ArrowsGray(10),
    xl4RedToBlack(11),
    xl4CRV(12),
    xl4TrafficLights(13),
    xl5Arrows(14),
    xl5ArrowsGray(15),
    xl5CRV(16),
    xl5Quarters(17),
    ;

    private final int value;
    XlIconSet(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
