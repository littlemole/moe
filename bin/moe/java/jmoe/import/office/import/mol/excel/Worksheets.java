package mol.excel  ;

import com4j.*;

@IID("{00020400-0000-0000-C000-000000000046}")
public interface Worksheets extends Com4jObject,Iterable<Com4jObject> {
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
    com4j.Com4jObject add(
        java.lang.Object before,
        java.lang.Object after,
        java.lang.Object count,
        java.lang.Object type);

    @DISPID(551)
    void copy(
        java.lang.Object before,
        java.lang.Object after);

    @DISPID(118)
    @PropGet
    int count();

    @DISPID(117)
    void delete();

    @DISPID(469)
    void fillAcrossSheets(
        mol.excel.Range range,
        mol.excel.XlFillWith type);

    @DISPID(170)
    @PropGet
    com4j.Com4jObject item(
        java.lang.Object index);

    @DISPID(637)
    void move(
        java.lang.Object before,
        java.lang.Object after);

    @DISPID(-4)
    @PropGet
    java.util.Iterator<Com4jObject> iterator();

    @DISPID(905)
    void __PrintOut(
        java.lang.Object from,
        java.lang.Object to,
        java.lang.Object copies,
        java.lang.Object preview,
        java.lang.Object activePrinter,
        java.lang.Object printToFile,
        java.lang.Object collate);

    @DISPID(281)
    void printPreview(
        java.lang.Object enableChanges);

    @DISPID(235)
    void select(
        java.lang.Object replace);

    @DISPID(1418)
    @PropGet
    mol.excel.HPageBreaks hPageBreaks();

    @DISPID(1419)
    @PropGet
    mol.excel.VPageBreaks vPageBreaks();

    @DISPID(558)
    @PropGet
    java.lang.Object visible();

    @DISPID(558)
    @PropPut
    void visible(
        java.lang.Object rhs);

    @DISPID(0)
    @PropGet
    @DefaultMethod
    com4j.Com4jObject _Default(
        java.lang.Object index);

    @DISPID(1772)
    void _PrintOut(
        java.lang.Object from,
        java.lang.Object to,
        java.lang.Object copies,
        java.lang.Object preview,
        java.lang.Object activePrinter,
        java.lang.Object printToFile,
        java.lang.Object collate,
        java.lang.Object prToFileName);

    @DISPID(2361)
    void printOut(
        java.lang.Object from,
        java.lang.Object to,
        java.lang.Object copies,
        java.lang.Object preview,
        java.lang.Object activePrinter,
        java.lang.Object printToFile,
        java.lang.Object collate,
        java.lang.Object prToFileName,
        java.lang.Object ignorePrintAreas);

}
