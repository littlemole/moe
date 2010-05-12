package mol.vba  ;

import com4j.*;

@IID("{0002E164-0000-0000-C000-000000000046}")
public interface _VBComponent_Old extends Com4jObject {
    @VTID(7)
    boolean saved();

    @VTID(8)
    java.lang.String name();

    @VTID(9)
    void name(
        java.lang.String pbstrReturn);

    @VTID(10)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject designer();

    @VTID(11)
    mol.vba._CodeModule codeModule();

    @VTID(12)
    mol.vba.vbext_ComponentType type();

    @VTID(13)
    void export(
        java.lang.String fileName);

    @VTID(14)
    mol.vba.VBE vbe();

    @VTID(15)
    mol.vba._VBComponents collection();

    @VTID(16)
    boolean hasOpenDesigner();

    @VTID(17)
    mol.vba._Properties properties();

    @VTID(18)
    mol.vba.Window designerWindow();

    @VTID(19)
    void activate();

}
