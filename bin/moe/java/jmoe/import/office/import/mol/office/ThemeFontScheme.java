package mol.office  ;

import com4j.*;

@IID("{000C03A5-0000-0000-C000-000000000046}")
public interface ThemeFontScheme extends mol.office._IMsoDispObj {
    @VTID(9)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

    @VTID(10)
    void load(
        java.lang.String fileName);

    @VTID(11)
    void save(
        java.lang.String fileName);

    @VTID(12)
    mol.office.ThemeFonts minorFont();

    @VTID(12)
    @ReturnValue(defaultPropertyThrough={mol.office.ThemeFonts.class})
    mol.office.ThemeFont minorFont(
        mol.office.MsoFontLanguageIndex index);

    @VTID(13)
    mol.office.ThemeFonts majorFont();

    @VTID(13)
    @ReturnValue(defaultPropertyThrough={mol.office.ThemeFonts.class})
    mol.office.ThemeFont majorFont(
        mol.office.MsoFontLanguageIndex index);

}
