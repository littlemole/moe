package mol.mshtml  ;

import com4j.*;

public enum _HTMLDlgEdge implements ComEnum {
    HTMLDlgEdgeSunken(0),
    HTMLDlgEdgeRaised(16),
    HTMLDlgEdge_Max(2147483647),
    ;

    private final int value;
    _HTMLDlgEdge(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
