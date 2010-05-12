package mol.office  ;

import com4j.*;

@IID("{000C036C-0000-0000-C000-000000000046}")
public interface FileTypes extends mol.office._IMsoDispObj,Iterable<Com4jObject> {
    @VTID(9)
    @DefaultMethod
    mol.office.MsoFileType item(
        int index);

    @VTID(10)
    int count();

    @VTID(11)
    void add(
        mol.office.MsoFileType fileType);

    @VTID(12)
    void remove(
        int index);

    @VTID(13)
    java.util.Iterator<Com4jObject> iterator();

}
