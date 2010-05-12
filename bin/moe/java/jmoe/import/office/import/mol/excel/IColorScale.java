package mol.excel  ;

import com4j.*;

@IID("{00024493-0001-0000-C000-000000000046}")
public interface IColorScale extends Com4jObject {
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
    java.lang.String formula();

    @VTID(15)
    void formula(
        java.lang.String rhs);

    @VTID(16)
    int type();

    @VTID(17)
    void setFirstPriority();

    @VTID(18)
    void setLastPriority();

    @VTID(19)
    void delete();

    @VTID(20)
    void modifyAppliesToRange(
        mol.excel.Range range);

    @VTID(21)
    boolean ptCondition();

    @VTID(22)
    mol.excel.XlPivotConditionScope scopeType();

    @VTID(23)
    void scopeType(
        mol.excel.XlPivotConditionScope rhs);

    @VTID(24)
    mol.excel.ColorScaleCriteria colorScaleCriteria();

}
