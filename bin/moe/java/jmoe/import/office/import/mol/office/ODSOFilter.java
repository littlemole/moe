package mol.office  ;

import com4j.*;

@IID("{000C1533-0000-0000-C000-000000000046}")
public interface ODSOFilter extends mol.office._IMsoDispObj {
    @VTID(9)
    int index();

    @VTID(10)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

    @VTID(11)
    java.lang.String column();

    @VTID(12)
    void column(
        java.lang.String pbstrCol);

    @VTID(13)
    mol.office.MsoFilterComparison comparison();

    @VTID(14)
    void comparison(
        mol.office.MsoFilterComparison pComparison);

    @VTID(15)
    java.lang.String compareTo();

    @VTID(16)
    void compareTo(
        java.lang.String pbstrCompareTo);

    @VTID(17)
    mol.office.MsoFilterConjunction conjunction();

    @VTID(18)
    void conjunction(
        mol.office.MsoFilterConjunction pConjunction);

}
