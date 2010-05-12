package mol.excel  ;

import com4j.*;
import mol.office.*;
import mol.vba.*;

@IID("{00024449-0000-0000-C000-000000000046}")
public interface WebOptions extends Com4jObject {
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
    boolean organizeInFolder();

    @VTID(13)
    void organizeInFolder(
        boolean rhs);

    @VTID(14)
    boolean useLongFileNames();

    @VTID(15)
    void useLongFileNames(
        boolean rhs);

    @VTID(16)
    boolean downloadComponents();

    @VTID(17)
    void downloadComponents(
        boolean rhs);

    @VTID(18)
    boolean relyOnVML();

    @VTID(19)
    void relyOnVML(
        boolean rhs);

    @VTID(20)
    boolean allowPNG();

    @VTID(21)
    void allowPNG(
        boolean rhs);

    @VTID(22)
    mol.office.MsoScreenSize screenSize();

    @VTID(23)
    void screenSize(
        mol.office.MsoScreenSize rhs);

    @VTID(24)
    int pixelsPerInch();

    @VTID(25)
    void pixelsPerInch(
        int rhs);

    @VTID(26)
    java.lang.String locationOfComponents();

    @VTID(27)
    void locationOfComponents(
        java.lang.String rhs);

    @VTID(28)
    mol.office.MsoEncoding encoding();

    @VTID(29)
    void encoding(
        mol.office.MsoEncoding rhs);

    @VTID(30)
    java.lang.String folderSuffix();

    @VTID(31)
    void useDefaultFolderSuffix();

    @VTID(32)
    mol.office.MsoTargetBrowser targetBrowser();

    @VTID(33)
    void targetBrowser(
        mol.office.MsoTargetBrowser rhs);

}
