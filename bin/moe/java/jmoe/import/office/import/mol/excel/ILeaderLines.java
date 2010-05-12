package mol.excel  ;

import com4j.*;

@IID("{00024437-0001-0000-C000-000000000046}")
public interface ILeaderLines extends Com4jObject {
    @VTID(7)
    mol.excel._Application application();

    @VTID(8)
    mol.excel.XlCreator creator();

    @VTID(9)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

    @VTID(10)
    mol.excel.Border border();

    @VTID(11)
    void delete();

    @VTID(12)
    void select();

    @VTID(13)
    mol.excel.ChartFormat format();

}
