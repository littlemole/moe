package mol.excel  ;

import com4j.*;

@IID("{00020400-0000-0000-C000-000000000046}")
public interface Windows extends Com4jObject,Iterable<Com4jObject> {
    @DISPID(148)
    @PropGet
    mol.excel._Application application();

    @DISPID(149)
    @PropGet
    mol.excel.XlCreator creator();

    @DISPID(150)
    @PropGet
    com4j.Com4jObject parent();

    @DISPID(638)
    java.lang.Object arrange(
        mol.excel.XlArrangeStyle arrangeStyle,
        java.lang.Object activeWorkbook,
        java.lang.Object syncHorizontal,
        java.lang.Object syncVertical);

    @DISPID(118)
    @PropGet
    int count();

    @DISPID(170)
    @PropGet
    mol.excel.Window item(
        java.lang.Object index);

    @DISPID(-4)
    @PropGet
    java.util.Iterator<Com4jObject> iterator();

    @DISPID(0)
    @PropGet
    @DefaultMethod
    mol.excel.Window _Default(
        java.lang.Object index);

    @DISPID(2246)
    boolean compareSideBySideWith(
        java.lang.Object windowName);

    @DISPID(2248)
    boolean breakSideBySide();

    @DISPID(2249)
    @PropGet
    boolean syncScrollingSideBySide();

    @DISPID(2249)
    @PropPut
    void syncScrollingSideBySide(
        boolean rhs);

    @DISPID(2250)
    void resetPositionsSideBySide();

}
