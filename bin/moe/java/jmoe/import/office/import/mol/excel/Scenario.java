package mol.excel  ;

import com4j.*;

@IID("{00020400-0000-0000-C000-000000000046}")
public interface Scenario extends Com4jObject {
    @DISPID(148)
    @PropGet
    mol.excel._Application application();

    @DISPID(149)
    @PropGet
    mol.excel.XlCreator creator();

    @DISPID(150)
    @PropGet
    com4j.Com4jObject parent();

    @DISPID(912)
    java.lang.Object changeScenario(
        java.lang.Object changingCells,
        java.lang.Object values);

    @DISPID(911)
    @PropGet
    mol.excel.Range changingCells();

    @DISPID(910)
    @PropGet
    java.lang.String comment();

    @DISPID(910)
    @PropPut
    void comment(
        java.lang.String rhs);

    @DISPID(117)
    java.lang.Object delete();

    @DISPID(268)
    @PropGet
    boolean hidden();

    @DISPID(268)
    @PropPut
    void hidden(
        boolean rhs);

    @DISPID(486)
    @PropGet
    int index();

    @DISPID(269)
    @PropGet
    boolean locked();

    @DISPID(269)
    @PropPut
    void locked(
        boolean rhs);

    @DISPID(110)
    @PropGet
    java.lang.String name();

    @DISPID(110)
    @PropPut
    void name(
        java.lang.String rhs);

    @DISPID(496)
    java.lang.Object show();

    @DISPID(164)
    @PropGet
    java.lang.Object values(
        java.lang.Object index);

}
