package mol.word.events;

import com4j.*;

@IID("{00020A00-0000-0000-C000-000000000046}")
public abstract class ApplicationEvents3 {
    @DISPID(1)
    public void startup() {
            throw new UnsupportedOperationException();
    }

    @DISPID(2)
    public void quit() {
            throw new UnsupportedOperationException();
    }

    @DISPID(3)
    public void documentChange() {
            throw new UnsupportedOperationException();
    }

    @DISPID(4)
    public void documentOpen(
        mol.word._Document doc) {
            throw new UnsupportedOperationException();
    }

    @DISPID(6)
    public void documentBeforeClose(
        mol.word._Document doc,
        Holder<Boolean> cancel) {
            throw new UnsupportedOperationException();
    }

    @DISPID(7)
    public void documentBeforePrint(
        mol.word._Document doc,
        Holder<Boolean> cancel) {
            throw new UnsupportedOperationException();
    }

    @DISPID(8)
    public void documentBeforeSave(
        mol.word._Document doc,
        Holder<Boolean> saveAsUI,
        Holder<Boolean> cancel) {
            throw new UnsupportedOperationException();
    }

    @DISPID(9)
    public void newDocument(
        mol.word._Document doc) {
            throw new UnsupportedOperationException();
    }

    @DISPID(10)
    public void windowActivate(
        mol.word._Document doc,
        mol.word.Window wn) {
            throw new UnsupportedOperationException();
    }

    @DISPID(11)
    public void windowDeactivate(
        mol.word._Document doc,
        mol.word.Window wn) {
            throw new UnsupportedOperationException();
    }

    @DISPID(12)
    public void windowSelectionChange(
        mol.word.Selection sel) {
            throw new UnsupportedOperationException();
    }

    @DISPID(13)
    public void windowBeforeRightClick(
        mol.word.Selection sel,
        Holder<Boolean> cancel) {
            throw new UnsupportedOperationException();
    }

    @DISPID(14)
    public void windowBeforeDoubleClick(
        mol.word.Selection sel,
        Holder<Boolean> cancel) {
            throw new UnsupportedOperationException();
    }

    @DISPID(15)
    public void ePostagePropertyDialog(
        mol.word._Document doc) {
            throw new UnsupportedOperationException();
    }

    @DISPID(16)
    public void ePostageInsert(
        mol.word._Document doc) {
            throw new UnsupportedOperationException();
    }

    @DISPID(17)
    public void mailMergeAfterMerge(
        mol.word._Document doc,
        mol.word._Document docResult) {
            throw new UnsupportedOperationException();
    }

    @DISPID(18)
    public void mailMergeAfterRecordMerge(
        mol.word._Document doc) {
            throw new UnsupportedOperationException();
    }

    @DISPID(19)
    public void mailMergeBeforeMerge(
        mol.word._Document doc,
        int startRecord,
        int endRecord,
        Holder<Boolean> cancel) {
            throw new UnsupportedOperationException();
    }

    @DISPID(20)
    public void mailMergeBeforeRecordMerge(
        mol.word._Document doc,
        Holder<Boolean> cancel) {
            throw new UnsupportedOperationException();
    }

    @DISPID(21)
    public void mailMergeDataSourceLoad(
        mol.word._Document doc) {
            throw new UnsupportedOperationException();
    }

    @DISPID(22)
    public void mailMergeDataSourceValidate(
        mol.word._Document doc,
        Holder<Boolean> handled) {
            throw new UnsupportedOperationException();
    }

    @DISPID(23)
    public void mailMergeWizardSendToCustom(
        mol.word._Document doc) {
            throw new UnsupportedOperationException();
    }

    @DISPID(24)
    public void mailMergeWizardStateChange(
        mol.word._Document doc,
        Holder<Integer> fromState,
        Holder<Integer> toState,
        Holder<Boolean> handled) {
            throw new UnsupportedOperationException();
    }

    @DISPID(25)
    public void windowSize(
        mol.word._Document doc,
        mol.word.Window wn) {
            throw new UnsupportedOperationException();
    }

}
