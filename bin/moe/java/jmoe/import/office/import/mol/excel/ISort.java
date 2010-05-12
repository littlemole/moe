package mol.excel  ;

import com4j.*;

@IID("{000244AB-0001-0000-C000-000000000046}")
public interface ISort extends Com4jObject {
    @VTID(7)
    mol.excel._Application application();

    @VTID(8)
    mol.excel.XlCreator creator();

    @VTID(9)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

    @VTID(10)
    mol.excel.Range rng();

    @VTID(11)
    mol.excel.XlYesNoGuess header();

    @VTID(12)
    void header(
        mol.excel.XlYesNoGuess rhs);

    @VTID(13)
    boolean matchCase();

    @VTID(14)
    void matchCase(
        boolean rhs);

    @VTID(15)
    mol.excel.XlSortOrientation orientation();

    @VTID(16)
    void orientation(
        mol.excel.XlSortOrientation rhs);

    @VTID(17)
    mol.excel.XlSortMethod sortMethod();

    @VTID(18)
    void sortMethod(
        mol.excel.XlSortMethod rhs);

    @VTID(19)
    mol.excel.SortFields sortFields();

    @VTID(20)
    void setRange(
        mol.excel.Range rng);

    @VTID(21)
    void apply();

}
