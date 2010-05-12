package mol.office.events;

import com4j.*;

@IID("{000CDB07-0000-0000-C000-000000000046}")
public abstract class _CustomXMLPartEvents {
    @DISPID(1)
    public void nodeAfterInsert(
        mol.office.CustomXMLNode newNode,
        boolean inUndoRedo) {
            throw new UnsupportedOperationException();
    }

    @DISPID(2)
    public void nodeAfterDelete(
        mol.office.CustomXMLNode oldNode,
        mol.office.CustomXMLNode oldParentNode,
        mol.office.CustomXMLNode oldNextSibling,
        boolean inUndoRedo) {
            throw new UnsupportedOperationException();
    }

    @DISPID(3)
    public void nodeAfterReplace(
        mol.office.CustomXMLNode oldNode,
        mol.office.CustomXMLNode newNode,
        boolean inUndoRedo) {
            throw new UnsupportedOperationException();
    }

}
