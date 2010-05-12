package mol.word  ;

import com4j.*;

@IID("{09760240-0B89-49F7-A79D-479F24723F56}")
public interface XMLNode extends Com4jObject {
    @VTID(7)
    @DefaultMethod
    java.lang.String baseName();

    @VTID(8)
    mol.word._Application application();

    @VTID(9)
    int creator();

    @VTID(10)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

    @VTID(11)
    mol.word.Range range();

    @VTID(12)
    java.lang.String text();

    @VTID(13)
    void text(
        java.lang.String prop);

    @VTID(14)
    java.lang.String namespaceURI();

    @VTID(15)
    java.lang.String xml(
        boolean dataOnly);

    @VTID(16)
    mol.word.XMLNode nextSibling();

    @VTID(17)
    mol.word.XMLNode previousSibling();

    @VTID(18)
    mol.word.XMLNode parentNode();

    @VTID(19)
    mol.word.XMLNode firstChild();

    @VTID(20)
    mol.word.XMLNode lastChild();

    @VTID(21)
    mol.word._Document ownerDocument();

    @VTID(22)
    mol.word.WdXMLNodeType nodeType();

    @VTID(23)
    mol.word.XMLNodes childNodes();

    @VTID(23)
    @ReturnValue(defaultPropertyThrough={mol.word.XMLNodes.class})
    mol.word.XMLNode childNodes(
        int index);

    @VTID(24)
    mol.word.XMLNodes attributes();

    @VTID(24)
    @ReturnValue(defaultPropertyThrough={mol.word.XMLNodes.class})
    mol.word.XMLNode attributes(
        int index);

    @VTID(25)
    java.lang.String nodeValue();

    @VTID(26)
    void nodeValue(
        java.lang.String prop);

    @VTID(27)
    boolean hasChildNodes();

    @VTID(28)
    mol.word.XMLNode selectSingleNode(
        java.lang.String xPath,
        java.lang.String prefixMapping,
        boolean fastSearchSkippingTextNodes);

    @VTID(29)
    mol.word.XMLNodes selectNodes(
        java.lang.String xPath,
        java.lang.String prefixMapping,
        boolean fastSearchSkippingTextNodes);

    @VTID(30)
    mol.word.XMLChildNodeSuggestions childNodeSuggestions();

    @VTID(30)
    @ReturnValue(defaultPropertyThrough={mol.word.XMLChildNodeSuggestions.class})
    mol.word.XMLChildNodeSuggestion childNodeSuggestions(
        java.lang.Object index);

    @VTID(31)
    mol.word.WdXMLNodeLevel level();

    @VTID(32)
    mol.word.WdXMLValidationStatus validationStatus();

    @VTID(33)
    mol.word.SmartTag smartTag();

    @VTID(34)
    java.lang.String validationErrorText(
        boolean advanced);

    @VTID(35)
    java.lang.String placeholderText();

    @VTID(36)
    void placeholderText(
        java.lang.String prop);

    @VTID(37)
    void delete();

    @VTID(38)
    void copy();

    @VTID(39)
    void removeChild(
        mol.word.XMLNode childElement);

    @VTID(40)
    void cut();

    @VTID(41)
    void validate();

    @VTID(42)
    void setValidationError(
        mol.word.WdXMLValidationStatus status,
        java.lang.Object errorText,
        boolean clearedAutomatically);

    @VTID(43)
    java.lang.String wordOpenXML();

}
