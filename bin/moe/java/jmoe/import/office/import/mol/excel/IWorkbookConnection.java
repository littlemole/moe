package mol.excel  ;

import com4j.*;

@IID("{00024485-0001-0000-C000-000000000046}")
public interface IWorkbookConnection extends Com4jObject {
    @VTID(7)
    mol.excel._Application application();

    @VTID(8)
    mol.excel.XlCreator creator();

    @VTID(9)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

    @VTID(10)
    java.lang.String name();

    @VTID(11)
    void name(
        java.lang.String rhs);

    @VTID(12)
    java.lang.String description();

    @VTID(13)
    void description(
        java.lang.String rhs);

    @VTID(14)
    @DefaultMethod
    java.lang.String _Default();

    @VTID(15)
    @DefaultMethod
    void _Default(
        java.lang.String rhs);

    @VTID(16)
    mol.excel.XlConnectionType type();

    @VTID(17)
    mol.excel.OLEDBConnection oledbConnection();

    @VTID(18)
    mol.excel.ODBCConnection odbcConnection();

    @VTID(19)
    mol.excel.Ranges ranges();

    @VTID(20)
    void delete();

    @VTID(21)
    void refresh();

}
