package mol.mshtml  ;

import com4j.*;

public enum _htmlEncoding implements ComEnum {
    htmlEncodingURL(0),
    htmlEncodingMultipart(1),
    htmlEncodingText(2),
    htmlEncoding_Max(2147483647),
    ;

    private final int value;
    _htmlEncoding(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}