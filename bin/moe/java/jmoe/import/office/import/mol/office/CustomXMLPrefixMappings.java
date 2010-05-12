package mol.office  ;

import com4j.*;

@IID("{000CDB00-0000-0000-C000-000000000046}")
public interface CustomXMLPrefixMappings extends mol.office._IMsoDispObj,Iterable<Com4jObject> {
    @VTID(9)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

    @VTID(10)
    int count();

    @VTID(11)
    @DefaultMethod
    mol.office.CustomXMLPrefixMapping item(
        @MarshalAs(NativeType.VARIANT) java.lang.Object index);

    @VTID(12)
    void addNamespace(
        java.lang.String prefix,
        java.lang.String namespaceURI);

    @VTID(13)
    java.lang.String lookupNamespace(
        java.lang.String prefix);

    @VTID(14)
    java.lang.String lookupPrefix(
        java.lang.String namespaceURI);

    @VTID(15)
    java.util.Iterator<Com4jObject> iterator();

}
