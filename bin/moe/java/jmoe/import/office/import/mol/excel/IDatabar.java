package mol.excel  ;

import com4j.*;

@IID("{00024496-0001-0000-C000-000000000046}")
public interface IDatabar extends Com4jObject {
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
    mol.excel.ConditionValue minPoint();

    @VTID(15)
    mol.excel.ConditionValue maxPoint();

    @VTID(16)
    int percentMin();

    @VTID(17)
    void percentMin(
        int rhs);

    @VTID(18)
    int percentMax();

    @VTID(19)
    void percentMax(
        int rhs);

    @VTID(20)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject barColor();

    @VTID(21)
    boolean showValue();

    @VTID(22)
    void showValue(
        boolean rhs);

    @VTID(23)
    java.lang.String formula();

    @VTID(24)
    void formula(
        java.lang.String rhs);

    @VTID(25)
    int type();

    @VTID(26)
    void setFirstPriority();

    @VTID(27)
    void setLastPriority();

    @VTID(28)
    void delete();

    @VTID(29)
    void modifyAppliesToRange(
        mol.excel.Range range);

    @VTID(30)
    boolean ptCondition();

    @VTID(31)
    mol.excel.XlPivotConditionScope scopeType();

    @VTID(32)
    void scopeType(
        mol.excel.XlPivotConditionScope rhs);

}
