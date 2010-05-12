package mol.vba  ;

import com4j.*;

@IID("{0002E188-0000-0000-C000-000000000046}")
public interface _Properties extends Com4jObject,Iterable<Com4jObject> {
    @VTID(7)
    @DefaultMethod
    mol.vba.Property item(
        @MarshalAs(NativeType.VARIANT) java.lang.Object index);

    @VTID(8)
    mol.vba.Application application();

    @VTID(9)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

    @VTID(10)
    int count();

    @VTID(11)
    java.util.Iterator<Com4jObject> iterator();

    @VTID(12)
    mol.vba.VBE vbe();

}
