package mol.vba  ;

import com4j.*;

@IID("{0002E172-0000-0000-C000-000000000046}")
public interface _CodePanes extends Com4jObject,Iterable<Com4jObject> {
    @VTID(7)
    mol.vba.VBE parent();

    @VTID(8)
    mol.vba.VBE vbe();

    @VTID(9)
    @DefaultMethod
    mol.vba._CodePane item(
        @MarshalAs(NativeType.VARIANT) java.lang.Object index);

    @VTID(10)
    int count();

    @VTID(11)
    java.util.Iterator<Com4jObject> iterator();

    @VTID(12)
    mol.vba._CodePane current();

    @VTID(13)
    void current(
        mol.vba._CodePane codePane);

}
