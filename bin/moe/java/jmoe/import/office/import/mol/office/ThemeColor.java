package mol.office  ;

import com4j.*;

@IID("{000C03A1-0000-0000-C000-000000000046}")
public interface ThemeColor extends mol.office._IMsoDispObj {
    @VTID(9)
    @DefaultMethod
    int rgb();

    @VTID(10)
    @DefaultMethod
    void rgb(
        int rgb);

    @VTID(11)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

    @VTID(12)
    mol.office.MsoThemeColorSchemeIndex themeColorSchemeIndex();

}
