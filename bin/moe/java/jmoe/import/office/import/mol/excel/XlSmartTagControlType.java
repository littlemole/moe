package mol.excel  ;

import com4j.*;

public enum XlSmartTagControlType implements ComEnum {
    xlSmartTagControlSmartTag(1),
    xlSmartTagControlLink(2),
    xlSmartTagControlHelp(3),
    xlSmartTagControlHelpURL(4),
    xlSmartTagControlSeparator(5),
    xlSmartTagControlButton(6),
    xlSmartTagControlLabel(7),
    xlSmartTagControlImage(8),
    xlSmartTagControlCheckbox(9),
    xlSmartTagControlTextbox(10),
    xlSmartTagControlListbox(11),
    xlSmartTagControlCombo(12),
    xlSmartTagControlActiveX(13),
    xlSmartTagControlRadioGroup(14),
    ;

    private final int value;
    XlSmartTagControlType(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
