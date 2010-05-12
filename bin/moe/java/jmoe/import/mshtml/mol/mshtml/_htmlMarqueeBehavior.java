package mol.mshtml  ;

import com4j.*;

public enum _htmlMarqueeBehavior implements ComEnum {
    htmlMarqueeBehaviorscroll(1),
    htmlMarqueeBehaviorslide(2),
    htmlMarqueeBehavioralternate(3),
    htmlMarqueeBehavior_Max(2147483647),
    ;

    private final int value;
    _htmlMarqueeBehavior(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
