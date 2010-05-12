package mol.excel  ;

import com4j.*;

public enum XlConsolidationFunction implements ComEnum {
    xlAverage(-4106),
    xlCount(-4112),
    xlCountNums(-4113),
    xlMax(-4136),
    xlMin(-4139),
    xlProduct(-4149),
    xlStDev(-4155),
    xlStDevP(-4156),
    xlSum(-4157),
    xlVar(-4164),
    xlVarP(-4165),
    xlUnknown(1000),
    ;

    private final int value;
    XlConsolidationFunction(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
