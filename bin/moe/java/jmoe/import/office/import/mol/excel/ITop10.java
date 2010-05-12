package mol.excel  ;

import com4j.*;

@IID("{0002449D-0001-0000-C000-000000000046}")
public interface ITop10 extends Com4jObject {
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
    mol.excel.XlTopBottom topBottom();

    @VTID(16)
    void topBottom(
        mol.excel.XlTopBottom rhs);

    @VTID(17)
    int rank();

    @VTID(18)
    void rank(
        int rhs);

    @VTID(19)
    boolean percent();

    @VTID(20)
    void percent(
        boolean rhs);

    @VTID(21)
    mol.excel.Interior interior();

    @VTID(22)
    mol.excel.Borders borders();

    @VTID(23)
    mol.excel.Font font();

    @VTID(24)
    int type();

    @VTID(25)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object numberFormat();

    @VTID(26)
    void numberFormat(
        @MarshalAs(NativeType.VARIANT) java.lang.Object rhs);

    @VTID(27)
    void setFirstPriority();

    @VTID(28)
    void setLastPriority();

    @VTID(29)
    void delete();

    @VTID(30)
    void modifyAppliesToRange(
        mol.excel.Range range);

    @VTID(31)
    boolean ptCondition();

    @VTID(32)
    mol.excel.XlPivotConditionScope scopeType();

    @VTID(33)
    void scopeType(
        mol.excel.XlPivotConditionScope rhs);

    @VTID(34)
    mol.excel.XlCalcFor calcFor();

    @VTID(35)
    void calcFor(
        mol.excel.XlCalcFor rhs);

}
