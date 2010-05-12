package mol.excel  ;

import com4j.*;

@IID("{00024497-0001-0000-C000-000000000046}")
public interface IIconSetCondition extends Com4jObject {
    @VTID(7)
    mol.excel._Application application();

    @VTID(8)
    mol.excel.XlCreator creator();

    @VTID(9)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

    @VTID(10)
    int priority();

    @VTID(11)
    void priority(
        int rhs);

    @VTID(12)
    boolean stopIfTrue();

    @VTID(13)
    mol.excel.Range appliesTo();

    @VTID(14)
    int type();

    @VTID(15)
    void modifyAppliesToRange(
        mol.excel.Range range);

    @VTID(16)
    boolean ptCondition();

    @VTID(17)
    mol.excel.XlPivotConditionScope scopeType();

    @VTID(18)
    void scopeType(
        mol.excel.XlPivotConditionScope rhs);

    @VTID(19)
    void setFirstPriority();

    @VTID(20)
    void setLastPriority();

    @VTID(21)
    void delete();

    @VTID(22)
    boolean reverseOrder();

    @VTID(23)
    void reverseOrder(
        boolean rhs);

    @VTID(24)
    boolean percentileValues();

    @VTID(25)
    void percentileValues(
        boolean rhs);

    @VTID(26)
    boolean showIconOnly();

    @VTID(27)
    void showIconOnly(
        boolean rhs);

    @VTID(28)
    java.lang.String formula();

    @VTID(29)
    void formula(
        java.lang.String rhs);

    @VTID(30)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object iconSet();

    @VTID(31)
    void iconSet(
        @MarshalAs(NativeType.VARIANT) java.lang.Object rhs);

    @VTID(32)
    mol.excel.IconCriteria iconCriteria();

}
