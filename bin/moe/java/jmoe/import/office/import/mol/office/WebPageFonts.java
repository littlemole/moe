package mol.office  ;

import com4j.*;

@IID("{000C0914-0000-0000-C000-000000000046}")
public interface WebPageFonts extends mol.office._IMsoDispObj,Iterable<Com4jObject> {
    @VTID(9)
    int count();

    @VTID(10)
    @DefaultMethod
    mol.office.WebPageFont item(
        mol.office.MsoCharacterSet index);

    @VTID(11)
    java.util.Iterator<Com4jObject> iterator();

}
