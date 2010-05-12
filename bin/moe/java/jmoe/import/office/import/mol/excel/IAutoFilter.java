package mol.excel  ;

import com4j.*;

@IID("{00024432-0001-0000-C000-000000000046}")
public interface IAutoFilter extends Com4jObject {
    @VTID(7)
    mol.excel._Application application();

    @VTID(8)
    mol.excel.XlCreator creator();

    @VTID(9)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

    @VTID(10)
    mol.excel.Range range();

    @VTID(11)
    mol.excel.Filters filters();

    @VTID(12)
    boolean filterMode();

    @VTID(13)
    mol.excel.Sort sort();

    @VTID(14)
    void applyFilter();

    @VTID(15)
    void showAllData();

}
