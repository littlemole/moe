package mol.vba  ;

import com4j.*;

@IID("{0002E161-0000-0000-C000-000000000046}")
public interface _Components extends Com4jObject,Iterable<Com4jObject> {
    @VTID(7)
    @DefaultMethod
    mol.vba._Component item(
        @MarshalAs(NativeType.VARIANT) java.lang.Object index);

    @VTID(8)
    mol.vba.Application application();

    @VTID(9)
    mol.vba._VBProject parent();

    @VTID(10)
    int count();

    @VTID(11)
    java.util.Iterator<Com4jObject> iterator();

    @VTID(12)
    void remove(
        mol.vba._Component component);

    @VTID(13)
    mol.vba._Component add(
        mol.vba.vbext_ComponentType componentType);

    @VTID(14)
    mol.vba._Component _import(
        java.lang.String fileName);

    @VTID(15)
    mol.vba.VBE vbe();

}
