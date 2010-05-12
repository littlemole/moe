package mol.word  ;

import com4j.*;

@IID("{00020920-0000-0000-C000-000000000046}")
public interface MailMerge extends Com4jObject {
    @VTID(7)
    mol.word._Application application();

    @VTID(8)
    int creator();

    @VTID(9)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

    @VTID(10)
    mol.word.WdMailMergeMainDocType mainDocumentType();

    @VTID(11)
    void mainDocumentType(
        mol.word.WdMailMergeMainDocType prop);

    @VTID(12)
    mol.word.WdMailMergeState state();

    @VTID(13)
    mol.word.WdMailMergeDestination destination();

    @VTID(14)
    void destination(
        mol.word.WdMailMergeDestination prop);

    @VTID(15)
    mol.word.MailMergeDataSource dataSource();

    @VTID(16)
    mol.word.MailMergeFields fields();

    @VTID(16)
    @ReturnValue(defaultPropertyThrough={mol.word.MailMergeFields.class})
    mol.word.MailMergeField fields(
        int index);

    @VTID(17)
    int viewMailMergeFieldCodes();

    @VTID(18)
    void viewMailMergeFieldCodes(
        int prop);

    @VTID(19)
    boolean suppressBlankLines();

    @VTID(20)
    void suppressBlankLines(
        boolean prop);

    @VTID(21)
    boolean mailAsAttachment();

    @VTID(22)
    void mailAsAttachment(
        boolean prop);

    @VTID(23)
    java.lang.String mailAddressFieldName();

    @VTID(24)
    void mailAddressFieldName(
        java.lang.String prop);

    @VTID(25)
    java.lang.String mailSubject();

    @VTID(26)
    void mailSubject(
        java.lang.String prop);

    @VTID(27)
    void createDataSource(
        java.lang.Object name,
        java.lang.Object passwordDocument,
        java.lang.Object writePasswordDocument,
        java.lang.Object headerRecord,
        java.lang.Object msQuery,
        java.lang.Object sqlStatement,
        java.lang.Object sqlStatement1,
        java.lang.Object connection,
        java.lang.Object linkToSource);

    @VTID(28)
    void createHeaderSource(
        java.lang.String name,
        java.lang.Object passwordDocument,
        java.lang.Object writePasswordDocument,
        java.lang.Object headerRecord);

    @VTID(29)
    void openDataSource2000(
        java.lang.String name,
        java.lang.Object format,
        java.lang.Object confirmConversions,
        java.lang.Object readOnly,
        java.lang.Object linkToSource,
        java.lang.Object addToRecentFiles,
        java.lang.Object passwordDocument,
        java.lang.Object passwordTemplate,
        java.lang.Object revert,
        java.lang.Object writePasswordDocument,
        java.lang.Object writePasswordTemplate,
        java.lang.Object connection,
        java.lang.Object sqlStatement,
        java.lang.Object sqlStatement1);

    @VTID(30)
    void openHeaderSource2000(
        java.lang.String name,
        java.lang.Object format,
        java.lang.Object confirmConversions,
        java.lang.Object readOnly,
        java.lang.Object addToRecentFiles,
        java.lang.Object passwordDocument,
        java.lang.Object passwordTemplate,
        java.lang.Object revert,
        java.lang.Object writePasswordDocument,
        java.lang.Object writePasswordTemplate);

    @VTID(31)
    void execute(
        java.lang.Object pause);

    @VTID(32)
    void check();

    @VTID(33)
    void editDataSource();

    @VTID(34)
    void editHeaderSource();

    @VTID(35)
    void editMainDocument();

    @VTID(36)
    void useAddressBook(
        java.lang.String type);

    @VTID(37)
    boolean highlightMergeFields();

    @VTID(38)
    void highlightMergeFields(
        boolean prop);

    @VTID(39)
    mol.word.WdMailMergeMailFormat mailFormat();

    @VTID(40)
    void mailFormat(
        mol.word.WdMailMergeMailFormat prop);

    @VTID(41)
    java.lang.String showSendToCustom();

    @VTID(42)
    void showSendToCustom(
        java.lang.String prop);

    @VTID(43)
    int wizardState();

    @VTID(44)
    void wizardState(
        int prop);

    @VTID(45)
    void openDataSource(
        java.lang.String name,
        java.lang.Object format,
        java.lang.Object confirmConversions,
        java.lang.Object readOnly,
        java.lang.Object linkToSource,
        java.lang.Object addToRecentFiles,
        java.lang.Object passwordDocument,
        java.lang.Object passwordTemplate,
        java.lang.Object revert,
        java.lang.Object writePasswordDocument,
        java.lang.Object writePasswordTemplate,
        java.lang.Object connection,
        java.lang.Object sqlStatement,
        java.lang.Object sqlStatement1,
        java.lang.Object openExclusive,
        java.lang.Object subType);

    @VTID(46)
    void openHeaderSource(
        java.lang.String name,
        java.lang.Object format,
        java.lang.Object confirmConversions,
        java.lang.Object readOnly,
        java.lang.Object addToRecentFiles,
        java.lang.Object passwordDocument,
        java.lang.Object passwordTemplate,
        java.lang.Object revert,
        java.lang.Object writePasswordDocument,
        java.lang.Object writePasswordTemplate,
        java.lang.Object openExclusive);

    @VTID(47)
    void showWizard(
        java.lang.Object initialState,
        java.lang.Object showDocumentStep,
        java.lang.Object showTemplateStep,
        java.lang.Object showDataStep,
        java.lang.Object showWriteStep,
        java.lang.Object showPreviewStep,
        java.lang.Object showMergeStep);

}
