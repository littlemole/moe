package mol.word  ;

import com4j.*;

@IID("{000209E3-0000-0000-C000-000000000046}")
public interface DefaultWebOptions extends Com4jObject {
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
    boolean updateLinksOnSave();

    @VTID(19)
    void updateLinksOnSave(
        boolean prop);

    @VTID(20)
    boolean useLongFileNames();

    @VTID(21)
    void useLongFileNames(
        boolean prop);

    @VTID(22)
    boolean checkIfOfficeIsHTMLEditor();

    @VTID(23)
    void checkIfOfficeIsHTMLEditor(
        boolean prop);

    @VTID(24)
    boolean checkIfWordIsDefaultHTMLEditor();

    @VTID(25)
    void checkIfWordIsDefaultHTMLEditor(
        boolean prop);

    @VTID(26)
    boolean relyOnVML();

    @VTID(27)
    void relyOnVML(
        boolean prop);

    @VTID(28)
    boolean allowPNG();

    @VTID(29)
    void allowPNG(
        boolean prop);

    @VTID(30)
    mol.office.MsoScreenSize screenSize();

    @VTID(31)
    void screenSize(
        mol.office.MsoScreenSize prop);

    @VTID(32)
    int pixelsPerInch();

    @VTID(33)
    void pixelsPerInch(
        int prop);

    @VTID(34)
    mol.office.MsoEncoding encoding();

    @VTID(35)
    void encoding(
        mol.office.MsoEncoding prop);

    @VTID(36)
    boolean alwaysSaveInDefaultEncoding();

    @VTID(37)
    void alwaysSaveInDefaultEncoding(
        boolean prop);

    @VTID(38)
    mol.office.WebPageFonts fonts();

    @VTID(38)
    @ReturnValue(defaultPropertyThrough={mol.office.WebPageFonts.class})
    mol.office.WebPageFont fonts(
        mol.office.MsoCharacterSet index);

    @VTID(39)
    java.lang.String folderSuffix();

    @VTID(40)
    mol.office.MsoTargetBrowser targetBrowser();

    @VTID(41)
    void targetBrowser(
        mol.office.MsoTargetBrowser prop);

    @VTID(42)
    boolean saveNewWebPagesAsWebArchives();

    @VTID(43)
    void saveNewWebPagesAsWebArchives(
        boolean prop);

}
