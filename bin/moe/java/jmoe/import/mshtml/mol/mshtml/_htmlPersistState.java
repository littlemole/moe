package mol.mshtml  ;

import com4j.*;

public enum _htmlPersistState implements ComEnum {
    htmlPersistStateNormal(0),
    htmlPersistStateFavorite(1),
    htmlPersistStateHistory(2),
    htmlPersistStateSnapshot(3),
    htmlPersistStateUserData(4),
    htmlPersistState_Max(2147483647),
    ;

    private final int value;
    _htmlPersistState(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
