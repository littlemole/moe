package mol.excel  ;

import com4j.*;

public enum XlCmdType implements ComEnum {
    xlCmdCube(1),
    xlCmdSql(2),
    xlCmdTable(3),
    xlCmdDefault(4),
    xlCmdList(5),
    ;

    private final int value;
    XlCmdType(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
