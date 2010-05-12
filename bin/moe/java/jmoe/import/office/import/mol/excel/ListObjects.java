package mol.excel  ;

import com4j.*;

@IID("{00020400-0000-0000-C000-000000000046}")
public interface ListObjects extends Com4jObject,Iterable<Com4jObject> {
    @DISPID(148)
    @PropGet
    mol.excel._Application application();

    @DISPID(149)
    @PropGet
    mol.excel.XlCreator creator();

    @DISPID(150)
    @PropGet
    com4j.Com4jObject parent();

    @DISPID(2085)
    mol.excel.ListObject _Add(
        mol.excel.XlListObjectSourceType sourceType,
        java.lang.Object source,
        java.lang.Object linkSource,
        mol.excel.XlYesNoGuess xlListObjectHasHeaders,
        java.lang.Object destination);

    @DISPID(0)
    @PropGet
    @DefaultMethod
    mol.excel.ListObject _Default(
        java.lang.Object index);

    @DISPID(-4)
    @PropGet
    java.util.Iterator<Com4jObject> iterator();

    @DISPID(170)
    @PropGet
    mol.excel.ListObject item(
        java.lang.Object index);

    @DISPID(118)
    @PropGet
    int count();

    @DISPID(181)
    mol.excel.ListObject add(
        mol.excel.XlListObjectSourceType sourceType,
        java.lang.Object source,
        java.lang.Object linkSource,
        mol.excel.XlYesNoGuess xlListObjectHasHeaders,
        java.lang.Object destination,
        java.lang.Object tableStyleName);

}
