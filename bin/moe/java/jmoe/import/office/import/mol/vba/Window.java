package mol.vba  ;

import com4j.*;

@IID("{0002E16B-0000-0000-C000-000000000046}")
public interface Window extends Com4jObject {
    @VTID(7)
    mol.vba.VBE vbe();

    @VTID(8)
    mol.vba._Windows collection();

    @VTID(9)
    void close();

    @VTID(10)
    java.lang.String caption();

    @VTID(11)
    boolean visible();

    @VTID(12)
    void visible(
        boolean pfVisible);

    @VTID(13)
    int left();

    @VTID(14)
    void left(
        int plLeft);

    @VTID(15)
    int top();

    @VTID(16)
    void top(
        int plTop);

    @VTID(17)
    int width();

    @VTID(18)
    void width(
        int plWidth);

    @VTID(19)
    int height();

    @VTID(20)
    void height(
        int plHeight);

    @VTID(21)
    mol.vba.vbext_WindowState windowState();

    @VTID(22)
    void windowState(
        mol.vba.vbext_WindowState plWindowState);

    @VTID(23)
    void setFocus();

    @VTID(24)
    mol.vba.vbext_WindowType type();

    @VTID(25)
    void setKind(
        mol.vba.vbext_WindowType eKind);

    @VTID(26)
    mol.vba._LinkedWindows linkedWindows();

    @VTID(27)
    mol.vba.Window linkedWindowFrame();

    @VTID(28)
    void detach();

    @VTID(29)
    void attach(
        int lWindowHandle);

    @VTID(30)
    int hWnd();

}
