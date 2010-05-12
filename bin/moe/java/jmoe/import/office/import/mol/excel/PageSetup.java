package mol.excel  ;

import com4j.*;

@IID("{00020400-0000-0000-C000-000000000046}")
public interface PageSetup extends Com4jObject {
    @DISPID(148)
    @PropGet
    mol.excel._Application application();

    @DISPID(149)
    @PropGet
    mol.excel.XlCreator creator();

    @DISPID(150)
    @PropGet
    com4j.Com4jObject parent();

    @DISPID(1009)
    @PropGet
    boolean blackAndWhite();

    @DISPID(1009)
    @PropPut
    void blackAndWhite(
        boolean rhs);

    @DISPID(1002)
    @PropGet
    double bottomMargin();

    @DISPID(1002)
    @PropPut
    void bottomMargin(
        double rhs);

    @DISPID(1010)
    @PropGet
    java.lang.String centerFooter();

    @DISPID(1010)
    @PropPut
    void centerFooter(
        java.lang.String rhs);

    @DISPID(1011)
    @PropGet
    java.lang.String centerHeader();

    @DISPID(1011)
    @PropPut
    void centerHeader(
        java.lang.String rhs);

    @DISPID(1005)
    @PropGet
    boolean centerHorizontally();

    @DISPID(1005)
    @PropPut
    void centerHorizontally(
        boolean rhs);

    @DISPID(1006)
    @PropGet
    boolean centerVertically();

    @DISPID(1006)
    @PropPut
    void centerVertically(
        boolean rhs);

    @DISPID(1012)
    @PropGet
    mol.excel.XlObjectSize chartSize();

    @DISPID(1012)
    @PropPut
    void chartSize(
        mol.excel.XlObjectSize rhs);

    @DISPID(1020)
    @PropGet
    boolean draft();

    @DISPID(1020)
    @PropPut
    void draft(
        boolean rhs);

    @DISPID(1008)
    @PropGet
    int firstPageNumber();

    @DISPID(1008)
    @PropPut
    void firstPageNumber(
        int rhs);

    @DISPID(1013)
    @PropGet
    java.lang.Object fitToPagesTall();

    @DISPID(1013)
    @PropPut
    void fitToPagesTall(
        java.lang.Object rhs);

    @DISPID(1014)
    @PropGet
    java.lang.Object fitToPagesWide();

    @DISPID(1014)
    @PropPut
    void fitToPagesWide(
        java.lang.Object rhs);

    @DISPID(1015)
    @PropGet
    double footerMargin();

    @DISPID(1015)
    @PropPut
    void footerMargin(
        double rhs);

    @DISPID(1016)
    @PropGet
    double headerMargin();

    @DISPID(1016)
    @PropPut
    void headerMargin(
        double rhs);

    @DISPID(1017)
    @PropGet
    java.lang.String leftFooter();

    @DISPID(1017)
    @PropPut
    void leftFooter(
        java.lang.String rhs);

    @DISPID(1018)
    @PropGet
    java.lang.String leftHeader();

    @DISPID(1018)
    @PropPut
    void leftHeader(
        java.lang.String rhs);

    @DISPID(999)
    @PropGet
    double leftMargin();

    @DISPID(999)
    @PropPut
    void leftMargin(
        double rhs);

    @DISPID(192)
    @PropGet
    mol.excel.XlOrder order();

    @DISPID(192)
    @PropPut
    void order(
        mol.excel.XlOrder rhs);

    @DISPID(134)
    @PropGet
    mol.excel.XlPageOrientation orientation();

    @DISPID(134)
    @PropPut
    void orientation(
        mol.excel.XlPageOrientation rhs);

    @DISPID(1007)
    @PropGet
    mol.excel.XlPaperSize paperSize();

    @DISPID(1007)
    @PropPut
    void paperSize(
        mol.excel.XlPaperSize rhs);

    @DISPID(1019)
    @PropGet
    java.lang.String printArea();

    @DISPID(1019)
    @PropPut
    void printArea(
        java.lang.String rhs);

    @DISPID(1004)
    @PropGet
    boolean printGridlines();

    @DISPID(1004)
    @PropPut
    void printGridlines(
        boolean rhs);

    @DISPID(1003)
    @PropGet
    boolean printHeadings();

    @DISPID(1003)
    @PropPut
    void printHeadings(
        boolean rhs);

    @DISPID(1021)
    @PropGet
    boolean printNotes();

    @DISPID(1021)
    @PropPut
    void printNotes(
        boolean rhs);

    @DISPID(1022)
    @PropGet
    java.lang.Object printQuality(
        java.lang.Object index);

    @DISPID(1022)
    @PropPut
    void printQuality(
        java.lang.Object index,
        java.lang.Object rhs);

    @DISPID(1023)
    @PropGet
    java.lang.String printTitleColumns();

    @DISPID(1023)
    @PropPut
    void printTitleColumns(
        java.lang.String rhs);

    @DISPID(1024)
    @PropGet
    java.lang.String printTitleRows();

    @DISPID(1024)
    @PropPut
    void printTitleRows(
        java.lang.String rhs);

    @DISPID(1025)
    @PropGet
    java.lang.String rightFooter();

    @DISPID(1025)
    @PropPut
    void rightFooter(
        java.lang.String rhs);

    @DISPID(1026)
    @PropGet
    java.lang.String rightHeader();

    @DISPID(1026)
    @PropPut
    void rightHeader(
        java.lang.String rhs);

    @DISPID(1000)
    @PropGet
    double rightMargin();

    @DISPID(1000)
    @PropPut
    void rightMargin(
        double rhs);

    @DISPID(1001)
    @PropGet
    double topMargin();

    @DISPID(1001)
    @PropPut
    void topMargin(
        double rhs);

    @DISPID(663)
    @PropGet
    java.lang.Object zoom();

    @DISPID(663)
    @PropPut
    void zoom(
        java.lang.Object rhs);

    @DISPID(1524)
    @PropGet
    mol.excel.XlPrintLocation printComments();

    @DISPID(1524)
    @PropPut
    void printComments(
        mol.excel.XlPrintLocation rhs);

    @DISPID(2149)
    @PropGet
    mol.excel.XlPrintErrors printErrors();

    @DISPID(2149)
    @PropPut
    void printErrors(
        mol.excel.XlPrintErrors rhs);

    @DISPID(2150)
    @PropGet
    mol.excel.Graphic centerHeaderPicture();

    @DISPID(2151)
    @PropGet
    mol.excel.Graphic centerFooterPicture();

    @DISPID(2152)
    @PropGet
    mol.excel.Graphic leftHeaderPicture();

    @DISPID(2153)
    @PropGet
    mol.excel.Graphic leftFooterPicture();

    @DISPID(2154)
    @PropGet
    mol.excel.Graphic rightHeaderPicture();

    @DISPID(2155)
    @PropGet
    mol.excel.Graphic rightFooterPicture();

    @DISPID(2600)
    @PropGet
    boolean oddAndEvenPagesHeaderFooter();

    @DISPID(2600)
    @PropPut
    void oddAndEvenPagesHeaderFooter(
        boolean rhs);

    @DISPID(2601)
    @PropGet
    boolean differentFirstPageHeaderFooter();

    @DISPID(2601)
    @PropPut
    void differentFirstPageHeaderFooter(
        boolean rhs);

    @DISPID(2602)
    @PropGet
    boolean scaleWithDocHeaderFooter();

    @DISPID(2602)
    @PropPut
    void scaleWithDocHeaderFooter(
        boolean rhs);

    @DISPID(2603)
    @PropGet
    boolean alignMarginsHeaderFooter();

    @DISPID(2603)
    @PropPut
    void alignMarginsHeaderFooter(
        boolean rhs);

    @DISPID(2604)
    @PropGet
    mol.excel.Pages pages();

    @DISPID(2605)
    @PropGet
    mol.excel.Page evenPage();

    @DISPID(2606)
    @PropGet
    mol.excel.Page firstPage();

}
