package mol.vba  ;

import com4j.*;

@IID("{EEE00915-E393-11D1-BB03-00C04FB6C4A6}")
public interface _VBProject extends mol.vba._VBProject_Old {
    @VTID(24)
    void saveAs(
        java.lang.String fileName);

    @VTID(25)
    void makeCompiledFile();

    @VTID(26)
    mol.vba.vbext_ProjectType type();

    @VTID(27)
    java.lang.String fileName();

    @VTID(28)
    java.lang.String buildFileName();

    @VTID(29)
    void buildFileName(
        java.lang.String lpbstrBldFName);

}
