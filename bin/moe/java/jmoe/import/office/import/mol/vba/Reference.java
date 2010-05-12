package mol.vba  ;

import com4j.*;

@IID("{0002E17E-0000-0000-C000-000000000046}")
public interface Reference extends Com4jObject {
    @VTID(7)
    mol.vba._References collection();

    @VTID(8)
    mol.vba.VBE vbe();

    @VTID(9)
    java.lang.String name();

    @VTID(10)
    java.lang.String guid();

    @VTID(11)
    int major();

    @VTID(12)
    int minor();

    @VTID(13)
    java.lang.String fullPath();

    @VTID(14)
    boolean builtIn();

    @VTID(15)
    boolean isBroken();

    @VTID(16)
    mol.vba.vbext_RefKind type();

    @VTID(17)
    java.lang.String description();

}
