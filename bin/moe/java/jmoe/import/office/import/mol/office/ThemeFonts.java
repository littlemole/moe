package mol.office  ;

import com4j.*;

@IID("{000C03A4-0000-0000-C000-000000000046}")
public interface ThemeFonts extends mol.office._IMsoDispObj,Iterable<Com4jObject> {
    @VTID(9)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

    @VTID(10)
    int count();

    @VTID(11)
    @DefaultMethod
    mol.office.ThemeFont item(
        mol.office.MsoFontLanguageIndex index);

    @VTID(12)
    java.util.Iterator<Com4jObject> iterator();

}
