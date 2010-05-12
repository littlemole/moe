package mol.wsh  ;

import com4j.*;

public enum WshWindowStyle implements ComEnum {
    WshHide(0),
    WshNormalFocus(1),
    WshMinimizedFocus(2),
    WshMaximizedFocus(3),
    WshNormalNoFocus(4),
    WshMinimizedNoFocus(6),
    ;

    private final int value;
    WshWindowStyle(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
