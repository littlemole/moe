package mol.mshtml  ;

import com4j.*;

public enum _htmlInput implements ComEnum {
    htmlInputNotSet(0),
    htmlInputButton(1),
    htmlInputCheckbox(2),
    htmlInputFile(3),
    htmlInputHidden(4),
    htmlInputImage(5),
    htmlInputPassword(6),
    htmlInputRadio(7),
    htmlInputReset(8),
    htmlInputSelectOne(9),
    htmlInputSelectMultiple(10),
    htmlInputSubmit(11),
    htmlInputText(12),
    htmlInputTextarea(13),
    htmlInputRichtext(14),
    htmlInput_Max(2147483647),
    ;

    private final int value;
    _htmlInput(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
