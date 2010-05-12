package mol.excel  ;

import com4j.*;

@IID("{00020400-0000-0000-C000-000000000046}")
public interface Connections extends Com4jObject,Iterable<Com4jObject> {
    @DISPID(148)
    @PropGet
    mol.excel._Application application();

    @DISPID(149)
    @PropGet
    mol.excel.XlCreator creator();

    @DISPID(150)
    @PropGet
    com4j.Com4jObject parent();

    @DISPID(118)
    @PropGet
    int count();

    @DISPID(2700)
    mol.excel.WorkbookConnection addFromFile(
        java.lang.String filename);

    @DISPID(181)
    mol.excel.WorkbookConnection add(
        java.lang.String name,
        java.lang.String description,
        java.lang.Object connectionString,
        java.lang.Object commandText,
        java.lang.Object lCmdtype);

    @DISPID(170)
    mol.excel.WorkbookConnection item(
        java.lang.Object index);

    @DISPID(0)
    @PropGet
    @DefaultMethod
    mol.excel.WorkbookConnection _Default(
        java.lang.Object index);

    @DISPID(-4)
    @PropGet
    java.util.Iterator<Com4jObject> iterator();

}
