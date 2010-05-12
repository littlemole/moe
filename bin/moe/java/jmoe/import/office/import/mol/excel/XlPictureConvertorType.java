package mol.excel  ;

import com4j.*;

public enum XlPictureConvertorType implements ComEnum {
    xlBMP(1),
    xlCGM(7),
    xlDRW(4),
    xlDXF(5),
    xlEPS(8),
    xlHGL(6),
    xlPCT(13),
    xlPCX(10),
    xlPIC(11),
    xlPLT(12),
    xlTIF(9),
    xlWMF(2),
    xlWPG(3),
    ;

    private final int value;
    XlPictureConvertorType(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
