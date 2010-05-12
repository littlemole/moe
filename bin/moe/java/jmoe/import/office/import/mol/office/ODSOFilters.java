package mol.office  ;

import com4j.*;

@IID("{000C1534-0000-0000-C000-000000000046}")
public interface ODSOFilters extends mol.office._IMsoDispObj {
    @VTID(9)
    int count();

    @VTID(10)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

    @VTID(11)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject item(
        int index);

    @VTID(12)
    void add(
        java.lang.String column,
        mol.office.MsoFilterComparison comparison,
        mol.office.MsoFilterConjunction conjunction,
        java.lang.String bstrCompareTo,
        boolean deferUpdate);

    @VTID(13)
    void delete(
        int index,
        boolean deferUpdate);

}
