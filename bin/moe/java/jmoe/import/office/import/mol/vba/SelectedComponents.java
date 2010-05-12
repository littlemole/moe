package mol.vba  ;

import com4j.*;

@IID("{BE39F3D4-1B13-11D0-887F-00A0C90F2744}")
public interface SelectedComponents extends Com4jObject,Iterable<Com4jObject> {
    @VTID(7)
    @DefaultMethod
    mol.vba._Component item(
        int index);

    @VTID(8)
    mol.vba.Application application();

    @VTID(9)
    mol.vba._VBProject parent();

    @VTID(10)
    int count();

    @VTID(11)
    java.util.Iterator<Com4jObject> iterator();

}
