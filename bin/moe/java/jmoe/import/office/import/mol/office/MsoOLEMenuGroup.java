package mol.office  ;

import com4j.*;

public enum MsoOLEMenuGroup implements ComEnum {
    msoOLEMenuGroupNone(-1),
    msoOLEMenuGroupFile(0),
    msoOLEMenuGroupEdit(1),
    msoOLEMenuGroupContainer(2),
    msoOLEMenuGroupObject(3),
    msoOLEMenuGroupWindow(4),
    msoOLEMenuGroupHelp(5),
    ;

    private final int value;
    MsoOLEMenuGroup(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
