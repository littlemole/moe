package mol.office  ;

import com4j.*;

public enum MsoBlackWhiteMode implements ComEnum {
    msoBlackWhiteMixed(-2),
    msoBlackWhiteAutomatic(1),
    msoBlackWhiteGrayScale(2),
    msoBlackWhiteLightGrayScale(3),
    msoBlackWhiteInverseGrayScale(4),
    msoBlackWhiteGrayOutline(5),
    msoBlackWhiteBlackTextAndLine(6),
    msoBlackWhiteHighContrast(7),
    msoBlackWhiteBlack(8),
    msoBlackWhiteWhite(9),
    msoBlackWhiteDontShow(10),
    ;

    private final int value;
    MsoBlackWhiteMode(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
