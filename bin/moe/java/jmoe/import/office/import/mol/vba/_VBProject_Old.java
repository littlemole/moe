package mol.vba  ;

import com4j.*;

@IID("{0002E160-0000-0000-C000-000000000046}")
public interface _VBProject_Old extends mol.vba._ProjectTemplate {
    @VTID(9)
    java.lang.String helpFile();

    @VTID(10)
    void helpFile(
        java.lang.String lpbstrHelpFile);

    @VTID(11)
    int helpContextID();

    @VTID(12)
    void helpContextID(
        int lpdwContextID);

    @VTID(13)
    java.lang.String description();

    @VTID(14)
    void description(
        java.lang.String lpbstrDescription);

    @VTID(15)
    mol.vba.vbext_VBAMode mode();

    @VTID(16)
    mol.vba._References references();

    @VTID(17)
    java.lang.String name();

    @VTID(18)
    void name(
        java.lang.String lpbstrName);

    @VTID(19)
    mol.vba.VBE vbe();

    @VTID(20)
    mol.vba._VBProjects collection();

    @VTID(21)
    mol.vba.vbext_ProjectProtection protection();

    @VTID(22)
    boolean saved();

    @VTID(23)
    mol.vba._VBComponents vbComponents();

}
