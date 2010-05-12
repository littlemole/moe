package mol.office  ;

import com4j.*;

@IID("{000CDB06-0000-0000-C000-000000000046}")
public interface ICustomXMLPartEvents extends Com4jObject {
    @VTID(7)
    void nodeAfterInsert(
        mol.office.CustomXMLNode newNode,
        boolean inUndoRedo);

    @VTID(8)
    void nodeAfterDelete(
        mol.office.CustomXMLNode oldNode,
        mol.office.CustomXMLNode oldParentNode,
        mol.office.CustomXMLNode oldNextSibling,
        boolean inUndoRedo);

    @VTID(9)
    void nodeAfterReplace(
        mol.office.CustomXMLNode oldNode,
        mol.office.CustomXMLNode newNode,
        boolean inUndoRedo);

}
