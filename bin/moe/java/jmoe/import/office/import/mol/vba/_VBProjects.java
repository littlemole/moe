package mol.vba  ;

import com4j.*;

@IID("{EEE00919-E393-11D1-BB03-00C04FB6C4A6}")
public interface _VBProjects extends mol.vba._VBProjects_Old {
    @VTID(12)
    mol.vba._VBProject add(
        mol.vba.vbext_ProjectType type);

    @VTID(13)
    void remove(
        mol.vba._VBProject lpc);

    @VTID(14)
    mol.vba._VBProject open(
        java.lang.String bstrPath);

}
