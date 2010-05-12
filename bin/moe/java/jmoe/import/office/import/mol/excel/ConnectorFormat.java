package mol.excel  ;

import com4j.*;
import mol.office.*;
import mol.vba.*;

@IID("{00020400-0000-0000-C000-000000000046}")
public interface ConnectorFormat extends Com4jObject {
    @DISPID(148)
    @PropGet
    mol.excel._Application application();

    @DISPID(149)
    @PropGet
    mol.excel.XlCreator creator();

    @DISPID(150)
    @PropGet
    com4j.Com4jObject parent();

    @DISPID(1750)
    void beginConnect(
        mol.excel.Shape connectedShape,
        int connectionSite);

    @DISPID(1753)
    void beginDisconnect();

    @DISPID(1754)
    void endConnect(
        mol.excel.Shape connectedShape,
        int connectionSite);

    @DISPID(1755)
    void endDisconnect();

    @DISPID(1756)
    @PropGet
    mol.office.MsoTriState beginConnected();

    @DISPID(1757)
    @PropGet
    mol.excel.Shape beginConnectedShape();

    @DISPID(1758)
    @PropGet
    int beginConnectionSite();

    @DISPID(1759)
    @PropGet
    mol.office.MsoTriState endConnected();

    @DISPID(1760)
    @PropGet
    mol.excel.Shape endConnectedShape();

    @DISPID(1761)
    @PropGet
    int endConnectionSite();

    @DISPID(108)
    @PropGet
    mol.office.MsoConnectorType type();

    @DISPID(108)
    @PropPut
    void type(
        mol.office.MsoConnectorType rhs);

}
