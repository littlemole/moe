package mol.word  ;

import com4j.*;

@IID("{000209C6-0000-0000-C000-000000000046}")
public interface ColorFormat extends Com4jObject {
    @VTID(7)
    mol.word._Application application();

    @VTID(8)
    int creator();

    @VTID(9)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

    @VTID(10)
    @DefaultMethod
    int rgb();

    @VTID(11)
    @DefaultMethod
    void rgb(
        int prop);

    @VTID(12)
    int schemeColor();

    @VTID(13)
    void schemeColor(
        int prop);

    @VTID(14)
    mol.office.MsoColorType type();

    @VTID(15)
    java.lang.String name();

    @VTID(16)
    void name(
        java.lang.String prop);

    @VTID(17)
    float tintAndShade();

    @VTID(18)
    void tintAndShade(
        float prop);

    @VTID(19)
    mol.office.MsoTriState overPrint();

    @VTID(20)
    void overPrint(
        mol.office.MsoTriState prop);

    @VTID(21)
    float ink(
        int index);

    @VTID(22)
    void ink(
        int index,
        float prop);

    @VTID(23)
    int cyan();

    @VTID(24)
    void cyan(
        int prop);

    @VTID(25)
    int magenta();

    @VTID(26)
    void magenta(
        int prop);

    @VTID(27)
    int yellow();

    @VTID(28)
    void yellow(
        int prop);

    @VTID(29)
    int black();

    @VTID(30)
    void black(
        int prop);

    @VTID(31)
    void setCMYK(
        int cyan,
        int magenta,
        int yellow,
        int black);

    @VTID(32)
    mol.word.WdThemeColorIndex objectThemeColor();

    @VTID(33)
    void objectThemeColor(
        mol.word.WdThemeColorIndex prop);

}
