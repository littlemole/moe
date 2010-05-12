package mol.word  ;

import com4j.*;

@IID("{0C1FABE7-F737-406F-9CA3-B07661F9D1A2}")
public interface XMLMapping extends Com4jObject {
    @VTID(7)
    mol.word._Application application();

    @VTID(8)
    int creator();

    @VTID(9)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

    @VTID(10)
    @DefaultMethod
    boolean isMapped();

    @VTID(11)
    mol.office._CustomXMLPart customXMLPart();

    @VTID(12)
    mol.office.CustomXMLNode customXMLNode();

    @VTID(13)
    boolean setMapping(
        java.lang.String xPath,
        java.lang.String prefixMapping,
        mol.office._CustomXMLPart source);

    @VTID(14)
    void delete();

    @VTID(15)
    boolean setMappingByNode(
        mol.office.CustomXMLNode node);

    @VTID(16)
    java.lang.String xPath();

    @VTID(17)
    java.lang.String prefixMappings();

}
