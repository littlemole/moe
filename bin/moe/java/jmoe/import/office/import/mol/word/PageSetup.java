package mol.word  ;

import com4j.*;

@IID("{00020971-0000-0000-C000-000000000046}")
public interface PageSetup extends Com4jObject {
    @VTID(7)
    mol.word._Application application();

    @VTID(8)
    int creator();

    @VTID(9)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

    @VTID(10)
    float topMargin();

    @VTID(11)
    void topMargin(
        float prop);

    @VTID(12)
    float bottomMargin();

    @VTID(13)
    void bottomMargin(
        float prop);

    @VTID(14)
    float leftMargin();

    @VTID(15)
    void leftMargin(
        float prop);

    @VTID(16)
    float rightMargin();

    @VTID(17)
    void rightMargin(
        float prop);

    @VTID(18)
    float gutter();

    @VTID(19)
    void gutter(
        float prop);

    @VTID(20)
    float pageWidth();

    @VTID(21)
    void pageWidth(
        float prop);

    @VTID(22)
    float pageHeight();

    @VTID(23)
    void pageHeight(
        float prop);

    @VTID(24)
    mol.word.WdOrientation orientation();

    @VTID(25)
    void orientation(
        mol.word.WdOrientation prop);

    @VTID(26)
    mol.word.WdPaperTray firstPageTray();

    @VTID(27)
    void firstPageTray(
        mol.word.WdPaperTray prop);

    @VTID(28)
    mol.word.WdPaperTray otherPagesTray();

    @VTID(29)
    void otherPagesTray(
        mol.word.WdPaperTray prop);

    @VTID(30)
    mol.word.WdVerticalAlignment verticalAlignment();

    @VTID(31)
    void verticalAlignment(
        mol.word.WdVerticalAlignment prop);

    @VTID(32)
    int mirrorMargins();

    @VTID(33)
    void mirrorMargins(
        int prop);

    @VTID(34)
    float headerDistance();

    @VTID(35)
    void headerDistance(
        float prop);

    @VTID(36)
    float footerDistance();

    @VTID(37)
    void footerDistance(
        float prop);

    @VTID(38)
    mol.word.WdSectionStart sectionStart();

    @VTID(39)
    void sectionStart(
        mol.word.WdSectionStart prop);

    @VTID(40)
    int oddAndEvenPagesHeaderFooter();

    @VTID(41)
    void oddAndEvenPagesHeaderFooter(
        int prop);

    @VTID(42)
    int differentFirstPageHeaderFooter();

    @VTID(43)
    void differentFirstPageHeaderFooter(
        int prop);

    @VTID(44)
    int suppressEndnotes();

    @VTID(45)
    void suppressEndnotes(
        int prop);

    @VTID(46)
    mol.word.LineNumbering lineNumbering();

    @VTID(47)
    void lineNumbering(
        mol.word.LineNumbering prop);

    @VTID(48)
    mol.word.TextColumns textColumns();

    @VTID(48)
    @ReturnValue(defaultPropertyThrough={mol.word.TextColumns.class})
    mol.word.TextColumn textColumns(
        int index);

    @VTID(49)
    void textColumns(
        mol.word.TextColumns prop);

    @VTID(50)
    mol.word.WdPaperSize paperSize();

    @VTID(51)
    void paperSize(
        mol.word.WdPaperSize prop);

    @VTID(52)
    boolean twoPagesOnOne();

    @VTID(53)
    void twoPagesOnOne(
        boolean prop);

    @VTID(54)
    boolean gutterOnTop();

    @VTID(55)
    void gutterOnTop(
        boolean prop);

    @VTID(56)
    float charsLine();

    @VTID(57)
    void charsLine(
        float prop);

    @VTID(58)
    float linesPage();

    @VTID(59)
    void linesPage(
        float prop);

    @VTID(60)
    boolean showGrid();

    @VTID(61)
    void showGrid(
        boolean prop);

    @VTID(62)
    void togglePortrait();

    @VTID(63)
    void setAsTemplateDefault();

    @VTID(64)
    mol.word.WdGutterStyleOld gutterStyle();

    @VTID(65)
    void gutterStyle(
        mol.word.WdGutterStyleOld prop);

    @VTID(66)
    mol.word.WdSectionDirection sectionDirection();

    @VTID(67)
    void sectionDirection(
        mol.word.WdSectionDirection prop);

    @VTID(68)
    mol.word.WdLayoutMode layoutMode();

    @VTID(69)
    void layoutMode(
        mol.word.WdLayoutMode prop);

    @VTID(70)
    mol.word.WdGutterStyle gutterPos();

    @VTID(71)
    void gutterPos(
        mol.word.WdGutterStyle prop);

    @VTID(72)
    boolean bookFoldPrinting();

    @VTID(73)
    void bookFoldPrinting(
        boolean prop);

    @VTID(74)
    boolean bookFoldRevPrinting();

    @VTID(75)
    void bookFoldRevPrinting(
        boolean prop);

    @VTID(76)
    int bookFoldPrintingSheets();

    @VTID(77)
    void bookFoldPrintingSheets(
        int prop);

}
