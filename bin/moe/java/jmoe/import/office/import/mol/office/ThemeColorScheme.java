package mol.office  ;

import com4j.*;

@IID("{000C03A2-0000-0000-C000-000000000046}")
public interface ThemeColorScheme extends mol.office._IMsoDispObj,Iterable<Com4jObject> {
    @VTID(9)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

    @VTID(10)
    int count();

    @VTID(11)
    @DefaultMethod
    mol.office.ThemeColor colors(
        mol.office.MsoThemeColorSchemeIndex index);

    @VTID(12)
    java.util.Iterator<Com4jObject> iterator();

    @VTID(13)
    void load(
        java.lang.String fileName);

    @VTID(14)
    void save(
        java.lang.String fileName);

    @VTID(15)
    int getCustomColor(
        java.lang.String name);

}
