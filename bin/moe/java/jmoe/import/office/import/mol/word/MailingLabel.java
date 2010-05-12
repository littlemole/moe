package mol.word  ;

import com4j.*;

@IID("{00020917-0000-0000-C000-000000000046}")
public interface MailingLabel extends Com4jObject {
    @VTID(7)
    mol.word._Application application();

    @VTID(8)
    int creator();

    @VTID(9)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

    @VTID(10)
    boolean defaultPrintBarCode();

    @VTID(11)
    void defaultPrintBarCode(
        boolean prop);

    @VTID(12)
    mol.word.WdPaperTray defaultLaserTray();

    @VTID(13)
    void defaultLaserTray(
        mol.word.WdPaperTray prop);

    @VTID(14)
    mol.word.CustomLabels customLabels();

    @VTID(14)
    @ReturnValue(defaultPropertyThrough={mol.word.CustomLabels.class})
    mol.word.CustomLabel customLabels(
        java.lang.Object index);

    @VTID(15)
    java.lang.String defaultLabelName();

    @VTID(16)
    void defaultLabelName(
        java.lang.String prop);

    @VTID(17)
    mol.word._Document createNewDocument2000(
        java.lang.Object name,
        java.lang.Object address,
        java.lang.Object autoText,
        java.lang.Object extractAddress,
        java.lang.Object laserTray);

    @VTID(18)
    void printOut2000(
        java.lang.Object name,
        java.lang.Object address,
        java.lang.Object extractAddress,
        java.lang.Object laserTray,
        java.lang.Object singleLabel,
        java.lang.Object row,
        java.lang.Object column);

    @VTID(19)
    void labelOptions();

    @VTID(20)
    mol.word._Document createNewDocument(
        java.lang.Object name,
        java.lang.Object address,
        java.lang.Object autoText,
        java.lang.Object extractAddress,
        java.lang.Object laserTray,
        java.lang.Object printEPostageLabel,
        java.lang.Object vertical);

    @VTID(21)
    void printOut(
        java.lang.Object name,
        java.lang.Object address,
        java.lang.Object extractAddress,
        java.lang.Object laserTray,
        java.lang.Object singleLabel,
        java.lang.Object row,
        java.lang.Object column,
        java.lang.Object printEPostageLabel,
        java.lang.Object vertical);

    @VTID(22)
    boolean vertical();

    @VTID(23)
    void vertical(
        boolean prop);

    @VTID(24)
    mol.word._Document createNewDocumentByID(
        java.lang.Object labelID,
        java.lang.Object address,
        java.lang.Object autoText,
        java.lang.Object extractAddress,
        java.lang.Object laserTray,
        java.lang.Object printEPostageLabel,
        java.lang.Object vertical);

    @VTID(25)
    void printOutByID(
        java.lang.Object labelID,
        java.lang.Object address,
        java.lang.Object extractAddress,
        java.lang.Object laserTray,
        java.lang.Object singleLabel,
        java.lang.Object row,
        java.lang.Object column,
        java.lang.Object printEPostageLabel,
        java.lang.Object vertical);

}
