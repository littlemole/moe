package mol.word  ;

import com4j.*;

@IID("{00020982-0000-0000-C000-000000000046}")
public interface Task extends Com4jObject {
    @VTID(7)
    mol.word._Application application();

    @VTID(8)
    int creator();

    @VTID(9)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

    @VTID(10)
    @DefaultMethod
    java.lang.String name();

    @VTID(11)
    int left();

    @VTID(12)
    void left(
        int prop);

    @VTID(13)
    int top();

    @VTID(14)
    void top(
        int prop);

    @VTID(15)
    int width();

    @VTID(16)
    void width(
        int prop);

    @VTID(17)
    int height();

    @VTID(18)
    void height(
        int prop);

    @VTID(19)
    mol.word.WdWindowState windowState();

    @VTID(20)
    void windowState(
        mol.word.WdWindowState prop);

    @VTID(21)
    boolean visible();

    @VTID(22)
    void visible(
        boolean prop);

    @VTID(23)
    void activate(
        java.lang.Object wait);

    @VTID(24)
    void close();

    @VTID(25)
    void move(
        int left,
        int top);

    @VTID(26)
    void resize(
        int width,
        int height);

    @VTID(27)
    void sendWindowMessage(
        int message,
        int wParam,
        int lParam);

}
