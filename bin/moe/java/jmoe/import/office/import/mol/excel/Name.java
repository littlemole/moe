package mol.excel  ;

import com4j.*;

@IID("{00020400-0000-0000-C000-000000000046}")
public interface Name extends Com4jObject {
    @DISPID(148)
    @PropGet
    mol.excel._Application application();

    @DISPID(149)
    @PropGet
    mol.excel.XlCreator creator();

    @DISPID(150)
    @PropGet
    com4j.Com4jObject parent();

    @DISPID(0)
    @PropGet
    @DefaultMethod
    java.lang.String _Default();

    @DISPID(486)
    @PropGet
    int index();

    @DISPID(934)
    @PropGet
    java.lang.String category();

    @DISPID(934)
    @PropPut
    void category(
        java.lang.String rhs);

    @DISPID(935)
    @PropGet
    java.lang.String categoryLocal();

    @DISPID(935)
    @PropPut
    void categoryLocal(
        java.lang.String rhs);

    @DISPID(117)
    void delete();

    @DISPID(936)
    @PropGet
    mol.excel.XlXLMMacroType macroType();

    @DISPID(936)
    @PropPut
    void macroType(
        mol.excel.XlXLMMacroType rhs);

    @DISPID(110)
    @PropGet
    java.lang.String name();

    @DISPID(110)
    @PropPut
    void name(
        java.lang.String rhs);

    @DISPID(938)
    @PropGet
    java.lang.Object refersTo();

    @DISPID(938)
    @PropPut
    void refersTo(
        java.lang.Object rhs);

    @DISPID(597)
    @PropGet
    java.lang.String shortcutKey();

    @DISPID(597)
    @PropPut
    void shortcutKey(
        java.lang.String rhs);

    @DISPID(6)
    @PropGet
    java.lang.String value();

    @DISPID(6)
    @PropPut
    void value(
        java.lang.String rhs);

    @DISPID(558)
    @PropGet
    boolean visible();

    @DISPID(558)
    @PropPut
    void visible(
        boolean rhs);

    @DISPID(937)
    @PropGet
    java.lang.String nameLocal();

    @DISPID(937)
    @PropPut
    void nameLocal(
        java.lang.String rhs);

    @DISPID(939)
    @PropGet
    java.lang.Object refersToLocal();

    @DISPID(939)
    @PropPut
    void refersToLocal(
        java.lang.Object rhs);

    @DISPID(940)
    @PropGet
    java.lang.Object refersToR1C1();

    @DISPID(940)
    @PropPut
    void refersToR1C1(
        java.lang.Object rhs);

    @DISPID(941)
    @PropGet
    java.lang.Object refersToR1C1Local();

    @DISPID(941)
    @PropPut
    void refersToR1C1Local(
        java.lang.Object rhs);

    @DISPID(1160)
    @PropGet
    mol.excel.Range refersToRange();

    @DISPID(910)
    @PropGet
    java.lang.String comment();

    @DISPID(910)
    @PropPut
    void comment(
        java.lang.String rhs);

    @DISPID(2607)
    @PropGet
    boolean workbookParameter();

    @DISPID(2607)
    @PropPut
    void workbookParameter(
        boolean rhs);

    @DISPID(2608)
    @PropGet
    boolean validWorkbookParameter();

}
