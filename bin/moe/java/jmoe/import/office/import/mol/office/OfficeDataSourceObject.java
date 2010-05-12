package mol.office  ;

import com4j.*;

@IID("{000C1530-0000-0000-C000-000000000046}")
public interface OfficeDataSourceObject extends Com4jObject {
    @VTID(7)
    java.lang.String connectString();

    @VTID(8)
    void connectString(
        java.lang.String pbstrConnect);

    @VTID(9)
    java.lang.String table();

    @VTID(10)
    void table(
        java.lang.String pbstrTable);

    @VTID(11)
    java.lang.String dataSource();

    @VTID(12)
    void dataSource(
        java.lang.String pbstrSrc);

    @VTID(13)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject columns();

    @VTID(14)
    int rowCount();

    @VTID(15)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject filters();

    @VTID(16)
    int move(
        mol.office.MsoMoveRow msoMoveRow,
        int rowNbr);

    @VTID(17)
    void open(
        java.lang.String bstrSrc,
        java.lang.String bstrConnect,
        java.lang.String bstrTable,
        int fOpenExclusive,
        int fNeverPrompt);

    @VTID(18)
    void setSortOrder(
        java.lang.String sortField1,
        boolean sortAscending1,
        java.lang.String sortField2,
        boolean sortAscending2,
        java.lang.String sortField3,
        boolean sortAscending3);

    @VTID(19)
    void applyFilter();

}
