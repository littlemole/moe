package mol.office  ;

import com4j.*;

@IID("{000C03A0-0000-0000-C000-000000000046}")
public interface OfficeTheme extends mol.office._IMsoDispObj {
    @VTID(9)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

    @VTID(10)
    mol.office.ThemeColorScheme themeColorScheme();

    @VTID(10)
    @ReturnValue(defaultPropertyThrough={mol.office.ThemeColorScheme.class})
    mol.office.ThemeColor themeColorScheme(
        mol.office.MsoThemeColorSchemeIndex index);

    @VTID(11)
    mol.office.ThemeFontScheme themeFontScheme();

    @VTID(12)
    mol.office.ThemeEffectScheme themeEffectScheme();

}
