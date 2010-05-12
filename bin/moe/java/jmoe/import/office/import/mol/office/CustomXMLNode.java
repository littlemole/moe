package mol.office  ;

import com4j.*;

@IID("{000CDB04-0000-0000-C000-000000000046}")
public interface CustomXMLNode extends mol.office._IMsoDispObj {
    @VTID(9)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

    @VTID(10)
    mol.office.CustomXMLNodes attributes();

    @VTID(10)
    @ReturnValue(defaultPropertyThrough={mol.office.CustomXMLNodes.class})
    mol.office.CustomXMLNode attributes(
        int index);

    @VTID(11)
    java.lang.String baseName();

    @VTID(12)
    mol.office.CustomXMLNodes childNodes();

    @VTID(12)
    @ReturnValue(defaultPropertyThrough={mol.office.CustomXMLNodes.class})
    mol.office.CustomXMLNode childNodes(
        int index);

    @VTID(13)
    mol.office.CustomXMLNode firstChild();

    @VTID(14)
    mol.office.CustomXMLNode lastChild();

    @VTID(15)
    java.lang.String namespaceURI();

    @VTID(16)
    mol.office.CustomXMLNode nextSibling();

    @VTID(17)
    mol.office.MsoCustomXMLNodeType nodeType();

    @VTID(18)
    java.lang.String nodeValue();

    @VTID(19)
    void nodeValue(
        java.lang.String pbstrNodeValue);

    @VTID(20)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject ownerDocument();

    @VTID(21)
    mol.office._CustomXMLPart ownerPart();

    @VTID(22)
    mol.office.CustomXMLNode previousSibling();

    @VTID(23)
    mol.office.CustomXMLNode parentNode();

    @VTID(24)
    java.lang.String text();

    @VTID(25)
    void text(
        java.lang.String pbstrText);

    @VTID(26)
    java.lang.String xPath();

    @VTID(27)
    java.lang.String xml();

    @VTID(28)
    void appendChildNode(
        java.lang.String name,
        java.lang.String namespaceURI,
        mol.office.MsoCustomXMLNodeType nodeType,
        java.lang.String nodeValue);

    @VTID(29)
    void appendChildSubtree(
        java.lang.String xml);

    @VTID(30)
    void delete();

    @VTID(31)
    boolean hasChildNodes();

    @VTID(32)
    void insertNodeBefore(
        java.lang.String name,
        java.lang.String namespaceURI,
        mol.office.MsoCustomXMLNodeType nodeType,
        java.lang.String nodeValue,
        mol.office.CustomXMLNode nextSibling);

    @VTID(33)
    void insertSubtreeBefore(
        java.lang.String xml,
        mol.office.CustomXMLNode nextSibling);

    @VTID(34)
    void removeChild(
        mol.office.CustomXMLNode child);

    @VTID(35)
    void replaceChildNode(
        mol.office.CustomXMLNode oldNode,
        java.lang.String name,
        java.lang.String namespaceURI,
        mol.office.MsoCustomXMLNodeType nodeType,
        java.lang.String nodeValue);

    @VTID(36)
    void replaceChildSubtree(
        java.lang.String xml,
        mol.office.CustomXMLNode oldNode);

    @VTID(37)
    mol.office.CustomXMLNodes selectNodes(
        java.lang.String xPath);

    @VTID(38)
    mol.office.CustomXMLNode selectSingleNode(
        java.lang.String xPath);

}
