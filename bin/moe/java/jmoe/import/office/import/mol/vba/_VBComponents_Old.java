package mol.vba  ;

import com4j.*;

@IID("{0002E162-0000-0000-C000-000000000046}")
public interface _VBComponents_Old extends Com4jObject,Iterable<Com4jObject> {
    @VTID(7)
    @DefaultMethod
    mol.vba._VBComponent item(
        @MarshalAs(NativeType.VARIANT) java.lang.Object index);

    @VTID(8)
    mol.vba._VBProject parent();

    @VTID(9)
    int count();

    @VTID(10)
    java.util.Iterator<Com4jObject> iterator();

    @VTID(11)
    void remove(
        mol.vba._VBComponent vbComponent);

    @VTID(12)
    mol.vba._VBComponent add(
        mol.vba.vbext_ComponentType componentType);

    @VTID(13)
    mol.vba._VBComponent _import(
        java.lang.String fileName);

    @VTID(14)
    mol.vba.VBE vbe();

}
