package mol.excel  ;

import com4j.*;

@IID("{000244A5-0001-0000-C000-000000000046}")
public interface ITableStyleElement extends Com4jObject {
    @VTID(7)
    mol.excel._Application application();

    @VTID(8)
    mol.excel.XlCreator creator();

    @VTID(9)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

    @VTID(10)
    boolean hasFormat();

    @VTID(11)
    mol.excel.Interior interior();

    @VTID(12)
    mol.excel.Borders borders();

    @VTID(13)
    mol.excel.Font font();

    @VTID(14)
    int stripeSize();

    @VTID(15)
    void stripeSize(
        int rhs);

    @VTID(16)
    void clear();

}
