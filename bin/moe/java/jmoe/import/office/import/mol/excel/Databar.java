package mol.excel  ;

import com4j.*;

@IID("{00020400-0000-0000-C000-000000000046}")
public interface Databar extends Com4jObject {
    @DISPID(148)
    @PropGet
    mol.excel._Application application();

    @DISPID(149)
    @PropGet
    mol.excel.XlCreator creator();

    @DISPID(150)
    @PropGet
    com4j.Com4jObject parent();

    @DISPID(985)
    @PropGet
    int priority();

    @DISPID(985)
    @PropPut
    void priority(
        int rhs);

    @DISPID(2625)
    @PropGet
    boolean stopIfTrue();

    @DISPID(2626)
    @PropGet
    mol.excel.Range appliesTo();

    @DISPID(2718)
    @PropGet
    mol.excel.ConditionValue minPoint();

    @DISPID(2719)
    @PropGet
    mol.excel.ConditionValue maxPoint();

    @DISPID(2720)
    @PropGet
    int percentMin();

    @DISPID(2720)
    @PropPut
    void percentMin(
        int rhs);

    @DISPID(2721)
    @PropGet
    int percentMax();

    @DISPID(2721)
    @PropPut
    void percentMax(
        int rhs);

    @DISPID(2722)
    @PropGet
    com4j.Com4jObject barColor();

    @DISPID(2024)
    @PropGet
    boolean showValue();

    @DISPID(2024)
    @PropPut
    void showValue(
        boolean rhs);

    @DISPID(261)
    @PropGet
    java.lang.String formula();

    @DISPID(261)
    @PropPut
    void formula(
        java.lang.String rhs);

    @DISPID(108)
    @PropGet
    int type();

    @DISPID(2629)
    void setFirstPriority();

    @DISPID(2630)
    void setLastPriority();

    @DISPID(117)
    void delete();

    @DISPID(2627)
    void modifyAppliesToRange(
        mol.excel.Range range);

    @DISPID(2631)
    @PropGet
    boolean ptCondition();

    @DISPID(2615)
    @PropGet
    mol.excel.XlPivotConditionScope scopeType();

    @DISPID(2615)
    @PropPut
    void scopeType(
        mol.excel.XlPivotConditionScope rhs);

}
