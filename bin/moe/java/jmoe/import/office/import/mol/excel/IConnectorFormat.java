package mol.excel  ;

import com4j.*;
import mol.office.*;
import mol.vba.*;

@IID("{0002443E-0001-0000-C000-000000000046}")
public interface IConnectorFormat extends Com4jObject {
    @VTID(7)
    mol.excel._Application application();

    @VTID(8)
    mol.excel.XlCreator creator();

    @VTID(9)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

    @VTID(10)
    void beginConnect(
        mol.excel.Shape connectedShape,
        int connectionSite);

    @VTID(11)
    void beginDisconnect();

    @VTID(12)
    void endConnect(
        mol.excel.Shape connectedShape,
        int connectionSite);

    @VTID(13)
    void endDisconnect();

    @VTID(14)
    mol.office.MsoTriState beginConnected();

    @VTID(15)
    mol.excel.Shape beginConnectedShape();

    @VTID(16)
    int beginConnectionSite();

    @VTID(17)
    mol.office.MsoTriState endConnected();

    @VTID(18)
    mol.excel.Shape endConnectedShape();

    @VTID(19)
    int endConnectionSite();

    @VTID(20)
    mol.office.MsoConnectorType type();

    @VTID(21)
    void type(
        mol.office.MsoConnectorType rhs);

}
