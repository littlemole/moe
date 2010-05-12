package mol.vba  ;

import com4j.*;

@IID("{0002E165-0000-0000-C000-000000000046}")
public interface _VBProjects_Old extends Com4jObject,Iterable<Com4jObject> {
    @VTID(7)
    @DefaultMethod
    mol.vba._VBProject item(
        @MarshalAs(NativeType.VARIANT) java.lang.Object index);

    @VTID(8)
    mol.vba.VBE vbe();

    @VTID(9)
    mol.vba.VBE parent();

    @VTID(10)
    int count();

    @VTID(11)
    java.util.Iterator<Com4jObject> iterator();

}
