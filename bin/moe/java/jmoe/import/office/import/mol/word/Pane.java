package mol.word  ;

import com4j.*;

@IID("{00020960-0000-0000-C000-000000000046}")
public interface Pane extends Com4jObject {
    @VTID(7)
    mol.word._Application application();

    @VTID(8)
    int creator();

    @VTID(9)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

    @VTID(10)
    mol.word._Document document();

    @VTID(11)
    mol.word.Selection selection();

    @VTID(12)
    boolean displayRulers();

    @VTID(13)
    void displayRulers(
        boolean prop);

    @VTID(14)
    boolean displayVerticalRuler();

    @VTID(15)
    void displayVerticalRuler(
        boolean prop);

    @VTID(16)
    mol.word.Zooms zooms();

    @VTID(16)
    @ReturnValue(defaultPropertyThrough={mol.word.Zooms.class})
    mol.word.Zoom zooms(
        mol.word.WdViewType index);

    @VTID(17)
    int index();

    @VTID(18)
    mol.word.View view();

    @VTID(19)
    mol.word.Pane next();

    @VTID(20)
    mol.word.Pane previous();

    @VTID(21)
    int horizontalPercentScrolled();

    @VTID(22)
    void horizontalPercentScrolled(
        int prop);

    @VTID(23)
    int verticalPercentScrolled();

    @VTID(24)
    void verticalPercentScrolled(
        int prop);

    @VTID(25)
    int minimumFontSize();

    @VTID(26)
    void minimumFontSize(
        int prop);

    @VTID(27)
    boolean browseToWindow();

    @VTID(28)
    void browseToWindow(
        boolean prop);

    @VTID(29)
    int browseWidth();

    @VTID(30)
    void activate();

    @VTID(31)
    void close();

    @VTID(32)
    void largeScroll(
        java.lang.Object down,
        java.lang.Object up,
        java.lang.Object toRight,
        java.lang.Object toLeft);

    @VTID(33)
    void smallScroll(
        java.lang.Object down,
        java.lang.Object up,
        java.lang.Object toRight,
        java.lang.Object toLeft);

    @VTID(34)
    void autoScroll(
        int velocity);

    @VTID(35)
    void pageScroll(
        java.lang.Object down,
        java.lang.Object up);

    @VTID(36)
    void newFrameset();

    @VTID(37)
    void tocInFrameset();

    @VTID(38)
    mol.word.Frameset frameset();

    @VTID(39)
    mol.word.Pages pages();

    @VTID(39)
    @ReturnValue(defaultPropertyThrough={mol.word.Pages.class})
    mol.word.Page pages(
        int index);

}
