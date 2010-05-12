package mol.excel  ;

import com4j.*;

@IID("{00024407-0001-0000-C000-000000000046}")
public interface IRecentFile extends Com4jObject {
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
    java.lang.String path();

    @VTID(12)
    int index();

    @VTID(13)
    mol.excel._Workbook open();

    @VTID(14)
    void delete();

}
