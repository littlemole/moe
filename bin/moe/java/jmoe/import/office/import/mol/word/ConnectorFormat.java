package mol.word  ;

import com4j.*;

@IID("{000209C7-0000-0000-C000-000000000046}")
public interface ConnectorFormat extends Com4jObject {
    @VTID(7)
    mol.word._Application application();

    @VTID(8)
    int creator();

    @VTID(9)
    mol.office.MsoTriState beginConnected();

    @VTID(10)
    mol.word.Shape beginConnectedShape();

    @VTID(11)
    int beginConnectionSite();

    @VTID(12)
    mol.office.MsoTriState endConnected();

    @VTID(13)
    mol.word.Shape endConnectedShape();

    @VTID(14)
    int endConnectionSite();

    @VTID(15)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

    @VTID(16)
    mol.office.MsoConnectorType type();

    @VTID(17)
    void type(
        mol.office.MsoConnectorType prop);

    @VTID(18)
    @ReturnValue(index=0)
    mol.word.Shape beginConnect(
        int connectionSite);

    @VTID(19)
    void beginDisconnect();

    @VTID(20)
    @ReturnValue(index=0)
    mol.word.Shape endConnect(
        int connectionSite);

    @VTID(21)
    void endDisconnect();

}
