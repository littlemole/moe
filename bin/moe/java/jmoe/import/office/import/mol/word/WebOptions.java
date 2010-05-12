package mol.word  ;

import com4j.*;

@IID("{000209E4-0000-0000-C000-000000000046}")
public interface WebOptions extends Com4jObject {
    @VTID(7)
    mol.word._Application application();

    @VTID(8)
    int creator();

    @VTID(9)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

    @VTID(10)
    boolean optimizeForBrowser();

    @VTID(11)
    void optimizeForBrowser(
        boolean prop);

    @VTID(12)
    mol.word.WdBrowserLevel browserLevel();

    @VTID(13)
    void browserLevel(
        mol.word.WdBrowserLevel prop);

    @VTID(14)
    boolean relyOnCSS();

    @VTID(15)
    void relyOnCSS(
        boolean prop);

    @VTID(16)
    boolean organizeInFolder();

    @VTID(17)
    void organizeInFolder(
        boolean prop);

    @VTID(18)
    boolean useLongFileNames();

    @VTID(19)
    void useLongFileNames(
        boolean prop);

    @VTID(20)
    boolean relyOnVML();

    @VTID(21)
    void relyOnVML(
        boolean prop);

    @VTID(22)
    boolean allowPNG();

    @VTID(23)
    void allowPNG(
        boolean prop);

    @VTID(24)
    mol.office.MsoScreenSize screenSize();

    @VTID(25)
    void screenSize(
        mol.office.MsoScreenSize prop);

    @VTID(26)
    int pixelsPerInch();

    @VTID(27)
    void pixelsPerInch(
        int prop);

    @VTID(28)
    mol.office.MsoEncoding encoding();

    @VTID(29)
    void encoding(
        mol.office.MsoEncoding prop);

    @VTID(30)
    java.lang.String folderSuffix();

    @VTID(31)
    void useDefaultFolderSuffix();

    @VTID(32)
    mol.office.MsoTargetBrowser targetBrowser();

    @VTID(33)
    void targetBrowser(
        mol.office.MsoTargetBrowser prop);

}
