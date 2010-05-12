package mol.vba  ;

import com4j.*;

@IID("{0002E17A-0000-0000-C000-000000000046}")
public interface _References extends Com4jObject,Iterable<Com4jObject> {
    @VTID(7)
    mol.vba._VBProject parent();

    @VTID(8)
    mol.vba.VBE vbe();

    @VTID(9)
    @DefaultMethod
    mol.vba.Reference item(
        @MarshalAs(NativeType.VARIANT) java.lang.Object index);

    @VTID(10)
    int count();

    @VTID(11)
    java.util.Iterator<Com4jObject> iterator();

    @VTID(12)
    mol.vba.Reference addFromGuid(
        java.lang.String guid,
        int major,
        int minor);

    @VTID(13)
    mol.vba.Reference addFromFile(
        java.lang.String fileName);

    @VTID(14)
    void remove(
        mol.vba.Reference reference);

}
