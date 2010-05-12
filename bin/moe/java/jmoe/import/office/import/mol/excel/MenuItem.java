package mol.excel  ;

import com4j.*;

@IID("{00020400-0000-0000-C000-000000000046}")
public interface MenuItem extends Com4jObject {
    @DISPID(148)
    @PropGet
    mol.excel._Application application();

    @DISPID(149)
    @PropGet
    mol.excel.XlCreator creator();

    @DISPID(150)
    @PropGet
    com4j.Com4jObject parent();

    @DISPID(139)
    @PropGet
    java.lang.String caption();

    @DISPID(139)
    @PropPut
    void caption(
        java.lang.String rhs);

    @DISPID(599)
    @PropGet
    boolean checked();

    @DISPID(599)
    @PropPut
    void checked(
        boolean rhs);

    @DISPID(117)
    void delete();

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

    @DISPID(486)
    @PropGet
    int index();

    @DISPID(596)
    @PropGet
    java.lang.String onAction();

    @DISPID(596)
    @PropPut
    void onAction(
        java.lang.String rhs);

    @DISPID(386)
    @PropGet
    java.lang.String statusBar();

    @DISPID(386)
    @PropPut
    void statusBar(
        java.lang.String rhs);

}
