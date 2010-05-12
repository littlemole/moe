package mol.excel  ;

import com4j.*;

@IID("{000C0312-0000-0000-C000-000000000046}")
public interface ColorFormat extends mol.office._IMsoDispObj {
    @VTID(9)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

    @VTID(10)
    @DefaultMethod
    int rgb();

    @VTID(11)
    @DefaultMethod
    void rgb(
        int rgb);

    @VTID(12)
    int schemeColor();

    @VTID(13)
    void schemeColor(
        int schemeColor);

    @VTID(14)
    mol.office.MsoColorType type();

    @VTID(15)
    float tintAndShade();

    @VTID(16)
    void tintAndShade(
        float pValue);

    @VTID(17)
    mol.office.MsoThemeColorIndex objectThemeColor();

    @VTID(18)
    void objectThemeColor(
        mol.office.MsoThemeColorIndex objectThemeColor);

}
