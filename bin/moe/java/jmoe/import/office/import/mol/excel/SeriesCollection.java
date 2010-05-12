package mol.excel  ;

import com4j.*;

@IID("{00020400-0000-0000-C000-000000000046}")
public interface SeriesCollection extends Com4jObject,Iterable<Com4jObject> {
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
    mol.excel.Series add(
        java.lang.Object source,
        mol.excel.XlRowCol rowcol,
        java.lang.Object seriesLabels,
        java.lang.Object categoryLabels,
        java.lang.Object replace);

    @DISPID(118)
    @PropGet
    int count();

    @DISPID(227)
    java.lang.Object extend(
        java.lang.Object source,
        java.lang.Object rowcol,
        java.lang.Object categoryLabels);

    @DISPID(170)
    mol.excel.Series item(
        java.lang.Object index);

    @DISPID(-4)
    java.util.Iterator<Com4jObject> iterator();

    @DISPID(211)
    java.lang.Object paste(
        mol.excel.XlRowCol rowcol,
        java.lang.Object seriesLabels,
        java.lang.Object categoryLabels,
        java.lang.Object replace,
        java.lang.Object newSeries);

    @DISPID(1117)
    mol.excel.Series newSeries();

    @DISPID(0)
    @DefaultMethod
    mol.excel.Series _Default(
        java.lang.Object index);

}
