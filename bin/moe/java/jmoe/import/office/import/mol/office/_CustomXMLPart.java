package mol.office  ;

import com4j.*;

@IID("{000CDB05-0000-0000-C000-000000000046}")
public interface _CustomXMLPart extends mol.office._IMsoDispObj {
    @VTID(9)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

    @VTID(10)
    mol.office.CustomXMLNode documentElement();

    @VTID(11)
    java.lang.String id();

    @VTID(12)
    java.lang.String namespaceURI();

    @VTID(13)
    mol.office._CustomXMLSchemaCollection schemaCollection();

    @VTID(14)
    void schemaCollection(
        mol.office._CustomXMLSchemaCollection ppSchemaCollection);

    @VTID(15)
    mol.office.CustomXMLPrefixMappings namespaceManager();

    @VTID(15)
    @ReturnValue(defaultPropertyThrough={mol.office.CustomXMLPrefixMappings.class})
    mol.office.CustomXMLPrefixMapping namespaceManager(
        @MarshalAs(NativeType.VARIANT) java.lang.Object index);

    @VTID(16)
    java.lang.String xml();

    @VTID(17)
    void addNode(
        mol.office.CustomXMLNode parent,
        java.lang.String name,
        java.lang.String namespaceURI,
        mol.office.CustomXMLNode nextSibling,
        mol.office.MsoCustomXMLNodeType nodeType,
        java.lang.String nodeValue);

    @VTID(18)
    void delete();

    @VTID(19)
    boolean load(
        java.lang.String filePath);

    @VTID(20)
    boolean loadXML(
        java.lang.String xml);

    @VTID(21)
    mol.office.CustomXMLNodes selectNodes(
        java.lang.String xPath);

    @VTID(22)
    mol.office.CustomXMLNode selectSingleNode(
        java.lang.String xPath);

    @VTID(23)
    mol.office.CustomXMLValidationErrors errors();

    @VTID(23)
    @ReturnValue(defaultPropertyThrough={mol.office.CustomXMLValidationErrors.class})
    mol.office.CustomXMLValidationError errors(
        int index);

    @VTID(24)
    boolean builtIn();

}
