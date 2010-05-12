package mol.office  ;

import com4j.*;

@IID("{000CDB09-0000-0000-C000-000000000046}")
public interface _CustomXMLParts extends mol.office._IMsoDispObj,Iterable<Com4jObject> {
    @VTID(9)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

    @VTID(10)
    int count();

    @VTID(11)
    @DefaultMethod
    mol.office._CustomXMLPart item(
        @MarshalAs(NativeType.VARIANT) java.lang.Object index);

    @VTID(12)
    mol.office._CustomXMLPart add(
        java.lang.String xml,
        @MarshalAs(NativeType.VARIANT) java.lang.Object schemaCollection);

    @VTID(13)
    mol.office._CustomXMLPart selectByID(
        java.lang.String id);

    @VTID(14)
    mol.office._CustomXMLParts selectByNamespace(
        java.lang.String namespaceURI);

    @VTID(15)
    java.util.Iterator<Com4jObject> iterator();

}
