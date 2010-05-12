package mol.word.events;

import com4j.*;

@IID("{00020A02-0000-0000-C000-000000000046}")
public abstract class DocumentEvents2 {
    @DISPID(4)
    public void _new() {
            throw new UnsupportedOperationException();
    }

    @DISPID(5)
    public void open() {
            throw new UnsupportedOperationException();
    }

    @DISPID(6)
    public void close() {
            throw new UnsupportedOperationException();
    }

    @DISPID(7)
    public void sync(
        mol.office.MsoSyncEventType syncEventType) {
            throw new UnsupportedOperationException();
    }

    @DISPID(8)
    public void xmlAfterInsert(
        mol.word.XMLNode newXMLNode,
        boolean inUndoRedo) {
            throw new UnsupportedOperationException();
    }

    @DISPID(9)
    public void xmlBeforeDelete(
        mol.word.Range deletedRange,
        mol.word.XMLNode oldXMLNode,
        boolean inUndoRedo) {
            throw new UnsupportedOperationException();
    }

    @DISPID(12)
    public void contentControlAfterAdd(
        mol.word.ContentControl newContentControl,
        boolean inUndoRedo) {
            throw new UnsupportedOperationException();
    }

    @DISPID(13)
    public void contentControlBeforeDelete(
        mol.word.ContentControl oldContentControl,
        boolean inUndoRedo) {
            throw new UnsupportedOperationException();
    }

    @DISPID(14)
    public void contentControlOnExit(
        mol.word.ContentControl contentControl,
        Holder<Boolean> cancel) {
            throw new UnsupportedOperationException();
    }

    @DISPID(15)
    public void contentControlOnEnter(
        mol.word.ContentControl contentControl) {
            throw new UnsupportedOperationException();
    }

    @DISPID(16)
    public void contentControlBeforeStoreUpdate(
        mol.word.ContentControl contentControl,
        Holder<java.lang.String> content) {
            throw new UnsupportedOperationException();
    }

    @DISPID(17)
    public void contentControlBeforeContentUpdate(
        mol.word.ContentControl contentControl,
        Holder<java.lang.String> content) {
            throw new UnsupportedOperationException();
    }

    @DISPID(18)
    public void buildingBlockInsert(
        mol.word.Range range,
        java.lang.String name,
        java.lang.String category,
        java.lang.String blockType,
        java.lang.String template) {
            throw new UnsupportedOperationException();
    }

}
