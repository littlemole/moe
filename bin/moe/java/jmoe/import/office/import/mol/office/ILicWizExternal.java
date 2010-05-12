package mol.office  ;

import com4j.*;

@IID("{4CAC6328-B9B0-11D3-8D59-0050048384E3}")
public interface ILicWizExternal extends Com4jObject {
    @VTID(7)
    void printHtmlDocument(
        com4j.Com4jObject punkHtmlDoc);

    @VTID(8)
    void invokeDateTimeApplet();

    @VTID(9)
    java.lang.String formatDate(
        java.util.Date date,
        java.lang.String pFormat);

    @VTID(10)
    void showHelp(
        java.lang.Object pvarId);

    @VTID(11)
    void terminate();

    @VTID(12)
    void disableVORWReminder(
        int bpc);

    @VTID(13)
    java.lang.String saveReceipt(
        java.lang.String bstrReceipt);

    @VTID(14)
    void openInDefaultBrowser(
        java.lang.String bstrUrl);

    @VTID(15)
    int msoAlert(
        java.lang.String bstrText,
        java.lang.String bstrButtons,
        java.lang.String bstrIcon);

    @VTID(16)
    int depositPidKey(
        java.lang.String bstrKey,
        int fMORW);

    @VTID(17)
    void writeLog(
        java.lang.String bstrMessage);

    @VTID(18)
    void resignDpc(
        java.lang.String bstrProductCode);

    @VTID(19)
    void resetPID();

    @VTID(20)
    void setDialogSize(
        int dx,
        int dy);

    @VTID(21)
    int verifyClock(
        int lMode);

    @VTID(22)
    void sortSelectOptions(
        @MarshalAs(NativeType.Dispatch) com4j.Com4jObject pdispSelect);

    @VTID(23)
    void internetDisconnect();

    @VTID(24)
    int getConnectedState();

    @VTID(25)
    int context();

    @VTID(26)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject validator();

    @VTID(27)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject licAgent();

    @VTID(28)
    java.lang.String countryInfo();

    @VTID(29)
    void wizardVisible(
        int rhs);

    @VTID(30)
    void wizardTitle(
        java.lang.String rhs);

    @VTID(31)
    int animationEnabled();

    @VTID(32)
    void currentHelpId(
        int rhs);

    @VTID(33)
    java.lang.String officeOnTheWebUrl();

}
