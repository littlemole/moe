package mol.excel  ;

import com4j.*;

@IID("{00024475-0001-0000-C000-000000000046}")
public interface IListRow extends Com4jObject {
    @VTID(7)
    mol.excel._Application application();

    @VTID(8)
    mol.excel.XlCreator creator();

    @VTID(9)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

    @VTID(10)
    void delete();

    @VTID(11)
    int index();

    @VTID(12)
    boolean invalidData();

    @VTID(13)
    mol.excel.Range range();

}
