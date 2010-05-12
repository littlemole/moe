package mol.mshtml  ;

import com4j.*;

public enum _HTMLDlgFlag implements ComEnum {
    HTMLDlgFlagNo(0),
    HTMLDlgFlagOff(0),
    HTMLDlgFlag0(0),
    HTMLDlgFlagYes(1),
    HTMLDlgFlagOn(1),
    HTMLDlgFlag1(1),
    HTMLDlgFlagNotSet(-1),
    HTMLDlgFlag_Max(2147483647),
    ;

    private final int value;
    _HTMLDlgFlag(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
