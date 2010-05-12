package mol.office  ;

import com4j.*;

@IID("{000CDB02-0000-0000-C000-000000000046}")
public interface _CustomXMLSchemaCollection extends mol.office._IMsoDispObj,Iterable<Com4jObject> {
    @VTID(9)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

    @VTID(10)
    int count();

    @VTID(11)
    @DefaultMethod
    mol.office.CustomXMLSchema item(
        @MarshalAs(NativeType.VARIANT) java.lang.Object index);

    @VTID(12)
    java.lang.String namespaceURI(
        int index);

    @VTID(13)
    mol.office.CustomXMLSchema add(
        java.lang.String namespaceURI,
        java.lang.String alias,
        java.lang.String fileName,
        boolean installForAllUsers);

    @VTID(14)
    void addCollection(
        mol.office._CustomXMLSchemaCollection schemaCollection);

    @VTID(15)
    boolean validate();

    @VTID(16)
    java.util.Iterator<Com4jObject> iterator();

}
