package mol.excel  ;

import com4j.*;

@IID("{000244A9-0001-0000-C000-000000000046}")
public interface ISortField extends Com4jObject {
    @VTID(7)
    mol.excel._Application application();

    @VTID(8)
    mol.excel.XlCreator creator();

    @VTID(9)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

    @VTID(10)
    mol.excel.XlSortOn sortOn();

    @VTID(11)
    void sortOn(
        mol.excel.XlSortOn rhs);

    @VTID(12)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject sortOnValue();

    @VTID(13)
    mol.excel.Range key();

    @VTID(14)
    mol.excel.XlSortOrder order();

    @VTID(15)
    void order(
        mol.excel.XlSortOrder rhs);

    @VTID(16)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object customOrder();

    @VTID(17)
    void customOrder(
        @MarshalAs(NativeType.VARIANT) java.lang.Object rhs);

    @VTID(18)
    mol.excel.XlSortDataOption dataOption();

    @VTID(19)
    void dataOption(
        mol.excel.XlSortDataOption rhs);

    @VTID(20)
    int priority();

    @VTID(21)
    void priority(
        int rhs);

    @VTID(22)
    void delete();

    @VTID(23)
    void modifyKey(
        mol.excel.Range key);

    @VTID(24)
    void setIcon(
        mol.excel.Icon icon);

}
