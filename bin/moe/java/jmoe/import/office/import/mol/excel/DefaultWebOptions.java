package mol.excel  ;

import com4j.*;
import mol.office.*;
import mol.vba.*;

@IID("{00024448-0000-0000-C000-000000000046}")
public interface DefaultWebOptions extends Com4jObject {
    @VTID(7)
    mol.excel._Application application();

    @VTID(8)
    mol.excel.XlCreator creator();

    @VTID(9)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

    @VTID(10)
    boolean relyOnCSS();

    @VTID(11)
    void relyOnCSS(
        boolean rhs);

    @VTID(12)
    boolean saveHiddenData();

    @VTID(13)
    void saveHiddenData(
        boolean rhs);

    @VTID(14)
    boolean loadPictures();

    @VTID(15)
    void loadPictures(
        boolean rhs);

    @VTID(16)
    boolean organizeInFolder();

    @VTID(17)
    void organizeInFolder(
        boolean rhs);

    @VTID(18)
    boolean updateLinksOnSave();

    @VTID(19)
    void updateLinksOnSave(
        boolean rhs);

    @VTID(20)
    boolean useLongFileNames();

    @VTID(21)
    void useLongFileNames(
        boolean rhs);

    @VTID(22)
    boolean checkIfOfficeIsHTMLEditor();

    @VTID(23)
    void checkIfOfficeIsHTMLEditor(
        boolean rhs);

    @VTID(24)
    boolean downloadComponents();

    @VTID(25)
    void downloadComponents(
        boolean rhs);

    @VTID(26)
    boolean relyOnVML();

    @VTID(27)
    void relyOnVML(
        boolean rhs);

    @VTID(28)
    boolean allowPNG();

    @VTID(29)
    void allowPNG(
        boolean rhs);

    @VTID(30)
    mol.office.MsoScreenSize screenSize();

    @VTID(31)
    void screenSize(
        mol.office.MsoScreenSize rhs);

    @VTID(32)
    int pixelsPerInch();

    @VTID(33)
    void pixelsPerInch(
        int rhs);

    @VTID(34)
    java.lang.String locationOfComponents();

    @VTID(35)
    void locationOfComponents(
        java.lang.String rhs);

    @VTID(36)
    mol.office.MsoEncoding encoding();

    @VTID(37)
    void encoding(
        mol.office.MsoEncoding rhs);

    @VTID(38)
    boolean alwaysSaveInDefaultEncoding();

    @VTID(39)
    void alwaysSaveInDefaultEncoding(
        boolean rhs);

    @VTID(40)
    mol.office.WebPageFonts fonts();

    @VTID(40)
    @ReturnValue(defaultPropertyThrough={mol.office.WebPageFonts.class})
    mol.office.WebPageFont fonts(
        mol.office.MsoCharacterSet index);

    @VTID(41)
    java.lang.String folderSuffix();

    @VTID(42)
    mol.office.MsoTargetBrowser targetBrowser();

    @VTID(43)
    void targetBrowser(
        mol.office.MsoTargetBrowser rhs);

    @VTID(44)
    boolean saveNewWebPagesAsWebArchives();

    @VTID(45)
    void saveNewWebPagesAsWebArchives(
        boolean rhs);

}
