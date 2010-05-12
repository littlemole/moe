package mol.mshtml  ;

import com4j.*;

public enum _htmlRules implements ComEnum {
    htmlRulesNotSet(0),
    htmlRulesnone(1),
    htmlRulesgroups(2),
    htmlRulesrows(3),
    htmlRulescols(4),
    htmlRulesall(5),
    htmlRules_Max(2147483647),
    ;

    private final int value;
    _htmlRules(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
