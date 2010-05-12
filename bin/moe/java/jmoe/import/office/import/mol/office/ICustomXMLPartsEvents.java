package mol.office  ;

import com4j.*;

@IID("{000CDB0A-0000-0000-C000-000000000046}")
public interface ICustomXMLPartsEvents extends Com4jObject {
    @VTID(7)
    void partAfterAdd(
        mol.office._CustomXMLPart newPart);

    @VTID(8)
    void partBeforeDelete(
        mol.office._CustomXMLPart oldPart);

    @VTID(9)
    void partAfterLoad(
        mol.office._CustomXMLPart part);

}
