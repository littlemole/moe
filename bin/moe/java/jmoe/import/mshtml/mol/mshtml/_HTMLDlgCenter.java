package mol.mshtml  ;

import com4j.*;

public enum _HTMLDlgCenter implements ComEnum {
    HTMLDlgCenterNo(0),
    HTMLDlgCenterOff(0),
    HTMLDlgCenter0(0),
    HTMLDlgCenterYes(1),
    HTMLDlgCenterOn(1),
    HTMLDlgCenter1(1),
    HTMLDlgCenterParent(1),
    HTMLDlgCenterDesktop(2),
    HTMLDlgCenter_Max(2147483647),
    ;

    private final int value;
    _HTMLDlgCenter(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
