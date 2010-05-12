package mol.excel  ;

import com4j.*;

@IID("{00024486-0001-0000-C000-000000000046}")
public interface IConnections extends Com4jObject,Iterable<Com4jObject> {
    @VTID(7)
    mol.excel._Application application();

    @VTID(8)
    mol.excel.XlCreator creator();

    @VTID(9)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

    @VTID(10)
    int count();

    @VTID(11)
    mol.excel.WorkbookConnection addFromFile(
        java.lang.String filename);

    @VTID(12)
    mol.excel.WorkbookConnection add(
        java.lang.String name,
        java.lang.String description,
        @MarshalAs(NativeType.VARIANT) java.lang.Object connectionString,
        @MarshalAs(NativeType.VARIANT) java.lang.Object commandText,
        @MarshalAs(NativeType.VARIANT) java.lang.Object lCmdtype);

    @VTID(13)
    mol.excel.WorkbookConnection item(
        @MarshalAs(NativeType.VARIANT) java.lang.Object index);

    @VTID(14)
    @DefaultMethod
    mol.excel.WorkbookConnection _Default(
        @MarshalAs(NativeType.VARIANT) java.lang.Object index);

    @VTID(15)
    java.util.Iterator<Com4jObject> iterator();

}
