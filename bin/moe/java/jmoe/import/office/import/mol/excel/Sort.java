package mol.excel  ;

import com4j.*;

@IID("{00020400-0000-0000-C000-000000000046}")
public interface Sort extends Com4jObject {
    @DISPID(148)
    @PropGet
    mol.excel._Application application();

    @DISPID(149)
    @PropGet
    mol.excel.XlCreator creator();

    @DISPID(150)
    @PropGet
    com4j.Com4jObject parent();

    @DISPID(2748)
    @PropGet
    mol.excel.Range rng();

    @DISPID(895)
    @PropGet
    mol.excel.XlYesNoGuess header();

    @DISPID(895)
    @PropPut
    void header(
        mol.excel.XlYesNoGuess rhs);

    @DISPID(426)
    @PropGet
    boolean matchCase();

    @DISPID(426)
    @PropPut
    void matchCase(
        boolean rhs);

    @DISPID(134)
    @PropGet
    mol.excel.XlSortOrientation orientation();

    @DISPID(134)
    @PropPut
    void orientation(
        mol.excel.XlSortOrientation rhs);

    @DISPID(897)
    @PropGet
    mol.excel.XlSortMethod sortMethod();

    @DISPID(897)
    @PropPut
    void sortMethod(
        mol.excel.XlSortMethod rhs);

    @DISPID(2749)
    @PropGet
    mol.excel.SortFields sortFields();

    @DISPID(2750)
    void setRange(
        mol.excel.Range rng);

    @DISPID(1675)
    void apply();

}
