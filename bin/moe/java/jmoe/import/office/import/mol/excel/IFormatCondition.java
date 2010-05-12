package mol.excel  ;

import com4j.*;

@IID("{00024425-0001-0000-C000-000000000046}")
public interface IFormatCondition extends Com4jObject {
    @VTID(7)
    mol.excel._Application application();

    @VTID(8)
    mol.excel.XlCreator creator();

    @VTID(9)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

    @VTID(10)
    void _Modify(
        mol.excel.XlFormatConditionType type,
        @MarshalAs(NativeType.VARIANT) java.lang.Object operator,
        @MarshalAs(NativeType.VARIANT) java.lang.Object formula1,
        @MarshalAs(NativeType.VARIANT) java.lang.Object formula2);

    @VTID(11)
    int type();

    @VTID(12)
    int operator();

    @VTID(13)
    java.lang.String formula1();

    @VTID(14)
    java.lang.String formula2();

    @VTID(15)
    mol.excel.Interior interior();

    @VTID(16)
    mol.excel.Borders borders();

    @VTID(17)
    mol.excel.Font font();

    @VTID(18)
    void delete();

    @VTID(19)
    void modify(
        mol.excel.XlFormatConditionType type,
        @MarshalAs(NativeType.VARIANT) java.lang.Object operator,
        @MarshalAs(NativeType.VARIANT) java.lang.Object formula1,
        @MarshalAs(NativeType.VARIANT) java.lang.Object formula2,
        @MarshalAs(NativeType.VARIANT) java.lang.Object string,
        @MarshalAs(NativeType.VARIANT) java.lang.Object operator2);

    @VTID(20)
    java.lang.String text();

    @VTID(21)
    void text(
        java.lang.String rhs);

    @VTID(22)
    mol.excel.XlContainsOperator textOperator();

    @VTID(23)
    void textOperator(
        mol.excel.XlContainsOperator rhs);

    @VTID(24)
    mol.excel.XlTimePeriods dateOperator();

    @VTID(25)
    void dateOperator(
        mol.excel.XlTimePeriods rhs);

    @VTID(26)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object numberFormat();

    @VTID(27)
    void numberFormat(
        @MarshalAs(NativeType.VARIANT) java.lang.Object rhs);

    @VTID(28)
    int priority();

    @VTID(29)
    void priority(
        int rhs);

    @VTID(30)
    boolean stopIfTrue();

    @VTID(31)
    void stopIfTrue(
        boolean rhs);

    @VTID(32)
    mol.excel.Range appliesTo();

    @VTID(33)
    void modifyAppliesToRange(
        mol.excel.Range range);

    @VTID(34)
    void setFirstPriority();

    @VTID(35)
    void setLastPriority();

    @VTID(36)
    boolean ptCondition();

    @VTID(37)
    mol.excel.XlPivotConditionScope scopeType();

    @VTID(38)
    void scopeType(
        mol.excel.XlPivotConditionScope rhs);

}
