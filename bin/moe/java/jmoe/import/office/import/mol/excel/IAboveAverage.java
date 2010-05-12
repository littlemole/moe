package mol.excel  ;

import com4j.*;

@IID("{0002449E-0001-0000-C000-000000000046}")
public interface IAboveAverage extends Com4jObject {
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
    void stopIfTrue(
        boolean rhs);

    @VTID(14)
    mol.excel.Range appliesTo();

    @VTID(15)
    mol.excel.XlAboveBelow aboveBelow();

    @VTID(16)
    void aboveBelow(
        mol.excel.XlAboveBelow rhs);

    @VTID(17)
    mol.excel.Interior interior();

    @VTID(18)
    mol.excel.Borders borders();

    @VTID(19)
    mol.excel.Font font();

    @VTID(20)
    int type();

    @VTID(21)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object numberFormat();

    @VTID(22)
    void numberFormat(
        @MarshalAs(NativeType.VARIANT) java.lang.Object rhs);

    @VTID(23)
    void setFirstPriority();

    @VTID(24)
    void setLastPriority();

    @VTID(25)
    void delete();

    @VTID(26)
    void modifyAppliesToRange(
        mol.excel.Range range);

    @VTID(27)
    boolean ptCondition();

    @VTID(28)
    mol.excel.XlPivotConditionScope scopeType();

    @VTID(29)
    void scopeType(
        mol.excel.XlPivotConditionScope rhs);

    @VTID(30)
    mol.excel.XlCalcFor calcFor();

    @VTID(31)
    void calcFor(
        mol.excel.XlCalcFor rhs);

    @VTID(32)
    int numStdDev();

    @VTID(33)
    void numStdDev(
        int rhs);

}
