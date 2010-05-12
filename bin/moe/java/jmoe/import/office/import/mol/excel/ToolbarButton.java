package mol.excel  ;

import com4j.*;

@IID("{00020400-0000-0000-C000-000000000046}")
public interface ToolbarButton extends Com4jObject {
    @DISPID(148)
    @PropGet
    mol.excel._Application application();

    @DISPID(149)
    @PropGet
    mol.excel.XlCreator creator();

    @DISPID(150)
    @PropGet
    com4j.Com4jObject parent();

    @DISPID(553)
    @PropGet
    boolean builtIn();

    @DISPID(554)
    @PropGet
    boolean builtInFace();

    @DISPID(554)
    @PropPut
    void builtInFace(
        boolean rhs);

    @DISPID(551)
    void copy(
        mol.excel.Toolbar toolbar,
        int before);

    @DISPID(966)
    void copyFace();

    @DISPID(117)
    void delete();

    @DISPID(562)
    void edit();

    @DISPID(600)
    @PropGet
    boolean enabled();

    @DISPID(600)
    @PropPut
    void enabled(
        boolean rhs);

    @DISPID(355)
    @PropGet
    int helpContextID();

    @DISPID(355)
    @PropPut
    void helpContextID(
        int rhs);

    @DISPID(360)
    @PropGet
    java.lang.String helpFile();

    @DISPID(360)
    @PropPut
    void helpFile(
        java.lang.String rhs);

    @DISPID(570)
    @PropGet
    int id();

    @DISPID(561)
    @PropGet
    boolean isGap();

    @DISPID(637)
    void move(
        mol.excel.Toolbar toolbar,
        int before);

    @DISPID(110)
    @PropGet
    java.lang.String name();

    @DISPID(110)
    @PropPut
    void name(
        java.lang.String rhs);

    @DISPID(596)
    @PropGet
    java.lang.String onAction();

    @DISPID(596)
    @PropPut
    void onAction(
        java.lang.String rhs);

    @DISPID(967)
    void pasteFace();

    @DISPID(560)
    @PropGet
    boolean pushed();

    @DISPID(560)
    @PropPut
    void pushed(
        boolean rhs);

    @DISPID(555)
    void reset();

    @DISPID(386)
    @PropGet
    java.lang.String statusBar();

    @DISPID(386)
    @PropPut
    void statusBar(
        java.lang.String rhs);

    @DISPID(122)
    @PropGet
    int width();

    @DISPID(122)
    @PropPut
    void width(
        int rhs);

}
