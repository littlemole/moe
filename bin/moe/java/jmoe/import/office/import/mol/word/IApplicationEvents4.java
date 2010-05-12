package mol.word  ;

import com4j.*;

@IID("{00020A01-0001-0000-C000-000000000046}")
public interface IApplicationEvents4 extends Com4jObject {
    @VTID(7)
    void startup();

    @VTID(8)
    void quit();

    @VTID(9)
    void documentChange();

    @VTID(10)
    void documentOpen(
        mol.word._Document doc);

    @VTID(11)
    void documentBeforeClose(
        mol.word._Document doc,
        Holder<Boolean> cancel);

    @VTID(12)
    void documentBeforePrint(
        mol.word._Document doc,
        Holder<Boolean> cancel);

    @VTID(13)
    void documentBeforeSave(
        mol.word._Document doc,
        Holder<Boolean> saveAsUI,
        Holder<Boolean> cancel);

    @VTID(14)
    void newDocument(
        mol.word._Document doc);

    @VTID(15)
    void windowActivate(
        mol.word._Document doc,
        mol.word.Window wn);

    @VTID(16)
    void windowDeactivate(
        mol.word._Document doc,
        mol.word.Window wn);

    @VTID(17)
    void windowSelectionChange(
        mol.word.Selection sel);

    @VTID(18)
    void windowBeforeRightClick(
        mol.word.Selection sel,
        Holder<Boolean> cancel);

    @VTID(19)
    void windowBeforeDoubleClick(
        mol.word.Selection sel,
        Holder<Boolean> cancel);

    @VTID(20)
    void ePostagePropertyDialog(
        mol.word._Document doc);

    @VTID(21)
    void ePostageInsert(
        mol.word._Document doc);

    @VTID(22)
    void mailMergeAfterMerge(
        mol.word._Document doc,
        mol.word._Document docResult);

    @VTID(23)
    void mailMergeAfterRecordMerge(
        mol.word._Document doc);

    @VTID(24)
    void mailMergeBeforeMerge(
        mol.word._Document doc,
        int startRecord,
        int endRecord,
        Holder<Boolean> cancel);

    @VTID(25)
    void mailMergeBeforeRecordMerge(
        mol.word._Document doc,
        Holder<Boolean> cancel);

    @VTID(26)
    void mailMergeDataSourceLoad(
        mol.word._Document doc);

    @VTID(27)
    void mailMergeDataSourceValidate(
        mol.word._Document doc,
        Holder<Boolean> handled);

    @VTID(28)
    void mailMergeWizardSendToCustom(
        mol.word._Document doc);

    @VTID(29)
    void mailMergeWizardStateChange(
        mol.word._Document doc,
        Holder<Integer> fromState,
        Holder<Integer> toState,
        Holder<Boolean> handled);

    @VTID(30)
    void windowSize(
        mol.word._Document doc,
        mol.word.Window wn);

    @VTID(31)
    void xmlSelectionChange(
        mol.word.Selection sel,
        mol.word.XMLNode oldXMLNode,
        mol.word.XMLNode newXMLNode,
        Holder<Integer> reason);

    @VTID(32)
    void xmlValidationError(
        mol.word.XMLNode xmlNode);

    @VTID(33)
    void documentSync(
        mol.word._Document doc,
        mol.office.MsoSyncEventType syncEventType);

    @VTID(34)
    void ePostageInsertEx(
        mol.word._Document doc,
        int cpDeliveryAddrStart,
        int cpDeliveryAddrEnd,
        int cpReturnAddrStart,
        int cpReturnAddrEnd,
        int xaWidth,
        int yaHeight,
        java.lang.String bstrPrinterName,
        java.lang.String bstrPaperFeed,
        boolean fPrint,
        Holder<Boolean> fCancel);

    @VTID(35)
    void mailMergeDataSourceValidate2(
        mol.word._Document doc,
        Holder<Boolean> handled);

}
