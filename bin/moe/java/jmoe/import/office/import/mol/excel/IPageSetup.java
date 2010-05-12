package mol.excel  ;

import com4j.*;

@IID("{000208B4-0001-0000-C000-000000000046}")
public interface IPageSetup extends Com4jObject {
    @VTID(7)
    mol.excel._Application application();

    @VTID(8)
    mol.excel.XlCreator creator();

    @VTID(9)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

    @VTID(10)
    boolean blackAndWhite();

    @VTID(11)
    void blackAndWhite(
        boolean rhs);

    @VTID(12)
    double bottomMargin();

    @VTID(13)
    void bottomMargin(
        double rhs);

    @VTID(14)
    java.lang.String centerFooter();

    @VTID(15)
    void centerFooter(
        java.lang.String rhs);

    @VTID(16)
    java.lang.String centerHeader();

    @VTID(17)
    void centerHeader(
        java.lang.String rhs);

    @VTID(18)
    boolean centerHorizontally();

    @VTID(19)
    void centerHorizontally(
        boolean rhs);

    @VTID(20)
    boolean centerVertically();

    @VTID(21)
    void centerVertically(
        boolean rhs);

    @VTID(22)
    mol.excel.XlObjectSize chartSize();

    @VTID(23)
    void chartSize(
        mol.excel.XlObjectSize rhs);

    @VTID(24)
    boolean draft();

    @VTID(25)
    void draft(
        boolean rhs);

    @VTID(26)
    int firstPageNumber();

    @VTID(27)
    void firstPageNumber(
        int rhs);

    @VTID(28)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object fitToPagesTall();

    @VTID(29)
    void fitToPagesTall(
        @MarshalAs(NativeType.VARIANT) java.lang.Object rhs);

    @VTID(30)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object fitToPagesWide();

    @VTID(31)
    void fitToPagesWide(
        @MarshalAs(NativeType.VARIANT) java.lang.Object rhs);

    @VTID(32)
    double footerMargin();

    @VTID(33)
    void footerMargin(
        double rhs);

    @VTID(34)
    double headerMargin();

    @VTID(35)
    void headerMargin(
        double rhs);

    @VTID(36)
    java.lang.String leftFooter();

    @VTID(37)
    void leftFooter(
        java.lang.String rhs);

    @VTID(38)
    java.lang.String leftHeader();

    @VTID(39)
    void leftHeader(
        java.lang.String rhs);

    @VTID(40)
    double leftMargin();

    @VTID(41)
    void leftMargin(
        double rhs);

    @VTID(42)
    mol.excel.XlOrder order();

    @VTID(43)
    void order(
        mol.excel.XlOrder rhs);

    @VTID(44)
    mol.excel.XlPageOrientation orientation();

    @VTID(45)
    void orientation(
        mol.excel.XlPageOrientation rhs);

    @VTID(46)
    mol.excel.XlPaperSize paperSize();

    @VTID(47)
    void paperSize(
        mol.excel.XlPaperSize rhs);

    @VTID(48)
    java.lang.String printArea();

    @VTID(49)
    void printArea(
        java.lang.String rhs);

    @VTID(50)
    boolean printGridlines();

    @VTID(51)
    void printGridlines(
        boolean rhs);

    @VTID(52)
    boolean printHeadings();

    @VTID(53)
    void printHeadings(
        boolean rhs);

    @VTID(54)
    boolean printNotes();

    @VTID(55)
    void printNotes(
        boolean rhs);

    @VTID(56)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object printQuality(
        @MarshalAs(NativeType.VARIANT) java.lang.Object index);

    @VTID(57)
    void printQuality(
        @MarshalAs(NativeType.VARIANT) java.lang.Object index,
        @MarshalAs(NativeType.VARIANT) java.lang.Object rhs);

    @VTID(58)
    java.lang.String printTitleColumns();

    @VTID(59)
    void printTitleColumns(
        java.lang.String rhs);

    @VTID(60)
    java.lang.String printTitleRows();

    @VTID(61)
    void printTitleRows(
        java.lang.String rhs);

    @VTID(62)
    java.lang.String rightFooter();

    @VTID(63)
    void rightFooter(
        java.lang.String rhs);

    @VTID(64)
    java.lang.String rightHeader();

    @VTID(65)
    void rightHeader(
        java.lang.String rhs);

    @VTID(66)
    double rightMargin();

    @VTID(67)
    void rightMargin(
        double rhs);

    @VTID(68)
    double topMargin();

    @VTID(69)
    void topMargin(
        double rhs);

    @VTID(70)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object zoom();

    @VTID(71)
    void zoom(
        @MarshalAs(NativeType.VARIANT) java.lang.Object rhs);

    @VTID(72)
    mol.excel.XlPrintLocation printComments();

    @VTID(73)
    void printComments(
        mol.excel.XlPrintLocation rhs);

    @VTID(74)
    mol.excel.XlPrintErrors printErrors();

    @VTID(75)
    void printErrors(
        mol.excel.XlPrintErrors rhs);

    @VTID(76)
    mol.excel.Graphic centerHeaderPicture();

    @VTID(77)
    mol.excel.Graphic centerFooterPicture();

    @VTID(78)
    mol.excel.Graphic leftHeaderPicture();

    @VTID(79)
    mol.excel.Graphic leftFooterPicture();

    @VTID(80)
    mol.excel.Graphic rightHeaderPicture();

    @VTID(81)
    mol.excel.Graphic rightFooterPicture();

    @VTID(82)
    boolean oddAndEvenPagesHeaderFooter();

    @VTID(83)
    void oddAndEvenPagesHeaderFooter(
        boolean rhs);

    @VTID(84)
    boolean differentFirstPageHeaderFooter();

    @VTID(85)
    void differentFirstPageHeaderFooter(
        boolean rhs);

    @VTID(86)
    boolean scaleWithDocHeaderFooter();

    @VTID(87)
    void scaleWithDocHeaderFooter(
        boolean rhs);

    @VTID(88)
    boolean alignMarginsHeaderFooter();

    @VTID(89)
    void alignMarginsHeaderFooter(
        boolean rhs);

    @VTID(90)
    mol.excel.Pages pages();

    @VTID(91)
    mol.excel.Page evenPage();

    @VTID(92)
    mol.excel.Page firstPage();

}
