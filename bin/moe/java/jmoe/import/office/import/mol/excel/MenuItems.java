package mol.excel  ;

import com4j.*;

@IID("{00020400-0000-0000-C000-000000000046}")
public interface MenuItems extends Com4jObject,Iterable<Com4jObject> {
    @DISPID(148)
    @PropGet
    mol.excel._Application application();

    @DISPID(149)
    @PropGet
    mol.excel.XlCreator creator();

    @DISPID(150)
    @PropGet
    com4j.Com4jObject parent();

    @DISPID(181)
    mol.excel.MenuItem add(
        java.lang.String caption,
        java.lang.Object onAction,
        java.lang.Object shortcutKey,
        java.lang.Object before,
        java.lang.Object restore,
        java.lang.Object statusBar,
        java.lang.Object helpFile,
        java.lang.Object helpContextID);

    @DISPID(598)
    mol.excel.Menu addMenu(
        java.lang.String caption,
        java.lang.Object before,
        java.lang.Object restore);

    @DISPID(118)
    @PropGet
    int count();

    @DISPID(0)
    @PropGet
    @DefaultMethod
    com4j.Com4jObject _Default(
        java.lang.Object index);

    @DISPID(170)
    @PropGet
    com4j.Com4jObject item(
        java.lang.Object index);

    @DISPID(-4)
    @PropGet
    java.util.Iterator<Com4jObject> iterator();

}
