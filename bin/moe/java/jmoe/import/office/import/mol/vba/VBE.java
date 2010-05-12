package mol.vba  ;

import com4j.*;
import mol.office.*;

@IID("{0002E166-0000-0000-C000-000000000046}")
public interface VBE extends mol.vba.Application {
    @VTID(8)
    mol.vba._VBProjects vbProjects();

    @VTID(9)
    mol.office._CommandBars commandBars();

    @VTID(10)
    mol.vba._CodePanes codePanes();

    @VTID(11)
    mol.vba._Windows windows();

    @VTID(12)
    mol.vba.Events events();

    @VTID(13)
    mol.vba._VBProject activeVBProject();

    @VTID(14)
    void activeVBProject(
        mol.vba._VBProject lppptReturn);

    @VTID(15)
    mol.vba._VBComponent selectedVBComponent();

    @VTID(16)
    mol.vba.Window mainWindow();

    @VTID(17)
    mol.vba.Window activeWindow();

    @VTID(18)
    mol.vba._CodePane activeCodePane();

    @VTID(19)
    void activeCodePane(
        mol.vba._CodePane ppCodePane);

    @VTID(20)
    mol.vba._AddIns addins();

}
