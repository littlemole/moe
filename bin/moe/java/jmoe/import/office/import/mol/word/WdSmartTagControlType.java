package mol.word  ;

import com4j.*;

public enum WdSmartTagControlType implements ComEnum {
    wdControlSmartTag(1),
    wdControlLink(2),
    wdControlHelp(3),
    wdControlHelpURL(4),
    wdControlSeparator(5),
    wdControlButton(6),
    wdControlLabel(7),
    wdControlImage(8),
    wdControlCheckbox(9),
    wdControlTextbox(10),
    wdControlListbox(11),
    wdControlCombo(12),
    wdControlActiveX(13),
    wdControlDocumentFragment(14),
    wdControlDocumentFragmentURL(15),
    wdControlRadioGroup(16),
    ;

    private final int value;
    WdSmartTagControlType(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
