package mol.vba  ;

import com4j.*;

@IID("{00020400-0000-0000-C000-000000000046}")
public interface _dispVBProjectsEvents extends Com4jObject {
    @DISPID(1)
    void itemAdded(
        mol.vba._VBProject vbProject);

    @DISPID(2)
    void itemRemoved(
        mol.vba._VBProject vbProject);

    @DISPID(3)
    void itemRenamed(
        mol.vba._VBProject vbProject,
        java.lang.String oldName);

    @DISPID(4)
    void itemActivated(
        mol.vba._VBProject vbProject);

}
