package mol.vba  ;

import com4j.*;

@IID("{0002E16A-0000-0000-C000-000000000046}")
public interface _Windows_old extends Com4jObject,Iterable<Com4jObject> {
    @VTID(7)
    mol.vba.VBE vbe();

    @VTID(8)
    mol.vba.Application parent();

    @VTID(9)
    @DefaultMethod
    mol.vba.Window item(
        @MarshalAs(NativeType.VARIANT) java.lang.Object index);

    @VTID(10)
    int count();

    @VTID(11)
    java.util.Iterator<Com4jObject> iterator();

}
