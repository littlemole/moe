package mol.word  ;

import com4j.*;

public enum WdStyleType implements ComEnum {
    wdStyleTypeParagraph(1),
    wdStyleTypeCharacter(2),
    wdStyleTypeTable(3),
    wdStyleTypeList(4),
    wdStyleTypeParagraphOnly(5),
    wdStyleTypeLinked(6),
    ;

    private final int value;
    WdStyleType(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
