package mol.office  ;

import com4j.*;

@IID("{000C0313-0000-0000-C000-000000000046}")
public interface ConnectorFormat extends mol.office._IMsoDispObj {
    @VTID(9)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

    @VTID(10)
    void beginConnect(
        mol.office.Shape connectedShape,
        int connectionSite);

    @VTID(11)
    void beginDisconnect();

    @VTID(12)
    void endConnect(
        mol.office.Shape connectedShape,
        int connectionSite);

    @VTID(13)
    void endDisconnect();

    @VTID(14)
    mol.office.MsoTriState beginConnected();

    @VTID(15)
    mol.office.Shape beginConnectedShape();

    @VTID(16)
    int beginConnectionSite();

    @VTID(17)
    mol.office.MsoTriState endConnected();

    @VTID(18)
    mol.office.Shape endConnectedShape();

    @VTID(19)
    int endConnectionSite();

    @VTID(20)
    mol.office.MsoConnectorType type();

    @VTID(21)
    void type(
        mol.office.MsoConnectorType type);

}
