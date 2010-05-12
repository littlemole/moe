package mol.office  ;

import com4j.*;

@IID("{000C0913-0000-0000-C000-000000000046}")
public interface WebPageFont extends mol.office._IMsoDispObj {
    @VTID(9)
    java.lang.String proportionalFont();

    @VTID(10)
    void proportionalFont(
        java.lang.String pstr);

    @VTID(11)
    float proportionalFontSize();

    @VTID(12)
    void proportionalFontSize(
        float pf);

    @VTID(13)
    java.lang.String fixedWidthFont();

    @VTID(14)
    void fixedWidthFont(
        java.lang.String pstr);

    @VTID(15)
    float fixedWidthFontSize();

    @VTID(16)
    void fixedWidthFontSize(
        float pf);

}
